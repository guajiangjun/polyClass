#include "includeLib/include.hpp"
int main()

{
    Matrix<int> A(5, 5);
    A << vector<int>{
        1, 2, 3, 78, 99,
        3, 2, 1, 101, 99,
        1, 1, 1, 33, 44,
        11, 22, 333, 44, 55,
        22, 33, 11, 99, 20};
    cout << A << endl;
    cout << det(A) << endl;
    return 0;
}