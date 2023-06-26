#include "Header.h"

// I'm an OOP-guy, ..sorry-not-sorry!
//  (I'm using this `namespace` like a `class`! 🤣)
namespace VendingMachine {

    const auto DRINKS_LIST_FORMATTED = { "Water", "Cola", "Lemonade", "Brand New Milkshake" },
        DRINKS_LIST_LOWERCASE = { "water", "cola", "lemonade", "brand new milkshake" };

    // C++ sucks. Forget this:
    // const auto DRINKS_LIST_LOWERCASE = convertToLowercase(VendingMachine::DRINKS_LIST_FORMATTED);

    void welcome() {
        write("Hiya! This is a vending machine!");
    }

    void promptForDrink() {
        write("Choose your drink!:");
        writeList(VendingMachine::DRINKS_LIST_FORMATTED);
    }

    bool checkDrinkInput() {
        std::string chosenDrink;
        std::getline(std::cin, chosenDrink);
        // print("You chose", chosenDrink, '!'); // "Debug Laag".

        // https://stackoverflow.com/q/313970/
        // This is bad, because using another language or encoding breaks it!
        // Better, use: https://stackoverflow.com/a/24063783/
        // std::transform(chosenDrink.begin(), chosenDrink.end(), chosenDrink.begin(),
        //     [](unsigned char c) { return std::tolower(c); }); // Nice use of lambdas here!

        convertToLowercase(chosenDrink);

        // I can think of so many ways to make this 
        // shorter and easier to edit, but *here we go!:*

        bool isAvailable;
        for (const std::string s : VendingMachine::DRINKS_LIST_LOWERCASE)
            if (s == chosenDrink) {
                isAvailable = true;
                chosenDrink = s;
                break;
            }

        if (!isAvailable) {
            write("Sorry, we don't seem to have that with us. Did you make a typo? Mind trying again?");
            return false;
        }

        writeWithoutLine("Here is your ");
        write(chosenDrink);
        return true;
    }

    void sayGoodbye() {
        write("Thank you for using our vending machine!");
        write("Ba-bye, see you soon!");
    }

}