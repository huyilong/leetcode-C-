import java.io.*;
import java.util.*;
class Solution {
	private static ArrayList<ArrayList<String>> helper(ArrayList<ArrayList<String>> dict){ 
		ArrayList<ArrayList<String>> res = new ArrayList<ArrayList<String>>();
    //check illegal input
		if(dict == null || dict.size() < 2){
			return res;
		}
    //initialize the result with each word in the first word list of dictionary
		ArrayList<String> temp = dict.get(0);
		for(int m=0; m<temp.size(); m++){
			ArrayList<String> sub = new ArrayList<String>();
			sub.add(temp.get(m));
			res.add(new ArrayList<String>(sub));    
		}
    //iteratively fetch the existing words from previous result
    //and combine them with the new words in the dictionary
		ArrayList<String> sub = new ArrayList<String>();
		ArrayList<ArrayList<String>> preres = new ArrayList<ArrayList<String>>();
		for(int i=1; i<dict.size(); i++){
      //get the word list from dictionary
			temp = dict.get(i);     
			for(int j=0; j<res.size(); j++){
        //get the existing combinations from result
				sub = res.get(j);
				for(int k=0; k<temp.size(); k++){
            //add the word into combination list
					sub.add(temp.get(k));
            //add the combination into result
					preres.add(new ArrayList<String>(sub)); 
            //delete the last word for next iteration
					sub.remove(sub.size()-1);
				} 
			} 
      //prepare for the next iteration
			res = preres;
			preres = new ArrayList<ArrayList<String>>();
		}
    //return the result
		return res;
	}
}

/*
You're given a vector of vectors of words, e.g.: 
[['quick', 'lazy'], ['brown', 'black', 'grey'], ['fox', 'dog']]. 

Write a generalized function that prints all combinations of one word from the first vector, one word from the second vector, etc. 
The solution may not use recursion. 
NOTE: the number of vectors and number of elements within each vector may vary.

For the input above, it should print (in any order): 
quick brown fox 
quick brown dog 
quick black fox 
quick black dog 
... 
lazy grey dog
*/




public ArrayList<String> norecursion(ArrayList<ArrayList<String>> strings){
	ArrayList<String> res=new ArrayList<String>();. from: 1point3acres.com/bbs 
	res.add("");
	for (int i=0;i<strings.size();i++).1point3acres缃�
	{
		ArrayList<String> tmp = new ArrayList<>();
		for (String str:res){
			tmp.add(str);
		}
		res.clear();
		ArrayList<String> str=strings.get(i);
		for (String s1:tmp){
			for (String s2:str){
				res.add(s1+" "+s2);
			}
		}
	}
	ArrayList<String> tmp=new ArrayList<String>();
	for (String str:res){
		tmp.add(str.trim());
	}
	return tmp;. 1point3acres.com/bbs
}

