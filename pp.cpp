makes enterprise software to manage business operations and customer relations.
SAP develops enterprise software for companies large and small. There are 3 components to SAPs strategy. Applications, platform, and business network. Applications are the commonly known ERP that SAP is known for, but it also refers to analytics, crm, hr, etc.
Enterprise resource planning (ERP) is business management software—typically a suite of integrated applications—that a company can use to collect, store, manage and interpret data from many business activities, including: Product planning, cost. Manufacturing or service delivery. Marketing and sales.
What is wrong with the below code?
First Normal Form (1NF)
A database table is said to be in 1NF if it contains no repeating fields/columns. The process of converting the UNF table into 1NF is as follows:
Separate the repeating fields into new database tables along with the key from unnormalized database table.
The primary key of new database tables may be a composite key

Normalization or data normalization is a process to organize the data into tabular format (database tables). A good database design includes the normalization, without normalization a database system may slow, inefficient and might not produce the expected result. Normalization reduces the data redundancy and inconsistent data dependency.
Normal Forms
We organize the data into database tables by using normal forms rules or conditions. Normal forms help us to make a good database design. Generally we organize the data up to third normal form. We rarely use the fourth and fifth normal form.

#include <iostream>
#include <string.h>
using namespace std;
class A
{
        char *p;
        public:
        A(const char* str)
        {
                p=new char[strlen(str)+1];
                strcpy(p,str);
        }
 
        ~A()
        {
                delete p; // should be delete [] p here
                //- you are trying to allocate memory for array and deleting only for one object 
                //- calling delete through destructor twice. 
        }
};
// it did not have a copy and assignment constructors and my code is here..... 
A& operator =(const A &a) 
{ 
	cout<<"assignment constructor"<<endl; 
	p=new char[strlen(a.p)+1]; 
	strcpy(p,a.p); 
} 
void print(){ cout<<"string= "<<p<<endl;} 

A(const A &a){ 
	cout<<"copy constructor"<<endl; 
	p=new char[strlen(a.p)+1]; 
	strcpy(p,a.p); 
} 
int main()
{
        A s("Object s");
        A t=s;
        s.~A();
        A u("Object u");
        u=s;
        return 0;
}
The problem is that in the line 
You have explicitly called the destructor for s object and then at the closing brace of the main function destructor is again been called i.e. what the C++ guarantees. 
And if freed memory is again freed, it is undefined behaviour by the Standard.
2) after calling destructor s->~A() u is assigned to S 
3) copy constructor is not present.... default copu constructor do shallow copy 
here deep copy is reqd 
A s("Object s"); 
A t=s; 
only above two lines in main will also give error.............


why? - innovative and grow fast
-- Our INNOVATIONS in analytics, mobile, cloud, and in-memory computing help customers succeed.
The SAP HANA® platform can increase analysis speed
by more than 10,000x – that’s equal to walking from
California to New York in 6 minutes.
Our reach is GLOBAL – from our employees and customers to the people we touch. Yours can be too.

A C string is usually declared as an array of char. However, an array of char is NOT by itself a C string. A valid C string requires the presence of a terminating "null character" (a character with ASCII value 0, usually represented by the character literal '\0').

   char s4[20] = "";        // Empty or null C string of length 0, equal to ""
It is also possible to declare a C string as a pointer to a char:
char* s3 = "hello";
So here \0  is also counted as the length of the C-style string -- null terminated char array

A C++ string is an object of the class string, which is defined in the header file <string> and which is in the standard namespace. The string class has several constructors that may be called (explicitly or implicitly) to create a string object.
A "null string" is a string with a length of 0:


“SAP solutions are not only for
large multinational companies.
Our products and services address
every challenge a company might
experience, no matter its size.”

The compiler we use in this class, GCC, uses the following sizes in a 32 bit system:
char: 8 bits  -- 1
short: 16 bits -- 2
int: 32 bits -- 4 / ptrs  -- however on 64 machine ptr is 8 bytes
long: 32 bits -- 4 -- however on 64 machine long is 8 bytes -- but int is always 4 bytes
double: 64 bits -- 4
 
On a 64 bit system, longs are typically changed to be 64 bits.
Size of a pointer should be 8 byte on any 64-bit C/C++ compiler, but not necessarily size of int.


