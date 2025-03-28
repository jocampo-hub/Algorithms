#include <iostream>
#include <vector>
using namespace std;

class BinaryConversions {
private:
    vector<int> binaryNumbers;

public:
    BinaryConversions() : binaryNumbers({}) {}

    void decimalToBinary(int decimalInput) {
        binaryNumbers.clear();

        if (decimalInput == 0) {
            binaryNumbers.push_back(0);
        }

        while (decimalInput > 0) {
            binaryNumbers.push_back(decimalInput % 2);
            decimalInput /= 2;
        }

        // Reverse the result since binary conversion gives digits in reverse order
        reverse(binaryNumbers.begin(), binaryNumbers.end());

        printResult();
    }

    void printResult() {
        cout << "Binary Representation: ";
        for (int num : binaryNumbers) {
            cout << num;
        }
        cout << endl;
    }
};

int main() {
    int decimalInput;
    cout << "Input a number in decimal form to be converted to binary: ";

    BinaryConversions converter;

    while (true) {
        cin >> decimalInput;

        if (cin.fail()) {
            cin.clear();  // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Bad input. Try again!\nInput a number in decimal form: ";
            continue;
        }

        converter.decimalToBinary(decimalInput);
        break;
    }

    return 0;
}
