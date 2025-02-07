#include "UserManager.h"
#include <iostream>
#include <fstream>
#include <regex>

using namespace std;

bool UserManager::userExists(const string& username) {
    ifstream file("users.txt");
    string u, pass;
    while (getline(file, u, ' ') && getline(file, pass)) {
        if (u == username) {
            return true;
        }
    }
    return false;
}

bool UserManager::isValidPassword(const string& password) {
    regex pattern("^[a-zA-Z0-9]{6,}$");
    return regex_match(password, pattern);
}

void UserManager::registerUser() {
    User user;
    cout << "Enter username: "; cin >> user.username;

    do {
        cout << "Enter password (at least 6 characters, only letters and numbers allowed): ";
        cin.ignore(); getline(cin, user.password);
        if (!isValidPassword(user.password)) {
            cout << "Invalid password format. Try again.\n";
        }
    } while (!isValidPassword(user.password));

    if (userExists(user.username)) {
        cout << "Error: User with this username already exists.\n";
        return;
    }

    ofstream file("users.txt", ios::app);
    file << user.username << " " << user.password << "\n";
    file.close();
    cout << "Registration successful!\n";
}

bool UserManager::loginUser(string& loggedInUser) {
    string input, password;
    while (true) {
        cout << "Enter username: "; cin >> input;
        cout << "Enter password: "; cin.ignore(); getline(cin, password);

        ifstream file("users.txt");
        string u, pass;
        while (getline(file, u, ' ') && getline(file, pass)) {
            if (u == input && pass == password) {
                cout << "Login successful!\n";
                loggedInUser = input;
                return true;
            }
        }
        cout << "Error: Incorrect username or password. Try again.\n";
    }
}
