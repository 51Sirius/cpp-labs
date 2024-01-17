#include "comlex.h"


Complex::Complex() {
    this->im = 0;
    this->re = 0;
}

Complex::Complex(double re, double im) {
    this->im = re;
    this->re = im;
}

Complex Complex::operator+(const Complex &comp) const {
    return Complex(re + comp.re, im + comp.im);
}


Complex Complex::operator*(const Complex &comp) const {
    return Complex(re * comp.re - im * comp.im,
                   re * comp.im + im * comp.re);
}

Complex::operator double() const {
    return pow(re * re + im * im, 0.5);
}

Complex Complex::operator*(double c1) const {
    return Complex(re * c1, im * c1);
}

void Complex::set_re(double r) {
    re = r;
}

void Complex::set_im(double i) {
    im = i;
}

double Complex::get_im() const {
    return im;
}

double Complex::get_re() const {
    return re;
}




