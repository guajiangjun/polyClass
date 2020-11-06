#include "includeLib/include.hpp"
int main()

{
    Matrix<int> A(6, 4);
    A << vector<int>{1, 2, 3, 4,
                     5, 6, 7, 8,
                     9, 10, 11, 12,
                     13, 14, 15, 16,
                     17, 18, 19, 20,
                     21, 22, 23, 24};
    cout << A << endl;
    return 0;
}