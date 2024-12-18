//
// Created by U439644 on 12/18/2024.
//

#include <map>
#include <string>
#include "LifeTime.h"

std::map<std::string, LifeTime, std::less<>> m;

std::map<std::string, LifeTime, std::less<>> &get_map() {
    m["key"] = LifeTime("a", "b");
    return m;
}

namespace Functions {
    void ex02() {

        std::cout << "ex02 --- begin" << std::endl;
        for (auto &[i,k]: get_map()) {
            std::cout << i << " " << k.payload << std::endl;
            k.payload = 7;
        }
        std::cout << "ex02 --- end" << std::endl;
    }
}
