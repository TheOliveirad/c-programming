# Welcome to My Mastermind
***

## Task
    Implement a simplified version of the classic game Mastermind in C.

    The game uses 9 pieces (0-8) to form a secret code composed of 4 distinct numbers.
    The player has 10 attempts by default to guess the code.
    After each guess, the program reports the number of well-placed pieces and misplaced pieces.
    The program supports command-line parameters to specify a custom secret code (-c [CODE]) and a custom number of attempts (-t [ATTEMPTS]).

## Description
    This project implements Mastermind in C using only a limited set of functions:
    printf, write, read, rand, srand, time, atoi, and strcmp.

    Input Handling: The program reads the player's input one character at a time using read(0, &c, 1) and validates that the guess is exactly 4 digits (each between '0' and '8').

    Game Logic: It compares the guess with the secret code, and provides feedback on well-placed and misplaced digits.

    Command-Line Options:
        -c [CODE] allows the user to specify a custom secret code.
        -t [ATTEMPTS] sets the number of attempts (default is 10).

    Output: The program prints a welcome message, prompts the user for input, and displays feedback after each guess.
    When the code is guessed correctly, it prints "Congratz! You did it!" and terminates.

## Installation

To compile the project, simply use the provided Makefile. Open a terminal in the project directory and run: make


## Usage

Run the program from the command line with optional arguments:

./my_mastermind [-c "CODE"] [-t ATTEMPTS]


    Example 1: Use a custom secret code "0123":

./my_mastermind -c "0123"


Example 2: Use a custom number of attempts (e.g., 15):

./my_mastermind -t 15


Example 3: Combine both:

./my_mastermind -c "0123" -t 15

### The Core Team


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>
