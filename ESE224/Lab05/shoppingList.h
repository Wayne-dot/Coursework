

#include <fstream>
#include <istream>
#include <string>

using namespace std;

class ShoppingList{
    private:
        string file_name;
        fstream myFile;
        string most_expansive_item;
        string name;
    public:
        ShoppingList();
        bool fileOpen(fstream& in);
        bool itemExists(fstream& in);
        void addItem(fstream& in);
        void printMostExpansiveItem();
        void printAll();
        void printTranspose();
        void priceSort();
};