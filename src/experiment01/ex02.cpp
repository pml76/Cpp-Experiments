//
// Created by U439644 on 12/18/2024.
//

#include <map>
#include <string>
#include "LifeTime.h"

std::map<std::string, LifeTime, std::less<>> get_map() {
    std::map<std::string, LifeTime, std::less<>> m;
    m["a"] = LifeTime();
    return m;
}

namespace Functions {
    void ex02() {
        using element_type = std::pair<const std::string, LifeTime>;


        for ([[maybe_unused]] const auto &i: get_map()) {
        }
    }
}
