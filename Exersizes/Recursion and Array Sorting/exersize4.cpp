#include <iostream>

const int ROWS = 5;
const int COLS = 5;

bool searchMaze(char maze[ROWS][COLS], int x, int y) {
    // Check if (x, y) is out of bounds or is a wall ('X') or already visited ('V')
    if (x < 0 || x >= ROWS || y < 0 || y >= COLS || maze[x][y] == 'X' || maze[x][y] == 'V') {
        return false;
    }

    // If we find the exit, return true
    if (maze[x][y] == 'E') {
        return true;
    }

    // Mark the current position as visited
    maze[x][y] = 'V';

    // Recursively search in all four directions (up, down, left, right)
    if (searchMaze(maze, x - 1, y)) { // Move up
        maze[x][y] = 'P';  // Mark this position as part of the path
        return true;
    }
    if (searchMaze(maze, x + 1, y)) { // Move down
        maze[x][y] = 'P';  // Mark this position as part of the path
        return true;
    }
    if (searchMaze(maze, x, y - 1)) { // Move left
        maze[x][y] = 'P';  // Mark this position as part of the path
        return true;
    }
    if (searchMaze(maze, x, y + 1)) { // Move right
        maze[x][y] = 'P';  // Mark this position as part of the path
        return true;
    }

    // If no path was found, backtrack (unmark the current position)
    maze[x][y] = ' ';

    return false;
}

// Function to print the maze
void printMaze(char maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            std::cout << maze[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    char maze[ROWS][COLS] = {
        {'X','X','X','X','X'},
        {'X',' ',' ',' ','X'},
        {'X',' ','X',' ','X'},
        {'X',' ','X',' ','X'},
        {'X','E','X','X','X'}
    };

    // Start the search from position (1, 1)
    bool pathExists = searchMaze(maze, 1, 1);

    if (pathExists) {
        std::cout << "Path found to the exit! Here's the maze with the path:" << std::endl;
        printMaze(maze);
    } else {
        std::cout << "No path to the exit." << std::endl;
    }

    return 0;
}
