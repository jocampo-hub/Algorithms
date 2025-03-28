#include <iostream>
using namespace std;

class binarySearch {
public:
    int BinarySearch(int arr[], int begin, int end, int data)
   {
        int mid;
        if (begin <= end)
            mid = (begin + end) / 2;

        if (arr[mid] == data)
            return mid + 1;

        if (arr[mid] < data)
            return BinarySearch(arr, mid + 1, end, data);
        else
            return BinarySearch(arr, begin, mid - 1, data);

        return -1;
    }

};

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    binarySearch bs;

    int n = sizeof(arr) / sizeof(arr[0]);
    int data = 9;
    int res = bs.BinarySearch(arr, 0, n - 1, data);

    if (res == -1)
        cout << "Element not found.";
    else
    cout << "Element found at index: " << res;
}
