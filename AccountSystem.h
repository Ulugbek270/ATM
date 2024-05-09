
#ifndef ER_ACCOUNTAccountSystem_H
#define ER_ACCOUNTAccountSystem_H


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class AccountSystem {

private:
    bool isRegistered(string username);
    void createUser(string username, string password, float balance);
    bool isCorrectPassword(string username, string password);


public:
    void signUp();
    void login();

    string  getUsername();
    float  getBalance();
    string username1;
    float balance1 = 101;


};


string AccountSystem::getUsername() { // Definition with return type string
    return username1;
}


float AccountSystem::getBalance() { // Definition with return type string
    return balance1;
}


void AccountSystem::signUp() {
    cout << "SIGN UP: " << endl;
    string username, password;
    float balance ;

    cout << "Username: ";
    getline(cin, username);

    if (isRegistered(username)) {
        cout << "Username already taken. Please choose another." << endl;
        return;
    }

    cout << "Password: ";
    getline(cin, password);

    cout << "Balance: ";
    cin>> balance;


    createUser(username, password, balance);
    username1 = username;
    balance1 = balance;
    cout << "Registered successfully!" << endl;
}


void AccountSystem::login() {
    cout << "LOG IN :" << endl;
    string username, password;

    cout << "Username: ";
    getline(cin, username);

    if (!isRegistered(username)) {
        cout << "User not found. Please sign up first." << endl;
        return;
    }

    cout << "Password: ";
    getline(cin, password);

    if (!isCorrectPassword(username, password)) {
        cout << "Incorrect password." << endl;
        return;
    }
    username1 = username;

    cout << "Logged in successfully!" << endl;
}

bool AccountSystem::isRegistered(string username) {
    ifstream file("User_" + username + ".txt");
    return file.good();
}



void AccountSystem::createUser(string username, string password, float balance) {
    ofstream file("User_" + username + ".txt");
    if (file.is_open()) {
        file << "Username: " << username << endl;
        file << "Password: " << password << endl;
        file << "Balance: " << balance << endl;
        file.close();
    } else {
        cout << "Error: Unable to create user profile." << endl;
    }
}



bool AccountSystem::isCorrectPassword(string username, string password) {
    ifstream file("User_" + username + ".txt");
    string line;
    bool foundPassword = false;

    if (file.is_open()) {
        while (getline(file, line)) {
            if (line == "Password: " + password) {
                foundPassword = true;
                break;
            }
        }
        file.close();
    }

    return foundPassword;
}




#endif //ER_ACCOUNTAccountSystem_H
