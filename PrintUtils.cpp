#include "PrintUtils.hpp"

namespace PrintUtils {

    template <typename PrintElementT>
    void print(const PrintElementT& p_toPrint) {
        std::cout << p_toPrint << std::endl;
    }

    template <typename PrintElementT>
    void print(const std::vector<PrintElementT>& p_list) {
        for (auto const i : p_list)
            std::cout << i << std::endl;
    }

    template <typename PrintElementT, typename... VarArgs>
    void print(const PrintElementT p_toPrint, const VarArgs... p_args) {
        std::cout << p_toPrint << std::endl;
        PrintUtils::print(p_args...);
    }

    template <typename PrintElementT>
    void print(const std::initializer_list<PrintElementT>& p_list) {
        for (auto const i : p_list)
            std::cout << i << std::endl;
    }

    void printList(const std::vector<std::string>& p_strList) {
        unsigned long long counter = 1;

        for (auto const i : p_strList)
            std::cout << counter++ << ". " << i << std::endl;
    }

    template <typename PrintElementT>
    void printList(const std::vector<PrintElementT>& p_list) {
        unsigned long long counter = 1;

        for (auto const i : p_list)
            std::cout << counter++ << ". " << i << std::endl;
    }

    template <typename PrintElementT>
    void printList(const std::initializer_list<PrintElementT>& p_list) {
        unsigned long long counter = 1;

        for (auto const i : p_list)
            std::cout << counter++ << ". " << i << std::endl;
    }

}
