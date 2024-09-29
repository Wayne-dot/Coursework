
#include "Box.h"
#include <iostream>
#include <ostream>

using namespace std;

Box::Box(double len, double wid, double he): length(len), width(wid), height(he){

}

void Box::display() {
    cout << length << " x " << width << " x " << height << endl;
}

Box Box::operator+(const Box& otherBox) const{
    double newlen = length + otherBox.length;
    double newwid = width + otherBox.width;
    double newhe = height + otherBox.height;

    return Box(newlen, newwid, newhe);
}

Box Box::operator-(const Box& otherBox) const{
    double newlen = length - otherBox.length;
    double newwid = width - otherBox.width;
    double newhe = height - otherBox.height;

    if(newlen < 0){
        newlen = 0;
    }
    if(newwid < 0){
        newwid = 0;
    }
    if(newhe < 0){
        newhe = 0;
    }

    return Box(newlen, newwid, newhe);
}