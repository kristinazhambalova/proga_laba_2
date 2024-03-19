#pragma once      //директива обеспечивает защиту от многократного включения заголовочного файла
#ifndef MATRIX_H  //начинает условную компиляцию, чтобы проверить, был ли файл уже включен ранее
#define MATRIX_H

#include <iostream>

class Matrix {
private:
    int** data;     //для хранепния данных матрицы
    unsigned int m, n;   //для хранения количества строк и столбцов матрицы

public:
    Matrix(unsigned int rows, unsigned int columns);   //конструктор, создает матрицу заданного размера
    ~Matrix();                                         //деструктор, освобождает динамически выделенную память

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
