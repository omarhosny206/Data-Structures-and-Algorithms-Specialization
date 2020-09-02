// Complexcity ... O(N Log N)
#include <iostream>
#include <vector>
using namespace std;

class Heap
{
private:
    vector<int> itemsOfArray;
    vector<pair<int, int>> Swaps;

public:
    void getItems()
    {
        int Size;
        cin >> Size;
        itemsOfArray.resize(Size);
        for (int i = 0; i < itemsOfArray.size(); ++i)
            cin >> itemsOfArray[i];
    }

    void siftDown(int initialPosition)
    {
        int minValue = initialPosition;
        int Left = 2 * initialPosition + 1;
        int Right = 2 * initialPosition + 2;

        if ((Left < itemsOfArray.size()) && (itemsOfArray[Left] < itemsOfArray[minValue]))
            minValue = Left;

        if ((Right < itemsOfArray.size()) && (itemsOfArray[Right] < itemsOfArray[minValue]))
            minValue = Right;

        // if minValue changed from its initialPosition, we will make swap between the current item and minValue item
        if (minValue != initialPosition)
        {
            swap(itemsOfArray[initialPosition], itemsOfArray[minValue]);
            Swaps.push_back(make_pair(initialPosition, minValue));
            siftDown(minValue);
        }
    }

    void heapSort()
    {
        Swaps.clear();
        // to reArrange the Items
        for (int i = int(itemsOfArray.size() / 2); i >= 0; --i)
        {
            siftDown(i);
        }
    }

    // print function
    void printSwaps()
    {
        cout << Swaps.size() << endl;
        for (int i = 0; i < Swaps.size(); ++i)
        {
            cout << Swaps[i].first << " " << Swaps[i].second << endl;
        }
    }
    void numberOfSwaps()
    {
        getItems();
        heapSort();
        printSwaps();
    }
};

int main()
{

    Heap HeapSort;
    HeapSort.numberOfSwaps();
}
