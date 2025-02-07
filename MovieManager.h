#ifndef MOVIE_MANAGER_H
#define MOVIE_MANAGER_H
#include "Movie.h"
#include <vector>

class MovieManager {
public:
    static std::vector<Movie> loadMovies();
    static void displayMovieInfo(const Movie& movie);
    static void viewMovies();
};

#endif // MOVIE_MANAGER_H