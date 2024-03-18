#pragma once
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix {
private:
    int** data;
    unsigned int m, n;

public:
    Matrix(unsigned int rows, unsigned int columns); 
    ~Matrix(); 

    int* operator[](unsigned int i); 

    void fillRandom();

    Matrix operator+(const Matrix& other);
    Matrix operator-(const Matrix& other);
    Matrix operator*(const Matrix& other);

    Matrix& operator+=(const Matrix& other);
    Matrix& operator-=(const Matrix& other);

    bool operator==(const Matrix& other);
    bool operator!=(const Matrix& other);

    friend std::ostream& operator<<(std::ostream& out, const Matrix& matrix); 
};

#endif