#include <stdio.h>
#include <stdlib.h>



void my_square(int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if ((x == 0 && y == 0) || (x == width - 1 && y == 0) || // Top-left corner
                (x == 0 && y == height - 1) || (x == width - 1 && y == height - 1)) { // Bottom-right corner
                printf("o");
            } else if (y == 0 || y == height - 1) { // Top or bottom edges (not corners)
                printf("-");
            } else if (x == 0 || x == width - 1) { // Left or right edges (not corners)
                printf("|");
            } else { // Inside the square print empty spaces
                printf(" ");
            }
        }
        printf("\n"); // New line after each row
    }
}

int main(int argumentCount, char **arguments) {
    if (argumentCount != 3) {
        return 0;
    }

    int width = atoi(arguments[1]);
    int height = atoi(arguments[2]);

    my_square(width, height);
    
    return 0;
}