电面：1. 给一个数组，要求负数放在正数前面，但相对顺序不变。
2. Valid Parenthese
3. PHP 改bug，我的是如果count()里面数为空的时候最后 $text 输出时候 type 不对
部分代码：
              if(count($size_array)==0){ // 这里是我改好的，判断为空时候的情况
              	$text .= 'It is Empty';
              }
              else if (count($size_array) > 5) {
              	$text .= ' in all sizes';   
              } else {
              	$text .= ' in sizes ' . implode(' - ', $size_array);      
              }
              $lines[] = $text;
          }
          return $lines;

          12.11下午1点交的OA，3点多HR就回邮件说约电话面试了，12.16下午一点开始的电面，上来问我简历和project就花了快二十分钟，然后做题，输入array，把negative放在左边，positive放在右边的题目，问了一下0和相对顺序可以打乱么，面试官回答0按正数处理，相对的顺序不可以打乱。先写了一个O(n) space的方法，然后用一个pointer写了一个in place的方法，面试官很满意。然后说给一段PHP代码，问代码是神马意思，之前自己没学过PHP，地里面的面经当时也没有PHP相关，自己看了一下，大概是有几种不同的鞋子，分不同的种类啊（high heel，sneaker什么的），颜色啊，尺码啊，价格啊什么的，然后把他们显示出来。我就大概和他讲了每段代码啥意思都，然后面试官运行了一下，说里面有个错误，你能找到哪里错了吗，我记得显示的是，小于50块钱的鞋子当中，红色的尺码有5,6,7,6.5什么的，黄色的尺码有什么什么
          ，然后蓝色的尺码没有显示，于是开始找哪里有错误，发现在最上面蓝色那里size这个attribute是空的，于是跟面试官说了，然后给他随便加了一些size, 运行显示了一下，面试官很开心。然后说那我再问你一下，如果我让你显示的是 A blue XX shoe out of stock你如何修改，这个是在中间那块改的，就照猫画虎加上了显示 out of stock 的语句，还有删除了之前的一些，给他显示出来了。面试官说OK 你的反应好快啊，我的问题都被你解答出来问完了，你有什么问题问我的吗，于是自己问了下大概每天的工作是什么之类的，面试官回答了一下，到2点的时候面试就结束了，相互祝好运之后面试官就挂掉了电话。

          时间就过了一半，直接给我贴上一段php代码，问我输出和如果改，代码不难，有两个key word不懂 一个是 PHP_EOL 换行符 一个是 implode 作用类似array.toString(). 我本来以为只需要说一下代码的意思，结果浪费了一段时间，当他让我写output的时候，我又出了一个小错误，他就说让我再想想，又浪费一段时间，改完以后完全正确了，他确认了跑了一下，结果时间也到了. 因为完全没时间被问到算法题，当时的心情非常糟糕. 求一个顺利.
          <?php

          $array = array('lastname', 'email', 'phone');
          $comma_separated = implode(",", $array);

echo $comma_separated; // lastname,email,phone
?>

echo 'A $variable_literal that I have'.PHP_EOL.'looks better than'.PHP_EOL;  
echo 'this other $one'."\n";

那我仔细说一下子把，php题就是你说的 shoes 题 . 其实前面地里的面经有些误导人，并不是找bug，首先, 会让你写出，如果执行某一个函数调用语句，output是啥，代码是没有bug的，是完全可以跑通的(但是他不会让你去run). 过了这一关，然后问题来了，就跟地里面经一样，比如 blue sneaker 后面怎么啥子描述都没有啊，然后你可以跟他说 它的array里并没有定义 size 这个变量 所以是空的 但是不会报错 按照面试官的原话是 looks weird. 你再说咋改.

import java.util.*;
/*
The java.util.Arrays.toString(int[]) method returns a string representation of the contents of the specified int array. The string representation consists of a list of the array's elements, enclosed in square brackets ("[]"). Adjacent elements are separated by the characters ", " (a comma followed by a space).

Sort n elements.
 n insert operations => O(n log n) time.
 n remove max operations => O(n log n) time.
 total time is O(n log n).

*/
//php must be very familiar with!!!
public class Move{
	
	写的时候才问了0如何处理，回答说和positive一样

	public static void main(String[] args){
		int[] test = {-6,2,1,2,-10,0, -4,8};//0 is regarded as positive number
		
		//void -- o(1) & o(n^2)
		helper(test);
		System.out.println(Arrays.toString(test));
		// for(int m : test){
		// 	System.out.print(test[m]);
		// }
		int[] test2 = {-6,2,1,2,-10,0, -4,8};
		//o(n) & o(n)
		int[] res = helper2(test2);
		System.out.println(Arrays.toString(res));
		int[] test3 = {-6,2,1,2,-10,0, -4,8};
		// Comparator<Integer> cmp = new Comparator<Integer>(){
		// 	public int compare(int in){
		// 		return -in;
		// 	}
		// };
		// Arrays.sort(test3, cmp);
		// Arrays.sort(test3, new MoveCmp());
		// System.out.println(Arrays.toString(test3));
	}

	//o(1) & o(n^2)
	private static void helper(int[] input){
		int temp;
		for(int i=0; i<input.length; i++){
			if(input[i]<0 && i>0){
				//make sure it is not the first one and our comparision of j-1 outOfBound
				//keep swapping it with the previous non-negative number
				for(int j = i; j>=0; j--){
					if(input[j-1] >=0 ){
						temp = input[j-1];
						input[j-1] = input[j];
						input[j] = temp;
					}else{
						break;
					}
				}
			}
		}
	}

