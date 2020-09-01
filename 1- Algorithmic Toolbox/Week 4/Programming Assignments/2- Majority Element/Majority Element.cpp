#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool majorityElement(vector<int> &Numbers, int &Size)
{
    // we need to sort the Numbers.
    sort(Numbers.begin(), Numbers.end());

    int Element = Numbers[0];
    int Majority = Size / 2;
    int Count = 1;

    for (int i = 1; i < Size; i++)
    {
        if (Count > Majority)
            break;

        if (Numbers[i] == Element)
            Count++;

        else
        {
            Element = Numbers[i];
            Count = 1;
        }
    }

    return Count > Majority;
}

int main()
{
    int Size;
    cin >> Size;
    vector<int> Numbers(Size);

    for (int i = 0; i < Size; i++)
        cin >> Numbers[i];

    cout << majorityElement(Numbers, Size);
}