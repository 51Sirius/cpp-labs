#ifndef CPP_FIFTH_LAB_51SIRIUS_MATRIXEXP_H
#define CPP_FIFTH_LAB_51SIRIUS_MATRIXEXP_H

#include <exception>
#include <string>


class MatrixException : public std::exception {
};

class MatrixIndexException : public MatrixException {
public:
    int indexes[2]{};

    MatrixIndexException(int i, int j) {
        indexes[0] = i;
        indexes[1] = j;
        message = "Invalid matrix index: " + std::to_string(i) + " ; " + std::to_string(j);

    }
    int *get_indexes(){
        return indexes;
    }

    const char *what() const noexcept override {
            return message.c_str();
    }

private:
    std::string message;
};

class MatrixDivisionByZero : public MatrixException {
public:
    MatrixDivisionByZero() {
        message = "Division by zero(";
    }

    const char *what() const noexcept override {
            return message.c_str();
    }

private:
    std::string message;
};

#endif