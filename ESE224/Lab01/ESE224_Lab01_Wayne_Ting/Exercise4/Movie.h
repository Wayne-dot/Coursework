
#ifndef MOVIE_H
#define MOVIE_H

#include <string>
using namespace std;

class Movie{
    private:
        string title;
        string director;
        double rating;

    public:
        Movie();
        Movie(string t, string dir, double rate);
        void display();
};

#endif