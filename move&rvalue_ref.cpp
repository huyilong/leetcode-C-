Technically, an rvalue is an unnamed value that exists only during the evaluation of an expression. For example, the following expression produces an rvalue:

x+(y*z); // A C++ expression that produces a temporary 

C++ creates a temporary (an rvalue) that stores the result of y*z, and then adds it to x. Conceptually, this rvalue evaporates by the time you reach the semicolon at the end of the full expression.

A declaration of an rvalue reference looks like this:

std::string&& rrstr; //C++11 rvalue reference variable

The traditional reference variables of C++ e.g.,

std::string& ref;

are now called lvalue references.

Rvalue references occur almost anywhere, even if you don’t use them directly in your code. They affect the semantics and lifetime of objects in C++11. To see how exactly, it’s time to talk about move semantics.

------Get to Know Move Semantics-----------
And yet, in many real-world scenarios, you don’t copy objects but move them. When my landlord cashes my rent check, he moves money from my account into his. Similarly, removing the SIM card from your mobile phone and installing it in another mobile is a move operation, and so are cutting-and-pasting icons on your desktop, or borrowing a book from a library.

Notwithstanding the conceptual difference between copying and moving, there’s a practical difference too: Move operations tend to be faster than copying because they transfer an existing resource to a new destination, whereas copying requires the creation of a new resource from scratch. The efficiency of moving can be witnessed among the rest in functions that return objects by value. Consider:

string func()
{
string s;
//do something with s
return s;
}
string mystr=func();

When func() returns, C++ constructs a temporary copy of s on the caller’s stack memory. Next, s is destroyed and the temporary is used for copy-constructing mystr. After that, the temporary itself is destroyed. Moving achieves the same effect without so many copies and destructor calls along the way.

Moving a string is almost free; it merely assigns the values of the source’s data members to the corresponding data members of the target. In contrast, copying a string requires the allocation of dynamic memory and copying the characters from the source.

C++11 introduces two new special member functions: the move constructor and the move assignment operator. They are an addition to the fabulous four you know so well:

Default constructor
Copy constructor
Copy assignment operator
Destructor

If a class doesn’t have any user-declared special member functions (save a default constructor), C++ declares its remaining five (or six) special member functions implicitly, including a move constructor and a move assignment operator. For example, the following class

class S{};

doesn’t have any user-declared special member functions. Therefore, C++ declares all of its six special member functions implicitly. 
Under certain conditions, implicitly declared special member functions become implicitly defined as well. The implicitly-defined move special member functions move their sub-objects and data members in a member-wise fashion. Thus, a move constructor invokes its sub-objects’ move constructors, recursively. Similarly, a move assignment operator invokes its sub-objects’ move assignment operators, recursively.


-------------what happens to a move-from object?---------------------
What happens to a moved-from object? The state of a moved-from object is unspecified. Therefore, always assume that a moved-from object no longer owns any resources, and that its state is similar to that of an empty (as if default-constructed) object. For example, if you move a string s1 to s2, after the move operation the state of s2 is identical to that of s1 before the move, whereas s1 is now an empty (though valid) string object.

Designing a Move Constructor
A move constructor looks like this:

C::C(C&& other); //C++11 move constructor

It doesn’t allocate new resources. Instead, it pilfers other‘s resources and then sets other to its default-constructed state.

Suppose you’re designing a MemoryPage class that represents a memory buffer:

class MemoryPage
{
size_t size;
char * buf;
public:
explicit MemoryPage(int sz=512):
size(sz), buf(new char [size]) {}
~MemoryPage( delete[] buf;}
//typical C++03 copy ctor and assignment operator
MemoryPage(const MemoryPage&);
MemoryPage& operator=(const MemoryPage&);
};

A typical move constructor definition would look like this:

//C++11
MemoryPage(MemoryPage&& other): size(0), buf(nullptr)
{
// pilfer other’s resource
size=other.size;
buf=other.buf;
// reset other
other.size=0;
other.buf=nullptr;
}

----------compare to copy constructor------------------
The copy constructor is used for creation of object based on another's instance of the same type. You don't have such. You can define it using code like this:

A(const A &other)
{
   myArray = new int[other._size];
   _size = other._size;
   memcpy(myArray, other.myArray, sizeof(int) * _size);
}
	
You should change your class, so it will store _size of array, you also need to change visibility of your constructors and destructor to public.

The overloaded assignment operator should look like this:

const A &operator=(const A &other)
{
	//copy assignment operator overloading we need to check for the SELF-ASSIGNMENT at first
	//if(this == &other) compare the address{ return *this; }
	//this is the pointer pointing to the current object of the class which is implicitly passed in
	//any non-static methods because static method could be used without instantiating it
   if(this == &other) return *this; // handling of self assignment, thanks for your advice, arul.
   delete[] myArray; // freeing previously used memory
   myArray = new int[other._size];
   _size = other._size;
   memcpy(myArray, other.myArray, sizeof(int) * _size);
   return *this;
}
You also can add a check of equality of array sizes in this assignment operator, so you will reuse your dynamic array without unnecessary reallocations of memory.

----------------------why would we use move constructor????--------------------------
The move constructor is much faster than a copy constructor because it doesn’t allocate memory nor does it copy memory buffers.