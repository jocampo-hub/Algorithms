#include <iostream>
#include <algorithm>
using namespace std;
#include <cctype> // for isupper, islower


bool isRadical(string str)
{
    for (char c : str)
    {
        if (isupper(c))
        {
            if (str.find(tolower(c)) != string::npos)
            {
                continue;
            } else {
                return false;
            }
        } else if (islower(c))
        {
            if (str.find(toupper(c)) != string::npos)
            {
                continue;
            } else {
                return false;
            }
        }
    }

    return true;
}

string longestRadical(string str)
{
    if (isRadical(str))
    {
        return str;
    } else
    {
        char badChar;

        for (char c : str)
        {
            if ((isupper(c) && str.find(tolower(c)) == string::npos) ||
                    (islower(c) && str.find(toupper(c)) == string::npos)) {
                badChar = c;
                break;
            }
        }

        int indexOfSplit = str.find(badChar);

        string leftSubString = str.substr(0, indexOfSplit);
        string rightSubString = str.substr(indexOfSplit + 1);

        string leftSplitRadical = longestRadical(leftSubString);
        string rightSplitRadical = longestRadical(rightSubString);

        if (leftSplitRadical.length() <= rightSplitRadical.length())
        {
            return rightSplitRadical;
        } else
            return leftSplitRadical;
    }

// try using aAbBcCdDeEfFz
// should output: The longest radical of your string is: aAbBcCdDeEfF
}

int main() {

    string myString;

    cout << "Please input a string of radicals: " << endl;
    cin >> myString;

    cout << "The longest radical of your string is: " << longestRadical(myString) << endl;

    return 0;
}
