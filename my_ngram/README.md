# Welcome to My Ngram
***

## Task
The goal of this project was to create a program that counts how many times each character appears in one or more input strings.
The challenge was to process multiple input strings and print the character counts in alphanumeric order, while following specific coding and compilation rules.

## Description
To solve the problem, I wrote a C program that:
    - Loops through the command-line arguments.
    - Counts occurrences of each character using an array indexed by the ASCII value of each character.
    - Prints the result in alphanumeric order, showing each character and how many times it appeared.
I also made sure to follow all the project requirements, such as using only a few basic functions and writing a Makefile to handle compilation.

## Installation
To get the program up and running, you just need to use the Makefile provided in the project directory, following these steps:

Compile the program by running --> make
If you want to clean up the object files and executables, use --> make clean
To rebuild everything from scratch (clean + compile) --> make re


## Usage
After compiling, the program can be run by passing one or more strings as arguments. For example:

./my_ngram "hello" "world" 

output:
d:1
e:1
h:1
l:3
o:2
r:1
w:1

### The Core Team


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>
