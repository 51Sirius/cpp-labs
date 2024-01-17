#ifndef CPP_THIRD_LAB_51SIRIUS_ARRAY_H
#define CPP_THIRD_LAB_51SIRIUS_ARRAY_H


class Array {
private:
    int len;
    int data[100];
public:
    Array();

    Array(const int a[], int n);

    bool operator==(const Array &arr) const;

    bool operator<(const Array &arr) const;

    bool operator>(const Array &arr) const;

    bool operator!=(const Array &arr) const;

    Array operator+(const Array &arr) const;

    bool is_empty() const;

    int get_value(int ind);

    int get_len();
};


#endif