#pragma once
#include <chrono>

#include "StringUtils.hpp"
#include "PrintUtils.hpp"
#include "NaturalWriting.hpp"

namespace VendingMachine {

    std::vector<std::string>
        DRINKS_LIST_FORMATTED = { "Water", "Cola", "Lemonade", "Brand New Milkshake" },
        DRINKS_LIST_LOWERCASE = convertToLowercase(VendingMachine::DRINKS_LIST_FORMATTED);

    void welcome(void);

    void promptForDrink(void);

    bool checkDrinkInput(void);

    void sayGoodbye(void);

};
