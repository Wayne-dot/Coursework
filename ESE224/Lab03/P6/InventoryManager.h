
#include "Product.h"

class InventoryManager{
    private:
        Product products[20];
        int numProducts;
    public:
        void loadInventoryFromFile(const char* filename);
        void saveInventoryToFile(const char* filename);
        void displayInventory() const;
        void processPurchase(string name, int quantity);
        void restockItem(string name, int quantity);
};