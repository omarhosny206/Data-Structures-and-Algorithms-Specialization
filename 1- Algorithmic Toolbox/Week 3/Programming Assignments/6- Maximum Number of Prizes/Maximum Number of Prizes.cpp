#include <iostream>
#include <vector>
using namespace std;

void winnersOfCandies(int &numberOfCandies)
{
    vector<int> Winners;
    int totalCandies = 0;
    for (int i = 1; i + totalCandies <= numberOfCandies; i++)
    {
        Winners.push_back(i);
        totalCandies += i;
    }

    int lastWinnerPosition = Winners.size() - 1;
    Winners[lastWinnerPosition] += numberOfCandies - totalCandies;

    // to show the winners
    cout << Winners.size() << endl;
    for (int i = 0; i < Winners.size(); i++)
        cout << Winners[i] << " ";
}

int main()
{
    int numberOfCandies;
    cin >> numberOfCandies;

    winnersOfCandies(numberOfCandies);
}
