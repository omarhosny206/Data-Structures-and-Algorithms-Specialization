#include <iostream>
using namespace std;

int Partition(int items[], int Left, int Right)
{

    int Pivot = items[Left];
    int i = Left;
    int j = Right;

    while (i < j)
    {

        do
        {
            i++;
        } while (items[i] <= Pivot);

        do
        {
            j--;
        } while (items[j] > Pivot);

        if (i < j)
            swap(items[i], items[j]);
    }

    swap(items[Left], items[j]);
    return j;
}

// quick sort function
void quickSort(int items[], int Left, int Right)
{

    if (Left < Right)
    {

        int Pivot = Partition(items, Left, Right);

        // for sorting leftSubArray
        quickSort(items, Left, Pivot);

        // for sorting rightSubArray
        quickSort(items, Pivot + 1, Right);
    }
}

// print function
void print(int items[], int Size)
{
    cout << "\n\n[ ";
    for (int i = 0; i < Size; i++)
    {
        cout << items[i] << " ";
    }
    cout << "]\n\n\n";
}

int main()
{

    int items[6] = {5, 3, 10, 1, 2, 8};
    quickSort(items, 0, 6);
    print(items, 6);
}
