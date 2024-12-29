#include <stdio.h>

// Define the size of the grid
#define ROWS 5
#define COLS 5

void drawGrid(int grid[ROWS][COLS]) {
    // Print the top border of the grid
    for (int i = 0; i < COLS; i++) {
        printf("+-----");
    }
    printf("+\n");

    // Print each row of the grid
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("| %-3d ", grid[i][j]);  // Print each cell value (formatted with padding)
        }
        printf("|\n");

        // Print the row border
        for (int j = 0; j < COLS; j++) {
            printf("+-----");
        }
        printf("+\n");
    }
}

int main() {
    // Declare and initialize a 2D array to represent the grid
    int grid[ROWS][COLS] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    // Call the function to draw and display the grid with data
    drawGrid(grid);

    return 0;
}

