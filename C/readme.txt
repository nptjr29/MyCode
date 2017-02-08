***"printTree.c" program - reader.txt***
Please read before compiling and running the program.

INTRODUCTION
------------
This program takes a start directory or path to a directory as a parameter and outputs a tree-like diagram showing all the subdirectories and files under that start directory.

REQUIREMENTS
------------
This program requires:
  1/ Linux operating system. Ubuntu 14.0 and above is recommended.
  2/ Terminal

COMPILATION
------------
To compile this program, follow these steps:
  1/ Use cd command to navigate to the directory the program file ("printTree.c") is in
  2/ Type gcc -0 printTree printTree.c to compile the program
  3/ It should not give any warning or error message
  4/ After compiling, a file name "printTree" should appear in the same directory as "printTree.c"

EXECUTION
------------
+ To execute or run the program type ./printTree <path to a directory>
+ If <path to a directory> is blank, the program automatically takes the current working directory as a parameter.
+ If <path to a directory> leads to a directory that does not exist, is not a directory, or cannot be opened, the program outputs "Cannot open directory" error message.

