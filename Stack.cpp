#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Stack {
private:

    vector<T> elements;


public:

   void push(const T& element) {

        elements.push_back(element);

    }

    T pop()
   {
        if (elements.empty()) {
            throw out_of_range("Stack is empty");
        }
        T top = elements.back();
        elements.pop_back();
        return top;
   }
    T peek() {
        if (elements.empty()) {
            throw out_of_range("Stack is empty");
        }
        return elements.back();
    }
    bool isEmpty() {
        return elements.empty();
    }

    int getSize() {
        return elements.size();
    }
};

int main()
{
    Stack<int> intStack;
    intStack.push(10);
    intStack.push(110);
    intStack.push(100);
    cout << "Top element currently is: " << intStack.peek() << endl;
    intStack.pop();
    cout << "Top element currently is: " << intStack.peek() << endl;

}

