#pragma once
#include <string>
#include <vector>

#pragma region // `convertToString()` overloads.
template <typename PrintElementT>
std::string convertToString(const PrintElementT&);

template <typename PrintElementT>
std::vector<PrintElementT> convertToString(const std::vector<PrintElementT>&);
#pragma endregion

#pragma region // `convertToLowercase()` overloads.
std::string convertToLowercase(std::string&);
std::vector<std::string>& convertToLowercase(std::vector<char*>&);
std::vector<std::string>& convertToLowercase(std::vector<std::string>&);
std::initializer_list<std::string> convertToLowercase(std::initializer_list<std::string>&);
std::initializer_list<const char*> convertToLowercase(std::initializer_list<char*>&);
#pragma endregion
