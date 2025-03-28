//// A, B, C (With the following dimensions underneath}
//// {{2, 3}, {3, 4}, {4, 2}
//
//// we must multiply from left to right.
//
//// (AxB) x C => 2x3x4 = 24 + ?
//// (2x4) x C => 24 + 16 = 40
//
//// A x (BxC) => 3x4x2 = 24 + ?
//// A x (3x2) => 24 + 12 = 36

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int matrixChainMultiplication(vector<pair<int, int>> matrices)
{
    int n = matrices.size();

    if (n < 2) return 0; // No multiplication needed for a single matrix

    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Loop over the chain length
    for (int c = 2; c <= n; c++) {
        for (int i = 0; i < n - c + 1; i++) {
            int j = i + c - 1;
            dp[i][j] = numeric_limits<int>::max();

            for (int k = i; k < j; k++) {
                int q = dp[i][k] + dp[k + 1][j] + matrices[i].first * matrices[k].second * matrices[j].second;
                dp[i][j] = min(dp[i][j], q);
            }
        }
    }

    return dp[0][n - 1];
}

int main()
{
    vector<pair<int, int>> matrices = {{2, 3}, {3, 4}, {4, 2}};
    int result = matrixChainMultiplication(matrices);
    cout << "Minimum number of operations: " << result << endl;
    return 0;
}