--Find the mood of communicating -- keep smiling and be confident!!! always add in own knowledge!!!
----communication is the key -- show what you know and connect with your project/experience

A virtual table contains one entry for each virtual function that can be called by objects of the class. Each entry in this table is simply a function pointer that points to the most-derived function accessible by that class. Second, the compiler also adds a hidden pointer to the base class, which we will call *__vptr.

Each time you create a class that contains virtual functions, or you derive from a class that contains virtual functions, the compiler creates a unique VTABLE for that class.

If you don’t override a function that was declared virtual in the base class, the compiler uses the address of the base-class version in the derived class.

Then it places the VPTR into the class. There is only one VPTR for each object when using simple inheritance . The VPTR must be initialized to point to the starting address of the appropriate VTABLE. (This happens in the constructor.) Once the VPTR is initialized to the proper VTABLE, the object in effect “knows” what type it is. But this self-knowledge is worthless unless it is used at the point a virtual function is called. When you call a virtual function through a base class address (the situation when the compiler doesn’t have all the information necessary to perform early binding), something special happens. Instead of performing a typical function call, which is simply an assembly-language CALL to a particular address, the compiler generates different code to perform the function call.

   if(nums.length == 0 || nums==null){
            return 0;
        }
        
        int local_max = nums[0];
        int global_max = nums[0];
        
        for(int i=1; i<nums.length; i++){
        	//accumulator + new individual / new individual
            local_max = Math.max(nums[i], local_max + nums[i]);
            global_max = Math.max(local_max, global_max);
            
        }
        
    return global_max;

public class Solution {
    public int maxProfit(int[] prices) {
        //corner condition -- ARRAY is NULL or array is not long enough
        if(prices == null || prices.length <2){
            return 0 ;
        }
        int profit =0;
        int min = Integer.MAX_VALUE;
        //min sets as the max value in integer range
        for(int i=0; i<prices.length;++i){
            
            //continuosly updating the smallest price
            min = Math.min(min, prices[i]);
            //continuously compare the profit with the current price - min
            profit = Math.max(profit, prices[i]-min);
        }
        
        return profit;
    }
};

public class Solution {
    public boolean canJump(int[] nums) {
        if(nums==null || nums.length == 0){
            return false;
        }
        
        int global_max= nums[0];
        
        //we get this global max to record the max
        for(int i=1; i<nums.length; i++){
            if(i>global_max){
                return false;
                //we cannot reach this point based on all the past record
            }else{
                global_max = Math.max(global_max, i+nums[i]);//which one is larger
            }
        }
        
        return global_max >= nums.length-1 ? true:false;
    }
};

public class Solution {
    public int lengthOfLIS(int[] nums) {
        //dynamic programming: 1.state 2. transition function 3.initialization 4. answer
        //max/min   whether have a feasible solution?  data could not be adjusted postion
        //if find subset or permutation :: all possible solutions: not DP!!! that is backtracking / recursive
        
        //f[i] means the LIS in the first i elements
        //f[i] = { 1 + max f[j] }    j<i  && nums[j]<nums[i]
        //at last we need to return max( f[0-i] )
        if(nums == null || nums.length ==0 ){
            return 0;
            //they are different!!! nums=nul and nums.length = 0 one is new one is not new
        }
        //just the length is equal to the length of original array should be fine
        int[] dp = new int[nums.length];
        //Integer.parseInt
        Arrays.fill(dp, 1);
        //dp[0] = 1;
        int max =0; 
        
        for(int i=1; i <nums.length; i++){
            for(int j=0; j<i; j++){
                //i is going forward from 1 to length /and/ check each j from 0 to i-1
                if(nums[j] < nums[i] && dp[i] < dp[j]+1 ){
                    dp[i] = dp[j] +1;
                   // max = Math.max(max,dp[i] ); -- not gonna work -- different from max sum array
                }
            }
        }
        //find the global max   
        for(int i=0; i<dp.length; ++i){
            if(dp[i] > max) max = dp[i];
        }
        
        return max;
        //get the max number 
        
    }
};
struct TreeNode {
              // An object of type TreeNode represents one node
              // in a binary tree of strings.

