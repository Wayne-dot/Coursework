
#include "shoppingList.h"
#include <fstream>
#include <ios>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>
#include <set>

using namespace std;

ShoppingList::ShoppingList(){

}

bool ShoppingList::fileOpen(const string& filename){
    file_name = filename;
    myFile.open(file_name);
    if(!myFile){
        cout << "File can not be found" << endl;
        return false;
    }
    cout << "Sucessfully opens the target file!" << endl << endl;
    return true;
}

void ShoppingList::addItem(const string& add_item, double add_price){
    
}

double ShoppingList::itemExists(const string& check_item){
    string line;
    vector<string> items;
    vector<double> prices;

    while(getline(myFile, line)){
        // cout << line << endl;
        stringstream ss(line);
        ss >> name;
        ss >> price;

        items.push_back(name);
        prices.push_back(price);
    }

    for (int i = 0; i < items.size(); ++i) {
        if (items[i] == check_item) {
            return prices[i];  
        }
    }

    return -1;  //-1 if is not found
}







string double_to_string(double num){
    stringstream stream;
    stream << fixed << setprecision(2) << num;
    return stream.str();
}

void ShoppingList::printTranspose(){
    string line;
    vector<string> items;
    vector<double> prices;

    while(getline(myFile, line)){
        // cout << line << endl;
        stringstream ss(line);
        ss >> name;
        ss >> price;

        items.push_back(name);
        prices.push_back(price);
    }

    for(int i = 0 ; i < items.size() ; i++){
        cout << left << setw(15) << items[i];
    }
    cout << endl;
    for(int i = 0 ; i < prices.size() ; i++){
        cout << left << setw(15) << ("$" + double_to_string(prices[i]));
    }
    

}

void ShoppingList::printAll(){
    string line;
    int i = 1;

    while(getline(myFile, line)){
        // cout << line << endl;
        stringstream ss(line);
        ss >> name;
        ss >> price;

        cout << left << setw(1) << i << ". "
            << left << setw(20) << name
            << "$" << left << setw(10) << price << endl;

        i++;
    }
}