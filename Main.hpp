#pragma once
#include <chrono>

#include "StringUtils.hpp"
#include "PrintUtils.hpp"
#include "NaturalWriting.hpp"

namespace VendingMachine {

    const std::vector<std::string>
        DRINK_NUMBERS = { "one", "two", "three", "four" },
        DRINKS_LIST_FORMATTED = { "Water", "Cola", "Lemonade", "Strawberry Milkshake" },
        DRINKS_LIST_LOWERCASE = StringUtils::convertCopyToLowercase(VendingMachine::DRINKS_LIST_FORMATTED);

    const int NUM_DRINKS = VendingMachine::DRINKS_LIST_FORMATTED.size();

    const std::vector<std::vector<std::string>> DRINKS_NAMES_TOKENS = []() {
        std::vector<std::vector<std::string>> toRet;
        toRet.reserve(VendingMachine::DRINKS_LIST_LOWERCASE.size());
        for (auto& s : VendingMachine::DRINKS_LIST_LOWERCASE)
            toRet.push_back(StringUtils::splitStringBySpaces(s));
        return toRet;
        }();

        void welcome(void);

        void promptForDrink(void);

        void writeDrinksList(void);

        void printDrinksList(void);

        int checkDrinkInput(void);

        int getDrinkFromNumberName(const std::string&);

        int getDrinkFromNumericalSymbol(std::string&, bool&);

        void serveDrink(const int);

        void reportIncorrectInput(void);

        void sayGoodbye(void);

};
