#include <algorithm>
#include <sstream>
#include <iostream>
#include "StringUtils.hpp"

namespace StringUtils {

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

#pragma region // `convertToLowercase(*)` implementations / definitions.
    std::string convertToLowercase(std::string& p_str) {
        // https://stackoverflow.com/q/313970/
        // This is bad, because using another language or encoding breaks it!
        // Better, use: https://stackoverflow.com/a/24063783/

        std::transform(p_str.begin(), p_str.end(), p_str.begin(),
            [](unsigned char c) { return std::tolower(c); }); // Nice use of lambdas here!

        return p_str;
    }

    std::vector<std::string>& convertToLowercase(std::vector<std::string>& p_strList) {
        for (std::string &s : p_strList) // Pass the `std::string` by reference.
            convertToLowercase(s);

        // New C++ feature :O
        return const_cast<std::vector<std::string>&>(p_strList);
    }

    std::vector<std::string> convertCopyToLowercase(const std::vector<std::string>& p_strList) {
        auto toRet = std::vector<std::string>{}; // Create a new `std::vector` to hold the `std::string`s.
        toRet.reserve(p_strList.size()); // Reserve memory. #SpeedFtw!

        for (std::string s : p_strList) // Send a copy of the `std::string`.
            toRet.push_back(convertToLowercase(s));

        return toRet;
    }
#pragma endregion

    std::vector<std::string> splitStringBySpaces(const std::string& p_str) {
        std::vector<std::string> toRet; // Contains our tokens.
        std::istringstream stringsInputStream(p_str); // Takes the strings
        std::string token; // Holds the current token.

        while (std::getline(stringsInputStream, token, ' '))
            toRet.push_back(token);

        return toRet;
    }

    std::vector<std::string> splitStringByChar(const std::string& p_str, const char p_delimiter) {
        std::vector<std::string> toRet; // Contains our tokens.
        std::istringstream stringsInputStream(p_str); // Takes the strings
        std::string token;

        while (std::getline(stringsInputStream, token, p_delimiter))
            toRet.push_back(token);

        return toRet;
    }

}
