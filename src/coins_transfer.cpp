#include <iostream>
#include "coins.hpp"

using namespace std;

int main() {
    Coins piggyBank(50, 50, 50, 50);
    Coins pocket(8, 3, 6, 8);

    cout << "Initial piggy bank: " << piggyBank << endl;
    cout << "Initial pocket: " << pocket << endl << endl;

    cout << "Bought chips using pocket" << endl;
    Coins chips_cost = coins_required_for_cents(149);
    Coins paid = pocket.extract_exact_change(chips_cost);
    cout << "Chips required the coins: " << chips_cost << endl;
    cout << "Pocket after paying for chips: " << pocket << endl << endl;

    cout << "Transferring money to pocket" << endl;
    Coins transfer_amount = coins_required_for_cents(405);
    Coins transferred = piggyBank.extract_exact_change(transfer_amount);
    cout << "Coins for transfer: " << transfer_amount << endl;
    pocket.deposit_coins(transferred);
    cout << "Pocket: " << pocket << endl;
    cout << "Piggy bank: " << piggyBank << endl << endl;

    cout << "Transferring sofa change to piggy bank" << endl;
    Coins sofa(10, 10, 10, 10);
    cout << "Sofa: " << sofa << endl;
    piggyBank.deposit_coins(sofa);
    cout << "Piggy bank: " << piggyBank << endl << endl;

    cout << "Piggy bank total: ";
    print_cents(piggyBank.total_value_in_cents(), cout);
    cout << endl;
}