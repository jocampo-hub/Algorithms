#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

// Function to find indices of two numbers that add up to target
vector<int> twoSum(vector<int> nums, int target) {
    unordered_map<int, int> targetMap;

    for (int i = 0; i < nums.size(); i++) { // Fix: Loop through all elements
        int complement = target - nums[i];

        if (targetMap.find(complement) != targetMap.end()) {
            return {targetMap[complement], i}; // Fix: Return indices, not values
        }

        targetMap[nums[i]] = i;
    }

    return {}; // Fix: Return empty vector if no solution
}

int main() {
    string userInput;
    int target;

    cout << "Enter a list of numbers separated by commas: ";
    getline(cin, userInput);

    vector<int> integers;
    stringstream ss(userInput);
    string temp;

    // Parse input string into vector of integers
    while (getline(ss, temp, ',')) {
        integers.push_back(stoi(temp)); // Fix: Convert characters to actual integers
    }

    cout << "Enter a target number: ";
    cin >> target;

    vector<int> result = twoSum(integers, target);

    if (!result.empty()) {
        cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}
