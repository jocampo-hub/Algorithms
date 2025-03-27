#include <iostream>
#include <vector>
using namespace std;

// You have a sorted vector containing omly 0's and 1's.

int bruteCount(vector<int> vec)
{
    int oneCount = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec.at(i) == 1)
            oneCount++;
    }
    return oneCount;
}

// D&C Solution inspired by a binary search
// O(logN)
int countOnes(vector<int> vec, int low, int high) {
// base case

if (high < low)
    return 0;

if (low == high)
    return vec[low];

int mid = low + (high - low) / 2;

// goal is to split our search space in half.
return countOnes(vec, low, mid) + countOnes(vec, mid + 1, high);
}

// This codes upperbound is O(logN) so long as the list is already sorted.
int main() {

    vector<int> vec = {0, 0, 0, 0, 0, 1, 1, 1, 1, 1};
    cout << countOnes(vec, 0, vec.size() - 1);
}
