#include "Header.h"
#include <string>

namespace Speed {

    // This *is* a bad practice, by the way!
    // What this "anonymous `namespace`" does, is that it
    // automatically runs some "initialization code" when
    // the program starts up.

    // Generally, you *should* write your own clean and clear
    // initialization function and call it in `main()`!:
    namespace {
        struct ForeverUnusedInitializerStruct {
            ForeverUnusedInitializerStruct() {
                Speed::reset();
            }

            ~ForeverUnusedInitializerStruct() {
                // print("Waaah!");
            }
        } foreverUnusedInstance;
    };


    const long ORIGINAL_WRITING_DELAY = 50;

    // This `static` limits these variables to this
    // "translation unit" (`.h` and `.cpp` combination.)

    /* static */ long LETTER, COMMA, FULLSTOP, EXCLAIM;

    void reset() {
        LETTER = ORIGINAL_WRITING_DELAY;
        COMMA = 4 * LETTER;
        FULLSTOP = 10 * LETTER;
        EXCLAIM = 6 * LETTER;
    }

    void setDelay(const long p_to) {
        LETTER = p_to;
        COMMA = p_to * 4.0f;
        FULLSTOP = p_to * 10.0f;
        EXCLAIM = p_to * 6.0f;
    }

}

void sleep(const long p_time) {
    std::this_thread::sleep_for(std::chrono::milliseconds(p_time));
}

// template <typename PrintElementT, typename... VarArgs>
// void write(const PrintElementT p_toPrint, const VarArgs... p_args) {
//     writeImpl(p_toPrint);
//     writeImpl(p_args...);
// }

template <typename PrintElementT>
void write(const PrintElementT& p_element) {
    writeWithoutLine(p_element);
    std::cout << std::endl;
}

template <typename PrintElementT>
void writeWithoutLine(const PrintElementT& p_element) {
    writeString(convertToString(p_element));
}

void writeString(const std::string& p_str) {
    char c;
    const unsigned int length = p_str.length();
    for (unsigned int i = 0; i < length; i++) {
        using namespace std;

        c = p_str.at(i);
        cout << c;
        cout.flush();

        using namespace Speed;

        // Sleep for some time, based on the character encountered:
        switch (c) {
        case ',':
            sleep(COMMA);
            break;
        case '.':
            sleep(FULLSTOP);
            break;
        case '!':
            sleep(EXCLAIM);
            break;
        default:
            sleep(LETTER);
        }
    }
}

template <typename PrintElementT>
void writeList(const std::initializer_list<PrintElementT> p_listItems) {
    unsigned long long counter = 1;

    for (auto const i : p_listItems) {
        std::cout << counter++ << ". ";
        write(i);
        sleep(Speed::FULLSTOP);
    }
}
