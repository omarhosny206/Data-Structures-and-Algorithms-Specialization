#include <iostream>
#include <climits>
using namespace std;

class maxHeap
{

private:
    int *Heap;
    int heapCapacity;
    int heapSize;

public:
    maxHeap(int Capacity) // Parameterized Constructor
    {
        heapSize = 0;
        heapCapacity = Capacity;
        Heap = new int[Capacity];
    }

    int Parent(int Index)
    {
        return (Index - 1) / 2;
    }

    // to get Index of leftChild child of node at Index
    int leftChild(int Index)
    {
        return (2 * Index + 1);
    }

    // to get Index of rightChild child of node at Index
    int rightChild(int Index)
    {
        return (2 * Index + 2);
    }

    // sift
    void siftDown(int Index)
    {
        int Left = leftChild(Index);
        int Right = rightChild(Index);
        int biggestItem = Index;

        if (Left < heapSize && Heap[Left] > Heap[Index])
            biggestItem = Left;

        if (Right < heapSize && Heap[Right] > Heap[biggestItem])
            biggestItem = Right;

        if (biggestItem != Index)
        {
            swap(&Heap[Index], &Heap[biggestItem]);
            siftDown(biggestItem);
        }
    }

    // Method to remove minimum element (or Root) from minHeap
    int extractMax()
    {
        if (heapSize <= 0)
            return INT_MAX;

        if (heapSize == 1)
        {
            heapSize--;
            return Heap[0];
        }

        // Store the minimum value, and remove it from Heap
        int Root = Heap[0];
        Heap[0] = Heap[heapSize - 1];
        heapSize--;
        siftDown(0);

        return Root;
    }

    void siftUP(int Index, int newValue)
    {
        Heap[Index] = newValue;
        while (Index != 0 && Heap[Parent(Index)] > Heap[Index])
        {
            swap(&Heap[Index], &Heap[Parent(Index)]);
            Index = Parent(Index);
        }
    }

    // Returns the minimum key (key at Root) from minHeap
    int getMax()
    {
        return Heap[0];
    }

    void deleteKey(int Index)
    {
        siftUP(Index, INT_MIN);
        extractMax();
    }

    void insertKey(int Key)
    {
        if (heapSize == heapCapacity)
        {
            cout << "\nOverflow: Could not insertKey\n";
            return;
        }

        // First insert the new key at the end
        heapSize++;
        int Index = heapSize - 1;
        Heap[Index] = Key;

        siftUP(Index, Key);
    }

    void changePriority(int Index, int newValue)
    {
        int oldValue = Heap[Index];
        Heap[Index] = newValue;

        if (newValue > oldValue)
            siftUP(Index, newValue);

        else
            siftDown(Index);
    }

    void swap(int *First, int *Second)
    {
        int temporaryItem = *First;
        *First = *Second;
        *Second = temporaryItem;
    }
};

class minHeap
{

private:
    int *Heap;
    int heapCapacity;
    int heapSize;

public:
    minHeap(int Capacity) // Parameterized Constructor
    {
        heapSize = 0;
        heapCapacity = Capacity;
        Heap = new int[Capacity];
    }

    int Parent(int Index)
    {
        return (Index - 1) / 2;
    }

    // to get Index of leftChild child of node at Index
    int leftChild(int Index)
    {
        return (2 * Index + 1);
    }

    // to get Index of rightChild child of node at Index
    int rightChild(int Index)
    {
        return (2 * Index + 2);
    }

    // sift
    void siftDown(int Index)
    {
        int Left = leftChild(Index);
        int Right = rightChild(Index);
        int smallestItem = Index;

        if (Left < heapSize && Heap[Left] < Heap[Index])
            smallestItem = Left;

        if (Right < heapSize && Heap[Right] < Heap[smallestItem])
            smallestItem = Right;

        if (smallestItem != Index)
        {
            swap(&Heap[Index], &Heap[smallestItem]);
            siftDown(smallestItem);
        }
    }

    // Method to remove minimum element (or Root) from minHeap
    int extractMin()
    {
        if (heapSize <= 0)
            return INT_MAX;

        if (heapSize == 1)
        {
            heapSize--;
            return Heap[0];
        }

        // Store the minimum value, and remove it from Heap
        int Root = Heap[0];
        Heap[0] = Heap[heapSize - 1];
        heapSize--;
        siftDown(0);

        return Root;
    }

    void siftUP(int Index, int newValue)
    {
        Heap[Index] = newValue;
        while (Index != 0 && Heap[Parent(Index)] > Heap[Index])
        {
            swap(&Heap[Index], &Heap[Parent(Index)]);
            Index = Parent(Index);
        }
    }

    // Returns the minimum key (key at Root) from minHeap
    int getMin()
    {
        return Heap[0];
    }

    void deleteKey(int Index)
    {
        siftUP(Index, INT_MIN);
        extractMin();
    }

    void insertKey(int Key)
    {
        if (heapSize == heapCapacity)
        {
            cout << "\nOverflow: Could not insertKey\n";
            return;
        }

        // First insert the new key at the end
        heapSize++;
        int Index = heapSize - 1;
        Heap[Index] = Key;

        siftUP(Index, Key);
    }

    void changePriority(int Index, int newValue)
    {
        int oldValue = Heap[Index];
        Heap[Index] = newValue;

        if (newValue > oldValue)
            siftUP(Index, newValue);

        else
            siftDown(Index);
    }

    void swap(int *First, int *Second)
    {
        int temporaryItem = *First;
        *First = *Second;
        *Second = temporaryItem;
    }
};

// Driver program to test above functions
int main()
{
    minHeap Heap(11);
    Heap.insertKey(3);
    Heap.insertKey(2);
    Heap.deleteKey(1);
    Heap.insertKey(15);
    Heap.insertKey(5);
    Heap.insertKey(4);
    Heap.insertKey(45);
    cout << Heap.extractMin() << " ";
    cout << Heap.getMin() << " ";
    Heap.siftUP(2, 1);
    cout << Heap.getMin();
    return 0;
}