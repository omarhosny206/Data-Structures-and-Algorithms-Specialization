// Complexcity ... O(N Log N)
#include <iostream>
using namespace std;

void siftDown(int Items[], int Size, int initialPosition)
{

    int Left = (2 * initialPosition) + 1;
    int Right = (2 * initialPosition) + 2;
    int maxValue = initialPosition;

    if (Left < Size && Items[Left] > Items[maxValue])
        maxValue = Left;

    if (Right < Size && Items[Right] > Items[maxValue])
        maxValue = Right;

    // if maxValue changed from its initialPosition, we will make swap between the current item and maxValue item
    if (maxValue != initialPosition)
    {
        swap(Items[initialPosition], Items[maxValue]);
        siftDown(Items, Size, maxValue);
    }
}

void heapSort(int Items[], int Size)
{

    // to reArrange the Items
    for (int i = (Size / 2) - 1; i >= 0; i--)
        siftDown(Items, Size, i);

    // One by one to extract an item from Heap
    for (int i = Size - 1; i >= 0; i--)
    {

        // to move currentNode to the end
        swap(Items[0], Items[i]);

        // call the function for the reduced Heap
        siftDown(Items, i, 0);
    }
}

// print function
void print(int Items[], int Size)
{
    cout << "[ ";
    for (int i = 0; i < Size; i++)
    {
        cout << Items[i] << " ";
    }
    cout << "]\n";
}

int main()
{

    int Items[6] = {14, 90, 12, 45, 2, 66};
    heapSort(Items, 6);
    print(Items, 6);
}
