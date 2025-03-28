#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

// US Coin vector {10, 25, 5, 1}
vector<int> greedyChange(vector<int> coins, int target)
{
     vector<int> result;
     sort(coins.rbegin(), coins.rend()); // in case the coins aren't sorted

     for (int coin : coins)
     {
         while(target >= coin)
         {
             target-= coin;
             result.push_back(coin);
         }
     }
     return result;
}

int main()
{
    vector<int> vec1 = {1, 10, 5, 25};
    int target1 = 93;
    vector<int> result1 = greedyChange(vec1, target1);

    for (int coin : result1)
    {
        cout << coin << " ";
    }
    cout << endl;

    vector<int> vec2 = {1, 4, 5};
    int target2 = 8;
    vector<int> result2 = greedyChange(vec1, target2);
    for (int coin : result2) {
        cout << coin << " ";
    }
    cout << endl;
}
