#include "mastermind.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>  


// Generate a random 4-digit code
void num_gen(int *rand_nums) {
    srand(time(NULL));
    int i = 0;
    while ( i < CODE_LENGTH) {
        int new_num = rand() % 9;
        int duplicate = 0;
        for (int j = 0; j < i; j++) {
            if (rand_nums[j] == new_num) {
                duplicate = 1;
                break;
            }
        }
        if (!duplicate) {  
            rand_nums[i] = new_num;
            i++;
        }
     }
}

// Count digits in the correct position.
void count_well_placed(int secret_code[CODE_LENGTH], int guess[CODE_LENGTH],
                       int *well_placed, int matched[4]) {
    *well_placed = 0;
    for (int i = 0; i < CODE_LENGTH; i++) {
        if (guess[i] == secret_code[i]) {
            (*well_placed)++;
            matched[i] = 1;
        } else {
            matched[i] = 0;
        }
    }
}
// Count digits in the wrong position.
void count_misplaced(int secret_code[CODE_LENGTH], int guess[CODE_LENGTH],
                     int matched[CODE_LENGTH], int *misplaced) {
    *misplaced = 0;
    for (int i = 0; i < CODE_LENGTH; i++) {
        if (guess[i] != secret_code[i]) {
            for (int j = 0; j < CODE_LENGTH; j++) {
                if (!matched[j] && guess[i] == secret_code[j]) {
                    (*misplaced)++;
                    matched[j] = 1;
                    break;
                }
            }
        }
    }
}

// Compare player's guess with secret code.
void check_guess(int secret_code[CODE_LENGTH], int guess[CODE_LENGTH],
                 int *well_placed, int *misplaced) {
    int matched[CODE_LENGTH];
    count_well_placed(secret_code, guess, well_placed, matched);
    count_misplaced(secret_code, guess, matched, misplaced);
}


// Validate player's input
int valid_input( char input[CODE_SIZE]){
    if (input[CODE_LENGTH] != '\0')
        return 0;
    for (int i = 0; i < CODE_LENGTH; i++){
        if (input[i] < '0' || input[i] > '8')
            return 0;
    }
    return 1;
}

// Copy the provided code into config->code and validate it.
void process_code_option(t_config *config, char *arg) {
    int j = 0;
    while (arg[j] && j < CODE_SIZE) {
        config->code[j] = arg[j];
        j++;
    }
    config->code[j] = '\0';
    if (!valid_input(config->code))
        printf("Invalid code.\n");
}

// Set the number of attempts from the argument.
void process_attempts_option(t_config *config, char *arg) {
    config->attempts = atoi(arg);
}


// Handle command-line arguments.
t_config args(int argc, char *argv[]){
    t_config config;
    config.attempts = 10;
    int code[CODE_LENGTH];
    num_gen(code);
    for (int i = 0; i < CODE_LENGTH; i++){
        config.code[i] = code[i] + '0';
    }
    config.code[CODE_LENGTH] = '\0';
    for (int i = 1; i < argc; i++){
        if (strcmp(argv[i], "-c") == 0 && i + 1 < argc) {
            process_code_option(&config, argv[i+1]);
            i++;
        } else if (strcmp(argv[i], "-t") == 0 && i + 1 < argc) {
            process_attempts_option(&config, argv[i+1]);
            i++;
        }
    }
    return config;
}
//Read a valid guess from STDIN and convert it to an integer array.
//Reads one character at a time until a valid 4-digit guess is entered.
int get_guess(int guess[CODE_LENGTH], char *buffer, int buffer_size) {
    int idx, bytes; char ch;
    while (1) {
        idx = 0;
        printf(">");  // Prompt the user.
        while ((bytes = read(0, &ch, 1)) > 0 && ch != '\n') {
            if (idx < buffer_size - 1) buffer[idx] = ch;
            idx++;
        }
        if (bytes == 0 && idx == 0) return 1;
        buffer[idx] = '\0';
        if (valid_input(buffer)) { 
            for (int i = 0; i < CODE_LENGTH; i++) guess[i] = buffer[i] - '0';
            return 0;
        }
        printf("Wrong input!\n");
    }
}

// Main function reads guesses, compares them, and gives feedback.
int main(int argc, char **argv) {
    t_config config = args(argc, argv);  // Get configuration from command line
    int secret_code[CODE_LENGTH];
    for (int i = 0; i < CODE_LENGTH; i++) secret_code[i] = config.code[i] - '0';
    printf("Will you find the secret code?\nPlease enter a valid guess\n");
    int round = 0; char input_buffer[BUFFER_SIZE]; // Set round index and Buffer for user input.
    while (round < config.attempts) {
        int guess[CODE_LENGTH], well_placed = 0, misplaced = 0;
        printf("---\nRound %d\n", round);
        if (get_guess(guess, input_buffer, sizeof(input_buffer))) {  // If EOF detected, exit the program.
            printf("Game exited due to EOF (Ctrl+D).\n");
            return 0;
        }
        check_guess(secret_code, guess, &well_placed, &misplaced);
        if (well_placed == 4) { printf("Congratz! You did it!\n"); return 0;}
        printf("Well placed pieces: %d\nMisplaced pieces: %d\n", well_placed, misplaced);
        round++;
    }
    return 0;
}