	//o(n) & o(n)
	private static int[] helper2(int[] input){
		int[] result = new int[input.length];
		int index=0;//new index for the result array
		for(int i=0; i<input.length; i++){
			if(input[i] < 0){
				result[index++] = input[i];
			}
		}
		for(int j=0; j<input.length; j++){
			if(input[j] >=0){
				result[index++] = input[j];
			}
		}
		return result;
	}
}

class MoveCmp implements Comparator<Integer>{

	@Override
	public int compare(int in) {
		return -in;
	}
}

import java.util.*;
//o(nlogn)   auxiliary space o(n) -- this is stable sort
public class MergerSort
{
	public static void main(String[] args)
	{
		Integer[] a = {2, 6, 3, 5, 1};
		mergeSort(a);
		System.out.println(Arrays.toString(a));
	}

	public static void mergeSort(Comparable [ ] a)
	{
		Comparable[] tmp = new Comparable[a.length];
		mergeSort(a, tmp,  0,  a.length - 1);
	}


	private static void mergeSort(Comparable [ ] a, Comparable [ ] tmp, int left, int right)
	{
		if( left < right )
		{
			int center = (left + right) / 2;
			mergeSort(a, tmp, left, center);
			mergeSort(a, tmp, center + 1, right);
			merge(a, tmp, left, center + 1, right);
		}
	}


	private static void merge(Comparable[ ] a, Comparable[ ] tmp, int left, int right, int rightEnd )
	{
		int leftEnd = right - 1;
		int k = left;
		int num = rightEnd - left + 1;

		while(left <= leftEnd && right <= rightEnd)
			if(a[left].compareTo(a[right]) <= 0)
				tmp[k++] = a[left++];
			else
				tmp[k++] = a[right++];

        while(left <= leftEnd)    // Copy rest of first half
        tmp[k++] = a[left++];

        while(right <= rightEnd)  // Copy rest of right half
        tmp[k++] = a[right++];

        // Copy tmp back
        for(int i = 0; i < num; i++, rightEnd--)
        	a[rightEnd] = tmp[rightEnd];
    }
}

public class Solution {
	public boolean isValid(String s) {
        //left -> push
        //right -> is Empty? pop() -- 2 places to check whether the stack is empty!!!
        //s.end -> Empty? -> yes then return true
		if(s.length() == 0 ||s.length() ==1){
			return false;   
		}  
		Stack<Character> x = new Stack<>();
		for(int i=0; i<s.length(); ++i){
            // == and  '' not ""
            //whenever meet with a left parenthesis we need to push into the stack
			if(s.charAt(i) == '(' || s.charAt(i) == '[' ||s.charAt(i) == '{'){
				x.push(s.charAt(i));
			}else{
                //we need to pop and check
				if(x.isEmpty()){
					return false;
				}
                char top = x.pop();//pop we do not need to peek
                if(s.charAt(i) == ')'){
                	if(top !='('){
                		return false;
                	}
                }
                if(s.charAt(i) == ']'){
                	if(top !='['){
                		return false;
                	}
                }
                if(s.charAt(i) == '}'){
                	if(top !='{'){
                		return false;
                	}
                }
            }
        }
        
        //after all
 //we need to check the stack empty
        return x.isEmpty(); 
        
        
    }
}

这道题运用位运算的异或。异或是相同为0，不同为1。所以对所有数进行异或，得出的那个数就是single number。初始时先让一个数与0异或，然后再对剩下读数挨个进行异或。

这里运用到异或的性质：对于任何数x，都有x^x=0，x^0=x

代码如下：

