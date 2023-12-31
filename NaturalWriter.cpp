#include "NaturalWriter.hpp"

void millisSleep(const unsigned long long p_time) { std::this_thread::sleep_for(std::chrono::milliseconds(p_time)); }

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
        const struct ForeverUnusedInitializerStruct {
            ForeverUnusedInitializerStruct(void) {
                Speeds::reset();
            }

            // ~ForeverUnusedInitializerStruct(void) {
            //     PrintUtils::print("Waaah!");
            // }
        } foreverUnusedInstance;
    };

    void reset(void) {
        Speeds::setSpeeds(Speeds::DEFAULT_SPEEDS_FACTOR);
    }

    void setSpeeds(const size_t p_to) {
        Speeds::LETTER = p_to;
        Speeds::COMMA = p_to * 4;
        Speeds::FULLSTOP = p_to * 10;
        Speeds::QUESTION = Speeds::EXCLAIM = p_to * 6;
    }

}

// `static` makes sure nobody outside this file can sue this function!:
template <typename PrintElementT>
static void writeListLoopImpl(const PrintElementT &p_element, const size_t p_counter) {
    std::cout << p_counter << ". ";
    NaturalWriter::writeln(p_element);
    millisSleep(Speeds::FULLSTOP);
}

namespace NaturalWriter {
#pragma region // `WriteUtils::write()` overloads.
    void write(const char *p_str) {
        NaturalWriter::write(std::string(p_str));
    }

    void write(const std::string &p_str) {
        // Current `char` of the string :>
        char c;

        // Previous character in the string.
        int p = INT32_MIN;

        // `int` because, ..if it was a `char`, there would be a chance,
        // that the random value it got due to remaining un-initialized
        // could interfere with the `switch` below!
        // Therefore, I initialize it with a custom value that I know 
        // the `switch` does not check for, in this manner.

        const size_t length = p_str.length();
        for (unsigned int i = 0; i < length; i++) {
            c = p_str.at(i);
            std::cout << c;
            std::cout.flush();

            // Sleep for some time, based on the character encountered:
            switch (c) {
                case ',':
                millisSleep(Speeds::COMMA);
                break;

                case '.':
                millisSleep(Speeds::FULLSTOP);
                break;

                case '\n': // If we're writing on a new line after finishing a sentence, why wait more?!
                if (p != '.')
                    millisSleep(Speeds::FULLSTOP);
                break;

                case '!':
                millisSleep(Speeds::EXCLAIM);
                break;

                case '?':
                millisSleep(Speeds::QUESTION);
                break;

                default:
                millisSleep(Speeds::LETTER);
            }

            p = c;
        }
    }

    template <typename PrintElementT>
    void write(const PrintElementT &p_element) {
        NaturalWriter::write(convertToString(p_element));
    }
#pragma endregion

#pragma region // `writeln()` overloads.
    void writeln(const char *p_str) {
        NaturalWriter::write(std::string(p_str));
        std::cout << std::endl;
    }

    void writeln(const std::string &p_str) {
        NaturalWriter::write(p_str);
        std::cout << std::endl;
    }

    template <typename PrintElementT>
    void writeln(const PrintElementT &p_element) {
        NaturalWriter::write(convertToString(p_element));
        std::cout << std::endl;
    }
#pragma endregion

#pragma region // `writeList()` overloads.
#pragma region // `writeList(const std::vector<*>)` overloads.
    void writeList(const std::vector<const char *> &p_strList) {
        size_t counter = 0;

        for (auto const i : p_strList)
            writeListLoopImpl(i, ++counter);
    }

    void writeList(const std::vector<std::string> &p_strList) {
        unsigned long long counter = 0;

        for (auto &i : p_strList)
            writeListLoopImpl(i, ++counter);
    }

    template <typename PrintElementT>
    void writeList(const std::vector<PrintElementT> &p_list) {
        unsigned long long counter = 0;

        for (auto const i : p_list)
            writeListLoopImpl(i, ++counter);
    }
#pragma endregion

#pragma region // `writeList(const std::initializer_list<*>)` overloads.
    void writeList(const std::initializer_list<const char *> &p_strList) {
        unsigned long long counter = 0;

        for (auto const i : p_strList)
            writeListLoopImpl(i, ++counter);
    }

    void writeList(const std::initializer_list<std::string> &p_strList) {
        unsigned long long counter = 0;

        for (auto &i : p_strList)
            writeListLoopImpl(i, ++counter);
    }

    template <typename PrintElementT>
    void writeList(const std::initializer_list<PrintElementT> &p_list) {
        unsigned long long counter = 0;

        for (auto const i : p_list)
            writeListLoopImpl(i, ++counter);
    }
#pragma endregion
#pragma endregion
}
