#include <iostream>
using namespace std;

//O(n log(n))Time, O(1)Space

// Binary Search Recursively.
int binarySearchRecursively(int items[], int Low, int High, int requiredItem)
{ // Low = Left, High = Right.

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

int main()
{

    int Size1, Size2;
    cin >> Size1;
    int Items1[Size1];
    for (int i = 0; i < Size1; i++)
    {
        cin >> Items1[i];
    }

    cin >> Size2;
    int Items2[Size2];
    for (int i = 0; i < Size2; i++)
    {
        cin >> Items2[i];
    }

    for (int i = 0; i < Size2; i++)
    {
        cout << binarySearchRecursively(Items1, 0, Size1 - 1, Items2[i]) << " ";
    }
}
