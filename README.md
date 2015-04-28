### Programming Assignment #5
### James Washington
### April 27,2015

### Design

The objective is to read a set of quarterback stats from a text file, and storing a subset of the data into binary search trees.

### Implementation
First, I wrote all the methods that I would need on a flowchart, which made it easier to figure out what functions I would need, and how information would be passed in and out of the application.

#### 1: Open, Read, and Select data fields from BST.txt TODO:
Data fields:

* Player (string)
* Attention (double)
* Yards (double)
* Rating (double)

#### 2: Create QB Class TODO:
Take the data returned from the text file and apply it towards a Quarterback class with attributes to match the aforementioned subset of data.

#### 3: Create QB Rating Methods TODO:
Compare quarterbacks based on one attribute, called by Search(), Insert(), and Delete().

We have two options in creating methods:

1. Make 3 different Boolean methods that each does one thing:
```
LessThan()
GreaterThan()
EqualTo()
```

2. Make a single Compare() method that encapsulate the following functionality:
```
// if 1n < 2n, return -1
// if 1n > 2n, return 0
// if 1n = 2n, return 1
```

I chose to implement several smaller functions that each do one task (properly).  Although it's just swapping complexity, it still makes finding bugs easier and reduces friction within the application, which is what I'm trying to do here.



### Testing TODO:
When I first tested my program, the console output this:

```
Insert 7 ok
( 7 )
Insert 9 ok
( 7 ( 9 ))
Insert 3 ok
(( 3 ) 7 ( 9 ))
Insert 8 ok
(( 3 ) 7 (( 8 ) 9 ))
Insert 0 ok
((( 0 ) 3 ) 7 (( 8 ) 9 ))
Insert 2 ok
((( 0 ( 2 )) 3 ) 7 (( 8 ) 9 ))
Insert 4 ok
((( 0 ( 2 )) 3 ( 4 )) 7 (( 8 ) 9 ))
Insert 8 ok
((( 0 ( 2 )) 3 ( 4 )) 7 (( 8 ( 8 )) 9 ))
Insert 3 ok
((( 0 ( 2 )) 3 (( 3 ) 4 )) 7 (( 8 ( 8 )) 9 ))
Insert 9 ok
((( 0 ( 2 )) 3 (( 3 ) 4 )) 7 (( 8 ( 8 )) 9 ( 9 )))
Search 0 found
Search 5 not found
Search 2 found
Search 2 found
Search 7 found
Search 3 found
Search 7 found
Search 9 found
Search 0 found
Search 2 found
Delete 3 ok
((( 0 ( 2 )) 3 ( 4 )) 7 (( 8 ( 8 )) 9 ( 9 )))
Delete 9 ok
((( 0 ( 2 )) 3 ( 4 )) 7 (( 8 ( 8 )) 9 ))
Delete 9 ok
((( 0 ( 2 )) 3 ( 4 )) 7 ( 8 ( 8 )))
Delete 7 ok
((( 0 ( 2 )) 3 ( 4 )) 8 ( 8 ))
Delete 0 ok
((( 2 ) 3 ( 4 )) 8 ( 8 ))
Delete 3 ok
((( 2 ) 4 ) 8 ( 8 ))
Delete 9 failed
((( 2 ) 4 ) 8 ( 8 ))
Delete 8 ok
((( 2 ) 4 ) 8 )
Delete 6 failed
((( 2 ) 4 ) 8 )
Delete 5 failed
((( 2 ) 4 ) 8 )
```

### Stuff I Learned
1. "Keeping your functions short and simple makes it easier for other people to read and modify your code."  -[Google C++ Style Guide](https://google-styleguide.googlecode.com/svn/trunk/cppguide.html#Write_Short_Functions).

2. "No matter what language you work in, programming in a functional style provides benefits. You should do it whenever it is convenient, and you should think hard about the decision when it isn't convenient." -John Carmack, "[In Depth Functional Programming in C](http://gamasutra.com/view/news/169296/Indepth_Functional_programming_in_C.php)".

### Summary

> TODO: Write summary
