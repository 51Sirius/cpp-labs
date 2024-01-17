#ifndef CPP_FIFTH_LAB_51SIRIUS_FUNC_H
#define CPP_FIFTH_LAB_51SIRIUS_FUNC_H
#include "iostream"

template<typename T>
void swap(const T &a, const T &b){
    T tmp = std::move(a);
    a = std::move(b);
    b = std::move(tmp);
}


#endif