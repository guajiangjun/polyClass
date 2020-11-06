#pragma once
#include "Matrix.hpp"

//判断两个矩阵是否维数相同
template <typename T>
bool ifSameSize(const Matrix<T> &A, const Matrix<T> &B)
{
    return A.ifSameSize(B);
}

//返回矩阵转置 test ok!
template <typename T>
Matrix<T> transpose(const Matrix<T> &A)
{
    Matrix<T> re(A.getN(), A.getM());
    for (int i = 1; i <= re.getM(); i++)
    {
        for (int j = 1; j <= re.getN(); j++)
            re(i, j) = A[j][i];
    }
    return re;
}

#pragma region 返回某一行或某一列，删除某一行或某一列 tesk ok !
//返回矩阵的第i行 (1 <= i <= m)
template <typename T>
Matrix<T> getRow(const Matrix<T> &A, int i)
{
    int m = A.getM(), n = A.getN();
    if (i <= 0 || i >= m + 1)
    {
        throw invalid_argument("getRow() Wrong!:need 1 <= i <= m");
    }
    Matrix<T> re(1, n);
    for (int j = 1; j <= n; j++)
    {
        re(1, j) = A[i][j];
    }
    return re;
}

//返回矩阵的第j列 (1 <= j <= n)
template <typename T>
Matrix<T> getCol(const Matrix<T> &A, int j)
{
    int m = A.getM(), n = A.getN();
    if (j <= 0 || j >= n + 1)
    {
        throw invalid_argument("geCol() Wrong!:need 1 <= j <= n");
    }
    Matrix<T> re(m, 1);
    for (int i = 1; i <= m; i++)
    {
        re(i, 1) = A[i][j];
    }
    return re;
}

//删除某一行 test ok
template <typename T>
Matrix<T> deleteRow(const Matrix<T> A, int ith)
{
    if (ith <= 0 || ith >= A.getM() + 1)
    {
        throw invalid_argument("deleteRow():size wrong!");
    }
    Matrix<T> re(A.getM() - 1, A.getN());
    for (int j = 1; j <= A.getN(); j++)
    {
        for (int i = 1; i <= ith - 1; i++)
            re(i, j) = A[i][j];
        for (int i = ith; i <= A.getM() - 1; i++)
            re(i, j) = A[i + 1][j];
    }
    return re;
}

//删除某一列 test ok
template <typename T>
Matrix<T> deleteCol(const Matrix<T> A, int jth)
{
    if (jth <= 0 || jth >= A.getN() + 1)
    {
        throw invalid_argument("deleteCol():size wrong!");
    }
    Matrix<T> re = A;
    re = transpose(re);
    re = deleteRow(re, jth);
    re = transpose(re);
    return re;
}
#pragma endregion

// //矩阵拼接
// template <typename T>
// Matrix<T> cat(const Matrix<T> &A, const Matrix<T> &B, const string &direction = "vertical")
// {

//     if (direction == "right")
//     {
//     }
//     else
//     {
//     }
//     return re;
// }
