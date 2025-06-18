#ifndef MASTERMIND_H
# define MASTERMIND_H

#define CODE_LENGTH 4                // Number of digits in the secret code.
#define CODE_SIZE (CODE_LENGTH + 1) // Code length plus the null terminator.
#define BUFFER_SIZE 10             // Size of input buffer.
#define DEFAULT_ATTEMPTS 10       // Default number of attempts.

// Struct that holds the secret code and allowed attempts.
typedef struct s_config {
    char code[CODE_SIZE];
    int  attempts;
} t_config;

// Function prototypes.
void    num_gen(int *rand_nums);
void    check_guess(int secret_code[CODE_LENGTH], int guess[CODE_LENGTH],
                    int *well_placed, int *misplaced);
int     valid_input(char input[CODE_SIZE]);
t_config args(int argc, char *argv[]);
int    get_guess(int guess[CODE_LENGTH], char *buffer, int buffer_size);

#endif
