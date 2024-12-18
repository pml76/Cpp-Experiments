//
// Created by U439644 on 12/18/2024.
//

#ifndef LIFETIME_H
#define LIFETIME_H


#include <cstdio>
struct LifeTime {
    LifeTime(){ puts("S()"); }
    LifeTime(const LifeTime &){ puts("S(const S &)"); }
    LifeTime(LifeTime &&) noexcept { puts("S(S &&)"); }
    LifeTime &operator=(const LifeTime &){
        puts("operator=(const S &)");
        return *this;
    }
    LifeTime &operator=(LifeTime &&) noexcept {
        puts("operator=(S &&)");
        return *this;
    }
    ~LifeTime() { puts("~S()"); }
};

#endif //LIFETIME_H
