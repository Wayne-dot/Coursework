#include "Rectangle.h"


Rectangle::Rectangle() : length(1.0), width(1.0){

}

Rectangle::Rectangle(double len, double wid): length(len), width(wid){

}

double Rectangle::getLength() const{
    return length;
}

double Rectangle::getWidth() const{
    return width;
}

void Rectangle::setLength(double len){
    length = len;
}

void Rectangle::setWidth(double wid){
    width = wid;
}

double Rectangle::area() const{
    return length*width;
}

double Rectangle::perimeter() const{
    return 2*(length+width);
}