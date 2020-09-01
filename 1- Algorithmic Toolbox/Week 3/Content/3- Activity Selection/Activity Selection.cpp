#include <iostream>
#include <algorithm>
using namespace std;

struct Activity
{
    int Start, Finish;
};

bool compareActivities(Activity Activity1, Activity Activity2)
{
    return (Activity1.Finish < Activity2.Finish);
}

int ActivitySelection(Activity Activities[], int Size)
{
    sort(Activities, Activities + Size, compareActivities);

    int activityPosition = 0;
    int numberOfActivities = 1;

    for (int i = 1; i < Size; i++)
    {
        if (Activities[activityPosition].Finish <= Activities[i].Start)
        {
            activityPosition = i;
            numberOfActivities++;
        }
    }
    return numberOfActivities;
}

int main()
{
    Activity Activities[6] = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}};
    cout << ActivitySelection(Activities, 6);
}