复制代码
1     public int singleNumber(int[] A) {
	2         int result = 0;
	3         for(int i = 0; i<A.length;i++){
		4             result = result^A[i];
		5         }
		6         return result;
		7     }

		所以对于这个数组来说，因为只有一个数字是single的，所以数组可以表示为 a a b b c c d d e。 那么利用上述规律可以异或结果为 0 0 0 0 e。这样写的代码为：

		1 public static int singleNumber(int[] A) {
			2     for (int i = 1; i < A.length; i++) {
				3         A[i] ^= A[i-1];
				4     }
				5     return A[A.length-1];
				6 }

				boolean	add(E e)
				Adds the specified element to this set if it is not already present.
				if existing -- return false

					public int singleNumber(int[] A) {
						HashSet<Integer> set = new HashSet<Integer>();
						for (int n : A) {
							if (!set.add(n))
								set.remove(n);
						}
						Iterator<Integer> it = set.iterator();
						return it.next();
					}


					PHP Case Sensitivity
					In PHP, all keywords (e.g. if, else, while, echo, etc.), classes, functions, and user-defined functions are NOT case-sensitive.

					In the example below, all three echo statements below are legal (and equal):

					Example
					<!DOCTYPE html>
					<html>
					<body>

					<?php
					ECHO "Hello World!<br>";
					echo "Hello World!<br>";
					EcHo "Hello World!<br>";
					?>

					</body>
					</html>

					PHP is a server scripting language, and a powerful tool for making dynamic and interactive Web pages.

					PHP is a widely-used, free, and efficient alternative to competitors such as Microsofts ASP.

					<!DOCTYPE html>
					<html>
					<body>

					<?php
					echo "My first PHP script!";
					?>

					</body>
					</html>

					PHP is an acronym for "PHP: Hypertext Preprocessor"
					PHP is a widely-used, open source scripting language
					PHP scripts are executed on the server
					PHP is free to download and use

					What is a PHP File?
					PHP files can contain text, HTML, CSS, JavaScript, and PHP code
					PHP code are executed on the server, and the result is returned to the browser as plain HTML
					PHP files have extension ".php"
					What Can PHP Do?
					PHP can generate dynamic page content
					PHP can create, open, read, write, delete, and close files on the server
					PHP can collect form data
					PHP can send and receive cookies
					PHP can add, delete, modify data in your database
					PHP can be used to control user-access
					PHP can encrypt data
					<?php
					$txt = "W3Schools.com";
					echo "I love $txt!";
					?>
					<?php
					$txt = "W3Schools.com";
					echo "I love " . $txt . "!";
					?>

					PHP is a Loosely Typed Language
					In the example above, notice that we did not have to tell PHP which data type the variable is.

					PHP automatically converts the variable to the correct data type, depending on its value.

					In other languages such as C, C++, and Java, the programmer must declare the name and type of the variable before using it.

					PHP Variables Scope
					In PHP, variables can be declared anywhere in the script.

					The scope of a variable is the part of the script where the variable can be referenced/used.

					PHP has three different variable scopes:

					local
					global
					static
					Global and Local Scope
					A variable declared outside a function has a GLOBAL SCOPE and can only be accessed outside a function:

					Example
					<?php
$x = 5; // global scope

function myTest() {
    // using x inside this function will generate an error
	echo "<p>Variable x inside function is: $x</p>";
} 
myTest();

echo "<p>Variable x outside function is: $x</p>";
?>

A variable declared within a function has a LOCAL SCOPE and can only be accessed within that function:

Example
<?php
function myTest() {
    $x = 5; // local scope
    echo "<p>Variable x inside function is: $x</p>";
} 
myTest();

// using x outside the function will generate an error
echo "<p>Variable x outside function is: $x</p>";
?>

PHP The global Keyword
The global keyword is used to access a global variable from within a function.

To do this, use the global keyword before the variables (inside the function):

Example
<?php
$x = 5;
$y = 10;

function myTest() {
	global $x, $y;
	$y = $x + $y;
}

myTest();
echo $y; // outputs 15
?>


PHP The static Keyword
Normally, when a function is completed/executed, all of its variables are deleted. However, sometimes we want a local variable NOT to be deleted. We need it for a further job.

To do this, use the static keyword when you first declare the variable:

Example
<?php
function myTest() {
	static $x = 0;
	echo $x;
	$x++;
}

myTest();
myTest();
myTest();
?>

Variables can store data of different types, and different data types can do different things.

PHP supports the following data types:

String
Integer
Float (floating point numbers - also called double)
Boolean
Array
Object
NULL
Resource

In the following example $x is an integer. The PHP var_dump() function returns the data type and value:

Example
<?php 
$x = 5985;
var_dump($x);
?>

<?php 
$cars = array("Volvo","BMW","Toyota");
var_dump($cars);
?>

In PHP, an object must be explicitly declared.

First we must declare a class of object. For this, we use the class keyword. A class is a structure that can contain properties and methods:

Example
<?php
class Car {
	function Car() {
		$this->model = "VW";
	}
}

// create an object
$herbie = new Car();

// show object properties -- use the arrows here...
echo $herbie->model;
?>

