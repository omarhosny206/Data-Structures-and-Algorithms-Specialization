#include <iostream>
using namespace std;

int GCD(int Number1, int Number2)
{

    if (Number1 == 0)
        return Number2;

    return GCD(Number2 % Number1, Number1);
}

int64_t leastCommonMultiple(int64_t Number1, int64_t Number2)
{
    return (Number1 * Number2) / GCD(Number1, Number2);
}

int main()
{
    int64_t Number1, Number2;
    cin >> Number1 >> Number2;
    cout << leastCommonMultiple(Number1, Number2);
}
