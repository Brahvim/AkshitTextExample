#include "Header.h"
#include "NaturalWriting.cpp"
#include "VendingMachine.cpp"

int main(const int p_argCount, char const *p_argValues[]) {
    // MAIN_THREAD_SLEEP(MILLISECONDS(500));
    sleep(500);
    VendingMachine::welcome();

prompt:
    VendingMachine::promptForDrink();

    bool success = VendingMachine::checkDrinkInput();

    // Using `goto` is a bad practice! ..but only if you use it everywhere and mess up.
    // Use it ONLY when *you are absolutely sure* it will have long-term benefits!
    // This program is small and has an almost linear, procedural flow,
    // so I see using `goto` as forever-beneficial and never bad:

    if (!success)
        goto prompt;

    VendingMachine::sayGoodbye();

    return 0;
}
