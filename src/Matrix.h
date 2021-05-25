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
Matrix<T>::Matrix(size_t rows, size_t cols)
        : mRows(rows),
          mCols(cols),
          mData(rows * cols)
{
}

template<class T>
T& Matrix<T>::operator()(size_t i, size_t j)
{
    return mData[i * mCols + j];
}

template<class T>
T Matrix<T>::operator()(size_t i, size_t j) const
{
    return mData[i * mCols + j];
}

template<class T>
size_t Matrix<T>::dim1() {
    return mRows;
}

template<class T>
size_t Matrix<T>::dim2() {
    return mCols;
}

#endif //WOLF_MATRIX_H
