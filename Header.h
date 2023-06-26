#pragma once

#include <algorithm>
#include <chrono>
#include <string>
#include <thread>
#include <stdio.h>
#include <sstream>
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
void print(const PrintElementT);

template <typename PrintElementT>
void print(const PrintElementT);

template <typename PrintElementT, typename... VarArgs>
void print(const PrintElementT, const VarArgs...);

// template <typename PrintElementT>
// void print(const std::initializer_list<PrintElementT>);

template <typename PrintElementT>
void printList(const std::initializer_list<PrintElementT>);
#pragma endregion

// Compiler problems forced me to do this...
// This took me HOURS to get placed. The compiler didn't understand where to refer to this from!:
// Templated function problems, haha.
template <typename PrintElementT>
std::string inline convertToString(const PrintElementT& p_element) {
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

std::string convertToLowercase(const std::string& p_str);

/**
 * @param p_str the string.
 * @return the same string. Feel free to ignore this return value!
 */
std::string inline convertToLowercase(std::string& p_str) {
    // https://stackoverflow.com/q/313970/
    // This is bad, because using another language or encoding breaks it!
    // Better, use: https://stackoverflow.com/a/24063783/
    std::transform(p_str.begin(), p_str.end(), p_str.begin(),
        [](unsigned char c) { return std::tolower(c); }); // Nice use of lambdas here!
    return p_str;
}

std::initializer_list<std::string> convertToLowercase(std::initializer_list<std::string>&);

std::initializer_list<const char*> inline convertToLowercase(
    const std::initializer_list<const char*>& p_strList) {
    for (auto s : p_strList)
        convertToLowercase(s);

    return p_strList;
}

std::initializer_list<std::string> inline convertToLowercase(
    std::initializer_list<std::string>& p_strList) {
    for (std::string s : p_strList)
        convertToLowercase(s);

    return p_strList;
}
