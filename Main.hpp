#pragma once

#include <algorithm>
#include <chrono>
#include <string>
#include <stdio.h>
#include <sstream>

#pragma region  // Other files to include.
#include "Utils.hpp"
#include "NaturalWriting.hpp"
#pragma endregion

// This took me HOURS to get placed. The compiler didn't understand where to refer to this from!
// Compiler problems forced me to do this...
// Templated function problems, haha:
template <typename PrintElementT>
std::string convertToString(const PrintElementT&);

template <typename PrintElementT>
std::string convertToString(const PrintElementT& p_element) {
    // Original code:
    std::stringstream stream;
    stream << p_element;
    return stream.str();

    // Shorter version:
    // std::stringstream stream;
    // return (stream << p_element).str();

    // Shortest! (Broken!!!):
    // return std::stringstream{} << p_element;
}

#pragma region // `convertToLowercase()` overloads:
std::string convertToLowercase(std::string& p_str);
std::vector<std::string>& convertToLowercase(std::vector<std::string>&);
std::initializer_list<std::string> convertToLowercase(std::initializer_list<std::string>&);
std::initializer_list<const char*> convertToLowercase(const std::initializer_list<const char*>& p_strList);

// Compiler problems forced me to do this...
// Definitions in headers make no sense!:
#pragma region // `convertToLowerCase(*)` Implementations / Definitions.
std::string convertToLowercase(std::string& p_str) {
    // https://stackoverflow.com/q/313970/
    // This is bad, because using another language or encoding breaks it!
    // Better, use: https://stackoverflow.com/a/24063783/
    std::transform(p_str.begin(), p_str.end(), p_str.begin(),
        [](unsigned char c) { return std::tolower(c); }); // Nice use of lambdas here!
    return p_str;
}

std::initializer_list<const char*> convertToLowercase(
    const std::initializer_list<const char*>& p_strList) {
    for (auto s : p_strList) {
        std::string str = std::string(s);
        convertToLowercase(str);
    }

    return p_strList;
}

std::vector<std::string>& convertToLowercase(std::vector<std::string>& p_strList) {
    for (std::string& s : p_strList)
        convertToLowercase(s);

    return p_strList;
}

std::initializer_list<std::string> convertToLowercase(
    const std::initializer_list<std::string>& p_strList) {
    for (std::string s : p_strList)
        convertToLowercase(s);

    return p_strList;
}
#pragma endregion
#pragma endregion

namespace VendingMachine {

    const std::vector<std::string>
        DRINKS_LIST_FORMATTED = { "Water", "Cola", "Lemonade", "Brand New Milkshake" },
        DRINKS_LIST_LOWERCASE = { "water", "cola", "lemonade", "brand new milkshake" };
    // DRINKS_LIST_LOWERCASE = convertToLowercase(VendingMachine::DRINKS_LIST_FORMATTED);

    // C++ sucks. Forget this:
    // const auto DRINKS_LIST_LOWERCASE = convertToLowercase(VendingMachine::DRINKS_LIST_FORMATTED);

    void welcome();
    void promptForDrink();
    bool checkDrinkInput();
    void sayGoodbye();

};
