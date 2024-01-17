#include "main.h"

using namespace std;

void swap_with_links(int &x, int &y) {
    int tmp = x;
    x = y;
    y = tmp;

}

void swap_with_pointer(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}


void round_with_pointer(double *x) {
    *x = floor(*x);
}

void round_with_links(double &x) {
    x = floor(x);
}

void multiply_complex_with_links(complex_numb &numb, double numb2) {
    numb.im *= numb2;
    numb.re *= numb2;
}

void multiply_complex_with_pointer(complex_numb *numb, double numb2) {
    numb->im *= numb2;
    numb->re *= numb2;
}

void transport_matrix_with_pointer(int(*matrix)[3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = i; j < 3; ++j) {
            swap_with_links(matrix[i][j], matrix[j][i]);
        }
    }
}

void transport_matrix_with_links(int (&matrix)[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = i; j < 3; ++j) {
            swap_with_links(matrix[i][j], matrix[j][i]);
        }
    }
}