#include <iostream>
#include <vector>
using namespace std;

// Recall permutation of a string.
// "ABC" -> ABC ACB BAC BCA CAB CBA 6 possibilities.
// O(N!)
//void permute(string str, int l, int r) {
//    // base case
//    if (l == r) {
//        cout << "Permutation found " << str << endl;
//    }
//    for (int i = l; i <= r; i++)
//    {
//        // swap character at index l with my character at index i
//        swap(str[l], str[i]);
//
//        // Call my function again moving l one step to the right
//        permute(str, l + 1, r);
//
//        // Backtrack and put the characters back to where I found them.
//        swap(str[l], str[i]);
//
//    }
//}
//
//int main() {
//    string str = "ABC";
//
//    permute(str, 0, str.length() - 1);
//
//    return 0;
//}

class NQueens {
private:
    int size;
    vector<vector<string>> solutions;
    vector<string> board;

    // Initialize our board
    void initializeBoard(int n) {
        size = n;
        string row(n, '.');

        for (int i = 0; i < n; i++) {
            board.push_back(row);
        }
    }
    // Function to check if it's safe to place a queen at board[row][column]
    bool isSafe(int row, int col)
    {
        // Check left side of this row
        for (int i = 0; i < col; i++) {
            // If there is a queen in my same row, do not place as it is not safe.
            if(board[row][i] == 'Q') {
                return false;
            }
        }
        // the upper diagonal on left side
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
            {
                return false;
            }
        }

        // lower diagonal on right side
        for (int i = row, j = col; j >= 0 && i < size; i++, j++){
          if (board[i][j] == 'Q') {
              return false;
          }
        }
        return true;

    }

    void solveNQ(int col) {
        // If we place all the queens, so for example, col = 5, we've successfully placed 5 queens.
        if (col >= size) {
            solutions.push_back(board);
        }
        // Consider this column and attempt to place a queen in all rows one by one.
        for (int i = 0; i < size; i++)
        {
            if (isSafe(i, col)) {
                // Place the queen at row = i, col = col
                board[i][col] = 'Q';

                // Recursion to place remaining queens
                solveNQ(col + 1);
                // If we placed a queen in board[i][column] and determined it doesnt for a solution
                // we need to backtrack.
                board[i][col] = '.';

            }
        }
    }
public:
    // Public function we can use to solve the N Queens problem.

    vector<vector<string>> solveNQueens(int n){
        initializeBoard(n);
        solveNQ(0);
        return solutions;
    }
};

int main() {
    NQueens nQ;
    int n = 3;
    vector<vector<string>> solutions= nQ.solveNQueens(n);

    for (auto &solution : solutions){
        for (auto &row : solution) {
            cout << row << endl;
        }


    }
}
