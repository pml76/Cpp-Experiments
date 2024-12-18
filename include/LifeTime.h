//
// Created by U439644 on 12/18/2024.
//

#ifndef LIFETIME_H
#define LIFETIME_H

#include <cstdio>
#include <iostream>
#include <ostream>
#include <source_location>
#include <utility>

void print(const std::string &str, const std::source_location loc = std::source_location::current()) {
    std::cout << str << ", filename: " << loc.file_name() << ", line: " << loc.line() << std::endl;
}

struct LifeTime {
    explicit(false) explicit LifeTime(const std::string &begin = "default-begin", const std::string &end = "default-end",
                                      const std::source_location loc = std::source_location::current()) : begin(begin),
        end(end) {

        std::cout << begin << " | ";
        print("LifeTime()", loc);
    }

    LifeTime(const LifeTime &l,
             const std::source_location loc = std::source_location::current()) : payload(l.payload),
        begin( begin + l.begin + "/&"), end(begin + l.end + "/&") {
        std::cout << begin << " | ";
        print("LifeTime(const LifeTime&)", loc);
    }

    LifeTime(LifeTime &&l,
             const std::source_location loc = std::source_location::current()) noexcept : payload(l.payload),
        begin( begin + l.begin + "/&&"), end(begin + l.end + "/&&") {
        std::cout << begin << " | ";
        print("LifeTime(LifeTime &&)", loc);
    }

    LifeTime &operator=(const LifeTime &l) noexcept {
        payload = l.payload;
        begin = l.begin + "/&=";
        end = l.end + "/&=";
        std::cout << begin << " | ";
        print("operator=(const LifeTime &)");
        return *this;
    }

    LifeTime &operator=(LifeTime &&l) noexcept {
        payload = l.payload;
        begin = l.begin + "/&&=";
        end = l.end + "/&&=";
        std::cout << begin << " | ";
        print("operator=(LifeTime &&)");
        return *this;
    }

    ~LifeTime() {
        std::cout << end << " | ";
        print("~LifeTime()");
    }

    u_int64_t payload = 0;
    std::string begin = "", end = "";
};

#endif //LIFETIME_H
