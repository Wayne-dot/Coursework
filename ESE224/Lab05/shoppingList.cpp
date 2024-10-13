
#include "shoppingList.h"
#include <istream>

ShoppingList::ShoppingList(){

}

bool ShoppingList::fileOpen(istream& in){
    if(!in){
        return false;
    }
    return true;
}

void ShoppingList::printAll(){
    
}