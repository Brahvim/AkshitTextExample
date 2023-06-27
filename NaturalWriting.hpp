#pragma once
#include <string>            // For `std::string`.
#include <iostream>          // For `std::cout`.
#include "CommonIncludes.hpp"

// `write()` overloads:
void write(const char*);

void write(const std::string&);

template <typename PrintElementT>
void write(const PrintElementT&);

void writeln(const char*);

void writeln(const std::string&);

template <typename PrintElementT>
void writeln(const PrintElementT&);

// `writeList()` overloads:
template <typename PrintElementT>
void writeList(const std::vector<PrintElementT>&);

template <typename PrintElementT>
void writeList(const std::initializer_list<PrintElementT>&);

namespace Speed {
    const long ORIGINAL_WRITING_DELAY = 50;

    // This `static` limits these variables to this
    // "translation unit" (`.h`/`.hpp` and `.cpp` combination.)

    /* static */ long LETTER, COMMA, FULLSTOP, EXCLAIM;

    void reset();
    void setDelay(const long);
};