         string item;      // The data in this node.
         TreeNode left;    // Pointer to left subtree.
         TreeNode right;   // Pointer to right subtree.

         TreeNode(string str) {
                // Constructor.  Make a node containing str.
         	item = str;
         	left = NULL;
         	right = NULL;
         }

      };  // end struct Treenode

bool treeContains( TreeNode *root, string item ) {
                 // Return true if item is one of the items in the binary
                 // sort tree to which root points.   Return false if not.
             if ( root == NULL ) {
                   // Tree is empty, so it certainly doesn't contain item.
                return false;
             }
             //failure sub solution
             //success termination
             if ( item == root->item ) {
                   // Yes, the item has been found in the root node.
                return true;
             }
             else if ( item < root->item ) {
                   // If the item occurs, it must be in the left subtree.
                return treeContains( root->left, item );
             }
             else {
                   // If the item occurs, it must be in the right subtree.
                return treeContains( root->right, item );
             }
          }  // end treeContains()    
Its worth noting that recursion is not really essential in this case. A simple, non-recursive algorithm for searching a binary sort tree just follows the rule: Move down the tree until you find the item or reach a NULL pointer. Since the search follows a single path down the tree, it can be implemented as a while loop. Here is non-recursive version of the search routine:

  bool treeContainsNR( TreeNode *root, string item ) {
         // Return true if item is one of the items in the binary
         // sort tree to which root points.   Return false if not.
     TreeNode *runner;  // For "running" down the tree.
     runner = root;     // Start at the root node.
     while (true) {
        if (runner == NULL) {
              // We've fallen off the tree without finding item.
           return false;  
        }
        else if ( item == runner->item ) {
              // We've found the item.
           return true;
        }
        else if ( item < runner->item ) {
              // If the item occurs, it must be in the left subtree,
              // So, advance the runner down one level to the left.
           runner = runner->left;
        }
        else {
              // If the item occurs, it must be in the right subtree.
              // So, advance the runner down one level to the right.
           runner = runner->right;
        }
     }  // end while
  } // end treeContainsNR();

 struct TreeNode {
              int item;         // The data in this node.
              TreeNode *left;   // Pointer to the left subtree.
              TreeNode *right;  // Pointer to the right subtree.
 };
 void preorderPrint( TreeNode *root ) {
           // Print all the items in the tree to which root points.
           // The item in the root is printed first, followed by the
           // items in the left subtree and then the items in the
           // right subtree.
        if ( root != NULL ) {  // (Otherwise, there's nothing to print.)
           cout << root->item << " ";      // Print the root item.
           preorderPrint( root->left );    // Print items in left subtree.
           preorderPrint( root->right );   // Print items in right subtree.
        }
     } // end preorderPrint()
int countNodes( TreeNode *root ) {
           // Count the nodes in the binary tree to which
           // root points, and return the answer.
        if ( root == NULL )
           return 0;  // The tree is empty.  It contains no nodes.
        else {
           int count = 1;   // Start by counting the root.
           count += countNodes(root->left);  // Add the number of nodes
                                            //     in the left subtree.
           count += countNodes(root->right); // Add the number of nodes
                                            //    in the right subtree.
           return count;  // Return the total.
        }
     } // end countNodes()

//it is important to know that the newly inserted node must be the leaf node
     //i.e. the position must be when root == null and we create a new one
  void treeInsert(TreeNode *root, string newItem) {
              // Add the item to the binary sort tree to which the parameter
              // "root" refers.  Note that root is passed by reference since
              // its value can change in the case where the tree is empty.
          if ( root == NULL ) {
                 // The tree is empty.  Set root to point to a new node containing
                 // the new item.  This becomes the only node in the tree.
             root = new TreeNode( newItem );
                     // NOTE:  The left and right subtrees of root
                     // are automatically set to NULL by the constructor.
                     // This is important!
             //we need to indicate this clearly !!!
             return;
          }
          else if ( newItem < root->item ) {
             treeInsert( root->left, newItem );
          }
          else {
             treeInsert( root->right, newItem );
          }
       }  // end treeInsert()


