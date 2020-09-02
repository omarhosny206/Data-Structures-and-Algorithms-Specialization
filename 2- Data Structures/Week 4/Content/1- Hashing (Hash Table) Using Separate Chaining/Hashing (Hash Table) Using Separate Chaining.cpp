#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Hash
{

    // attributes
private:
    int numberOfBuckets;

    // pointer to the List which carries the Buckets
    list<int> *hashTable;

    // methods
public:
    // default Constructor
    Hash(int Size) : numberOfBuckets(Size)
    {
        hashTable = new list<int>[numberOfBuckets];
    }

    // working of Hash Function, to map values to key
    int hashFunction(int Key)
    {
        return Key % numberOfBuckets;
    }

    // to insert a key into hashTable
    void insertItem(int Key)
    {
        int Value = hashFunction(Key);
        hashTable[Value].push_back(Key);
    }

    // to delete a key from hashTable
    void deleteItem(int Key)
    {

        int Value = hashFunction(Key);

        list<int>::iterator i;

        for (i = hashTable[Value].begin(); i != hashTable[Value].end(); i++)
        {
            if (*i == Key)
                break;
        }

        // if key is found in hashTable, remove it
        if (i != hashTable[Value].end())
            hashTable[Value].erase(i);
    }

    // function to print hashTable
    void printHashTable()
    {

        for (int i = 0; i < numberOfBuckets; i++)
        {
            cout << i;

            for (auto x : hashTable[i])
            {
                cout << " --> " << x;
            }

            cout << endl;
        }
    }
};

int main()
{
    int items[5] = {15, 11, 27, 8, 12};

    Hash hashTable(7);

    for (int i = 0; i < 5; i++)
        hashTable.insertItem(items[i]);

    hashTable.printHashTable();
}
