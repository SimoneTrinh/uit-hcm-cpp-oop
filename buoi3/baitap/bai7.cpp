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
    CDuongThang CDuongThang::operator=(CDuongThang &);
    CDuongThang();
    CDuongThang(int, int);
    CDuongThang(const CDuongThang &);
    ~CDuongThang();
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

CDuongThang CDuongThang::operator=(CDuongThang &x)
{
    a = x.a;
    b = x.b;
    return;
}

CDuongThang::CDuongThang()
{
    a = 1;
    b = 1;
}

CDuongThang::CDuongThang(int a1, int b1)
{
    a = a1;
    b = b1;
}

CDuongThang::CDuongThang(const CDuongThang &x)
{
    a = x.a;
    b = x.b;
}

CDuongThang::~CDuongThang()
{
    return;
}