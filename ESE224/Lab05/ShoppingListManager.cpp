
// main program

#include <fstream>
#include <iostream>
#include "shoppingList.h"

using namespace std;

int main(){

    ShoppingList shoppinglist;
    fstream file;
    string filename;
    char choice;

    cout << "Opening Shopping_List_Manager . . ." << endl;
    cout << "Please enter the file name: ";

    cin >> filename;
    shoppinglist.fileOpen();

    while(1){
        cout << "(a) - add an item and its price" << endl;
        cout << "(e) - print the most expansive item in the list" << endl;
        cout << "(i) - check to see if this item exists" << endl;
        cout << "(p) - print all items and its price" << endl;
        cout << "(q) - quit the program" << endl;
        cout << "(s) - print in price descending order" << endl;
        cout << "(t) - print transposed form" << endl;

        cout << "Please select an option: ";
        cin >> choice;

        if(choice == 'q'){
            break;
        }

        cout << choice << endl;


    }

    return 0;
}