#include <map>
#include "Main.hpp"

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

    // You may be wondering why I'm not calling `NaturalWriter::writeList()` or `PrintUtils::printList()` directly.
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

    void welcome(void) {
        NaturalWriter::writeln("Hiya! This is a vending machine!");
    }

    void promptForDrink(void) {
        NaturalWriter::writeln("Choose your drink!:");
    }

    void writeDrinksList(void) {
        NaturalWriter::writeList(VendingMachine::DRINKS_LIST_FORMATTED);
    }

    void printDrinksList(void) {
        PrintUtils::printList(VendingMachine::DRINKS_LIST_FORMATTED);
    }

    int checkDrinkInput(void) {
        std::string input;
        std::getline(std::cin, input);

        // Was the drink ID passed in as number as a symbol? (`1`, `2`, et cetera)?
        int drinkId = VendingMachine::getDrinkFromNumericalSymbol(input);
        if (drinkId > 0)
            return drinkId;

        // Convert `input` to lowercase so we can easily compare it against other strings:
        StringUtils::convertToLowercase(input); // PS Feel free to borrow/explore this ("these") function[s]!

        // So! If that didn't work out, we continue to check the string for words-numbers!:
        // Was the drink ID passed in as number's name'? ("one", "two", et cetera)?
        drinkId = VendingMachine::getDrinkFromNumberName(input);
        // If it was a valid number-name, we return the ID it refers to!:
        if (drinkId > 0)
            return drinkId;

        // If that didn't work out, we continue to check the string for drink names!:
        // ...Now, we check it against each string in our list of drinks:

        std::map<int, int> drinkIdToMatchedTokensMap;
        std::vector<std::string> inputTokens = StringUtils::splitStringBySpaces(input);

        // Find how many tokens from the input match each drink's name's tokens:
        for (int i = 0; i < VendingMachine::NUM_DRINKS; i++) {
            int numMatchedTokens; // Get tokens in drink name:
            const std::vector<std::string> drinkTokens = VendingMachine::DRINKS_NAMES_TOKENS.at(i);

            // Match!:
            for (auto &drTok : drinkTokens) {
                numMatchedTokens = 0; // Re-initialize.

                for (auto &inTok : inputTokens)
                    if (inTok.find(drTok) != std::string::npos || drTok.find(inTok) != std::string::npos)
                        numMatchedTokens++;

                drinkIdToMatchedTokensMap[i] = numMatchedTokens; // Place value in the map.
            }
        }

        // Find the ID of the drink, most tokens of which match the input:
        int maxMatchedDrinkId = -1, maxMatches = 0;
        for (auto &e : drinkIdToMatchedTokensMap)
            if (e.second > maxMatches) {
                maxMatches = e.second;
                maxMatchedDrinkId = e.first;
            }

        return maxMatchedDrinkId;
    }

    int getDrinkFromNumberName(const std::string &p_input) {
        for (int i = 0; i < VendingMachine::NUM_DRINKS; i++)
            if (p_input == VendingMachine::DRINK_NUMBERS.at(i))
                return i; // Returning the drink's ID.
        // We DON'T subtract `1` because `std::vector`s this time, we're under the `std::vector`'s length!

        return -1; // Not a real drink ID, right?
    }

    // `static`, therefore not visible outside this `namespace`.
    // Takes the `std::string` as a "non-`const`" reference so it can be edited.
    int getDrinkFromNumericalSymbol(std::string &p_input) {
        try {
            // Try converting it to an `int`:
            const int drinkId = std::stoi(p_input);

            // If the drink number is wrong, we state we were unsuccessful:
            if (drinkId < 0 || drinkId > VendingMachine::NUM_DRINKS)
                return -1; // Not a real drink ID, right?

            return drinkId - 1; // Returning the drink's ID.
            // We subtract `1` because `std::vector`s are just arrays, and start at `0`.
            // The numbers the user is given are natural ones!
        } catch (const std::invalid_argument &e) {
            // If it can't be converted to a number using `std::stoi()`, return!
            return -1; // Not a real drink ID, right?
        } catch (const std::out_of_range &e) {
            // This exception is thrown by `std::vector::at` when we access an ID not in the vector,
            // and also by `std::stoi()` when the number is too large or small to be an `int`.
            // ...we just return in either case:
            return -1; // Not a real drink ID, right?
        }

        // If for some reason, something we don't know happens, we state we were unsuccessful:
        return -1; // Not a real drink ID, right?
    }

    void reportIncorrectInput(void) {
        NaturalWriter::writeln("Sorry, I didn't understand.");
        NaturalWriter::writeln("Do I even have that drink? Maybe not?");
        NaturalWriter::writeln("Could you please try again?");
    }

    void serveDrink(const int p_drinkId) {
        NaturalWriter::write("Here is your ");
        NaturalWriter::write(VendingMachine::DRINKS_LIST_FORMATTED.at(p_drinkId));
        NaturalWriter::writeln(". Enjoy!");
    }

    void sayGoodbye(void) {
        NaturalWriter::writeln("Thank you for using our vending machine!");
        NaturalWriter::writeln("Ba-bye, see you soon!");
    }

}
