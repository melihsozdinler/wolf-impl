//
// Created by Melih Sozdinler on 5/16/2021.
//

#include "Matrix.h"

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