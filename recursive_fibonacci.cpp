#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
using namespace std;

#pragma once
class Timer final
{
public:
    Timer()
            : _start( std::chrono::high_resolution_clock::now() )
    {
    }
    ~Timer() = default ;
    Timer( Timer const& ) = delete ;
    Timer& operator=( Timer const& ) = delete ;
    Timer( Timer const&& ) = delete ;
    Timer& operator=( Timer const&& ) = delete ;
    double get_elapsed() const
    {
        return std::chrono::duration<double,std::micro>(
                std::chrono::high_resolution_clock::now() - _start ).count() ;
    }
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> _start ;
} ;


int Fibonacci(int n)
{
    if (n == 0)
        return 1;
    else if (n == 1)
        return 1;
    else
        return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int iterativeFibonacci(int n) {

    if (n == 0)
    {
        return 1;
    } else if ( n == 1)
    return 1;
    else
    {
        int thePrevious = 0;
        int theCurrent = 1;

        for (size_t i = 0; i < n; i++)
        {
            int theNext = thePrevious + theCurrent;
            thePrevious = theCurrent;
            theCurrent = theNext;
        }
        return theCurrent;
    }

}

bool hasRepeats(vector<int>& arr) {
    vector<int> seenElement;

    for (size_t i = 0; i < arr.size(); i++) {
        // Be mindful of the start of the inner loop
        // Don't compare an element against itself!
        for (size_t j = i + 1; j < arr.size(); j++) {
            if (arr[i] == arr[j]) {
                return true;
            }
        }
    }
    return false;
}

bool hasRepeatsBetter(vector<int>& arr)
{
    // Step 1) Sort the data.
    // Step 2) Compare adjacent elements, if they are equal we have duplicates.

    // C++ default sort is O(nlogn).
    sort(arr.begin(), arr.end()); // in place operation that will modify arr


    // Simple loop over sorted data, compare adjacent elements O(n)
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            return true;
        }
    }
    return false;
}

    int main() {

        vector<double> ONSquaredTime;
        vector<double> ONSquaredResult;

        vector<double> ONTime;
        vector<double> ONResult;
        double time;


        int result;
        Timer timer;

        cout << "Recursive Fibonacci in O(N^2)." << endl;
        for (size_t i = 1; i <= 40; i++) {
            timer.get_elapsed();
            result = Fibonacci(i);
            time = timer.get_elapsed();

            ONSquaredTime.push_back(time);
            ONSquaredResult.push_back(result);

            cout << i << ". Took " << time << " nanoseconds with a result of " << result << "." << endl;


        }


        int newResult;
        std::cout << endl << endl << "Iterative Fibonacci in O(N)." << endl;
        for (size_t i = 1; i <= 40; i++) {
            timer.get_elapsed();
            newResult = iterativeFibonacci(i);
            time = timer.get_elapsed();

            ONTime.push_back(time);
            ONResult.push_back(newResult);

            cout << i << ". Took " << time << " nanoseconds with a result of " << newResult << "." << endl;
        }


        cout << endl << "O(N^2) Times: " << endl;

        for (size_t i = 0; i < ONSquaredTime.size(); i++)
            cout << ONSquaredTime.at(i) << endl;

        cout << endl << endl << "O(N^2) Results: " << endl;
        for (size_t i = 0; i < ONSquaredResult.size(); i++) {
            cout << ONSquaredResult.at(i) << endl;
        }

        cout << endl << endl << "O(N) Times: " << endl;

        for (size_t i = 0; i < ONSquaredTime.size(); i++)
            cout << ONTime.at(i) << endl;

        cout << endl << endl << "O(N) Results: " << endl;
        for (size_t i = 0; i < ONResult.size(); i++) {
            cout << ONResult.at(i) << endl;
        }

        cout <<  "Repeat Results for iterations of checking a vector that is ";
        cout << "being updated by an icrement of one each time until it reaches 100. " << endl;


            vector<int> repeatVector;
        vector<double> timeVector1;
        vector<double> timeVector2;
            for (int i = 0; i < 100; i++) {
                repeatVector.push_back(i);

                cout <<  boolalpha; // output true or false rather than 0 or 1.
                Timer newTimer;
                auto start1 = newTimer.get_elapsed();
                cout << hasRepeats(repeatVector) << endl;
                auto stop1 = newTimer.get_elapsed();

                timeVector1.push_back(stop1);




                Timer newerTimer;
                auto start2 = newerTimer.get_elapsed();
                hasRepeatsBetter(repeatVector);
                auto stop2 = newerTimer.get_elapsed();

                timeVector2.push_back(stop2);
            }

            cout << endl << "Times for slower repeat checker: " << endl;
            for (size_t i = 0; i < timeVector1.size(); i++)
        {
                cout << i << ". " << timeVector1.at(i) << endl;
        }

        cout << "Times for faster repeat checker: " << endl;
        for (size_t i = 0; i < timeVector1.size(); i++)
        {
            cout << i << ". " << timeVector2.at(i) << endl;
        }

        cout << "O(NlogN) for 1 - 100." << endl;
        for (int N = 1; N <= 100; ++N) {
            double result = N * log(N);
            std::cout  << result << std::endl;
        }
        return 0;
        }
