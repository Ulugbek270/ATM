#include <iostream>
#include <fstream>
#include <string>
#include "AccountSystem.h"
#include "BankFunctions.h"
using namespace std;



int main() {
    AccountSystem acc;
    BankFunctions bank;
    acc.signUp();

    acc.login();




    string username2 = acc.getUsername();
    float balance2 = acc.getBalance();
    cout<<endl;



    bank.displayHomeMenu(username2, balance2);


    return 0;
}
