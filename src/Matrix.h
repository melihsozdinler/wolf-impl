//
// Created by Melih Sozdinler on 5/16/2021.
//

#ifndef WOLF_MATRIX_H
#define WOLF_MATRIX_H

#include <vector>

template<class T>
class Matrix {
public:
    Matrix(size_t rows, size_t cols);
    T& operator()(size_t i, size_t j);
    T operator()(size_t i, size_t j) const;

    size_t dim1();
    size_t dim2();

private:
    size_t mRows;
    size_t mCols;
    std::vector<T> mData;
};

template<class T>
using matrix = Matrix<T>;

#endif //WOLF_MATRIX_H
