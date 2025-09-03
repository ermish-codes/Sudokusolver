#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Functions
void print(int grid[9][9]);
int valid_move(int grid[9][9], int row, int col, int val);
int solution(int grid[9][9], int row, int col);
int valid_grid(int grid[9][9]);
void grid_selection(int grid[9][9]);
bool win(int grid[9][9]);

int main()
{
    int choice;

    int grid[9][9] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0}};

    grid_selection(grid);
    int r, c, val;
    cout << "=============SUDOKU SOLVER================" << endl;
    do
    {
        cout << "---------------Menu-----------------" << endl;
        cout << "1. Solve Sudoku Puzzle" << endl;
        cout << "2. See Solution" << endl;
        cout << "3. Exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\n---------------Original Board--------------------\n";
            print(grid);
            do
            {
                do
                {
                    cout << "Enter the row number (1-9): ";
                    cin >> r;
                    cout << "Enter the column number(1-9): ";
                    cin >> c;
                    cout << "Enter the value you want to enter(1-9): ";
                    cin >> val;

                } while (!valid_move(grid, r - 1, c - 1, val));
                grid[r - 1][c - 1] = val;
                print(grid);
            } while (!win(grid));
            cout << "Congrats! you have solved grid" << endl;
            break;
        case 2:
            cout << "\n---------------Original Board--------------------\n";
            print(grid);
            if (valid_grid(grid))
            {
                if (solution(grid, 0, 0))
                {
                    cout << "This Sudoku Board is solved!!" << endl;
                    print(grid);
                }
            }
            else
                cout << "Initial grid is invalid (duplicate numbers)!" << endl;

            break;
        case 3:
            cout << "Exiting the program...." << endl;
            break;
        default:
            cout << "Enter the correct choice" << endl;
            break;
        }
    } while (choice != 3);
    return 0;
}
int solution(int grid[9][9], int row, int col)
{

    if (col == 9)
    {
        if (row == 8)
        {
            return 1; // puzzle solved
        }
        row++;
        col = 0;
    }
    if (grid[row][col] > 0)
    {
        return solution(grid, row, col + 1);
    }

    for (int i = 1; i <= 9; i++)
    {
        if (valid_move(grid, row, col, i))
        {
            grid[row][col] = i;
            if (solution(grid, row, col + 1))
            {
                return 1;
            }
            grid[row][col] = 0;
        }
    }

    return 0;
}

int valid_move(int grid[9][9], int row, int col, int val)
{
    // checking repetition in row
    for (int i = 0; i < 9; i++)
    {
        if (grid[row][i] == val)
        {
            return 0;
        }
    }

    // checking repetition in col
    for (int i = 0; i < 9; i++)
    {
        if (grid[i][col] == val)
        {
            return 0;
        }
    }

    int r, c;
    if (row == 0 || row == 1 || row == 2)
    {
        r = 0;
    }
    if (row == 3 || row == 4 || row == 5)
    {
        r = 3;
    }
    if (row == 6 || row == 7 || row == 8)
    {
        r = 6;
    }

    if (col == 0 || col == 1 || col == 2)
    {
        c = 0;
    }
    if (col == 3 || col == 4 || col == 5)
    {
        c = 3;
    }
    if (col == 6 || col == 7 || col == 8)
    {
        c = 6;
    }
    // checking repetition in box
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[r + i][c + j] == val)
            {
                return 0;
            }
        }
    }

    return 1;
}

void print(int grid[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        if (i % 3 == 0)
        {
            cout << "+-------+-------+-------+" << endl;
        }
        for (int j = 0; j < 9; j++)
        {
            if (j % 3 == 0)
            {
                cout << "| ";
            }
            if (grid[i][j] == 0)
            {
                cout << "  ";
            }
            else
                cout << grid[i][j] << " ";
        }
        cout << "|" << endl;
    }

    cout << "+-------+-------+-------+" << endl;
}

