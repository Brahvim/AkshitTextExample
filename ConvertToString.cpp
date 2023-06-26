#include "Header.h"
#include <string>
#include <sstream>

// This took me HOURS to get placed. The compiler didn't understand where to refer to this from!:
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