#include "TicketManager.h"
#include "MovieManager.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

void TicketManager::bookTicket(const string& username) {
    vector<Movie> movies = MovieManager::loadMovies();
    if (movies.empty()) {
        cout << "No movies available for booking.\n";
        return;
    }

    cout << "\nChoose a movie:\n";
    for (size_t i = 0; i < movies.size(); i++) {
        cout << i + 1 << ". " << movies[i].title << "\n";
    }

    int movieChoice;
    cin >> movieChoice;
    if (movieChoice < 1 || movieChoice > movies.size()) {
        cout << "Invalid choice.\n";
        return;
    }

    Movie movie = movies[movieChoice - 1];

    cout << "\nChoose a date:\n";
    vector<string> dates;
    for (const auto& session : movie.sessions) {
        if (session.find(":") == string::npos) {
            dates.push_back(session);
            cout << dates.size() << ". " << session << "\n";
        }
    }

    int dateChoice;
    cin >> dateChoice;
    if (dateChoice < 1 || dateChoice > dates.size()) {
        cout << "Invalid choice.\n";
        return;
    }
    string date = dates[dateChoice - 1];

    cout << "\nChoose a time:\n";
    vector<string> times;
    for (const auto& session : movie.sessions) {
        if (session.find(":") != string::npos) {
            times.push_back(session);
            cout << times.size() << ". " << session << "\n";
        }
    }

    int timeChoice;
    cin >> timeChoice;
    if (timeChoice < 1 || timeChoice > times.size()) {
        cout << "Invalid choice.\n";
        return;
    }
    string time = times[timeChoice - 1];

    ofstream ticketFile("tickets.txt", ios::app);
    ticketFile << username << " | " << movie.title << " | " << date << " | " << time << "\n";
    ticketFile.close();

    cout << "\nTicket booked successfully!\n";
}

void TicketManager::viewBookings(const string& username) {
    ifstream ticketFile("tickets.txt");
    string line;
    bool found = false;

    cout << "\nYour bookings:\n";
    while (getline(ticketFile, line)) {
        if (line.find(username) != string::npos) {
            cout << line << "\n";
            found = true;
        }
    }
    ticketFile.close();

    if (!found) {
        cout << "No bookings found.\n";
    }
}