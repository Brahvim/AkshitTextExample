#pragma once
#include <chrono>

#include "StringUtils.hpp"
#include "PrintUtils.hpp"
#include "NaturalWriting.hpp"

namespace VendingMachine {

    // Why is this commented code here? See `Main.cpp:70`! (*line* `70`!)

    // #include <map>
    // const std::map<std::string, std::string> DRINKS_NAME_LOWERCASE_MAP;

    const std::vector<std::string>
        DRINKS_LIST_FORMATTED = { "Water", "Cola", "Lemonade", "Brand New Milkshake" },
        DRINKS_LIST_LOWERCASE = convertCopyToLowercase(VendingMachine::DRINKS_LIST_FORMATTED);
    const int NUM_DRINKS = VendingMachine::DRINKS_LIST_FORMATTED.size();

    void welcome(void);

    void promptForDrink(void);

    bool checkDrinkInput(void);

    void sayGoodbye(void);

};
