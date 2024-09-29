
#include <iostream>
#include <ostream>
#include "Rectangle.h"

using namespace std;

int main(){

    Rectangle rect1;
    Rectangle rect2(4.0, 5.0);

    cout << "Rectangle 1: Length = " << rect1.getLength() << ", Width = " << rect1.getWidth() << endl;

    cout << "Rectangle 2: Length = " << rect2.getLength() << ", Width = " << rect2.getWidth() << endl;


    rect1.setLength(3.5);
    rect1.setWidth(2.0);

    
    cout << "Updated Rectangle 1: Length = " << rect1.getLength() << ", Width = " << rect1.getWidth() << endl;

    cout << "Rectangle 1 area: " << rect1.area() << ", perimeter: "<< rect1.perimeter() << endl;
    
    return 0;
}
