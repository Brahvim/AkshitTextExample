#pragma once
#include <chrono>

#include "StringUtils.hpp"
#include "PrintUtils.hpp"
#include "NaturalWriting.hpp"

namespace VendingMachine {

    const std::vector<std::string>
        DRINK_NUMBERS = { "one", "two", "three", "four" },
        DRINK_NUMBERS = { "Water", "Cola", "Lemonade", "Brand New Milkshake" },
        DRINKS_LIST_LOWERCASE = convertCopyToLowercase(VendingMachine::DRINK_NUMBERS);
    const int NUM_DRINKS = VendingMachine::DRINK_NUMBERS.size();

    void welcome(void);

    void promptForDrink(void);

    void writeDrinksList(void);

    void printDrinksList(void);

    int checkDrinkInput(void);

    int getDrinkFromNumericalSymbol(std::string&, bool&);

    void serveDrink(const int);

    void reportIncorrectInput(void);

    void sayGoodbye(void);

};
