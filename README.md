# C++ Sudoku Solver & Player

This project is a C++ console application for solving Sudoku puzzles and interactively playing them. It provides a menu-driven interface where users can solve randomly selected puzzles, manually enter values, and view automated solutions.

## Features

- **Random Puzzle Selection:** Each run begins with a randomly selected Sudoku board from several pre-defined puzzles.
- **Interactive Play:** Users can input their values into the board and attempt to solve the puzzle manually.
- **Automated Solver:** The program can automatically solve the current puzzle and display the solution.
- **Validation:** User moves and initial grids are validated for Sudoku rules (no duplicates in rows, columns, or boxes).
- **Console Visualization:** Boards are printed in a clear, readable format mimicking a real Sudoku grid.

## How It Works

Upon running the program, you are presented with a randomly chosen puzzle. The menu allows you to:
1. **Solve Sudoku Puzzle:** Enter your values for empty cells until the puzzle is solved.
2. **See Solution:** View the solution found automatically by the program.
3. **Exit:** Quit the application.

All input is handled via the console, and the board is displayed after each move. The program ensures all moves are valid according to Sudoku rules.

## Usage

### Compile

Make sure you have a C++ compiler (e.g., g++, clang++) installed.

```bash
g++ -o sudoku_solver sudoku_solver.cpp
```

### Run

```bash
./sudoku_solver
```

### Menu Options

- **1. Solve Sudoku Puzzle**  
  Enter the row, column, and value for each move. The program checks for invalid moves and updates the board after each input. Continue until the puzzle is solved.

- **2. See Solution**  
  The program will automatically solve the puzzle (if valid) and print the completed board.

- **3. Exit**  
  Quits the application.

## Code Structure

- `main()`: Handles menu, user input, and main loop.
- `grid_selection()`: Initializes the grid with a random puzzle.
- `print()`: Displays the Sudoku board.
- `valid_move()`: Checks if a move is allowed.
- `solution()`: Recursively solves the puzzle using backtracking.
- `valid_grid()`: Checks for a valid initial grid.
- `win()`: Checks if the puzzle is completely filled and solved.

## Example

```
=============SUDOKU SOLVER================
---------------Menu-----------------
1. Solve Sudoku Puzzle
2. See Solution
3. Exit
```

Choose an option, and follow the prompts to play or solve the puzzle.

