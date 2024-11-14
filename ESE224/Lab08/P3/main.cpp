#include "GameInventory.h"
#include <iostream>
#include <string>

int main() {
    // Create GameInventory instances for int (weapon power) and double (potion healing)
    GameInventory<int> weaponInventory;
    GameInventory<double> potionInventory;

    int choice;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add Weapon\n";
        std::cout << "2. Add Potion\n";
        std::cout << "3. Display Weapon Inventory\n";
        std::cout << "4. Display Potion Inventory\n";
        std::cout << "5. Remove Most Recent Weapon\n";
        std::cout << "6. Remove Most Recent Potion\n";
        std::cout << "7. Total Value of Weapon Inventory\n";
        std::cout << "8. Total Value of Potion Inventory\n";
        std::cout << "9. Average Weapon Power\n";
        std::cout << "10. Average Potion Healing\n";
        std::cout << "11. Clear All Weapons\n";
        std::cout << "12. Clear All Potions\n";
        std::cout << "13. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string name;
            int power;
            double value;
            std::cout << "Enter weapon name: ";
            std::cin >> name;
            std::cout << "Enter weapon power: ";
            std::cin >> power;
            std::cout << "Enter weapon value: ";
            std::cin >> value;
            weaponInventory.addItem(name, power, value);
            break;
        }
        case 2: {
            std::string name;
            double healing, value;
            std::cout << "Enter potion name: ";
            std::cin >> name;
            std::cout << "Enter potion healing amount: ";
            std::cin >> healing;
            std::cout << "Enter potion value: ";
            std::cin >> value;
            potionInventory.addItem(name, healing, value);
            break;
        }
        case 3:
            weaponInventory.displayInventory();
            break;
        case 4:
            potionInventory.displayInventory();
            break;
        case 5:
            weaponInventory.removeMostRecentItem();
            break;
        case 6:
            potionInventory.removeMostRecentItem();
            break;
        case 7:
            weaponInventory.totalValue();
            break;
        case 8:
            potionInventory.totalValue();
            break;
        case 9:
            weaponInventory.averageAttribute();
            break;
        case 10:
            potionInventory.averageAttribute();
            break;
        case 11:
            weaponInventory.clear();
            break;
        case 12:
            potionInventory.clear();
            break;
        case 13:
            std::cout << "Exiting program.\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 13);

    return 0;
}
