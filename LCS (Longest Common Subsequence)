#include<iostream>
#include<vector>

using namespace std;

string dynamicLCS(string s1, string s2)
{
    int m = s1.size();
    int n = s2.size();

    vector<vector<int>> dp(m+1, vector<int>(n + 1));
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                // a string is empty so no common character to be found
                dp[i][j] = 0;
            } else if (s1[i - 1] == s2[j - 1]) {
                // we have a match of characters
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // Find the max of the two diagonal.
            }

        }
    }
    string lcs = " ";
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            // same character, this should be included in our lcs.
            lcs = s1[i - 1] + lcs;
            i--;
            j--;
        } else {
            // they are not the same char move in direction of greater value
            if (dp[i - 1][j] > dp[i][j - 1]) {
                i--; // move up in my table
            } else {
                j--; // move left in my table
            }
        }
    }
    return lcs;
}

int main() {
    string s1 = "bradley";
    string s2= "braves";
    string lcs = dynamicLCS(s1, s2);
    cout << "Longest common subsequence of " << s1 << " and " << s2 << " is: " << lcs << endl;
}
