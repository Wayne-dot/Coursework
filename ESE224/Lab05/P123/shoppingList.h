

#include <fstream>
#include <string>

using namespace std;

class ShoppingList{
    private:
        string file_name;
        fstream myFile;
        string most_expansive_item;
        string name;
        double price;
        double max_price;
    public:
        ShoppingList();
        bool fileOpen(const string& filename);
        double itemExists(const string& check_item);
        void addItem(const string& add_item, double add_price);
        void printMostExpansiveItem();
        void printAll();
        void printTranspose();
        void priceSort();
};