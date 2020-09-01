#include <iostream>
using namespace std;

int GCD(int Number1, int Number2)
{

    if (Number1 == 0)
        return Number2;

    return GCD(Number2 % Number1, Number1);
}

int main()
{

    int Nummber1, Nummber2;
    cin >> Nummber1 >> Nummber2;
    cout << GCD(Nummber1, Nummber2);
}
