#include <iostream>
#include <algorithm>
using namespace std;

int64_t maximumAdsRevenue(int64_t &numberOfAds, int64_t sequenceA[], int64_t sequenceB[])
{
    int64_t maximumAdsRevenue = 0;
    sort(sequenceA, sequenceA + numberOfAds);
    sort(sequenceB, sequenceB + numberOfAds);

    for (int64_t i = 0; i < numberOfAds; i++)
        maximumAdsRevenue += sequenceA[i] * sequenceB[i];

    return maximumAdsRevenue;
}

int main()
{
    int64_t numberOfAds;
    cin >> numberOfAds;
    int64_t sequenceA[numberOfAds], sequenceB[numberOfAds];

    for (int64_t i = 0; i < numberOfAds; i++)
        cin >> sequenceA[i];
    for (int64_t i = 0; i < numberOfAds; i++)
        cin >> sequenceB[i];

    cout << maximumAdsRevenue(numberOfAds, sequenceA, sequenceB);
}
