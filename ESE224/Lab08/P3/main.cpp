#include "GameInventory.h"
#include <iostream>
#include <string>

int main() {
    // Create GameInventory instances for weapons and potions
    GameInventory<int> weaponInventory;
    GameInventory<double> potionInventory;

    int choice;
    do {
        std::cout << "\nGame Inventory Management System\n";
        std::cout << "=================================\n";
        std::cout << "1. Add a weapon\n";
        std::cout << "2. Add a potion\n";
        std::cout << "3. Display inventory\n";
        std::cout << "4. Retrieve most recent item\n";
        std::cout << "5. Show total inventory value\n";
        std::cout << "6. Show average item attribute\n";
        std::cout << "7. Clear inventory\n";
        std::cout << "8. Exit\n";
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
        case 3: {
            std::cout << "\nWeapons Inventory:\n";
            weaponInventory.displayInventory();
            std::cout << "\nPotions Inventory:\n";
            potionInventory.displayInventory();
            break;
        }
        case 4: {
            std::cout << "\nMost Recent Weapon:\n";
            weaponInventory.retrieveMostRecentItem();
            std::cout << "\nMost Recent Potion:\n";
            potionInventory.retrieveMostRecentItem();
            break;
        }
        case 5: {
            std::cout << "\nWeapon Inventory:\n";
            weaponInventory.totalInventoryValue();
            std::cout << "\nPotion Inventory:\n";
            potionInventory.totalInventoryValue();
            break;
        }
        case 6: {
            std::cout << "\nWeapon Inventory:\n";
            weaponInventory.averageItemAttribute();
            std::cout << "\nPotion Inventory:\n";
            potionInventory.averageItemAttribute();
            break;
        }
        case 7: {
            std::cout << "\nClearing weapon inventory...\n";
            weaponInventory.clear();
            std::cout << "Clearing potion inventory...\n";
            potionInventory.clear();
            break;
        }
        case 8:
            std::cout << "Exiting Game Inventory Management System.\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}
