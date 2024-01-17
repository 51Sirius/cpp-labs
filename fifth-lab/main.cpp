#include "func.h"
#include "matrix.h"
#include "iostream"

using namespace std;

int main() {
    Matrix<int, 3, 1> M;
    cout << M(1, 0) << endl;
    M(1, 0) = 1;
    cout << M(1, 0) << endl;
    Matrix<int, 3, 1> A;
    swap(A, M);
    cout << A(1, 0) << endl;
    A(2, 2) = 1;
}