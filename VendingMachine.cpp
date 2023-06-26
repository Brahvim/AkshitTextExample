#include "Header.h"

// I'm an OOP-guy, ..sorry-not-sorry!
//  (I'm using this `namespace` like a `class`! 🤣)
namespace VendingMachine {

    const auto DRINKS_LIST = { "Water", "Cola", "Lemonade", "Brand New Milkshake" };

    void welcome() {
        write("Hiya! This is a vending machine!");
    }

    void promptForDrink() {
        write("Choose your drink!:");
        writeList(VendingMachine::DRINKS_LIST);
    }

    bool checkDrinkInput() {
        std::string chosenDrink;
        std::getline(std::cin, chosenDrink);
        // print("You chose", chosenDrink, '!'); // "Debug Laag".

        convertStringToLowerCase(chosenDrink);

        // I can think of so many ways to make this 
        // shorter and easier to edit, but *here we go!:*

        bool isAvailable;
        for (const std::string s : VendingMachine::DRINKS_LIST) {
            if (s == chosenDrink) {
                isAvailable = true;
                break;
            }
        }

        if (!isAvailable) {
            write("Sorry, we don't seem to have that with us. Did you makea typo? Mind trying again?");
            return false;
        }

        return true;
    }

    void sayGoodbye() {
        write("Here is your drink.");
        write("Thank you for using our vending machine!");
        write("Ba-bye, see you soon!");
    }



}