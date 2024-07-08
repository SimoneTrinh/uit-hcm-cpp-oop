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
    CHinhCau CHinhCau::operator=(CHinhCau &);
    CHinhCau();
    CHinhCau(float, float);
    CHinhCau(CHinhCau &);
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

CHinhCau CHinhCau::operator=(CHinhCau &x)
{
    r = x.r;
    pi = x.pi;
    return *this;
};

CHinhCau::CHinhCau()
{
    r = 1.0;
    pi = 3.14;
}

CHinhCau::CHinhCau(float r1, float pi1)
{
    r = r1;
    pi = pi1;
}

CHinhCau::CHinhCau(CHinhCau &x)
{
    r = x.r;
    pi = x.pi;
}
