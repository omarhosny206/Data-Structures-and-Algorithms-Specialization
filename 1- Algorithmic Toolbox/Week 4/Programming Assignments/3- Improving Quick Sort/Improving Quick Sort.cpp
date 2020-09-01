#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

int partition1(vector<int> &Numbers, int Left, int Right)
{
    int Pivot = Numbers[Left];
    int j = Left;

    for (int i = Left + 1; i <= Right; i++)
    {
        if (Numbers[i] <= Pivot)
        {
            j++;
            swap(Numbers[i], Numbers[j]);
        }
    }

    swap(Numbers[Left], Numbers[j]);
    return j;
}

void partition2(vector<int> &Numbers, int Left, int Right, int &Middle1, int &Middle2)
{
    int Pivot = Numbers[Left];
    Middle2 = Left;
    int count_Pivot = 1;
    for (int i = Left + 1; i <= Right; i++)
    {
        if (Numbers[i] <= Pivot)
        {
            Middle2++;
            swap(Numbers[i], Numbers[Middle2]);
        }
        if (Numbers[i] == Pivot)
        {
            swap(Numbers[Left + count_Pivot], Numbers[Middle2]);
            count_Pivot++;
        }
    }

    for (int i = 0; i < count_Pivot; i++)
    {
        swap(Numbers[Left + i], Numbers[Middle2 - i]);
    }

    Middle1 = Middle2 - count_Pivot + 1;
}

void randomizedQuickSort(vector<int> &Numbers, int Left, int Right)
{
    if (Left >= Right)
    {
        return;
    }

    int K = Left + rand() % (Right - Left + 1);
    swap(Numbers[Left], Numbers[K]);
    int Middle1 = Left, Middle2 = Left;
    partition2(Numbers, Left, Right, Middle1, Middle2);

    randomizedQuickSort(Numbers, Left, Middle1 - 1);
    randomizedQuickSort(Numbers, Middle2 + 1, Right);
}

int main()
{
    int Size;
    cin >> Size;
    vector<int> Numbers(Size);

    for (int i = 0; i < Numbers.size(); i++)
    {
        cin >> Numbers[i];
    }

    randomizedQuickSort(Numbers, 0, Numbers.size() - 1);

    for (int i = 0; i < Numbers.size(); i++)
    {
        cout << Numbers[i] << " ";
    }
}