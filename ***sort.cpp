When this first pass through the array is complete, the bubble sort returns to elements one and two and starts the process all over again.  So, when does it stop?  The bubble sort knows that it is finished when it examines the entire array and no "swaps" are needed (thus the list is in proper order).  The bubble sort keeps track of occurring swaps by the use of a flag. 

The bubble sort is an easy algorithm to program, but it is slower than many other sorts.  With a bubble sort, it is always necessary to make one final "pass" through the array to check to see that no swaps are made to ensure that the process is finished.  In actuality, the process is finished before this last pass is made.

In the bubble sort, as elements are sorted they gradually "bubble" (or rise) to their proper location in the array, like bubbles rising in a glass of soda.  The bubble sort repeatedly compares adjacent elements of an array.  The first and second elements are compared and swapped if out of order.  Then the second and third elements are compared and swapped if out of order.  This sorting process continues until the last two elements of the array are compared and swapped if out of order. 

// Bubble Sort Function for Descending Order 
//space complexity  O(1)
//time complexity O(n)	O(n^2)
void BubbleSort(apvector <int> &num)
{
      int i, j, flag = 1;    // set flag to 1 to start first pass
      int temp;             // holding variable
      int numLength = num.length( ); 
      for(i = 1; (i <= numLength) && flag; i++)
     {
          flag = 0;
          for (j=0; j < (numLength -1); j++)
         {
               if (num[j+1] > num[j])      // ascending order simply changes to <
              { 
                    temp = num[j];             // swap elements
                    num[j] = num[j+1];
                    num[j+1] = temp;

                    flag = 1;               // indicates that a swap occurred.
               }
          }
     }
     return;   //arrays are passed to functions by address; nothing is returned
}


//quick sort -- divide and conquer
O(n log(n))	O(n log(n))	O(n^2) -- worst need to be O(n2)
//space complexity - just the stack for recursion O(log(n))
void quickSort(int arr[], int left, int right) {
      int i = left, j = right;
      //here we need to be careful because we are using the middle number as the pivot each time
      int pivot = arr[(left + right) / 2];
 
      /* partition */
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
              //after that i and j will locate a pair of values that need to be swapped
              //after while i<=j here we need to double check if i<=j
            if (i <= j) {
            	//double check i<=j to stop at viable positions before we swap them
                  int tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  //after this we still need to i++ and j-- just like 3 sum
                  i++;
                  j--;
            }
      };
 
      /* recursion */
      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
}
Like Merge Sort, QuickSort is a Divide and Conquer algorithm. It picks an element as pivot and partitions the given array around the picked pivot. There are many different versions of quickSort that pick pivot in different ways.
1) Always pick first element as pivot.
2) Always pick last element as pivot (implemented below)
3) Pick a random element as pivot.
4) Pick median as pivot.

The key process in quickSort is partition(). Target of partitions is, given an array and an element x of array as pivot, put x at its correct position in sorted array and put all smaller elements (smaller than x) before x, and put all greater elements (greater than x) after x. All this should be done in linear time.

/* A typical recursive implementation of quick sort */
#include<stdio.h>
 
// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
//or without swap(&a, &b) and using void swap(int *a, int *b) to receive the address
//we could do call swap(a,b) -- and directly using swap(int &a,  int &b) to receive reference
void swap(int& i, int& j) {
    int t = i;
    i = j;
    j = t;
}


/* This function takes last element as pivot, places the pivot element at its
   correct position in sorted array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right of pivot */
int partition (int arr[], int l, int h)
{
    int x = arr[h];    // pivot
    int i = (l - 1);  // Index of smaller element
 
    for (int j = l; j <= h- 1; j++)
    {
        // If current element is smaller than or equal to pivot 
        if (arr[j] <= x)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);  // Swap current element with index
        }
    }
    swap(&arr[i + 1], &arr[h]);  
    return (i + 1);
}
 
/* arr[] --> Array to be sorted, l  --> Starting index, h  --> Ending index */
void quickSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int p = partition(arr, l, h); /* Partitioning index */
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, h);
    }
}
 
// Driver program to test above functions
int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    //size of arr = 4 bytes * 6
    //size of arr[0] = 4 bytes
    //int arr_size = arr.size();
	//for(int i=0; i<arr_size; ++i) {//print the values}

    quickSort(arr, 0, n-1);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}

//selection sort -- O(n^2)	O(n^2) bad even in sorted array still O n2
The selection sort is a combination of searching and sorting.
While being an easy sort to program, the selection sort is one of the least efficient.  The algorithm offers no way to end the sort early, even if it begins with an already sorted list. 


During each pass, the unsorted element with the smallest (or largest) value is moved to its proper position in the array.  
The number of times the sort passes through the array is one less than the number of items in the array.  In the selection sort, the inner loop finds the next smallest (or largest) value and the outer loop places that value into its proper location.


