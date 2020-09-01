#include <iostream>
using namespace std;

int minNumberOfGroups(float childrenAges[], int numberOfChildren)
{
    int lastChild = numberOfChildren;
    int currentChild = 1;
    int startingPoint = 0; // start from left point.
    int minNumberOfGroups = 0;

    while (currentChild < lastChild)
    {

        if (childrenAges[currentChild] - childrenAges[startingPoint] > 1)
        {
            startingPoint = currentChild;
            minNumberOfGroups++;
        }

        if (currentChild == lastChild - 1)
            minNumberOfGroups++;

        currentChild++;
    }

    return minNumberOfGroups;
}

int main()
{
    int numberOfChildren;
    cin >> numberOfChildren;
    float childrenAges[numberOfChildren];

    for (int i = 0; i < numberOfChildren; i++)
        cin >> childrenAges[i];

    cout << minNumberOfGroups(childrenAges, numberOfChildren);

    return 0;
}
