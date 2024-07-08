#include <stdio.h>
#include <iostream>
using namespace std;
// Khai bao ham va toan tu vao va toan tu ra cho: 7. Lop duong thang (y = ax + b)

class CDuongThang
{
private:
    int a;
    int b;

public:
    friend istream &operator>>(istream &is, CDuongThang &x);
    friend ostream &operator<<(ostream &os, CDuongThang &x);
};

istream &operator>>(istream &is, CDuongThang &x)
{
    cout << "Nhap a:" << endl;
    is >> x.a;
    cout << "Nhap b:" << endl;
    is >> x.b;
    return is;
};

ostream &operator<<(ostream &os, CDuongThang &x)
{
    os << "Duong thang: " << "y = " << x.a << " *x" << " + " << x.b;
    return os;
};
