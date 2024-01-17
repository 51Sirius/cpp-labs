// 1 6 9 14


#ifndef CPP_FIRST_LAB_51SIRIUS_MAIN_H
#define CPP_FIRST_LAB_51SIRIUS_MAIN_H

#include "cmath"


void swap_with_pointer(int *, int *);

void swap_with_links(int &, int &);

void round_with_pointer(double *);

void round_with_links(double &);

struct complex_numb {
    double re;
    double im;
};

void multiply_complex_with_pointer(complex_numb *, double);

void multiply_complex_with_links(complex_numb &, double);

void transport_matrix_with_pointer(int(*)[3]);

void transport_matrix_with_links(int (&)[3][3]);

#endif