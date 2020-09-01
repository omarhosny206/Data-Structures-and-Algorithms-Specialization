// Time Complexity: O(N)
#include <iostream>
using namespace std;

int64_t countRefill(int64_t Distance, int64_t tankCapacity, int64_t numberOfPumps, int64_t Pumps[])
{
    int64_t numberOfRefills = 0;
    int64_t coveredDistance = 0;
    int64_t pumpsPosition = 0;
    bool impossibleToReach = false;
    int64_t temporaryTankCapacity = tankCapacity;

    // while the car in the journey.
    while (coveredDistance < Distance)
    {

        // When the car reaches the pump.
        if (pumpsPosition < numberOfPumps && Pumps[pumpsPosition] <= coveredDistance + tankCapacity)
        {
            tankCapacity -= Pumps[pumpsPosition] - coveredDistance;
            coveredDistance = Pumps[pumpsPosition];
            pumpsPosition++;

            // If must visited pump is  between coveredDistance and coveredDistance + tankCapacity.
            if (pumpsPosition < numberOfPumps && Pumps[pumpsPosition] - Pumps[pumpsPosition - 1] > tankCapacity)
            {
                numberOfRefills++;
                tankCapacity = temporaryTankCapacity;
            }
        }

        //If we are at the last pump.
        else if (pumpsPosition == numberOfPumps)
        {

            if (tankCapacity >= Distance - coveredDistance)
                return numberOfRefills;

            else if (temporaryTankCapacity >= Distance - Pumps[pumpsPosition - 1])
            {
                numberOfRefills++;
                return numberOfRefills;
            }

            else
                return -1;
        }

        else
            return -1;
    }
}

int main()
{
    int64_t Distance, tankCapacity, numberOfPumps;
    cin >> Distance >> tankCapacity >> numberOfPumps;
    int64_t Pumps[numberOfPumps];
    for (int64_t pumpsPosition = 0; pumpsPosition < numberOfPumps; pumpsPosition++)
        cin >> Pumps[pumpsPosition];

    cout << countRefill(Distance, tankCapacity, numberOfPumps, Pumps);
}