#include "Header.h"

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

/*
int main(const int p_argCount, char const *p_arrArgValues[]) {
    Speed::reset();
    printf("Yo, I'm here simply waiting for you to press Enter.");
    std::cin.ignore();
    write("Hello, World!\a");
}

template <typename T>
void print(T p_toOutput) {
    std::cout << p_toOutput << '\n';
}
*/

// void sleep(const long p_time) {
//     std::this_thread::sleep_for(std::chrono::milliseconds(p_time));
// }

void write(const std::string p_str) {
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
            // sleep(COMMA);
            MAIN_THREAD_SLEEP(MILLISECONDS(COMMA));
            break;
        case '.':
            // sleep(FULLSTOP);
            MAIN_THREAD_SLEEP(MILLISECONDS(FULLSTOP));
            break;
        case '!':
            // sleep(EXCLAIM);
            MAIN_THREAD_SLEEP(MILLISECONDS(EXCLAIM));
            break;
        default:
            // sleep(LETTER);
            MAIN_THREAD_SLEEP(MILLISECONDS(LETTER));
        }
    }

    std::cout << '\n';
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