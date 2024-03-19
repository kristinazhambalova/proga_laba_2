#include "matrix.h"
#include <cstdlib>


Matrix::Matrix(unsigned int rows, unsigned int columns) : m(rows), n(columns) {  //конструктор, инициализирует новый обЪект матрицы, класс предсталяет матрицу с базовыми операциями + - *
    data = new int* [m];
    for (unsigned int i = 0; i < m; ++i) {
        data[i] = new int[n];                                                    // двумерный массив data
    }
}

Matrix::~Matrix() {                                                            //деструктор, удаляет объект матрицы, освобождает память, перебирает все строки матрицы и освобождает память для каждой строки, 
    for (unsigned int i = 0; i < m; ++i) {                                     //затем удаляет указатели строки и освобождает память для указателей строк
        delete[] data[i];
    }
    delete[] data;
}

int* Matrix::operator[](unsigned int i) {                                     //оператор [], который позволяет получить доступ к строке матрицы по заданному индексу
    return data[i];
}

void Matrix::fillRandom() {                                            //метод, который заполняет матрицу случайными значениями
    for (unsigned int i = 0; i < m; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            data[i][j] = rand() % 10;
        }
    }
}

Matrix Matrix::operator+(const Matrix& other) {
    if (m == other.m || n == other.n) {
        Matrix result(m, n);
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                result[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
    else std::cout << "Matrix dimensions do not match! \n";
}

Matrix Matrix::operator-(const Matrix& other) {
    if (m == other.m || n == other.n) {
        Matrix result(m, n);
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                result[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }
    else std::cout << "Matrix dimensions do not match! \n";
}

Matrix Matrix::operator*(const Matrix& other) {
    if (n == other.m) {
        Matrix result(m, other.n);
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < other.n; ++j) {
                result[i][j] = 0;
                for (unsigned int k = 0; k < n; ++k) {
                    result[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }
    else std::cout << "The number of columns of Matrix 1 does not match the number of rows of Matrix 2! \n";
}

Matrix& Matrix::operator+=(const Matrix& other) {  //для добавления другой матрицы
    if (m == other.m || n == other.n) {
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                data[i][j] += other.data[i][j];
            }
        }
        return *this;
    }
    else std::cout << "Matrix dimensions do not match! \n";
}

Matrix& Matrix::operator-=(const Matrix& other) {  //для вычитания другой матрицы из текущей
    if (m == other.m || n == other.n) {
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                data[i][j] -= other.data[i][j];
            }
        }
        return *this;
    }
    else std::cout << "Matrix dimensions do not match! \n";
}

bool Matrix::operator==(const Matrix& other) {  //для сравнения матриц на равенство
    if (m != other.m || n != other.n) {
        return false;
    }

    for (unsigned int i = 0; i < m; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            if (data[i][j] != other.data[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix& other) {  //для сравнения матриц на неравенство
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& out, const Matrix& matrix) {  //оператор вывода в поток, для красивого вывода
    for (unsigned int i = 0; i < matrix.m; ++i) {
        for (unsigned int j = 0; j < matrix.n; ++j) {
            out << matrix.data[i][j] << " ";
        }
        out << std::endl;
    }
    return out;
}

int main() {
    srand(time(0));

    Matrix matrix1(2, 3);
    matrix1.fillRandom();
    std::cout << "Matrix 1:" << std::endl;
    std::cout << matrix1 << std::endl;

    Matrix matrix2(2, 3);
    matrix2.fillRandom();
    std::cout << "Matrix 2:" << std::endl;
    std::cout << matrix2 << std::endl;

    std::cout << "Sum of Matrix 1 and Matrix 2:" << std::endl;
    Matrix sum = matrix1 + matrix2;
    std::cout << sum << std::endl;

    std::cout << "Difference of Matrix 1 and Matrix 2:" << std::endl;
    Matrix difference = matrix1 - matrix2;
    std::cout << difference << std::endl;

    std::cout << "Product of Matrix 1 and Matrix 2:" << std::endl;
    Matrix product = matrix1 * matrix2;
    std::cout << product << std::endl;

    return 0;
}
