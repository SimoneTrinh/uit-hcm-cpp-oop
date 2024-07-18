#include <stdio.h>
#include <iostream>
using namespace std;

class CDonThuc
{
private:
    int a;
    int b;

public:
    friend istream &operator>>(istream &is, CDonThuc &x);
    friend ostream &operator<<(ostream &os, CDonThuc &x);
    CDonThuc();
    CDonThuc(int, int);
    CDonThuc(const CDonThuc &);
    ~CDonThuc();
    CDonThuc CDonThuc::operator=(CDonThuc &);
    CDonThuc CDonThuc::operator*(CDonThuc x);
    CDonThuc CDonThuc::operator/(CDonThuc x);
    CDonThuc CDonThuc::operator*=(CDonThuc x);
    CDonThuc CDonThuc::operator/=(CDonThuc x);
};

istream &operator>>(istream &is, CDonThuc &x)
{
    cout << "Nhap a:" << endl;
    is >> x.a;
    cout << "Nhap b:" << endl;
    is >> x.b;
    return is;
};

ostream &operator<<(ostream &os, CDonThuc &x)
{
    os << "Don thuc: " << x.a << "/" << x.b << endl;
    return os;
};

CDonThuc CDonThuc::operator=(CDonThuc &x)
{
    a = x.a;
    b = x.b;
    return *this;
}

CDonThuc::CDonThuc()
{
    a = 2;
    b = 1;
}

CDonThuc::CDonThuc(int a1, int b1)
{
    a = a1;
    b = b1;
}

CDonThuc::CDonThuc(const CDonThuc &x)
{
    a = x.a;
    b = x.b;
}

CDonThuc::~CDonThuc()
{
    return;
}

CDonThuc CDonThuc::operator*(CDonThuc x)
{
    CDonThuc result;
    result.a = a * x.a;
    result.b = b * x.b;
    return result;
}

CDonThuc CDonThuc::operator/(CDonThuc x)
{
    CDonThuc result;
    result.a = a * x.b;
    result.b = b * x.a;
    return result;
}

CDonThuc CDonThuc::operator*=(CDonThuc x)
{
    CDonThuc result;
    result.a = a * x.a;
    result.b = b * x.b;
    return result;
}

CDonThuc CDonThuc::operator/=(CDonThuc x)
{
    CDonThuc result;
    result.a = a * x.b;
    result.b = b * x.a;
    return result;
}
