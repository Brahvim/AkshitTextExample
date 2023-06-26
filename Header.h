#include <stdio.h>
#include <chrono>
#include <thread>
#include <iostream>

#define SECONDS(p_time) std::chrono::seconds(p_time) // (p_time))
#define MILLISECONDS(p_time) std::chrono::milliseconds(p_time) // ((p_time))
#define MAIN_THREAD_SLEEP(p_time) std::this_thread::sleep_for(p_time) // ((p_time))

#pragma region // For `NaturalWriting.cpp`
// void sleep(const long);
void write(std::string);

template <typename PrintElementT>
void writeList(const std::initializer_list<PrintElementT>);

namespace Speed {
    void reset();
    void setDelay(const long);
};
#pragma endregion

#pragma region // For `Utils.cpp`
void convertStringToLowerCase(const std::string&);

template <typename PrintElementT>
void print(const PrintElementT);

template <typename PrintElementT, typename... VarArgs>
void print(const PrintElementT, const VarArgs...);

// template <typename PrintElementT>
// void print(const std::initializer_list<PrintElementT>);

template <typename PrintElementT>
void printList(const std::initializer_list<PrintElementT>);
#pragma endregion