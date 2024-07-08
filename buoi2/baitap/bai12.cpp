#include <stdio.h>
#include <iostream>
using namespace std;
// Khai bao ham va toan tu vao va toan tu ra cho: 12. Lop hinh cau;

class CHinhCau
{
private:
    float r;
    float pi = 3.14;

public:
    friend istream &operator>>(istream &is, CHinhCau &x);
    friend ostream &operator<<(ostream &os, CHinhCau &x);
};

istream &operator>>(istream &is, CHinhCau &x)
{
    cout << "Nhap ban kinh:" << endl;
    is >> x.r;
    return is;
};

ostream &operator<<(ostream &os, CHinhCau &x)
{
    os << "Hinh cau co ban kinh: r = " << x.r;
    return os;
};
