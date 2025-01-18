#include <iostream>
#include <vector>
using namespace std;

void print2Dvector(const vector<vector<int>> &ans, int n) {
    for (size_t sol = 0; sol < ans.size(); sol++) {
        cout << "Solution " << sol + 1 << ":\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << ans[sol][i * n + j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

void addSolution(vector<vector<int>> &ans, vector<vector<int>> &board, int n) {
    vector<int> temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int>> &board, int n) {
    // Check left side of the row
    for (int y = 0; y < col; y++) {
        if (board[row][y] == 1)
            return false;
    }

    // Check upper-left diagonal
    for (int x = row, y = col; x >= 0 && y >= 0; x--, y--) {
        if (board[x][y] == 1)
            return false;
    }

    // Check lower-left diagonal
    for (int x = row, y = col; x < n && y >= 0; x++, y--) {
        if (board[x][y] == 1)
            return false;
    }

    return true;
}

void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n) {
    // Base case: If all queens are placed
    if (col == n) {
        addSolution(ans, board, n);
        return;
    }

    // Try placing a queen in each row of this column
    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 1; // Place queen
            solve(col + 1, ans, board, n);
            board[row][col] = 0; // Backtrack
        }
    }
}

vector<vector<int>> nQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;

    solve(0, ans, board, n);
    return ans;
}

int main() {
    int n;
    cout << "Enter order of matrix: ";
    cin >> n;

    vector<vector<int>> ans = nQueens(n);
    if (ans.empty()) {
        cout << "No solutions found for " << n << " queens.\n";
    } else {
        print2Dvector(ans, n);
    }

    return 0;
}
