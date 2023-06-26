#include "Header.h"
#include <cctype>
#include <algorithm>

// https://stackoverflow.com/q/313970/
// This is bad, because using another language or encoding breaks it!
// Better, use: https://stackoverflow.com/a/24063783/

void convertStringToLowerCase(const std::string& p_str) { // Passing by reference, unlike Java.
    std::transform(
        p_str.begin(), p_str.end(), p_str.begin(),
        [](unsigned char c) { return std::tolower(c); }); // Nice use of lambdas here!
}

template <typename PrintElementT>
void print(const PrintElementT p_toPrint) {
    std::cout << p_toPrint << '\n';
}

// These functions require using "set notation" AKA "set syntax", id est, this!:
// `printList({ "A", "B" });` (Notice the `{ }`!)

#pragma region // Functions using `std::intializer_list`.
// template <typename PrintElementT>
// void print(const std::initializer_list<PrintElementT> p_listItems) {
//     for (auto const i : p_listItems)
//         std::cout << p_toPrint << '\n';
// }
#pragma endregion

// Idea to use "variable number of arguments" from: https://stackoverflow.com/a/16338804/

template <typename PrintElementT, typename... VarArgs>
void print(const PrintElementT p_toPrint, const VarArgs... p_args) {
    std::cout << p_toPrint << '\n';
    print(p_args...);
}

// Could use recursion here, but I ain't got time for dealing with that mess!
// Better use an `std::initializer_list`!:
template <typename PrintElementT>
void printList(const std::initializer_list<PrintElementT> p_listItems) {
    unsigned long long counter = 1;

    for (auto const i : p_listItems)
        std::cout << counter++ << ". " << i << '\n';
}
