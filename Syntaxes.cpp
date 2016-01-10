HashMap
map <key_type, data_type, [comparison_function]>
map <string, char> grade_list;
grade_list["John"] = 'B';
// John's grade improves
grade_list["John"] = 'A';
For instance, to erase "John" from our map, we could do the following:
grade_list.erase("John");
"The class is size "<<grade_list.size()<<std::endl;
grade_list.clear(); // bool empty();

map <string, char> grade_list;
grade_list["John"] = 'A';
if(grade_list.find("Tim") == grade_list.end())
{
    std::cout<<"Tim is not in the map!"<<endl;
}

For instance, the following sample shows the use of an iterator (pointing to the beginning of a map) to access the key and value.
std::map <string, char> grade_list;
grade_list["John"] = 'A';
// Should be John
std::cout<<grade_list.begin()->first<<endl;
// Should be A
std::cout<<grade_list.begin()->second<<endl;

//iterate through c++
map< string, map<string, string> > mymap
for(auto const &ent1 : mymap) {
  // ent1.first is the first key
  for(auto const &ent2 : ent1.second) {
    // ent2.first is the second key
    // ent2.second is the data
  }
}

typedef std::map<std::string, std::map<std::string, std::string>>::iterator it_type;
for(it_type iterator = m.begin(); iterator != m.end(); iterator++) {
    // iterator->first = key
    // iterator->second = value
    // Repeat if you also want to iterate through the second map.
}

//we could do something -- go the view of sublime -> word wrap
Use these smart pointers as a first choice for encapsulating pointers to plain old C++ objects (POCO).
unique_ptr  -- can be moved but cannot be copied or shared
Allows exactly one owner of the underlying pointer. Use as the default choice for POCO unless you know for certain that you require a shared_ptr. Can be moved to a new owner, but not copied or shared. 

Replaces auto_ptr, which is deprecated. Compare to boost::scoped_ptr. unique_ptr is small and efficient; the size is one pointer and it supports rvalue references for fast insertion and retrieval from STL collections. Header file: <memory>. For more information, see How to: Create and Use unique_ptr Instances and unique_ptr Class. -- This class template provides a limited garbage collection facility for pointers, by allowing pointers to have the elements they point to automatically destroyed when the auto_ptr object is itself destroyed.

shared_ptr  -- reference counting  -- when the reference counting becomes 0 then delete
Reference-counted smart pointer. Use when you want to assign one raw pointer to multiple owners, for example, when you return a copy of a pointer from a container but want to keep the original. The raw pointer is not deleted until all shared_ptr owners have gone out of scope or have otherwise given up ownership. The size is two pointers; one for the object and one for the shared control block that contains the reference count. Header file: <memory>. For more information, see How to: Create and Use shared_ptr Instances and shared_ptr Class.

weak_ptr 
Special-case smart pointer for use in conjunction with shared_ptr. A weak_ptr provides access to an object that is owned by one or more shared_ptr instances, but does not participate in reference counting. Use when you want to observe an object, but do not require it to remain alive. Required in some cases to break circular references between shared_ptr instances. Header file: <memory>. For more information, see How to: Create and Use weak_ptr Instances and weak_ptr Class.
void UseRawPointer(){
    // Using a raw pointer -- not recommended.
    Song* pSong = new Song(L"Nothing on You", L"Bruno Mars"); 

    // Use pSong...

    // Don't forget to delete!
    delete pSong;   
}
void UseSmartPointer(){
    // Declare a smart pointer on stack and pass it the raw pointer.
    unique_ptr<Song> song2(new Song(L"Nothing on You", L"Bruno Mars"));

    // Use song2...
    wstring s = song2->duration_;
    //...

} // song2 is deleted automatically here.


And yet, in many real-world scenarios, you don’t copy objects but move them. 
When my landlord cashes my rent check, he moves money from my account into his. 
Similarly, removing the SIM card from your mobile phone and installing it in another
 mobile is a move operation, and so are cutting-and-pasting icons on your desktop, 
 or borrowing a book from a library.



Move Special Member Functions
C++11 introduces two new special member functions: the move constructor and the move assignment operator. They are an addition to the fabulous four you know so well:

Default constructor
Copy constructor
Copy assignment operator
Destructor
move constructor
move assignment operator

If a class doesn’t have any user-declared special member functions (save a default constructor), C++ declares its remaining five (or six) special member functions implicitly, including a move constructor and a move assignment operator. For example, the following class


One of the nice features of C++ is that you can give special meanings to operators, when they are used with user-defined classes. This is called operator overloading. You can implement C++ operator overloads by providing special member-functions on your classes that follow a particular naming convention. For example, to overload the + operator for your class, you would provide a member-function named operator+ on your class.

The following set of operators is commonly overloaded for user-defined classes:

= (assignment operator)
+ - * (binary arithmetic operators)
+= -= *= (compound assignment operators)
== != (comparison operators)