public class Solution {
    public int minDepth(TreeNode root) {
        ////minmum depth???
        if(root==null){
            return 0;
        }
        
        if(root.left == null){
            return minDepth(root.right) +1;
        }
        
        if(root.right == null){
            return minDepth(root.left)+1 ;
        }
        
        return 1 + Math.min(minDepth(root.left), minDepth(root.right));
        
    }
};
public class Solution {
    public boolean isBalanced(TreeNode root) {
        //when it recursives to the end it is correct
        if(root == null){
            return true;
        }
        
        if(Math.abs(depth(root.left)-depth(root.right)) > 1){
            return false;
        }
        
        //any sub tree needs to satisfy the condition above
        return isBalanced(root.left) && isBalanced(root.right);
    }
    
    public int depth(TreeNode n){
        if(n==null){
            return 0;
        }
        
        return 1 + Math.max(depth(n.left), depth(n.right));
    }
        
};
5 Awesome AngularJS Features
AngularJS incorporates the basic principles behind the original MVC software design pattern into how it builds client-side web applications.

The MVC or Model-View-Controller pattern means a lot of different things to different people. AngularJS does not implement MVC in the traditional sense, but rather something closer to MVVM (Model-View-ViewModel).

Feature 2: Templates

It's important to realize that at no point does AngularJS manipulate the template as strings. It's all the browser DOM.

The Document Object Model (DOM) is an application programming interface (API) for valid HTML and well-formed XML documents. It defines the logical structure of documents and the way a document is accessed and manipulated.

he HTML DOM is a standard object model and programming interface for HTML. It defines:

The HTML elements as objects
The properties of all HTML elements
The methods to access all HTML elements
The events for all HTML elements
In other words: The HTML DOM is a standard for how to get, change, add, or delete HTML elements
JS do it on the client-side/browser while PHP do it on the server side
With the object model, JavaScript gets all the power it needs to create dynamic HTML:

JavaScript can change all the HTML elements in the page
JavaScript can change all the HTML attributes in the page
JavaScript can change all the CSS styles in the page
JavaScript can remove existing HTML elements and attributes
JavaScript can add new HTML elements and attributes
JavaScript can react to all existing HTML events in the page
JavaScript can create new HTML events in the page

Feature 4: Dependency Injection

AngularJS has a built-in dependency injection subsystem that helps the developer by making the application easier to develop, understand, and test.
HP is a server scripting language, and a powerful tool for making dynamic and interactive Web pages.
PHP is a widely-used, free, and efficient alternative to competitors such as Microsoft's ASP.
<!DOCTYPE html>
<html>
<body>

<?php
echo "My first PHP script!";
?>

</body>
</html>

Feature 5: Directives

Directives are my personal favorite feature of AngularJS. Have you ever wished that your browser would do new tricks for you? Well, now it can! This is one of my favorite parts of AngularJS. It is also probably the most challenging aspect of AngularJS.

Directives can be used to create custom HTML tags that serve as new, custom widgets. They can also be used to "decorate" elements with behavior and manipulate DOM attributes in interesting ways.

Here is a simple example of a directive that listens for an event and updates its $scope, accordingly.

  myModule.directive('myComponent', function(mySharedService) {
      return {
          restrict: 'E',
          controller: function($scope, $attrs, mySharedService) {
              $scope.$on('handleBroadcast', function() {
                  $scope.message = 'Directive: ' + mySharedService.message;
              });
          },
          replace: true,
          template: '<input>'
      };
  });
Then, you can use this custom directive, like so.
<my-component ng-model="message"></my-component>
Creating your application as a composition of discrete components makes it incredibly easy to add, update or delete functionality as needed.
--------------------------------------------------------------------
public int strStr(String haystack, String needle) {
    //Returns the index of the "first occurrence of needle in haystack", or -1 if needle is not part of haystack.
    //the needle in haystack
    //judge whether the string is the substring of another string
    if(needle.length() == 0){
        return 0; //because if we want to search a needle " empty" 
        //then we just return the whole string back is okay
    }     
    int j;
    for(int i=0; i<haystack.length()-needle.length()+1; i++){
        for(j =0; j<needle.length(); j++){
            if(needle.charAt(j) != haystack.charAt(i+j)){
                //start next index
                break;
            }
            //found
            if(j == needle.length()-1){
             return i;
            }
        }
        
        
    }    
    return -1;
}
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public int closestValue(TreeNode root, double target) {
        
        int closest = root.val;
        double min = Double.MAX_VALUE;
        
        while(root!=null) {
            if( Math.abs(root.val - target) < min  ) {
                min = Math.abs(root.val - target);
                closest = root.val;
            }
            
            if(target < root.val) {
                root = root.left;
            } else if(target > root.val) {
                root = root.right;
            } else {
                return root.val;
            }
        }
        
        return closest;
    }
};

