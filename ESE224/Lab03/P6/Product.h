#include <iostream>
using namespace std;

class Product{
    private:
        string name;
        float price;
        int quantity;
    public:
        void set_data(string n, float p, int q);
        
        string get_name();
        float get_price();
        int get_quantity();

        void displayProduct() const;
        void restock(int amount);
        bool sell(int amount);
};