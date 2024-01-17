#ifndef CPP_THIRD_LAB_51SIRIUS_COMLEX_H
#define CPP_THIRD_LAB_51SIRIUS_COMLEX_H
#include "math.h"


class Complex {
private:
    double re;
    double im;

public:
    Complex();
    Complex(double r, double i);

    void set_re(double r);

    void set_im(double i);

    Complex operator+(const Complex& comp) const;

    Complex operator*(const Complex& comp) const;

    Complex operator*(double c1) const;

    explicit operator double() const;

    double get_im() const;

    double get_re() const;

};


#endif