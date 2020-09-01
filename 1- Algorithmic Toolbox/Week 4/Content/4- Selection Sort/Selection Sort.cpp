#include <iostream>
using namespace std;

void selectionSort(int items[], int Size)
{

    int minimumItem;

    // to get min
    for (int i = 0; i < Size - 1; i++)
    {

        minimumItem = i;

        for (int k = i + 1; k < Size; k++)
        {

            if (items[k] < items[minimumItem])
                minimumItem = k;
        }

        swap(items[minimumItem], items[i]);
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
    int items[6] = {60, 40, 50, 30, 10, 20};
    selectionSort(items, 6);
    print(items, 6);
}
