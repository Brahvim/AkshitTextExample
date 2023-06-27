#include "Main.hpp"

int main(const int p_argCount, char const *p_argValues[]) {
    sleep(500);
    VendingMachine::welcome();

prompt:
    VendingMachine::promptForDrink();

    bool success = VendingMachine::checkDrinkInput();

    // Using `goto` is a bad practice! ..but only if you use it everywhere and mess up.
    // Use it ONLY when *you are absolutely sure* it will have long-term benefits!
    // This program is small and has an almost linear, procedural flow,
    // so I see using `goto` as forever-beneficial and never bad:

    if (!success)
        goto prompt;

    VendingMachine::sayGoodbye();
    return 0;
}

// I'm an OOP-guy, ..sorry-not-sorry!
// (I'm using this `namespace` like a `class`! 🤣)


namespace VendingMachine {

    void welcome() {
        writeln("Hiya! This is a vending machine!");
    }

    void promptForDrink() {
        writeln("Choose your drink!:");
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
            writeln("Sorry, we don't seem to have that with us. Did you make a typo? Mind trying again?");
            return false;
        }

        write("Here is your ");
        writeln(chosenDrink);
        return true;
    }

    void sayGoodbye() {
        writeln("Thank you for using our vending machine!");
        writeln("Ba-bye, see you soon!");
    }

}
