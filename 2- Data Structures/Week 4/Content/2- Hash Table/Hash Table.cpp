#include <iostream>
const int HashTableSize = 200;
using namespace std;

struct LinkedHash
{
    int Value, Key;
    LinkedHash *Next;
    LinkedHash *p;

    LinkedHash(int Key, int Value)
    {
        this->Key = Key;
        this->Value = Value;
        this->Next = NULL;
    }
};

class HashMapTable
{
public:
    LinkedHash **HashTable;

    HashMapTable() // default constructor
    {
        HashTable = new LinkedHash *[HashTableSize];

        for (int i = 0; i < HashTableSize; i++)
            HashTable[i] = NULL;
    }

    int HashFunction(int Key)
    {
        return Key % HashTableSize;
    }

    void Insert(int Key, int Value)
    {
        int hashTableValue = HashFunction(Key);

        LinkedHash *previousLinkedHash = NULL;
        LinkedHash *entryLinkedHash = HashTable[hashTableValue];

        while (entryLinkedHash != NULL)
        {
            previousLinkedHash = entryLinkedHash;
            entryLinkedHash = entryLinkedHash->Next;
        }

        if (entryLinkedHash == NULL)
        {
            entryLinkedHash = new LinkedHash(Key, Value);

            if (previousLinkedHash == NULL)
            {
                HashTable[hashTableValue] = entryLinkedHash;
            }

            else
            {
                previousLinkedHash->Next = entryLinkedHash;
            }
        }

        else
        {
            entryLinkedHash->Value = Value;
        }
    }

    void Remove(int Key)
    {
        int hashTableValue = HashFunction(Key);

        LinkedHash *entryLinkedHash = HashTable[hashTableValue];
        LinkedHash *previousLinkedHash = NULL;

        if (entryLinkedHash == NULL || entryLinkedHash->Key != Key)
        {
            cout << "No Element found at key " << Key << endl;
            return;
        }

        while (entryLinkedHash->Next != NULL)
        {
            previousLinkedHash = entryLinkedHash;
            entryLinkedHash = entryLinkedHash->Next;
        }

        if (previousLinkedHash != NULL)
        {
            previousLinkedHash->Next = entryLinkedHash->Next;
        }

        delete entryLinkedHash;
        cout << "Element Deleted" << endl;
    }

    void SearchKey(int Key)
    {
        int hashTableValue = HashFunction(Key);
        bool Flag = false;

        LinkedHash *entryLinkedHash = HashTable[hashTableValue];

        if (entryLinkedHash != NULL)
        {
            while (entryLinkedHash != NULL)
            {
                if (entryLinkedHash->Key == Key)
                {
                    Flag = true;
                }
                if (Flag)
                {
                    cout << "Element found at key " << Key << ": ";
                    cout << entryLinkedHash->Value << endl;
                }
                entryLinkedHash = entryLinkedHash->Next;
            }
        }

        if (!Flag)
            cout << "No Element found at key " << Key << endl;
    }

    ~HashMapTable() // destructor
    {
        delete[] HashTable;
    }
};

int main()
{
    HashMapTable Hash;
    int Key, Value;
    int Choice;
    while (1)
    {
        cout << "1.Insert element into the table" << endl;
        cout << "2.Search element from the key" << endl;
        cout << "3.Delete element at a key" << endl;
        cout << "4.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> Choice;
        switch (Choice)
        {
        case 1:
            cout << "Enter element to be inserted: ";
            cin >> Value;
            cout << "Enter key at which element to be inserted: ";
            cin >> Key;
            Hash.Insert(Key, Value);
            break;

        case 2:
            cout << "Enter key of the element to be searched: ";
            cin >> Key;
            Hash.SearchKey(Key);
            break;

        case 3:
            cout << "Enter key of the element to be deleted: ";
            cin >> Key;
            Hash.Remove(Key);
            break;

        case 4:
            exit(1);

        default:
            cout << "\nEnter correct option\n";
        }
    }
    return 0;
}
