#pragma once
#include <thread>            // For `std::thread`.
#include <cstdint>           // For `long`s.
#include "CommonIncludes.hpp"

void sleep(const long); // Not passed by reference because `size_t` is larger than a `long`! Slow!

// Idea to use "variable number of arguments" from: https://stackoverflow.com/a/16338804/

// `print()` overloads:
template <typename PrintElementT>
void print(const PrintElementT&);

template <typename PrintElementT>
void print(const std::vector<PrintElementT>&);

template <typename PrintElementT, typename... VarArgs>
void print(const PrintElementT, const VarArgs...);

template <typename PrintElementT>
void print(const std::initializer_list<PrintElementT>&);

// Could use recursion here, but I ain't got time for dealing with that mess!
// Better use an `std::vector` or `std::initializer_list`!
// And so, we have these `printList()` overloads:
template <typename PrintElementT>
void printList(const std::vector<PrintElementT>&);

template <typename PrintElementT>
void printList(const std::initializer_list<PrintElementT>&);