1. Find Min and Max of an array in only one   traversal 2. Given a chessboard find maximum number of squares present 3. Job description. 4. Difference between deep and shallow copy. 5. What is C++ 6. Whats "preinitialization" 
 1. reverse a linked list 1.1 Use Recursion 2. Copy   constructor, operator = different used cases, code 3. Deep Copy, Shallow Copy Used cases 4. Different versions of polymorphism, how to solve the problem of multiple inheritance. 5. Deep look into Virtual concepts, inheritance. 6. Template classes, WAP operator= for template class such that it behaves differently for int and char * 7. Given a tree, WAP such that a matrix is generated so that: Tree: 1 / \ 2 3 | / \ 4 5 6 1 2 3 4 5 6 1 0 1 1 1 1 1 2 0 0 0 1 0 0 3 0 0 0 0 1 1 4 0 0 0 0 0 0 5 0 0 0 0 0 0 6 0 0 0 0 0 0 Hint: Preorder 8. Given an array, 1 2 0 5 4 88 0 0 0 6 make it, 1 2 5 4 88 6 0 0 0 0 9. Gave me class hierarchy, List the number of VTables created 10. When to use List and when to use Vector of STL 11. Given a string "I LOVE INDIA", print "INDIA LOVE I" 

Shallow copies duplicate as little as possible. A shallow copy of a collection is a copy of the collection structure, not the elements. With a shallow copy, two collections now share the individual elements.
-- When the owned variables are immutable types, a shallow copy is sufficient. A deep copy is possible, but would only result in additional memory use.
For example string in java will use shallow copy -- it just make the additional reference pointing to the existing reference of the string

Deep copies duplicate everything. A deep copy of a collection is two collections with all of the elements in the original collection duplicated.

In short, it depends on what points to what. In a shallow copy, object B points to object As location in memory. In deep copy, all things in object A's memory location get copied to object B's memory location.


Recall array variables in Java are references or pointers. A shallow copy can be made by simply copying the reference.

public class Ex{
    private int[] data;

    public Ex(int[] values){
        data = values;
    }

    public void showData(){
        System.out.println( Arrays.toString(data) );
    }
};
This can lead to unpleasant side effects if the elements of values are changed via some other reference.
public class UsesEx{
    public static void main(String[] args){
        int[] vals = {-5, 12, 0};
        Ex e = new Ex(vals);
        e.showData(); // prints out [-5, 12, 0]
        vals[0] = 13;
        e.showData(); // prints out [13, 12, 0]
        // Very confusiin, because I didn't intentionally change anything about the 
        // object e refers to.
    }
};
A deep copy means actually creating a new array and copying over the values.

public class Ex{
    private int[] data;

    public Ex(int[] values){
        data = new int[values.length];
        for(int i = 0; i < data.length; i++)
            data[i] = values[i];
    }

    public void showData(){
        System.out.println( Arrays.toString(data) );
    }
};
Changes to the array values refers to will not result in changes to the array data refers to.


----------------copy constructor -- uninitialized -- assignment operator --- replace existing
class A {
public:
    A() {
        cout << "A::A()" << endl;
    }
};

// The copy constructor
A a = b;

// The assignment constructor
A c;
c = a;

the difference between a copy constructor and an assignment constructor is:

In case of a copy constructor it creates a new object.(<classname> <o1>=<o2>)
In case of an assignment constructor it will not create any object means it apply on already created objects(<o1>=<o2>).

A copy constructor is used to initialize a previously uninitialized object from some other objects data.

A(const A& rhs) : data_(rhs.data_) {}
An assignment operator is used to replace the data of a previously initialized object with some other objects data.

A& operator=(const A& rhs) {data_ = rhs.data_; return *this;}
You could replac