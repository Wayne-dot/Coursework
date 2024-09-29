
#include "Movie.h"
#include <ios>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

Movie::Movie(string t, string dir, double rate): title(t), director(dir), rating(rate){

}

void Movie::display(){
    cout << setw(15) << left << title
        << setw(20) << left << director
        << setw(5) << left << fixed << setprecision(1) << rating << endl;
}