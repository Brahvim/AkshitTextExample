#pragma once
#include <string>            // For `std::string`.
#include <iostream>          // For `std::cout`.
#include "CommonIncludes.hpp"

#pragma region // `write()` overloads.
void write(const char*);

void write(const std::string&);

template <typename PrintElementT>
void write(const PrintElementT&);

// template <typename PrintElementT, typename... VarArgs>
// void write(const PrintElementT p_toPrint, const VarArgs... p_args) {
//     writeImpl(p_toPrint);
//     writeImpl(p_args...);
// }
#pragma endregion

#pragma region // `writeln()` overloads.
void writeln(const char*);

void writeln(const std::string&);

template <typename PrintElementT>
void writeln(const PrintElementT&);
#pragma endregion

#pragma region // `writeList()` overloads.
// `std::vector<*>` overloads:
void writeList(const std::vector<const char*>&);

void writeList(const std::vector<std::string>&);

template <typename PrintElementT>
void writeList(const std::vector<PrintElementT>&);

// `std::initializer_list<*>` overloads:
void writeList(const std::initializer_list<const char*>&);

void writeList(const std::initializer_list<std::string>&);

template <typename PrintElementT>
void writeList(const std::initializer_list<PrintElementT>&);
#pragma endregion

namespace Speed {
#ifdef DEBUG
    const inline long ORIGINAL_WRITING_DELAY = 10;
#else
    const inline long ORIGINAL_WRITING_DELAY = 50;
#endif

    // This `static` limits these variables to this
    // "translation unit" (`.h`/`.hpp` and `.cpp` combination.)

    /* static */ inline long LETTER, COMMA, FULLSTOP, EXCLAIM;

    void reset(void);
    void setDelay(const long);
};
