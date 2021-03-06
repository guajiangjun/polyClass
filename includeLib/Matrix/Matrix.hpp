/*
Remark:
You should define T a=0; and T a=1;
a>=0,和a<=0
to_string(a)
-a
*/
#pragma once
#include "../includeSTL.hpp"

#pragma region Matrix < T> 类的定义
template <typename T>
class Matrix
{
private:
#pragma region 成员变量（数据）
    vector<vector<T>> A;
    int m, n;
#pragma endregion

public:
#pragma region 成员函数
#pragma region 初始化和赋值以及输出 test ok
    //初始化矩阵为 m x n 的零矩阵  [矩阵构造step1]
    Matrix(int m_row = 1, int n_col = 1) : m(m_row), n(n_col)
    {
        for (int i = 0; i < m; i++)
        {
            A.push_back(vector<T>(n)); //n个0
        }
    }
    //使用 << 为矩阵元素赋值操作   [矩阵构造step2]
    void operator<<(vector<T> a)
    {
        if (a.size() != m * n)
        {
            throw invalid_argument("matrix << size wrong!");
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                A[i][j] = a[i * n + j];
            }
        }
        return;
    }
    //输出矩阵
    friend ostream &operator<<(ostream &out, const Matrix<T> &A)
    {
        for (int i = 0; i < A.m; i++)
        {
            for (int j = 0; j < A.n; j++)
            {
                cout << A.A[i][j] << "\t";
            }
            if (i != A.m - 1)
            {
                cout << endl;
            }
        }
        return out;
    }

#pragma endregion

#pragma region 返回行数，列数，某行某列的元素（可修改和不可修改）tesk ok
    int getM() const
    {
        return m;
    }
    int getN() const
    {
        return n;
    }
    //返回A(i,j)（可以修改）（1 <= i <= m，1 <= j <= n）
    T &operator()(int i, int j)
    {
        if (i <= 0 || i >= m + 1 || j <= 0 || j >= n + 1)
        {
            throw invalid_argument("A(i,j)返回矩阵元素错误！:need  1 <= i <= m，1 <= j <= n");
        }

        return A[i - 1][j - 1];
    }
    //返回A[i][j]（不可以修改）（1 <= i <= m，1 <= j <= n）
    vector<T> operator[](int i) const
    {
        if (i <= 0 || i >= m + 1)
        {
            throw invalid_argument("A[i][j]返回矩阵元素错误！:need  1 <= i <= m，1 <= j <= n");
        }
        vector<T> re = A[i - 1];
        re.insert(re.begin(), T(0));
        return re;
    }
#pragma endregion

    //矩阵切片(包前且包后)（1 <= i1<=i2 <= m，1 <= j1<=j2 <= n）
    Matrix<T> operator()(int i1, int i2, int j1, int j2) const
    {
        if (i1 > i2 || j1 > j2)
        {
            throw invalid_argument("矩阵切片index大小顺序错误");
        }
        i1--;
        j1--;
        if (i1 < 0 || j1 < 0 || i2 > m || j2 > n)
            throw invalid_argument("矩阵切片index越界");
        Matrix<T> re(i2 - i1, j2 - j1);
        for (int i = 0; i < re.getM(); i++)
        {
            for (int j = 0; j < re.getN(); j++)
            {
                re[i][j] = A[i + i1][j + j1];
            }
        }

        return re;
    }

#pragma region[bool] 判断矩阵的性质
    //判断和另一个矩阵是否维数相同
    bool ifSameSize(const Matrix<T> &B)
    {
        return m == B.m && n == B.n;
    }

    //判断矩阵是否是方阵
    bool ifSquare() const
    {
        return m == n;
    }
#pragma endregion

#pragma region 加等, 减等, 标量乘等，乘等 test ok !!!
    //
    Matrix<T> operator+=(const Matrix &rhs)
    {
        if (!ifSameSize(rhs))
            cout << "The two Matrix can't be added!" << endl;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                A[i][j] += rhs.A[i][j];
            }
        }
        return *this;
    }
    Matrix<T> operator-=(const Matrix &rhs)
    {
        if (!ifSameSize(rhs))
            cout << "The two Matrix can't be minused!" << endl;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                A[i][j] -= rhs.A[i][j];
            }
        }
        return *this;
    }
    Matrix<T> operator*=(T rhs)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                A[i][j] *= rhs;
            }
        }
        return *this;
    }
    Matrix<T> operator*=(const Matrix &B)
    {
        if (n != B.m)
        {
            throw invalid_argument("The two Matrix can't be multiplied!");
        }
        int p = B.n;
        Matrix<T> C(m, p);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < p; j++)
            {
                T re = 0;
                for (int k = 0; k < n; k++)
                    re += A[i][k] * B.A[k][j];
                C.A[i][j] = re;
            }
        }
        *this = C;
        return *this;
    }

#pragma endregion
#pragma endregion
};
#pragma endregion

#pragma region 外部函数

#pragma region +, -*
//矩阵加法
template <typename T>
Matrix<T> operator+(const Matrix<T> &A, const Matrix<T> &B)
{
    Matrix<T> re(A);
    re += B;
    return re;
}
//矩阵减法
template <typename T>
Matrix<T> operator-(const Matrix<T> &A, const Matrix<T> &B)
{
    Matrix<T> re(A);
    re -= B;
    return re;
}
//矩阵乘法
template <typename T>
Matrix<T> operator*(const Matrix<T> &A, const Matrix<T> &B)
{
    Matrix<T> re(A);
    re *= B;
    return re;
}
//矩阵标量乘法1
template <typename T>
Matrix<T> operator*(const Matrix<T> &A, const T &d)
{
    Matrix<T> re(A);
    re *= d;
    return re;
}
//矩阵标量乘法2
template <typename T>
Matrix<T> operator*(const T &d, const Matrix<T> &A)
{
    Matrix<T> re(A);
    re *= d;
    return re;
}
#pragma endregion

#pragma region 特殊矩阵：单位矩阵和零矩阵
template <typename T>
Matrix<T> Indentity(int m)
{
    Matrix<T> A(m, m);
    T one = 1;
    for (int i = 0; i < m; i++)
    {
        A[i][i] = one;
    }
    return Matrix<T>(A);
}
template <typename T>
Matrix<T> Zero(int m, int n)
{
    return Matrix<T>(m, n);
}
template <typename T>
Matrix<T> Zero(int m)
{
    return Matrix<T>(m, m);
}
#pragma endregion

#pragma region 特定类型的Matrix重命名
typedef Matrix<int> MatrixI;
typedef Matrix<float> MatrixF;
typedef Matrix<double> MatrixD;
#pragma endregion

#pragma endregion