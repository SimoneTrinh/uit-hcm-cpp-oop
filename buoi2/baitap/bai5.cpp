#include <stdio.h>
#include <iostream>
using namespace std;
// Khai bao ham va toan tu vao va toan tu ra cho: 5. Lop don thuc : ax + by + cz = 0

class CDonThuc
{
private:
    int a;
    int b;
    int c;

public:
    friend istream &operator>>(istream &is, CDonThuc &x);
    friend ostream &operator<<(ostream &os, CDonThuc &x);
};

istream &operator>>(istream &is, CDonThuc &x)
{
    cout << "Nhap a:" << endl;
    is >> x.a;
    cout << "Nhap b:" << endl;
    is >> x.b;
    cout << "Nhap c:" << endl;
    is >> x.c;
    return is;
};

ostream &operator<<(ostream &os, CDonThuc &x)
{
    os << "Don thuc: " << x.a << "*x" << " + " << x.b << "*y" << " + " << x.c << "*z" << " = 0";
    return os;
};
