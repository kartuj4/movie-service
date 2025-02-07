#include <iostream>
#include "Menu.h"
#include "UserManager.h"
#include "MovieManager.h"
#include "TicketManager.h"

using namespace std;

void userMenu(const string& username) {
    while (true) {
        int choice;
        cout << "\nWelcome, " << username << "!\n";
        cout << "1. View movies\n2. Book a ticket\n3. View my bookings\n4. Logout\nChoose an option: ";
        cin >> choice;

        switch (choice) {
        case 1: MovieManager::viewMovies(); break;
        case 2: TicketManager::bookTicket(username); break;
        case 3: TicketManager::viewBookings(username); break;
        case 4: cout << "Logging out...\n"; return;
        default: cout << "Invalid option! Please enter 1, 2, 3, or 4.\n";
        }
    }
}

void startMenu() {
    while (true) {
        int choice;
        cout << "1. Register\n2. Login\n3. Exit\nChoose an option: ";
        cin >> choice;

        if (choice == 1) {
            UserManager::registerUser();
        }
        else if (choice == 2) {
            string loggedInUser;
            if (UserManager::loginUser(loggedInUser)) {
                userMenu(loggedInUser);
            }
        }
        else if (choice == 3) {
            cout << "Exiting program.\n";
            break;
        }
        else {
            cout << "Invalid option! Please enter 1, 2, or 3.\n";
        }
    }
}
