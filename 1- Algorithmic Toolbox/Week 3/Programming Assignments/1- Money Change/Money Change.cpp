#include <iostream>
using namespace std;

int64_t minimumNumberOfCoins(int64_t &Money)
{
    int64_t minimumNumberOfCoins = Money / 10 + (Money % 10) / 5 + ((Money % 10) % 5);
    return minimumNumberOfCoins;
}

int moneyChange(int money)
{
    int number_of_coins = 0;
    int covered_money = 0;

    int coin1 = 1, coin2 = 5, coin3 = 10;

    while (covered_money < money)
    {
        if (money >= covered_money + coin3)
        {
            covered_money += coin3;
            number_of_coins++;
        }

        else if (money >= covered_money + coin2)
        {
            covered_money += coin2;
            number_of_coins++;
        }

        else if (money >= covered_money + coin1)
        {
            covered_money += coin1;
            number_of_coins++;
        }
    }

    return number_of_coins;
}

int main()
{
    int64_t Money;
    cin >> Money;
    cout << minimumNumberOfCoins(Money);
}
