#ifndef CPP_FIFTH_LAB_51SIRIUS_MATRIX_H
#define CPP_FIFTH_LAB_51SIRIUS_MATRIX_H


#include <exception>
#include <string>
#include <cstring>
#include "matrixexp.h"
#include <iostream>


template<typename T, int N, int M>
class Matrix {
public:
    Matrix() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                data[i][j] = T();
            }
        }
    }

    Matrix(const Matrix &other) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                data[i][j] = other.data[i][j];
            }
        }
    }

    T &operator()(int i, int j) {
        if (i >= N or i < 0 or j >= M or j < 0) throw MatrixIndexException(i, j);
        return data[i][j];
    }

    Matrix &operator=(const Matrix &other) {
        if (this == &other) {
            return *this;
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                data[i][j] = other.data[i][j];
            }
        }
        return *this;
    }

    template<int K>
    Matrix<T, N, K> operator*(const Matrix<T, M, K> &other) const {
        Matrix<T, N, K> result;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < K; j++) {
                for (int k = 0; k < M; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    bool operator==(const Matrix &other) const {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (data[i][j] != other.data[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    Matrix<T, N, M> operator+(const Matrix<T, M, M> &other) const {
        Matrix<T, N, M> result;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];

            }
        }
        return result;
    }

    Matrix<T, N, M> operator-(const Matrix<T, M, M> &other) const {
        Matrix<T, N, M> result;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                result.data[i][j] = data[i][j] - other.data[i][j];

            }
        }
        return result;
    }

    Matrix<T, N, M> operator/(const int &num) const {
        if (num == 0) throw
                    Matrix<T, N, M> result;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                result.data[i][j] = data[i][j] / num;

            }
        }
        return result;
    }





private:
    T data[N][M];
};


#endif