Pointers are used for storing address of dynamically allocated arrays and for arrays which are passed as arguments to functions. In other contexts, arrays and pointer are two different things, see the following programs to justify this statement.
Behavior of sizeof operator

// 1st program to show that array and pointers are different
#include <stdio.h>
int main()
{
   int arr[] = {10, 20, 30, 40, 50, 60};
   int *ptr = arr;
    
   // sizof(int) * (number of element in arr[]) is printed
   printf("Size of arr[] %d\n", sizeof(arr));
 
   // sizeof a pointer is printed which is same for all type 
   // of pointers (char *, void *, etc)
   printf("Size of ptr %d", sizeof(ptr));
   return 0;
}
Size of arr[] 24 -- 4 bytes * 6
Size of ptr 4 -- 4 bytes on x32 machine
the size of ptr is always same with the size of int on machine
sizeof(ptr) -- to tell whether a machine is 64-bit or 32-bit


Assigning any address to an array variable is not allowed.

// IInd program to show that array and pointers are different
#include <stdio.h>
int main()
{
   int arr[] = {10, 20}, x = 10;
   int *ptr = &x; // This is fine
   arr = &x;  // Compiler Error
   return 0;
}

Although array and pointer are different things, following properties of array make them look similar.

1) Array name gives address of first element of array.
Consider the following program for example.

#include <stdio.h>
int main()
{
   int arr[] = {10, 20, 30, 40, 50, 60};
   int *ptr = arr;  // Assigns address of array to ptr
   printf("Value of first element is %d", *ptr)
   return 0;
}

2) Array members are accessed using pointer arithmetic.
Compiler uses pointer arithmetic to access array element. For example, an expression like “arr[i]” is treated as *(arr + i) by the compiler. That is why the expressions like *(arr + i) work for array arr, and expressions like ptr[i] also work for pointer ptr.

#include <stdio.h>
int main()
{
   int arr[] = {10, 20, 30, 40, 50, 60};
   int *ptr = arr;
   printf("arr[2] = %d\n", arr[2]);
   printf("*(ptr + 2) = %d\n", *(arr + 2));
   printf("ptr[2] = %d\n", ptr[2]);
   printf("*(ptr + 2) = %d\n", *(ptr + 2));
   return 0;
}
arr[2] = 30
*(ptr + 2) = 30
ptr[2] = 30
*(ptr + 2) = 30 

3) Array parameters are always passed as pointers, even when we use square brackets.

#include <stdio.h>
 
int fun(int ptr[])
{
   int x = 10;
 
   // size of a pointer is printed
   printf("sizeof(ptr) = %d\n", sizeof(ptr));
 
   // This allowed because ptr is a pointer, not array
   ptr = &x;
 
   printf("*ptr = %d ", *ptr);
 
   return 0;
}
int main()
{
   int arr[] = {10, 20, 30, 40, 50, 60};
   fun(arr);
   return 0;
}

Sequence containers
Sequence containers implement data structures which can be accessed sequentially.
array -- static contiguous array 

vector == dynamic contiguous array 

deque -- double-ended queue 

forward_list -- singly-linked list 

list -- doubly-linked list 

-------------------------------vector and dequeue ------------------
One main difference between vectors and deques is that the latter allows efficient insertion at the front of the structure as well as the back.

Deques also do not guarantee that their elements are contiguous in memory so the at-style operator (indexing) may not be as efficient.

Note that the difference is unlikely to matter in practice for smaller collections but would generally become more important if, for example, the collection size increases or you're modifying it many times per second.


Associative containers
Associative containers implement sorted data structures that can be quickly searched
(O(log n) complexity).

set -- collection of unique keys, sorted by keys 

map -- collection of key-value pairs, sorted by keys, keys are unique 

multiset -- collection of keys, sorted by keys 

multimap -- collection of key-value pairs, sorted by keys 


Unordered associative containers
Unordered associative containers implement unsorted (hashed) data structures that can be quickly searched (O(1) amortized, O(n) worst-case complexity).

unordered_set -- collection of unique keys, hashed by keys 

unordered_map -- collection of key-value pairs, hashed by keys, keys are unique 

unordered_multiset -- collection of keys, hashed by keys 

unordered_multimap -- collection of key-value pairs, hashed by keys 

container adaptors
Container adaptors provide a different interface for sequential containers.
stack -- adapts a container to provide stack (LIFO data structure) 

queue -- adapts a container to provide queue (FIFO data structure) 

priority_queue -- adapts a container to provide priority queue 
