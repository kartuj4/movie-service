#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include <vector>

struct Movie {
    std::string title;
    std::string description;
    std::string genre;
    std::string director;
    std::vector<std::string> actors;
    std::vector<std::string> sessions;
};

#endif // MOVIE_H