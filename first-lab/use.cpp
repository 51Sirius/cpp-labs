#include "main.h"
#include <iostream>

using namespace std;


int main() {
    int a = 5;
    int b = 6;
    swap_with_links(a, b);
    cout << a << " " << b << "\n";
    swap_with_pointer(&a, &b);
    cout << a << " " << b << '\n';
    double num = 10.5;
    round_with_pointer(&num);
    cout << num << "\n";
    num = 10.5;
    round_with_links(num);
    cout << num << '\n';
    complex_numb numb1 = {4, 10};
    multiply_complex_with_links(numb1, 4);
    multiply_complex_with_pointer(&numb1, 2);
    cout << numb1.re << " + i" << numb1.im << '\n';
    int matrix[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    transport_matrix_with_links(matrix);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << matrix[i][j] << ' ';
        }
        cout << "\n";
    }
    transport_matrix_with_pointer(matrix);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << matrix[i][j] << ' ';
        }
        cout << "\n";
    }
    return 0;
}