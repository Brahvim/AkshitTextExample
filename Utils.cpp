#include "Header.h"
#include <string>
#include <sstream>

// This took me HOURS to get placed. The compiler didn't understand where to refer to this from!:
template <typename PrintElementT>
std::string inline convertToString(const PrintElementT& p_element) {
    // Original code:
    // std::stringstream stream;
    // stream << p_element;
    // return stream.str();

    // Shorter version:
    // std::stringstream stream;
    // return (stream << p_element).str();

    // Shortest! (Broken!!!):
    return std::stringstream{} << p_element;
}

template <typename PrintElementT>
void inline print(const PrintElementT p_toPrint) {
    std::cout << p_toPrint << std::endl;
}

// These functions require using "set notation" AKA "set syntax", id est, this!:
// `printList({ "A", "B" });` (Notice the `{ }`!)

#pragma region // Functions using `std::intializer_list`.
// template <typename PrintElementT>
// void print(const std::initializer_list<PrintElementT> p_listItems) {
//     for (auto const i : p_listItems)
//         std::cout << p_toPrint << std::endl;
// }
#pragma endregion

// Idea to use "variable number of arguments" from: https://stackoverflow.com/a/16338804/

template <typename PrintElementT, typename... VarArgs>
void inline print(const PrintElementT p_toPrint, const VarArgs... p_args) {
    std::cout << p_toPrint << std::endl;
    print(p_args...);
}

// Could use recursion here, but I ain't got time for dealing with that mess!
// Better use an `std::initializer_list`!:
template <typename PrintElementT>
void inline printList(const std::initializer_list<PrintElementT> p_listItems) {
    unsigned long long counter = 1;

    for (auto const i : p_listItems)
        std::cout << counter++ << ". " << i << std::endl;
}
