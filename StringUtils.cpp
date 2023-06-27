#include <algorithm>
#include <sstream>
#include "StringUtils.hpp"

#pragma region // `convertToString(*)` definitions:
template <typename PrintElementT>
std::string convertToString(const PrintElementT& p_element) {
    return std::to_string(p_element);
}

template <typename PrintElementT>
std::vector<PrintElementT> convertToString(const std::vector<PrintElementT>& p_list) {
    std::vector<PrintElementT> result;
    for (const auto& element : p_list)
        result.push_back(std::to_string(element));
    return result;
}
#pragma endregion

#pragma region // `convertToLowerCase(*)` implementations / definitions.
std::string convertToLowercase(std::string& p_str) {
    // https://stackoverflow.com/q/313970/
    // This is bad, because using another language or encoding breaks it!
    // Better, use: https://stackoverflow.com/a/24063783/

    std::transform(p_str.begin(), p_str.end(), p_str.begin(),
        [](unsigned char c) { return std::tolower(c); }); // Nice use of lambdas here!

    return p_str;
}

std::initializer_list<const char*> convertToLowercase(std::initializer_list<const char*>& p_strList) {
    for (auto s : p_strList) {
        std::string str = std::string(s);
        convertToLowercase(str);
    }

    return p_strList;
}

// TODO: Make new vectors! Don't modify old ones!
std::vector<std::string>& convertToLowercase(std::vector<std::string>& p_strList) {
    for (std::string& s : p_strList)
        convertToLowercase(s);

    return p_strList;
}

std::initializer_list<std::string> convertToLowercase(
    std::initializer_list<std::string>& p_strList) {
    for (std::string s : p_strList)
        convertToLowercase(s);

    return p_strList;
}
#pragma endregion
