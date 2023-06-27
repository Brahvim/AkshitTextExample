#include "Main.hpp"
#define DEBUG // Makes text go brrrrr!

int main(const int p_argCount, char const *p_argValues[]) {
    sleep(500);
    VendingMachine::welcome();
    VendingMachine::promptForDrink();
    VendingMachine::writeDrinksList(); // This *writes* them, one-bye-one.

    int chosenDrinkId; // Declaring this here, because that makes the code faster!
    while (true) {
        // If `VendingMachine::checkDrinkInput()` does not return `-1`, we serve the drink and stop!
        if ((chosenDrinkId = VendingMachine::checkDrinkInput()) != -1) {
            VendingMachine::serveDrink(chosenDrinkId);
            break;
        }

        // Otherwise, we keep asking the user what they want:
        VendingMachine::reportIncorrectInput();
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
        writeList(VendingMachine::DRINK_NUMBERS);
    }

    void printDrinksList(void) {
        printList(VendingMachine::DRINK_NUMBERS);
    }

    int checkDrinkInput(void) {
        std::string input;
        std::getline(std::cin, input);

        bool isNumber = false;
        int drinkId = VendingMachine::getDrinkFromNumericalSymbol(input, isNumber); // Was the drink ID passed in?
        if (isNumber)
            return drinkId;

        // If that didn't work out, we continue to check the string!:

        // Convert `input` to lowercase so we can easily compare it against other strings:
        convertToLowercase(input); // PS Feel free to borrow/explore this ("these") function[s]!

        // ...Now, we check it against each string in our list of drinks:
        for (int i = 0; i < VendingMachine::NUM_DRINKS; i++)
            if (VendingMachine::DRINKS_LIST_LOWERCASE.at(i) == input)
                return i; // If one of the names is exactly what the user entered, we return its ID.

        // ...Else we just report that the user wants a drink we don't have. Sad.
        return -1;
    }

    // `static`, therefore not visible outside this `namespace`.
    // Takes the `std::string` as a "non-`const`" reference so it can be edited.
    int getDrinkFromNumericalSymbol(std::string& p_input, bool& p_isNumber) {
        try {
            // Try converting it to an `int`:
            const int drinkId = std::stoi(p_input);
            p_isNumber = true; // If that didn't throw an exception, we state that the input was an `int`!

            // If the drink number is wrong, we state we were unsucessful:
            if (drinkId < 0 || drinkId > VendingMachine::NUM_DRINKS)
                return -1; // Not a real drink ID, right?

            // Return the drink's ID:
            return drinkId - 1;
            // We subtract `1` because `std::vector`s are just arrays, and start at `0`.
            // The numbers the user is given are natural ones!
        }
        catch (const std::invalid_argument& e) {
            // If it can't be converted to a number using `std::stoi()`, return!
            p_isNumber = false;
            return -1; // Not a real drink ID, right?
        }
        catch (const std::out_of_range& e) {
            // This exception is thrown by `std::vector::at` when we access an ID not in the vector,
            // and also by `std::stoi()` when the number is too large or small to be an `int`.
            // ...we just return in either case:
            p_isNumber = false;
            return -1; // Not a real drink ID, right?
        }

        // If for some reason, something we don't know happens, we state we were unsuccessful:
        p_isNumber = false;
        return -1; // Not a real drink ID, right?
    }

    void reportIncorrectInput(void) {
        writeln("Sorry, it looks like that I don't have that drink. Did you make a typo? Mind trying again?");
    }

    void serveDrink(const int p_drinkId) {
        write("Here is your ");
        write(VendingMachine::DRINK_NUMBERS.at(p_drinkId));
        writeln(". Enjoy!");
    }

    void sayGoodbye(void) {
        writeln("Thank you for using our vending machine!");
        writeln("Ba-bye, see you soon!");
    }

}
