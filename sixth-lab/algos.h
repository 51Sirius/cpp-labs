#ifndef CPP_SIXTH_LAB_51SIRIUS_ALGOS_H
#define CPP_SIXTH_LAB_51SIRIUS_ALGOS_H


template<typename It, typename Pred>
bool any_of(It begin, It end, Pred p){
    for (auto iter = begin; iter != end; ++iter) {
        if (p(*iter)) return true;
    }
    return false;
}

template<typename It, typename Pred>
bool one_of(It begin, It end, Pred p){
    It iter = begin;
    bool is_one = true;
    while (iter != end) {
        if (p(*iter) and is_one) {
            is_one = false;
        } else if(p(*iter) and !is_one){
            return false;
        }
        ++iter;
    }
    if (!is_one) return true;
    else return false;
}

template<typename It, typename DataType, typename Pred>
It find_not(It begin, It end, const DataType &value, Pred p){
    It iter = begin;
    while (iter != end){
        if (p(*iter, value)) {
            return iter;
        }
        ++iter;
    }
    return end;
}

#endif