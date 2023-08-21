#include <iostream>
#include <vector>
#include <list>

using namespace std;

class HashTable {
private:
    static const int TABLE_SIZE = 10; // Size of the hash table

    // Define a structure to hold key-value pairs
    struct KeyValue {
        string key;
        string value;
    };

    // Array of linked lists to represent the hash table
    vector<list<KeyValue>> table;

    // Hash function to map a key to an index
    int hashFunction(const string& key) {
        int hash = 0;
        for (char c : key) {
            hash += c;
        }
        return hash % TABLE_SIZE;
    }

public:
    HashTable() {
        // Initialize the hash table with empty linked lists
        table.resize(TABLE_SIZE);
    }

    // Insert a key-value pair into the hash table
    void insert(const string& key, const string& value) {
        int index = hashFunction(key);
        table[index].push_back({ key, value });
    }

    // Retrieve the value associated with a given key
    string get(const string& key) {
        int index = hashFunction(key);
        for (const auto& kv : table[index]) {
            if (kv.key == key) {
                return kv.value;
            }
        }
        return ""; // Return an empty string if key not found
    }

    // Remove a key-value pair from the hash table
    void remove(const string& key) {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->key == key) {
                table[index].erase(it);
                break;
            }
        }
    }
};

int main() {
    // Create a hash table
    HashTable ht;

    // Insert key-value pairs
    ht.insert("John", "Doe");
    ht.insert("Jane", "Smith");
    ht.insert("Alice", "Johnson");

    // Retrieve values
    cout << "Value for John: " << ht.get("John") << endl;
    cout << "Value for Alice: " << ht.get("Alice") << endl;

    // Remove a key-value pair
    ht.remove("Jane");

    // Try to retrieve the removed value
    cout << "Value for Jane: " << ht.get("Jane") << endl;

    return 0;
}
