
// main program

#include <fstream>
#include <iostream>
#include "shoppingList.h"

using namespace std;

int main(){

    ShoppingList shoppinglist;
    fstream myfile;
    string filename, item;
    char choice;
    double price;

    cout << "Opening Shopping_List_Manager . . ." << endl << endl;
    cout << "Please enter the file name: ";

    cin >> filename;

    if(shoppinglist.fileOpen(filename)){
        while(1){
            cout << "(a) - add an item and its price" << endl;
            cout << "(e) - print the most expansive item in the list" << endl;
            cout << "(i) - check to see if this item exists" << endl;
            cout << "(p) - print all items and its price" << endl;
            cout << "(q) - quit the program" << endl;
            cout << "(s) - print in price descending order" << endl;
            cout << "(t) - print transposed form" << endl;

            cout << endl << "Please select an option: ";
            cin >> choice;
            cout << endl;

            if(choice == 'q'){
                break;
            }
            else if (choice == 'p') {
                shoppinglist.printAll();
            }
            else if (choice == 't') {
                shoppinglist.printTranspose();
            }
            else if (choice == 'i') {
                cout << "Enter the item name: ";
                cin >> item;

                double result = shoppinglist.itemExists(item) ;

                if(result > 0){
                    cout << "The item exists and it cost $" << result << endl;
                }
                else{
                    cout << "The item does not exist" << endl;
                }
            }
            else if (choice == 'a') {
                cout << "Enter item name and its price: ";
                cin >> item >> price;
                shoppinglist.addItem(item, price);
            }


            cout << endl;

        }
    }

    

    return 0;
}