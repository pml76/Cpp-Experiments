//
// Created by U439644 on 12/18/2024.
//


#include <cstdio>
#include <iostream>
#include "TypeName.h"

constexpr int dummy = 5;

namespace Functions {
    const int *getVal1() {return &dummy; }
    const int &getVal2() {return dummy; }

    void ex01() {
        puts("ex01");

        [[maybe_unused]] const auto *val1 = getVal1();
        std::cout << "const auto *val1 = getVal1(); ==> val1 is of type: " << type_name<decltype(val1)>() << std::endl;

        [[maybe_unused]] const auto &val2 = getVal2();
        std::cout << "const auto &val2 = getVal2(); ==> val2 is of type: " << type_name<decltype(val2)>() << std::endl;

        [[maybe_unused]] const auto val3 = getVal2();
        std::cout << "const auto val3 = getVal2(); ==> val3 is of type: " << type_name<decltype(val3)>() << std::endl;

        [[maybe_unused]] const auto val4 = getVal1();
        std::cout << "const auto val4 = getVal1(); ==> val4 is of type: " << type_name<decltype(val4)>() << std::endl;

        [[maybe_unused]] const auto &val5 = getVal1();
        std::cout << "const auto &val5 = getVal1(); ==> val5 is of type: " << type_name<decltype(val5)>() << std::endl;

        [[maybe_unused]] auto &&val6 = getVal2();
        std::cout << "auto &&val6 = getVal2(); ==> val6 is of type: " << type_name<decltype(val6)>() << std::endl;
    }
}
