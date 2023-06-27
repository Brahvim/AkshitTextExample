#include "Main.hpp"

int main(const int p_argCount, char const *p_argValues[]) {
    sleep(500);
    VendingMachine::welcome();
    VendingMachine::promptForDrink();
    VendingMachine::writeDrinksList(); // This *writes* them, one-bye-one.

    while (true) {
        if (VendingMachine::checkDrinkInput())
            break;

        VendingMachine::promptForDrink();
        VendingMachine::printDrinksList(); // This *prints* them out instantly!
    }

    // You may be wondering why I'm not calling `writeList()` or `printList()` directly.
    // This is a principle of good design - "abstraction"; hiding away functionality and
    // making it *seem to be easy to use* is a good way to design programs. This is because,
    // if we ever want to change what *actually **is** happening inside*, we won't have to write
    // *too much* code to do so. Changing what's happening inside the "abstract function" will do!

    VendingMachine::sayGoodbye();
    return 0;
}

// I'm an OOP-guy, ..sorry-not-sorry!
// (I'm using this `namespace` like a `class`! 🤣)

namespace VendingMachine {

    // Generally, you *should* write your own clean and clear
    // initialization function and call it in `main()`!:
    namespace {
        struct ForeverUnusedInitializerStruct {
            ForeverUnusedInitializerStruct(void) {

            }

            ~ForeverUnusedInitializerStruct(void) {
                // print("Waaah!");
            }
        } foreverUnusedInstance;
    };


    void welcome(void) {
        writeln("Hiya! This is a vending machine!");
    }

    void promptForDrink(void) {
        writeln("Choose your drink!:");
    }

    void writeDrinksList(void) {
        writeList(VendingMachine::DRINKS_LIST_FORMATTED);
    }

    void printDrinksList(void) {
        printList(VendingMachine::DRINKS_LIST_FORMATTED);
    }

    bool checkDrinkInput(void) {
        std::string chosenDrink;
        std::getline(std::cin, chosenDrink);
        convertToLowercase(chosenDrink); // Feel free to borrow/explore!

        bool isAvailable = false;
        for (int i = 0; i < VendingMachine::NUM_DRINKS; i++) {
            // Instead of doing this, I could've used an `std::map`.
            const std::string& s = VendingMachine::DRINKS_LIST_LOWERCASE.at(i);

            if (s == chosenDrink) {
                isAvailable = true;
                chosenDrink = VendingMachine::DRINKS_LIST_FORMATTED.at(i);
                break;
            }
        }

        if (!isAvailable) {
            writeln("Sorry, we don't seem to have that with us. Did you make a typo? Mind trying again?");
            return false;
        }

        write("Here is your ");
        write(chosenDrink);
        write(". Enjoy!");
        return true;
    }

    void sayGoodbye(void) {
        writeln("Thank you for using our vending machine!");
        writeln("Ba-bye, see you soon!");
    }

}
