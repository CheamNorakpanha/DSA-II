#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Hash
{
    // No. of buckets
    int BUCKET;

    // Pointer to an array containing buckets
    list<int> *table;

    public:
        // Constructor
        Hash(int V);

        // inserts a key into hash table
        void insertItem(int x);
        
        // deletes a key from has table
        void deleteItem(int x);

        // has function to map values to key
        int hasFunction(int x)
        {
            return (x % BUCKET);
        }

        // function to display the has table
        void displayHash();
};

Hash::Hash(int b)
{
    this->BUCKET = b;
    table = new list<int>[BUCKET];
}

void Hash::insertItem(int key)
{
    int index = hasFunction(key);
    table[index].push_back(key);
}

void Hash::deleteItem(int key)
{
    // get the hash index of key
    int index = hasFunction(key);

    // find the key in (index)th list
    list <int> :: iterator i;
    for(i = table[index].begin(); i != table[index].end(); i++)
    {
        if(*i == key)
        {
            break;
        }
    }

    // if key is found in has table, remove it
    if (i != table[index].end())
    {
        table[index].erase(i);
    }
}

// function to display hash table
void Hash::displayHash()
{
    for(int i = 0; i < BUCKET; i++)
    {
        cout << i;
        for(auto x : table[i])
        {
            cout << " ---> " << x;
        }
        cout << endl;
    }
}

int main() {
    
    // Create a Hash object with a given number of buckets
    Hash hashTable(10);

    // Insert data into the hash table
    int data[] = {20,11,12,23,5,17,8,9};
    int size = sizeof(data) / sizeof(data[0]);
    for (int i = 0; i < size; i++) {
        hashTable.insertItem(data[i]);
    }
    
    // Display of the hash table after inserting data
    hashTable.displayHash(); // Display the hash table
    cout << endl; 

    // Display of the hash table after deleting 12
    hashTable.deleteItem(12); // Display of the hash table after deleting 12
    hashTable.displayHash(); // Display the hash table
    cout << endl;

    // Let inserting data then to look at collision event
    hashTable.insertItem(13); // Insert 13, 44, 86, 57
    hashTable.insertItem(44);
    hashTable.insertItem(86);
    hashTable.insertItem(57);
    hashTable.displayHash(); // Display the hash table

    return 0;
}