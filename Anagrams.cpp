#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

// brain, sorted = abinr
// brian, sorted = abinr

// O(NlogN).
bool isAnagram1(string str1, string str2) {

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    return str1 == str2;

}


bool isAnagram2(string str1, string str2) {

    // O(1)
    unordered_map<char, int> charCount;

    // O(N)
    for (char c : str1) {
        charCount[c]++;
    }

    // O(N)
    for (char c : str2)
    {
        charCount[c]--;
    }

    // O(N)
    for(auto pair : charCount)
    {
        if (pair.second != 0)
        {
            return false;
        }
    }
    return true;
}

int main() {
    string s1 = "silent";
    string s2 = "entsil";

    cout << boolalpha;
    cout << isAnagram1(s1, s2) << endl;
    cout << isAnagram2(s1, s2) << endl;
}
