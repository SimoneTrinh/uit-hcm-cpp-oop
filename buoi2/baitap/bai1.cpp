#include <stdio.h>
#include <iostream>
using namespace std;
// Khai bao ham va toan tu vao va toan tu ra cho: 1. Lop Phan so

class CPhanSo
{
private:
    int _tuSo;
    int _mauSo;

public:
    friend istream &operator>>(istream &is, CPhanSo &x);
    friend ostream &operator<<(ostream &os, CPhanSo &x);
};

istream &operator>>(istream &is, CPhanSo &x)
{
    cout << "Nhap tu:" << endl;
    is >> x._tuSo;
    cout << "Nhap mau:" << endl;
    is >> x._mauSo;
    return is;
};

ostream &operator<<(ostream &os, CPhanSo &x)
{
    os << x._tuSo << "/" << x._mauSo;
    return os;
};
