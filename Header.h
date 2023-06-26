#pragma once

#include <stdio.h>
#include <chrono>
#include <thread>
#include <iostream>

// Using macros may seem convenient, but it's bad for this purpose, since
// I'll now have to include the required headers in each file.
// This increases the size of my program executable!
// Using the function, `sleep(const long)` as declared below, instead, saves us.
// #define SECONDS(p_time) std::chrono::seconds(p_time) // (p_time))
// #define MILLISECONDS(p_time) std::chrono::milliseconds(p_time) // ((p_time))
// #define MAIN_THREAD_SLEEP(p_time) std::this_thread::sleep_for(p_time) // ((p_time))

#pragma region // For `NaturalWriting.cpp`.
void sleep(const long); // Not passed by reference because `size_t` is larger than a `long`! Slow!

void writeString(const std::string& p_str);

template <typename PrintElementT>
void write(const PrintElementT & p_element);

template <typename PrintElementT>
void writeWithoutLine(const PrintElementT & p_element);

template <typename PrintElementT>
void writeList(const std::initializer_list<PrintElementT>);

namespace Speed {
    void reset();
    void setDelay(const long);
};
#pragma endregion

#pragma region // For `Utils.cpp`.
template <typename PrintElementT>
std::string inline convertToString(const PrintElementT& p_element);

template <typename PrintElementT>
void print(const PrintElementT);

template <typename PrintElementT, typename... VarArgs>
void print(const PrintElementT, const VarArgs...);

// template <typename PrintElementT>
// void print(const std::initializer_list<PrintElementT>);

template <typename PrintElementT>
void printList(const std::initializer_list<PrintElementT>);
#pragma endregion
