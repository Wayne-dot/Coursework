#include <iostream>
#include "InventoryManager.h"
#include <string>

using namespace std;

int main(){

    int choice, quantity;
    string product_name;
    InventoryManager manager;

    manager.loadInventoryFromFile("inventory.txt");

    while(1){
        cout << "1. View Inventory" << endl;
        cout << "2. Process a Purchase" << endl;
        cout << "3. Restock an Item" << endl;
        cout << "4. Save and Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if(choice == 1){
            manager.displayInventory();
        }
        else if(choice == 2){
            cout << "Enter the product name: ";
            cin >> product_name;
            cout << "Enter the quantity to sell: ";
            cin >> quantity;
            
            manager.processPurchase(product_name, quantity);
        }
        else if(choice == 3){
            // restock
            cout << "Enter the product name for restock: ";
            cin >> product_name;
            cout << "Enter the quantity to restock: ";
            cin >> quantity;

            manager.restockItem(product_name, quantity);
        }
        else if(choice == 4){
            manager.saveInventoryToFile("inventory.txt");
            cout << "Inventory saved successfully!" << endl;
            break;
        }
        cout << endl;
        
    }
    return 0;
}