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
    CDonThuc CDonThuc::operator=(CDonThuc &);
    CDonThuc();
    CDonThuc(int, int, int);
    CDonThuc(const CDonThuc &);
    ~CDonThuc();
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

CDonThuc CDonThuc::operator=(CDonThuc &x)
{
    a = x.a;
    b = x.b;
    c = x.c;
    return *this;
}

CDonThuc::CDonThuc()
{
    a = 1;
    b = 1;
    c = 1;
}

CDonThuc::CDonThuc(int a1, int b1, int c1)
{
    a = a1;
    b = b1;
    c = c1;
}

CDonThuc::CDonThuc(const CDonThuc &x)
{
    a = x.a;
    b = x.b;
    c = x.c;
}

CDonThuc::~CDonThuc()
{
    return;
}