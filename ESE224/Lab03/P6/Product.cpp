
#include "Product.h"
using namespace std;

// class Product{
//     private:
//         string name;
//         float price;
//         int quantity;
//     public:
//         void displayProduct() const;
//         void restock(int amount);
//         bool sell(int amount);
// };

void Product::displayProduct() const{
    cout << "Product: " << name << ", Price: $" << price << ", Quantity: " << quantity << endl;
}

void Product::restock(int amount){
    quantity += amount;
}

bool Product::sell(int amount){
    if(quantity >= amount){
        quantity -= amount;
        return true;
    }
    return false;
}

void Product::set_data(string n, float p, int q){
    name = n;
    price = p;
    quantity = q;
}

string Product::get_name(){
    return name;
}
float Product::get_price(){
    return price;
}
int Product::get_quantity(){
    return quantity;
}