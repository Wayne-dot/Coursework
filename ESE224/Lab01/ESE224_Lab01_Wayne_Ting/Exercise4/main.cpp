
#include "Movie.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    Movie movie1("Inception", "Christopher Nolan", 8.8325);
    Movie movie2("Interstellar", "Christopher Nolan", 8.6);

    cout << setw(15) << left << "Title"
        << setw(20) << left << "Director"
        << setw(5) << left << "Rating" << endl;
    cout << "-------------------------------------------" << endl;


    movie1.display();
    movie2.display();

    return 0;
}