#include <stdio.h>
#include <iostream>
using namespace std;
// Khai bao ham va toan tu vao va toan tu ra cho: 11. Lop tam giac;

class CTamGiac
{
private:
    int a;
    int b;
    int c;

public:
    friend istream &operator>>(istream &is, CTamGiac &x);
    friend ostream &operator<<(ostream &os, CTamGiac &x);
};

istream &operator>>(istream &is, CTamGiac &x)
{
    cout << "Nhap do dai canh a:" << endl;
    is >> x.a;
    cout << "Nhap do dai canh b:" << endl;
    is >> x.b;
    cout << "Nhap do dai canh c:" << endl;
    is >> x.c;
    return is;
};

ostream &operator<<(ostream &os, CTamGiac &x)
{
    os << "Tam giac da cho co do dai 3 canh: a = " << x.a << " ; " << "b = " << x.b << " ; " << x.c;
    return os;
};
