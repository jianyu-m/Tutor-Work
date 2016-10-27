Some of you may come across some segmentation faults during finishing your exercise.A **segmentation fault** (aka segfault) is a common conditionthat causes programs to crash. Segfaults are caused by a program trying to **read or write an illegal memory location**.

Here I will shows how to debug a simple program with segmentation fault here.



Suppose I have such a program a.cpp

```c++
#include<iostream>

int main(){
	int a[10];
	for (int i = 0; i < 10000;i++){
		a[i] = i;
	}
	return 0;
}
```



You may compile them and it shows segmentation fault.

```shell
$ g++ a.cpp
$ ./a.out
Segmentation fault (core dumped)
```



According to the definition above, you have accessed an illegal memory location.



1. You could add some printf into your program to find out which part goes wrong, like

```c++
#include<iostream>

using namespace std;
int main(){
  	//Mark 0
  	cout << "run to mark 0\n";
	int a[3];
  	cout << "run to mark 1\n";
  	//Mark 1
	for (int i = 0; i < 10000;i++){
		a[i] = i;
	}
  	//Mark 2
  	cout << "run to mark 2\n";
	return 0;
}
```

Run the program,

```shell
$ g++ a.cpp
$ ./a.out
run to mark A
Segmentation fault (core dumped)
```

From the output, we will know that the problem comes from codes after mark 1 and before mark 2, and then you could go into detail and add some printf into this part. Eventually, you will find the problem.



1. You could also use gdb to debug such problem. 

First, you need to compile the program with debug symbol(add a -g), you could run

```shell
$ g++ a.cpp -g
```

Then, you run the program with gdb,

```shell
$ gdb ./a.out
GNU gdb (Ubuntu 7.7.1-0ubuntu5~14.04.2) 7.7.1
Copyright (C) 2014 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
<http://www.gnu.org/software/gdb/documentation/>.
For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from ./a.out...done.
$ (gdb) run
```

Note:(if you need to pipe an input, append < input_file_name to this command), like

```shell
$ (gdb) run < input.txt
```

The program will run until it comes across a problem, like

```shell
(gdb) run
Starting program: /home/postgrad/16/jyjiang/a.out

Program received signal SIGSEGV, Segmentation fault.
0x00000000004006e2 in main () at a.cpp:6
6                       a[i] = i;
(gdb) 
```

You will know that the problem comes from line 6.

You can now use p to get the value of variables, like

```shell
(gdb) p i
$1 = 456
```

It means that i is 456 now, as the size of array is 10, obviously you are accessing an invalid memory position.



This is a pretty easy example of how to use gdb to debug your program, sometimes it may be a bot more complicated, you may read tutorial from cmu(https://www.cs.cmu.edu/~gilpin/tutorial/) or GNU GDB Project(https://www.gnu.org/software/gdb/) to get more information.
