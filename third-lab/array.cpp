#include "array.h"

bool Array::operator==(const Array &arr) const {
    return arr.len == len;
}

bool Array::operator<(const Array &arr) const {
    return arr.len > len;
}

bool Array::operator>(const Array &arr) const {
    return arr.len < len;
}

bool Array::operator!=(const Array &arr) const {
    return arr.len != len;
}

Array Array::operator+(const Array &arr) const {
    Array result;
    for (int i = 0; i < len; i++) {
        result.data[i] = data[i];
    }
    for (int i = 0; i < arr.len; i++) {
        result.data[len + i] = arr.data[i];
    }
    result.len = len + arr.len;
    return result;
}

bool Array::is_empty() const {
    return len==0;
}

Array::Array(const int *a, int n) {
    len= n;
    for (int i = 0; i < n; i++) {
        data[i] = a[i];
    }
    for (int i = n; i < 100; i++) {
        data[i] = 0;
    }
}

Array::Array() {
    len = 0;
    for (int & i : data) {
        i = 0;
    }
}

int Array::get_value(int ind) {
    return data[ind];
}

int Array::get_len() {
    return len;
}