-----------------------------------------------------------------------------

Create an Array in PHP
In PHP, the array() function is used to create an array:

array();
In PHP, there are three types of arrays:

Indexed arrays - Arrays with a numeric index
Associative arrays - Arrays with named keys
Multidimensional arrays - Arrays containing one or more arrays
<?php
$cars = array("Volvo", "BMW", "Toyota");
echo "I like " . $cars[0] . ", " . $cars[1] . " and " . $cars[2] . ".";
?>

<?php
$cars = array("Volvo", "BMW", "Toyota");
echo count($cars);
?>

$age = array("Peter"=>"35", "Ben"=>"37", "Joe"=>"43");
or:

$age['Peter'] = "35";
$age['Ben'] = "37";
$age['Joe'] = "43";
The named keys can then be used in a script:

Example
<?php
$age = array("Peter"=>"35", "Ben"=>"37", "Joe"=>"43");
echo "Peter is " . $age['Peter'] . " years old.";
?>

Loop Through an Associative Array
To loop through and print all the values of an associative array, you could use a foreach loop, like this:

Example
<?php
$age = array("Peter"=>"35", "Ben"=>"37", "Joe"=>"43");

foreach($age as $x => $x_value) {
	echo "Key=" . $x . ", Value=" . $x_value;
	echo "<br>";
}
?>

PHP User Defined Functions
Besides the built-in PHP functions, we can create our own functions.

A function is a block of statements that can be used repeatedly in a program.

A function will not execute immediately when a page loads.

A function will be executed by a call to the function.

A user defined function declaration starts with the word "function":

Syntax -- not case-sensitive
function functionName() {
	code to be executed;
}
Note: A function name can start with a letter or underscore (not a number).

Tip: Give the function a name that reflects what the function does!

<?php
function writeMsg() {
	echo "Hello world!";
}

writeMsg(); // call the function
?>
//arguments we also need to use $$$$$$$$$$$$$$$$$$$$ ($fname)
<?php
function familyName($fname) {
	echo "$fname Refsnes.<br>";
}

familyName("Jani");
familyName("Hege");
familyName("Stale");
familyName("Kai Jim");
familyName("Borge");

<?php
function setHeight($minheight = 50) {
	echo "The height is : $minheight <br>";
}

setHeight(350);
setHeight(); // will use the default value of 50
setHeight(135);
setHeight(80);
?>

<?php
function sum($x, $y) {
	$z = $x + $y;
	return $z;
}

echo "5 + 10 = " . sum(5, 10) . "<br>";
echo "7 + 13 = " . sum(7, 13) . "<br>";
echo "2 + 4 = " . sum(2, 4);
?>
?>


Example #1 list() examples

<?php

$info = array('coffee', 'brown', 'caffeine');

// Listing all the variables
list($drink, $color, $power) = $info;
echo "$drink is $color and $power makes it special.\n";

// Listing some of them
list($drink, , $power) = $info;
echo "$drink has $power.\n";

// Or let's skip to only the third one
list( , , $power) = $info;
echo "I need $power!\n";

// list() doesn't work with strings
list($bar) = "abcde";
var_dump($bar); // NULL
?>
Example #2 An example use of list()

<table>
<tr>
<th>Employee name</th>
<th>Salary</th>
</tr>

<?php
$result = $pdo->query("SELECT id, name, salary FROM employees");
while (list($id, $name, $salary) = $result->fetch(PDO::FETCH_NUM)) {
	echo " <tr>\n" .
	"  <td><a href=\"info.php?id=$id\">$name</a></td>\n" .
	"  <td>$salary</td>\n" .
	" </tr>\n";
}

?>

</table>
Example #3 Using nested list()

<?php

list($a, list($b, $c)) = array(1, array(2, 3));

var_dump($a, $b, $c);

?>
int(1)
int(2)
int(3)
Example #4 Using list() with array indices

<?php

$info = array('coffee', 'brown', 'caffeine');

list($a[0], $a[1], $a[2]) = $info;

var_dump($a);

?>
Gives the following output (note the order of the elements compared in which order they were written in the list() syntax):

array(3) {
	[2]=>
	string(8) "caffeine"
	[1]=>
	string(5) "brown"
	[0]=>
	string(6) "coffee"
}