#pragma once
#include "algorithm1.hpp"

#pragma region 矩阵相关函数与算法2

#pragma region 初等行变换
//某一行乘以一个数
template <typename T>
Matrix<T> &multiplyRow(const Matrix<T> &A, int i, T a)
{
    Matrix<T> re = A;
    for (int j = 1; j < re.getN(); j++)
    {
        re(i, j) *= a;
    }
    return re;
}
//交换两行
template <typename T>
Matrix<T> exchangeRows(const Matrix<T> &A, int i, int j)
{
    if (i <= 0 || i >= A.getM() + 1 || j <= 0 || j >= A.getM() + 1)
    {
        throw invalid_argument("exchangeRows() wrong!");
    }
    Matrix<T> re = A;
    for (int k = 1; k < re.getN(); k++)
    {
        re(i, k) = A(j, k);
        re(j, k) = A(i, k);
    }
    return re;
}
//把某一行乘以某个数加到另一行上(把第i行乘以a加到第j行上去)
template <typename T>
Matrix<T> addRow2Row(const Matrix<T> &A, int i, T a, int j)
{
    Matrix<T> tempt = getRow(A, i);
    tempt *= a;
    Matrix<T> re = A;
    for (int k = 1; k <= re.getN(); k++)
    {
        re(j, k) += a[1][k];
    }

    return re;
}
#pragma endregion

#pragma region 计算trace, determinant
//计算trace should bo ok!
template <typename T>
T trace(const Matrix<T> &A)
{
    if (A.ifSquare() == false)
    {
        throw invalid_argument("compute trace shuold be square matrix!");
    }
    T re = 0;
    for (int i = 1; i <= A.getM(); i++)
    {
        re += A[i][i];
    }
    return re;
}

//计算determinant tesk ok!!!
template <typename T>
T det(const Matrix<T> &A)
{
    int m = A.getM(), n = A.getN();
    if (m != n)
    {
        throw invalid_argument("compute det shuold be square matrix!");
    }
    if (m == 1)
    {
        return A[1][1];
    }
    else if (m == 2)
    {
        return A[1][1] * A[2][2] - A[1][2] * A[2][1];
    }
    else
    {
        T re = 0;
        for (int j = 1; j <= A.getN(); j++)
        {
            Matrix<T> tempt = A;
            tempt = deleteRow(tempt, 1);
            tempt = deleteCol(tempt, j);
            if (j % 2 == 1)
            {
                re += A[1][j] * det(tempt);
            }
            else
            {
                re -= A[1][j] * det(tempt);
            }
        }
        return re;
    }
}
#pragma endregion

#pragma endregion