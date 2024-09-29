

#include "InventoryManager.h"
#include <fstream>
#include <ostream>
#include <string.h>

using namespace std;

void InventoryManager::loadInventoryFromFile(const char* filename){
    string name;
    float price;
    int quantity;
    numProducts = 0;

    ifstream inputfile(filename);
    if(!inputfile){
        cout << "File can not be found" << endl;
    }
    else{
        int i = 0;
        while(!inputfile.eof()){
            inputfile >> name >> price >> quantity;
            products[i].set_data(name, price, quantity);
            numProducts+=1;
            i++;
        }
    }
    
}

void InventoryManager::saveInventoryToFile(const char* filename){
    ofstream outputfile(filename);
    if(!outputfile){
        cout << "File can not be found" << endl;
    }

    for(int i = 0 ; i < numProducts ; i++){
        outputfile << products[i].get_name() << " " << products[i].get_price() << " " << products[i].get_quantity() << endl;
    }
    
}

void InventoryManager::displayInventory() const{
    for(int i = 0 ; i < numProducts ; i++){
        products[i].displayProduct();
    }
}

void InventoryManager::processPurchase(string name, int quantity){
    for(int i = 0 ; i < numProducts ; i++){
        if(strcmp(products[i].get_name().c_str(), name.c_str()) == 0){
            if(products[i].sell(quantity)){
                cout << "Purchase successful!" << endl;
            }
            else{
                cout << "Purchase NOT successful" << endl;
            }
        }
    }
}

void InventoryManager::restockItem(string name, int quantity){
    for(int i = 0 ; i < numProducts ; i++){
        if(strcmp(products[i].get_name().c_str(), name.c_str()) == 0){
            products[i].restock(quantity);
        }
    }
}