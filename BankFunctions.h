
#ifndef ER_BANKFUNCTIONS_H
#define ER_BANKFUNCTIONS_H


#include <iostream>
#include <fstream>
#include <string>
#include "AccountSystem.h"

using namespace std;


class BankFunctions : public AccountSystem {
private:
    float balance;
    int credits;


public:
    void deposit_money(float money) {
        cout << "Current balance " << balance << endl;
        if (money > 0) {
            balance += money;
            cout << "Money transfered successfully" << endl;
            cout << "Your balance now " << balance << endl;
        } else {
            cout << "Not enough fundings" << endl;
        }
    }
    void take_credit(int duration, float money) {
        float percentage = 0.1;
        float total_loan = money;
        while (duration > 0) {
            total_loan += total_loan * percentage;
            duration--;
        }
        cout << "Total loan " << total_loan;
        credits += total_loan;

    }
    void withdraw_money(float money) {
        cout << "Current balance " << balance << endl;
        if (balance >= money) {
            balance -= money;
            cout << "Withdraw amount " << money << endl;
            cout << "Your balance now " << balance << endl;
        } else {
            cout << "Not enough fundings" << endl;

        }
    }


    void displayHomeMenu(string username2, float balance2) {

        cout << "Hi, " << username2 << endl;
        cout << "Balance, " << balance2 << endl;
        cout << "1. deposit_money =====" << endl;
        cout << "2. take_credit =====" << endl;
        cout << "3. withdraw_money =====" << endl;
        cout << "4. EXIT =====" << endl;

    }

};





#endif //ER_BANKFUNCTIONS_H