int valid_grid(int grid[9][9])
{
    int val;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            val = grid[i][j];
            if (val != 0)
            {
                grid[i][j] = 0; // temporarily clear the cell
                if (!valid_move(grid, i, j, val))
                {
                    grid[i][j] = val; // restore before returning
                    return 0;         // invalid grid
                }
                grid[i][j] = val; // restore
            }
        }
    }
    return 1;
}

void grid_selection(int grid[9][9])
{
    int choice;
    srand(time(0));
    choice = rand() % 10 + 1;

    switch (choice)
    {
    case 1:
    {
        int temp[9][9] = {
            {0, 0, 0, 0, 0, 0, 2, 0, 0},
            {0, 8, 0, 0, 0, 7, 0, 9, 0},
            {6, 0, 2, 0, 0, 0, 5, 0, 0},
            {0, 7, 0, 0, 6, 0, 0, 0, 0},
            {0, 0, 0, 9, 0, 1, 0, 0, 0},
            {0, 0, 0, 0, 2, 0, 0, 4, 0},
            {0, 0, 5, 0, 0, 0, 6, 0, 3},
            {0, 9, 0, 4, 0, 0, 0, 7, 0},
            {0, 0, 6, 0, 0, 0, 0, 0, 0}};
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                grid[i][j] = temp[i][j];
            }
        }
        break;
    }
    case 2:
    {
        int temp[9][9] = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 3, 0, 8, 5},
            {0, 0, 1, 0, 2, 0, 0, 0, 0},
            {0, 0, 0, 5, 0, 7, 0, 0, 0},
            {0, 0, 4, 0, 0, 0, 1, 0, 0},
            {0, 9, 0, 0, 0, 0, 0, 0, 0},
            {5, 0, 0, 0, 0, 0, 0, 7, 3},
            {0, 0, 2, 0, 1, 0, 0, 0, 0},
            {0, 0, 0, 0, 4, 0, 0, 0, 9}};
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                grid[i][j] = temp[i][j];
            }
        }
        break;
    }
    case 3:
    {
        int temp[9][9] = {
            {0, 0, 0, 0, 0, 0, 9, 0, 7},
            {0, 0, 0, 4, 2, 0, 1, 8, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 2, 0, 0, 0, 0, 0},
            {0, 8, 0, 0, 0, 0, 0, 4, 0},
            {0, 0, 0, 0, 0, 3, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 9, 2, 0, 3, 6, 0, 0, 0},
            {8, 0, 3, 0, 0, 0, 0, 0, 0}};
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                grid[i][j] = temp[i][j];
            }
        }
        break;
    }
    case 4:
    {
        int temp[9][9] = {{0, 0, 0, 6, 0, 0, 4, 0, 0},
                          {7, 0, 0, 0, 0, 3, 6, 0, 0},
                          {0, 0, 0, 0, 9, 1, 0, 8, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 5, 0, 1, 8, 0, 0, 0, 3},
                          {0, 0, 0, 3, 0, 6, 0, 4, 5},
                          {0, 4, 0, 2, 0, 0, 0, 6, 0},
                          {9, 0, 3, 0, 0, 0, 0, 0, 0},
                          {0, 2, 0, 0, 0, 0, 1, 0, 0}};
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                grid[i][j] = temp[i][j];
            }
        }
        break;
    }
    case 5:
    {
        int temp[9][9] = {
            {2, 0, 0, 3, 0, 0, 0, 0, 0},
            {8, 0, 4, 0, 6, 2, 0, 0, 3},
            {0, 1, 3, 8, 0, 0, 2, 0, 0},
            {0, 0, 0, 0, 2, 0, 3, 9, 0},
            {5, 0, 7, 0, 0, 0, 6, 0, 1},
            {0, 3, 2, 0, 1, 0, 0, 0, 0},
            {0, 0, 1, 0, 0, 9, 7, 8, 0},
            {7, 0, 0, 6, 8, 0, 5, 0, 2},
            {0, 0, 0, 0, 0, 5, 0, 0, 9}};
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                grid[i][j] = temp[i][j];
            }
        }
        break;
    }
    case 6:
    {
        int temp[9][9] = {
            {0, 0, 0, 0, 0, 0, 0, 1, 2},
            {0, 0, 0, 0, 0, 7, 0, 0, 0},
            {0, 0, 1, 0, 9, 0, 5, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 5, 3, 8, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 6, 0, 1, 0, 7, 0, 0},
            {0, 0, 0, 2, 0, 0, 0, 0, 0},
            {8, 7, 0, 0, 0, 0, 0, 0, 0}};
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                grid[i][j] = temp[i][j];
            }
        }
        break;
    }
    case 7:
    {
        int temp[9][9] = {
            {0, 0, 0, 0, 0, 0, 2, 0, 0},
            {0, 8, 0, 0, 0, 7, 0, 9, 0},
            {6, 0, 2, 0, 0, 0, 5, 0, 0},
            {0, 7, 0, 0, 6, 0, 0, 0, 0},
            {0, 0, 0, 9, 0, 1, 0, 0, 0},
            {0, 0, 0, 0, 2, 0, 0, 4, 0},
            {0, 0, 5, 0, 0, 0, 6, 0, 3},
            {0, 9, 0, 4, 0, 0, 0, 7, 0},
            {0, 0, 6, 0, 0, 0, 0, 0, 0}};
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                grid[i][j] = temp[i][j];
            }
        }
        break;
    }
    case 8:
    {
        int temp[9][9] = {{0, 2, 0, 6, 0, 8, 0, 0, 0},
                          {5, 8, 0, 0, 0, 9, 7, 0, 0},
                          {0, 0, 0, 0, 4, 0, 0, 0, 0},
                          {3, 7, 0, 0, 0, 0, 5, 0, 0},
                          {6, 0, 0, 0, 0, 0, 0, 0, 4},
                          {0, 0, 8, 0, 0, 0, 0, 1, 3},
                          {0, 0, 0, 0, 2, 0, 0, 0, 0},
                          {0, 0, 9, 8, 0, 0, 0, 3, 6},
                          {0, 0, 0, 3, 0, 6, 0, 9, 0}};
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                grid[i][j] = temp[i][j];
            }
        }
        break;
    }
    case 9:
    {
        int temp[9][9] = {{0, 0, 0, 2, 6, 0, 7, 0, 1},
                          {6, 8, 0, 0, 7, 0, 0, 9, 0},
                          {1, 9, 0, 0, 0, 4, 5, 0, 0},
                          {8, 2, 0, 1, 0, 0, 0, 4, 0},
                          {0, 0, 4, 6, 0, 2, 9, 0, 0},
                          {0, 5, 0, 0, 0, 3, 0, 2, 8},
                          {0, 0, 9, 3, 0, 0, 0, 7, 4},
                          {0, 4, 0, 0, 5, 0, 0, 3, 6},
                          {7, 0, 3, 0, 1, 8, 0, 0, 0}};
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                grid[i][j] = temp[i][j];
            }
        }
        break;
    }
    case 10:
    {
        int temp[9][9] = {
            {3, 0, 0, 0, 2, 0, 0, 7, 0},
            {9, 0, 0, 5, 0, 0, 0, 1, 4},
            {0, 1, 6, 3, 7, 0, 0, 0, 8},
            {2, 0, 0, 8, 0, 0, 0, 0, 1},
            {5, 0, 0, 0, 4, 1, 8, 0, 0},
            {0, 8, 9, 0, 0, 0, 0, 5, 0},
            {0, 0, 5, 0, 1, 0, 2, 8, 0},
            {0, 4, 0, 0, 0, 6, 0, 9, 3},
            {7, 3, 1, 0, 8, 2, 0, 0, 0}};
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                grid[i][j] = temp[i][j];
            }
        }
        break;
    }
    default:
        break;
    }
}

bool win(int grid[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (grid[i][j] == 0)
            {
                return false;
            }
        }
    }
    return true;
}