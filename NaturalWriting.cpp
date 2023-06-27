#include "NaturalWriting.hpp"

extern void sleep(const long);

// Bad naming alert!
// Generally, if you have an `enum`, or something like one, you never name it in plural!
// I'm doing it this time because I can, haha!

namespace Speeds {

    // This *is* a bad practice, by the way!
    // What this "anonymous `namespace`" does, is that it
    // automatically runs some "initialization code" when
    // the program starts up.

    // Generally, you *should* write your own clean and clear
    // initialization function and call it in `main()`!:
    namespace {
        struct ForeverUnusedInitializerStruct {
            ForeverUnusedInitializerStruct(void) {
                Speeds::reset();
            }

            ~ForeverUnusedInitializerStruct(void) {
                // print("Waaah!");
            }
        } foreverUnusedInstance;
    };

    void reset(void) {
        Speeds::setSpeeds(Speeds::DEFAULT_SPEEDS);
    }

    void setSpeeds(const unsigned long p_to) {
        Speeds::LETTER = p_to;
        Speeds::COMMA = p_to * 4;
        Speeds::FULLSTOP = p_to * 10;
        Speeds::QUESTION = Speeds::EXCLAIM = p_to * 6;
    }

}

#pragma region // `write()` overloads.
void write(const char * p_str) {
    write(std::string(p_str));
}

void write(const std::string& p_str) {
    // Current `char` of the string :>
    char c;

    // Previous character in the string.
    int p = INT32_MIN;

    // `int` because, ..if it was a `char`, there would be a chance,
    // that the random value it got due to remaining un-initialized
    // could interfere with the `switch` below!
    // Therefore, I initialize it with a custom value that I know 
    // the `switch` does not check for, in this manner.

    const unsigned int length = p_str.length();
    for (unsigned int i = 0; i < length; i++) {
        using namespace std;

        c = p_str.at(i);
        cout << c;
        cout.flush();

        using namespace Speeds;

        // Sleep for some time, based on the character encountered:
        switch (c) {
        case ',':
            sleep(Speeds::COMMA);
            break;

        case '.':
            sleep(Speeds::FULLSTOP);
            break;

        case '\n': // If we're writing on a new line after finishing a sentence, why wait more?!
            if (p != '.')
                sleep(Speeds::FULLSTOP);
            break;

        case '!':
            sleep(Speeds::EXCLAIM);
            break;

        case '?':
            sleep(Speeds::QUESTION);
            break;

        default:
            sleep(Speeds::LETTER);
        }

        p = c;
    }
}

template <typename PrintElementT>
void write(const PrintElementT& p_element) {
    write(convertToString(p_element));
}
#pragma endregion

#pragma region // `writeln()` overloads.
void writeln(const char * p_str) {
    write(std::string(p_str));
    std::cout << std::endl;
}

void writeln(const std::string& p_str) {
    write(p_str);
    std::cout << std::endl;
}

template <typename PrintElementT>
void writeln(const PrintElementT& p_element) {
    write(convertToString(p_element));
    std::cout << std::endl;
}
#pragma endregion

#pragma region // `writeList()` overloads.
// `static` makes sure nobody outside this file can sue this function!:
template <typename PrintElementT>
static void writeListLoopImpl(const PrintElementT& p_element, const int p_counter) {
    std::cout << p_counter << ". ";
    writeln(p_element);
    sleep(Speeds::FULLSTOP);
}

#pragma region // `writeList(const std::vector<*>)` overloads.
void writeList(const std::vector<const char*>& p_strList) {
    unsigned long long counter = 0;

    for (auto const i : p_strList)
        writeListLoopImpl(i, ++counter);
}

void writeList(const std::vector<std::string>& p_strList) {
    unsigned long long counter = 0;

    for (auto const i : p_strList)
        writeListLoopImpl(i, ++counter);
}

template <typename PrintElementT>
void writeList(const std::vector<PrintElementT>& p_list) {
    unsigned long long counter = 0;

    for (auto const i : p_list)
        writeListLoopImpl(i, ++counter);
}
#pragma endregion

#pragma region // `writeList(const std::initializer_list<*>)` overloads.
void writeList(const std::initializer_list<const char*>&p_strList) {
    unsigned long long counter = 0;

    for (auto const i : p_strList)
        writeListLoopImpl(i, ++counter);
}

void writeList(const std::initializer_list<std::string>&p_strList) {
    unsigned long long counter = 0;

    for (auto const i : p_strList)
        writeListLoopImpl(i, ++counter);
}

template <typename PrintElementT>
void writeList(const std::initializer_list<PrintElementT>&p_list) {
    unsigned long long counter = 0;

    for (auto const i : p_list)
        writeListLoopImpl(i, ++counter);
}

#pragma endregion
#pragma endregion
