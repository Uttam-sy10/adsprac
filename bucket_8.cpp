#include<bits/stdc++.h>

using namespace std;


struct KeyValuePair {
    string key;
    int value;
    KeyValuePair(const string& k, int v) : key(k), value(v) {}
};

class HashTable {
private:
    vector<list<KeyValuePair>> table;
    int size;

    
    size_t hash(const string& key) {
        size_t hash = 0;
        for (char c : key) {
            hash = (hash * 31 + c) % table.size();
        }
        return hash;
    }

public:
    HashTable(int tableSize) : size(tableSize) {
        table.resize(size);
    }

    
    void insert(const string& key, int value) {
        size_t index = hash(key);
        for (auto& pair : table[index]) {
            if (pair.key == key) {
                pair.value = value; 
                return;
            }
        }
        table[index].push_back({key, value});
    }

    
    int get(const string& key) {
        size_t index = hash(key);
        for (const auto& pair : table[index]) {
            if (pair.key == key) {
                return pair.value; 
            }
        }
        return -1; 
    }

   
    void remove(const string& key) {
        size_t index = hash(key);
        table[index].remove_if([&](const KeyValuePair& pair) {
            return pair.key == key;
        });
    }
};

int main() {
    HashTable ht(10);

    
    ht.insert("apple", 10);
    ht.insert("banana", 20);
    ht.insert("orange", 30);

    cout << "Value of 'apple': " << ht.get("apple") << endl;
    cout << "Value of 'banana': " << ht.get("banana") << endl;
    cout << "Value of 'orange': " << ht.get("orange") << endl;

    
    ht.remove("banana");

    
    cout << "Value of 'banana' after removal: " << ht.get("banana") << endl;

    return 0;
}
