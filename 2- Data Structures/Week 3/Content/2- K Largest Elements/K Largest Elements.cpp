#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void kLargestElements(int *Items, int Size, int kElements)
{
    sort(Items, Items + Size, greater<int>());

    cout << "[ ";
    for (int i = 0; i < kElements; i++)
        cout << Items[i] << " ";
    cout << "]";
}

int main()
{
    int Items[7] = {1, 23, 12, 9, 30, 2, 50};
    int kElements;
    cin >> kElements;
    kLargestElements(Items, 7, kElements);
}