void SelectionSort(apvector <int> &num)
{
      int i, j, first, temp;
      int numLength = num.length( );
      for (i= numLength - 1; i > 0; i--)
     {
           first = 0;                 // initialize to subscript of first element
           for (j=1; j<=i; j++)   // locate smallest between positions 1 and i.
          {
                 if (num[j] < num[first])
                 first = j;
          }

          //here we declare temp outside the loop so that it will not be
          //declared each time for the iteration
         temp = num[first];   // Swap smallest found with element in position i.
         num[first] = num[i];
         num[i] = temp;
     }
     return;
}

//merge sort -- O(n log(n))	O(n log(n)) -- O(n)
The merge sort combines two sorted arrays into
one larger sorted array.   
As the diagram at the left shows,
Array A and Array B merge to form Array C. 

Arrays to be merged MUST be SORTED FIRST!! 
 The first element of array A is compared with the first element of array B.  If the first element of array A is smaller than the first element of array B, the element from array A is moved to the new array C.  The subscript of array A is now increased since the first element is now set and we move on.  If the element from array B should be smaller, it is moved to the new array C.  The subscript of array B is increased.  This process of comparing the elements in the two arrays continues until either array A or array B is empty. 
 *** When one array is empty, any elements remaining in the other (non-empty) array are "pushed" into the end of array C and the merge is complete. 

#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> v)
{
	for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
	cout << endl;
}

vector<int> merge(vector<int> left, vector<int> right)
{
   vector<int> result;
   while ((int)left.size() > 0 || (int)right.size() > 0) {
      if ((int)left.size() > 0 && (int)right.size() > 0) {
         if ((int)left.front() <= (int)right.front()) {
            result.push_back((int)left.front());
            left.erase(left.begin());
         } 
	 else {
            result.push_back((int)right.front());
            right.erase(right.begin());
         }
      }  else if ((int)left.size() > 0) {
            for (int i = 0; i < (int)left.size(); i++)
               result.push_back(left[i]);
            break;
      }  else if ((int)right.size() > 0) {
            for (int i = 0; i < (int)right.size(); i++)
               result.push_back(right[i]);
            break;
      }
   }
   return result;
}

vector<int> mergeSort(vector<int> m)
{
   if (m.size() <= 1)
      return m;
 
   vector<int> left, right, result;
   int middle = ((int)m.size()+ 1) / 2;
 
   for (int i = 0; i < middle; i++) {
      left.push_back(m[i]);
   }

   for (int i = middle; i < (int)m.size(); i++) {
      right.push_back(m[i]);
   }
 
   left = mergeSort(left);
   right = mergeSort(right);
   result = merge(left, right);
 
   return result;
}

------------------------------------------------
#include <iostream>
using namespace std;

void print(int a[], int sz)
{
	for (int i = 0; i < sz; i++) cout << a[i] << " ";
	cout << endl;
}
 
/* for variable length array initialization we must use dynamic allocation
int x;
in >> x;
int* array = new int[ x ];
// use array here ...
delete [] array;

int x;
in >> x;
int array[x];
//this is wrong*/

void merge(int a[], const int low, const int mid, const int high)
{
	int *temp = new int[high-low+1];
        
	int left = low;
	int right = mid+1;
	int current = 0;
	// Merges the two arrays into temp[] 
	while(left <= mid && right <= high) {
		if(a[left] <= a[right]) {
			temp[current] = a[left];
			left++;
		}
		else { // if right element is smaller that the left
			temp[current] = a[right];  
			right++;
		}
		current++;
	}

	// Completes the array 

        // Extreme example a = 1, 2, 3 || 4, 5, 6
        // The temp array has already been filled with 1, 2, 3, 
        // So, the right side of array a will be used to fill temp.
	if(left > mid) { 
		for(int i=right; i <= high;i++) {
			temp[current] = a[i];
			current++;
		}
	}
        // Extreme example a = 6, 5, 4 || 3, 2, 1
        // The temp array has already been filled with 1, 2, 3
        // So, the left side of array a will be used to fill temp.
	else {  
		for(int i=left; i <= mid; i++) {
			temp[current] = a[i];
			current++;
		}
	}
	// into the original array
	for(int i=0; i<=high-low;i++) {
                a[i+low] = temp[i];
	}
	delete[] temp;
}
 
void merge_sort(int a[], const int low, const int high)
{
	if(low >= high) return;
	int mid = (low+high)/2;
	merge_sort(a, low, mid);  //left half
	merge_sort(a, mid+1, high);  //right half
	merge(a, low, mid, high);  //merge them
}
 
int main()
{        
	int a[] = {38, 27, 43, 3, 9, 82, 10};
	int arraySize = sizeof(a)/sizeof(int);

	print(a, arraySize);

	merge_sort(a, 0, (arraySize-1) );   

	print(a, arraySize);	
	return 0;
}
