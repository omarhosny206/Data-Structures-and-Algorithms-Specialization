#include <iostream>
using namespace std;

//O(n log(n))Time, O(1)Space

// Binary Search Recursively.
int binarySearchRecursively(int items[], int Low, int High, int requiredItem)
{
    // Low = Left, High = Right.

    if (Low > High)
        return -1;

    int middlePosition = (Low + High) / 2;

    if (items[middlePosition] == requiredItem)
        return middlePosition;

    else if (items[middlePosition] > requiredItem)
        return binarySearchRecursively(items, Low, middlePosition - 1, requiredItem);

    else if (items[middlePosition] < requiredItem)
        return binarySearchRecursively(items, middlePosition + 1, High, requiredItem);
}

// Binary Search Iteratively.
int binarySearchIteratively(int items[], int Low, int High, int requiredItem)
{
    // Low = Left, High = Right.

    while (Low <= High)
    {

        int middlePosition = (Low + High) / 2;

        if (items[middlePosition] == requiredItem)
            return middlePosition;

        else if (items[middlePosition] > requiredItem)
            High = middlePosition - 1;

        else if (items[middlePosition] < requiredItem)
            Low = middlePosition + 1;
    }

    return -1;
}

int main()
{

    int items[6] = {10, 15, 16, 23, 26, 90};

    cout << binarySearchIteratively(items, 0, 5, 90) << endl;

    if (binarySearchRecursively(items, 0, 5, 100) != -1)
        cout << "True\n";

    else
        cout << "False\n";
}
