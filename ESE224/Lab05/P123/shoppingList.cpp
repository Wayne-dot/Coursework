
#include "shoppingList.h"
#include <fstream>
#include <ios>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>

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
    myFile.close();
    myFile.open(file_name);
    myFile.seekp(0, ios::end);
    myFile << endl << add_item << " " << add_price << endl;
    myFile.close();
}

double ShoppingList::itemExists(const string& check_item){
    myFile.close();
    myFile.open(file_name);
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

    myFile.close();

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
    myFile.close();
    myFile.open(file_name);
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

    myFile.close();
    

}

void ShoppingList::printMostExpansiveItem(){
    myFile.close();
    myFile.open(file_name);
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
    myFile.close();

    max_price = prices[0];
    int index = 0;
    for(int i = 0 ; i < prices.size() ; i++){
        if(prices[i] > max_price){
            max_price = prices[i];
            index = i;
        }
    }
    cout << "The most expansive item is " << items[index] << " and it cost $" << max_price << endl;
}

void ShoppingList::printAll(){
    myFile.close();
    myFile.open(file_name);
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
    myFile.close();
}

void ShoppingList::priceSort(){
    myFile.close();
    myFile.open(file_name);
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
    myFile.close();

    // selection sorting algorthim
    double max, temp;
    string temp_string;

    for(int i = 0 ; i < prices.size() ; i++){
        max = i;
        for(int j = i+1 ; j < prices.size() ; j++){
            if(prices[j] > prices[max]){
                // set current maximum
                max = j;
            }
        }
        // swap
        temp = prices[i];
        prices[i] = prices[max];
        prices[max] = temp;

        // also swap the items
        temp_string = items[i];
        items[i] = items[max];
        items[max] = temp_string;
    }

    for(int i = 0 ; i < prices.size() ; i++){
        cout << left << setw(3) << (to_string(i+1) + ".") << 
        left << setw(20) << items[i] << "$" << prices[i] << endl;
    }

}