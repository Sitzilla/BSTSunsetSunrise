# BSTSunsetSunrise
Homework assignment from Programming Foundations II. Problem found at:
http://csce.uark.edu/~lbg002/csce2014/homework/homework-4-bst-sunrisesunset/

# Problem Statement
Binary search trees are excellent data structures for simple databases, since they can be searched efficiently. In this assignment, you will write a simple database using a binary search tree to store information about the sunrise and sunset times of each day in the year 2015. You will be given a file of all the sunrise and sunset times, and your program should allow the user to search for days based on the time of the sunrise or sunset.

Your program will load in sunrise and sunset times from the file provided and store them in a binary search tree. You should create a class for storing each day (i.e. a Day class), and you may store them in the BST by treating either the sunrise or the sunset time as the key value. Next, your program should enter a while loop that processes commands from the user. 

Must implement the following commands:

<table>
<tr>
<th>Command</th>
<th>Description</th>
</tr>
<tr>
<td><code>sunrise before [time]</code></td>
<td>Prints all information in the BST for dates with sunrise before [time].</td>
</tr>
<tr>
<td><code>sunrise after [time]</code></td>
<td>Prints all information in the BST for dates with sunrise after [time].</td>
</tr>
<tr>
<td><code>sunrise between [start_time] [end_time]</code></td>
<td>Prints all information in the BST for dates with sunrise between [start_time] and [end_time].</td>
</tr>
<tr>
<td><code>sunset before [time]</code></td>
<td>Prints all information in the BST for dates with sunset before [time].</td>
</tr>
<tr>
<td><code>sunset after [time]</code></td>
<td>Prints all information in the BST for dates with sunset after [time].</td>
</tr>
<tr>
<td><code>sunset between [start_time] [end_time]</code></td>
<td>Prints all information in the BST for dates with sunset between [start_time] and [end_time].</td>
</tr>
<tr>
<td><code>all</code></td>
<td>Prints all information in the BST for all dates.</td>
</tr>
</table>

# Design
First, you must design a way to store each day. Probably the best way is to create a Day class with properties year, month, date, sunrise, and sunset and a public print method. You can modify struct Node so that the value is a Day * instead of an integer. Alternatively, you may add year, month, date, sunrise, and sunset to Node directly, but that may make your work harder, especially if you decide to extend your program for both sunrise and sunset.

Second, you must design your binary tree. You can start with the binary search tree provided on the course website: Tree.h and Tree.cpp. You will need to modify the tree so that it works with whatever you decided to do to store day information. Take special care of what your tree does when duplicate “key” values are inserted; if two days have the exact same sunrise time, for example, your program should be able to print them both out correctly if they are in the user’s provided range.

Finally, you must write your main program. You may also begin with this main file: Homework4.cpp. The provided main file loads in the data, but does not insert it into a tree for you. Also download the data file: Sunrise-sunset.txt.

Your program should basically be a while loop that continues until the user enters a “quit” command. Inside the while loop, you will do the following:

- Get the command. This will be either “before”, “after”, “between”, or “all”.
- Get parameters for the command. The before and after commands have only one int parameter, the between command has two int parameters, and the all command has no parameters.
- Output the result.
