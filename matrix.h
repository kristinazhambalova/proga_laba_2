#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix {
private:
    int** data;
    unsigned int m;
    unsigned int n;

public:
    Matrix(unsigned int m, unsigned int n);
    ~Matrix();

    int* operator[](unsigned int index) const;

    void fillRandom();

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
    Matrix operator+=(const Matrix& matrix);
    Matrix operator+(const Matrix& matrix);
    Matrix operator-=(const Matrix& matrix);
    Matrix operator-(const Matrix& matrix);
    Matrix operator*(const Matrix& matrix);
    bool operator!=(const Matrix& matrix);
    bool operator==(const Matrix& matrix);
};

#endif //MATRIX_H