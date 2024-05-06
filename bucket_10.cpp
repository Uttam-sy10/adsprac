#include<bits/stdc++.h>
using namespace std;

class SimpleIndexFile {
private:
    unordered_map<string, long> indexMap; // Key-value pairs
    string filename; // Name of the file

public:
    SimpleIndexFile(const string& filename) : filename(filename) {}

    // Add key-value pair to the index
    void add(const string& key, long value) {
        indexMap[key] = value;
    }

    // Get value associated with the key
    long get(const string& key) {
        if (indexMap.find(key) != indexMap.end()) {
            return indexMap[key];
        } else {
            return -1; // Return -1 if key not found
        }
    }

    // Save the index to a file
    void saveToFile() {
        ofstream outFile(filename);
        if (outFile.is_open()) {
            for (const auto& entry : indexMap) {
                outFile << entry.first << " " << entry.second << endl;
            }
            outFile.close();
            cout << "Index saved to file successfully." << endl;
        } else {
            cerr << "Unable to open file: " << filename << endl;
        }
    }

    // Load the index from a file
    void loadFromFile() {
        ifstream inFile(filename);
        if (inFile.is_open()) {
            string key;
            long value;
            while (inFile >> key >> value) {
                indexMap[key] = value;
            }
            inFile.close();
            cout << "Index loaded from file successfully." << endl;
        } else {
            cerr << "Unable to open file: " << filename << endl;
        }
    }
};

int main() {
    SimpleIndexFile index("index.txt");

    // Add some key-value pairs
    index.add("apple", 100);
    index.add("banana", 200);
    index.add("orange", 300);

    // Save the index to a file
    index.saveToFile();

    // Load the index from the file
    index.loadFromFile();

    // Get and print the value associated with a key
    cout << "Value of 'banana': " << index.get("banana") << endl;

    return 0;
}