#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;
//cout<< vector类数据
template <typename T>
ostream &operator<<(ostream &out, const vector<T> &a)
{
    for (int i = 0; i < a.size(); i++)
    {
        out << a[i];
        if (i != a.size() - 1)
            out << endl;
    }
    return out;
}
//vector相加
template <typename T>
vector<T> operator+(const vector<T> &a, const vector<T> &b)
{
    vector<T> re;
    for (int i = 0; i < a.size(); i++)
    {
        re.push_back(a[i] + b[i]);
    }
    return re;
}
//整数的gcd
inline int gcd(int a, int b)
{
    if (a == 0 || b == 0)
    {
        return 0;
    }
    while (b ^= a ^= b ^= a %= b)
        ;
    return a;
}