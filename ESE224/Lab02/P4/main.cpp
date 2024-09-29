

#include <iostream>
#include "Pyramid.h"

using namespace std;


int main(){
    
    int height;
    cout << "Enter the height of the pyramid: ";
    cin >> height;

    Pyramid pyramid(height);
    pyramid.create();
    pyramid.flip();

    return 0;
}