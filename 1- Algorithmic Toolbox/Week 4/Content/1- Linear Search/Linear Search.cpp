#include <iostream>
using namespace std;

// Linear Search Recursively.
int linearSearchRecursively(int items[], int requiredItem, int Low, int High)
{

    if (Low > High)
        return -1;

    if (items[Low] == requiredItem)
        return Low;

    return linearSearchRecursively(items, requiredItem, Low + 1, High);
}

// Iteratively Linear Search.
int linearSearchIteratively(int items[], int Size, int requiredItem)
{

    for (int i = 0; i < Size; i++)
    {

        if (items[i] == requiredItem)
            return i;
    }
    return -1;
}

int main()
{

    int items[6] = {5, 6, 1, 8, 19, 64};

    //Linear Search Recursively.
    cout << linearSearchRecursively(items, 64, 0, 5) << endl;
    cout << linearSearchRecursively(items, 65, 0, 5) << endl;

    //Linear Search Iteratively.
    if (linearSearchIteratively(items, 6, 18) > -1)
        cout << "true\n";

    else
        cout << "false\n";
}
