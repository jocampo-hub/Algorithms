#include <iostream>
#include <vector>
using namespace std;


class SimpleHashMap {
private:

    int HASH_SIZE = 256; // Some toy value, feel free to change and see what happens.

    vector<vector<pair<string, string>>> table;

public:

    SimpleHashMap() : table(HASH_SIZE) {};

    // Rough, (very rough) hashing algorithm for educational purposes only.

    int hashFunction(string key) {
        int hashValue = 0;

        for (char c: key) {
            hashValue += c;
        }
        return hashValue % HASH_SIZE;
    }

    // Insert key/value pair.
    void insert(string key, string value) {
        int hashValue = hashFunction(key);
        auto & cell = table[hashValue];
        for (auto  & pair : cell) {
            if (pair.first == key) {
                pair.second = value; // Update existing key
                cout << "Key exists, value updated for key: " << key << endl;
                return;
            }
        }
        cell.emplace_back(key, value); // Insertion of a new key/value pair.

    }

    // Retrieve a value given a key.
    string get(string key) {
        int hashValue = hashFunction(key);
        auto & cell = table[hashValue];
        for (auto pair: cell) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        return "Not found";
    }

    // Removal of a key from our map.
    bool remove(string &key) {
        int hashValue = hashFunction(key);
        auto & cell = table[hashValue];

        for (auto it = cell.begin(); it != cell.end(); it++) {
            if (it->first == key)
                cell.erase(it);
            return true;
        }

        return false;
    }


};

int main() {

    SimpleHashMap myMap;
    myMap.insert("TX", "Texas");
    myMap.insert("FL", "Florida");
    myMap.insert("WY", "Wyoming");

    // Update the spelling of Wyoming (Not correct but as an example of updating something)
    // Pluto used to be a planet bruh who knows these days what will change.

    myMap.insert("WY", "Y-oming");


}
