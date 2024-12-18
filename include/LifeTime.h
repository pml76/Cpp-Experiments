//
// Created by U439644 on 12/18/2024.
//

#ifndef LIFETIME_H
#define LIFETIME_H


#include <cstdio>
struct LifeTime {
    LifeTime(){ puts("LifeTime()"); }
    LifeTime(const LifeTime &){ puts("LifeTime(const LifeTime &)"); }
    LifeTime(LifeTime &&) noexcept { puts("LifeTime(LifeTime &&)"); }
    LifeTime &operator=(const LifeTime &){
        puts("operator=(const LifeTime &)");
        return *this;
    }
    LifeTime &operator=(LifeTime &&) noexcept {
        puts("operator=(LifeTime &&)");
        return *this;
    }
    ~LifeTime() { puts("~LifeTime()"); }
};

#endif //LIFETIME_H
