#include<iostream>
using namespace std;

void printTriangle(int someN)
{
    cout << "The pascal triangle up to row " << someN << " is..." << endl;
    int arr[someN][someN];

    for (int row = 0; row < someN; row++)
    {
        for (int i = 0; i <= row; i++)
        {
            if (row == i || i == 0)
                arr[row][i] = 1;
            else
                arr[row][i] = arr[row - 1][i - 1] + arr[row - 1][i];

            cout << arr[row][i] << " ";
        }
        cout << endl;
    }
}

int main() {

    cout << "Please input a value n: ";
    int n;
    cin >> n;
    printTriangle(n);

    return 0;
}

