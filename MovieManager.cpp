// MovieManager.cpp
#include "MovieManager.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

vector<Movie> MovieManager::loadMovies() {
    vector<Movie> movies;
    ifstream file("movies.txt");
    string line;

    while (getline(file, line)) {
        Movie movie;
        stringstream ss(line);
        getline(ss, movie.title, '|');
        getline(ss, movie.description, '|');
        getline(ss, movie.genre, '|');
        getline(ss, movie.director, '|');

        string actor;
        while (getline(ss, actor, ',')) {
            movie.actors.push_back(actor);
        }

        vector<string> dates;
        while (getline(file, line) && !line.empty()) {
            dates.push_back(line);
        }
        movie.sessions = dates;
        movies.push_back(movie);
    }
    return movies;
}

void MovieManager::displayMovieInfo(const Movie& movie) {
    cout << "\nTitle: " << movie.title << "\n";
    cout << "Description: " << movie.description << "\n";
    cout << "Genre: " << movie.genre << "\n";
    cout << "Director: " << movie.director << "\n";
    cout << "Actors: ";
    for (const auto& actor : movie.actors) {
        cout << actor << ", ";
    }
    cout << "\n";
}

void MovieManager::viewMovies() {
    vector<Movie> movies = loadMovies();
    if (movies.empty()) {
        cout << "No movies available.\n";
        return;
    }

    while (true) {
        cout << "\nAvailable movies:\n";
        for (size_t i = 0; i < movies.size(); ++i) {
            cout << i + 1 << ". " << movies[i].title << "\n";
        }
        cout << movies.size() + 1 << ". Return to main menu\n";

        int choice;
        cout << "Select a movie: ";
        cin >> choice;
        if (choice > 0 && choice <= movies.size()) {
            displayMovieInfo(movies[choice - 1]);
        }
        else if (choice == movies.size() + 1) {
            break;
        }
        else {
            cout << "Invalid choice, try again.\n";
        }
    }
}
