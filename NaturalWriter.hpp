#pragma once
#include <string>            // For `std::string`.
#include <chrono>            // For `std::chrono`.
#include <thread>            // For `std::this_thread`.
#include <iostream>          // For `std::cout`.
#include "CommonIncludes.hpp"

void sleep(const long p_time); // Not passed by reference because `size_t` is larger than a `long`! Slow!

namespace NaturalWriter {
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
}

namespace Speeds {

    // `inline` makes sure these are never re-defined.
    // Saves us from random linker errors!!1!1!!
    const inline unsigned long DEFAULT_SPEEDS = 50L;

    // This `static` limits these variables to this
    // "translation unit" (`.h`/`.hpp` and `.cpp` combination.)

    /* static */ inline long LETTER = 0, COMMA = 0, FULLSTOP = 0, EXCLAIM = 0, QUESTION = 0;

    void reset(void);
    void setSpeeds(const unsigned long);

};
