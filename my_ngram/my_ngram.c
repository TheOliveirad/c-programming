#include <stdio.h>

int main(int argc, char *argv[])
{
    int char_count[128] = {0}; // array to store the frequency count of each character (ASCII 0-127).
    
    for ( int i = 1; i < argc; i++) // index starts with 1 to skip program's name.
    {
        for (int j = 0 ; argv[i][j] != '\0'; j++) {
           char_count[(int)argv[i][j]]++; // Increment the counter for the corresponding character's ASCII value.
        }
    }


    for (int i = 0; i < 128 ; i++) { 
        if (char_count[i] > 0) { // Print characters that appeared at least once.
            printf("%c:%d\n", i, char_count[i]);
        }
    }

    return 0;
}
