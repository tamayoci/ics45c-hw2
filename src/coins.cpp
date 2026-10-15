#include "coins.hpp"
#include <iostream>

using namespace std;

Coins::Coins(int q, int d, int n, int p)
    : quarters{q}, dimes{d}, nickels{n}, pennies{p}
{
}

void Coins::deposit_coins(Coins& coins) {
    quarters += coins.quarters;
    dimes += coins.dimes;
    nickels += coins.nickels;
    pennies += coins.pennies;

    coins.quarters = 0;
    coins.dimes = 0;
    coins.nickels = 0;
    coins.pennies = 0;
}

bool Coins::has_exact_change_for_coins(const Coins& coins) const {
    return quarters >= coins.quarters &&
           dimes >= coins.dimes &&
           nickels >= coins.nickels &&
           pennies >= coins.pennies;
}

Coins Coins::extract_exact_change(const Coins& coins) {
    if (!has_exact_change_for_coins(coins)) {
        return Coins{0, 0, 0, 0};
    }

    quarters -= coins.quarters;
    dimes -= coins.dimes;
    nickels -= coins.nickels;
    pennies -= coins.pennies;

    return coins;
}

