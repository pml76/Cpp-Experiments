//
// Created by U439644 on 12/18/2024.
//

#ifndef TYPENAMEHH
#define TYPENAMEHH

#include <type_traits>
#include <typeinfo>
#ifndef _MSC_VER
#   include <cxxabi.h>
#endif
#include <memory>
#include <string>

namespace Functions {

    template <class T>
    std::string
    type_name()
    {
        using TR = std::remove_reference_t<T>;
        std::unique_ptr<char, void(*)(void*)> own
               (
    #ifndef _MSC_VER
                    abi::__cxa_demangle(typeid(TR).name(), nullptr,
                                               nullptr, nullptr),
    #else
                    nullptr,
    #endif
                  std::free
               );
        std::string r = own != nullptr ? own.get() : typeid(TR).name();
        if (std::is_const_v<TR>)
            r += " const";
        if (std::is_volatile_v<TR>)
            r += " volatile";
        if (std::is_lvalue_reference_v<T>)
            r += "&";
        else if (std::is_rvalue_reference_v<T>)
            r += "&&";
        return r;
    }
}
#endif //TYPENAMEHH
