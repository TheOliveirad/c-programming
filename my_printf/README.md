# Welcome to My Printf
***

## Task
Recreate a simplified version of the C standard printf function from scratch.
The challenge is to implement a function that behaves like printf, without using any standard output functions such as printf, fprintf, sprintf, etc.

Only the following functions are allowed:
    write(2)
    malloc, free
    Variadic macros: va_start, va_arg, va_end

## Description
This project implements a custom function:

int my_printf(char *format, ...);

It supports the following format specifiers:

    %c — character
    %s — string
    %d — signed integer
    %u — unsigned integer
    %o — octal
    %x, %X — hexadecimal (uppercase output)
    %p — pointer (memory address in hex with 0x prefix)

All formatting is handled manually using recursion for number conversion and character-by-character output with write().
It safely handles null strings, negative numbers, and edge cases like INT_MIN.
No global or static variables are used. Each function is limited to a maximum of 20 lines, as required by the project constraints.

## Installation
To compile the project, simply run:

make

This will generate the my_printf.o object file.

To clean compiled object files:
make clean

To fully rebuild from scratch:
make re

## Usage
Since my_printf.c does not include a main() function, you must create your own test file to use and verify the implementation.

Step 1: Create a test file called test.c

#include <stdio.h>
int my_printf(char *format, ...);
int main() { my_printf("Hello %s! Score: %d Hex: %x\n", "Alice", 42, 255); my_printf("Char: %c | Unsigned: %u | Octal: %o | Pointer: %p\n", 'A', 3000000000U, 100, main); return 0; }

Step 2: Compile your test file with your object file

gcc -Wall -Wextra -Werror -o test test.c my_printf.o

Step 3: Run the compiled test

./test

Example output:

Hello Alice! Score: 42 Hex: FF
Char: A | Unsigned: 3000000000 | Octal: 144 | Pointer: 0x...

This shows that my_printf correctly handles format specifiers like %s, %d, %x, %u, %c, %o, and %p.

### The Core Team


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>
