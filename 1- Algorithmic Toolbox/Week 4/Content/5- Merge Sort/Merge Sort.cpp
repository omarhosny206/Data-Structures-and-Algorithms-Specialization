#include <iostream>
using namespace std;

// O(n log(n))
void Merge(int items[], int Left, int Right, int M)
{
    // M = Left + (Right-Left)/2

    int i, j, k;

    int leftSize = M - Left + 1; // Left SubArray [Left, ...., M]
    int rightSize = Right - M;   // Right SubArray [M+1, ...., Left]

    int *leftItems = new int[leftSize];
    int *rightItems = new int[rightSize];

    for (i = 0; i < leftSize; i++)
        leftItems[i] = items[Left + i];

    for (j = 0; j < rightSize; j++)
        rightItems[j] = items[M + j + 1];

    i = j = 0;
    k = Left;

    // comparison part
    while (i < leftSize && j < rightSize)
    {

        if (leftItems[i] <= rightItems[j])
        {
            items[k] = leftItems[i];
            i++;
        }

        else
        {
            items[k] = rightItems[j];
            j++;
        }

        k++;
    }

    // if it still have items
    while (i < leftSize)
    {
        items[k] = leftItems[i];
        i++;
        k++;
    }

    while (j < rightSize)
    {
        items[k] = rightItems[j];
        j++;
        k++;
    }
}

// merge sort function
void mergeSort(int items[], int Left, int Right)
{

    if (Left < Right)
    {
        int M = Left + (Right - Left) / 2;

        // to divide into subbArrays
        mergeSort(items, Left, M);
        mergeSort(items, M + 1, Right);

        Merge(items, Left, Right, M);
    }
}

// print function
void print(int items[], int Size)
{
    cout << "[ ";
    for (int i = 0; i < Size; i++)
    {
        cout << items[i] << " ";
    }
    cout << "]\n";
}

int main()
{
    int items[8] = {13, 2, 30, 17, 18, 9, 9, 21};
    mergeSort(items, 0, 7);
    print(items, 8);
}
