#include <stdarg.h>
#include <unistd.h>

// Prints a single character to stdout (handles %c)
int print_char(char c) {
    write(1, &c, 1);
    return 1;
}

// Prints a null-terminated string to stdout (handles %s)
int print_string(char *str) {
    int count = 0;
    if (!str)
        str = "(null)";
    while (*str) {
        count += print_char(*str);
        str++;
    }
    return count;
}

//Prints a signed integer to stdout (handles %d and %i)
//Supports negative numbers and handles the INT_MIN.
int print_number(int num) { 
    int count = 0;
    if (num < 0) {
        count += print_char('-');
        if (num == -2147483648) // most negative nbr in 32-bit systems 
            return count + print_string("2147483648");
        num = -num; // convert to positive for digit processing
    }
    if (num >= 10) //if more than 1 digit
        count += print_number(num / 10); // Use recursion to print digits left to right by stripping right digit each time
    count += print_char((num % 10) + '0'); //gives last digit of a nbr + converts it to its ASCII char
    return count;
}

// Prints an unsigned number in a given base - decimal (10), octal (8), hex (16).
// Handles format specifiers: %u, %x, %X, %o.
// Unsigned ints store twice the positive range of signed ints.
int print_unsigned(unsigned int num, int base, int upper) {
    int count = 0;
    char *digits = upper ? "0123456789ABCDEF" : "0123456789abcdef"; // Choose digit characters - uppercase or lowercase for base > 10
    if (num >= (unsigned int)base)
        count += print_unsigned(num / base, base, upper); // use recursion to get digits from left to right
    count += print_char(digits[num % base]); // Get current digit using remainder and print the corresponding character
    return count;
}

// Prints a memory address in hexadecimal format (handles %p), includes '0x' prefix.
int print_pointer(void *ptr) {
    unsigned long num = (unsigned long)ptr;
    char *digits = "0123456789abcdef";
    char temp[16];
    int i = 0, count = 0;

    count += print_string("0x");
    if (num == 0)
        return count + print_char('0');

    while (num > 0) { // Convert the number to hex digits in reverse
        temp[i++] = digits[num % 16]; //Get the last hex digit and store its character in temp.
        num /= 16; // convert to hex.
    }
    while (i > 0) { //Print digits in the correct order by reversing the temp.
        i--;
        count += print_char(temp[i]);
    }
    return count;
}

// Handles format specifiers and calls the appropriate print function.
int print_format(char type, va_list args) {
    if (type == 'c') {
        return print_char(va_arg(args, int));
    } else if (type == 's') {
        return print_string(va_arg(args, char *));
    } else if (type == 'd') {
        return print_number(va_arg(args, int));
    } else if (type == 'u') {
        return print_unsigned(va_arg(args, unsigned int), 10, 0);
    } else if (type == 'o') {
        return print_unsigned(va_arg(args, unsigned int), 8, 0);
    } else if (type == 'x' || type == 'X') {
        return print_unsigned(va_arg(args, unsigned int), 16, 1);
    } else if (type == 'p') {
        return print_pointer(va_arg(args, void *));
    }

    return 0;
}

// my_printf -  parses format string and prints arguments.
int my_printf(char *format, ...) {
    va_list args;
    va_start(args, format);
    int count = 0;

    while (*format) {
        if (*format == '%') {
            format++;
            count += print_format(*format, args);
        } else {
            count += print_char(*format);
        }
        format++;
    }

    va_end(args);
    return count;
}