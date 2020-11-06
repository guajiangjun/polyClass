#pragma once
#include "../includeSTL.hpp"
#include "../Matrix/include.hpp"

class Mono
{
private:
    Matrix<int> degrees;
    vector<string> varName;

public:
    Mono(const vector<int> &a)
    {
        Matrix<int> re(1, a.size());
        for (int i = 0; i < a.size(); i++)
        {
            re(1, i + 1) = a[i];
            varName.push_back("x^" + to_string(i + 1));
        }
        degrees = re;
    }
    friend ostream &operator<<(ostream &out, const Mono &m)
    {
        for(int i=0;i<m.varName)
        return out;
    }
};