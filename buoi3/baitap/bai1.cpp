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
    CPhanSo operator=(CPhanSo &);
    CPhanSo();
    CPhanSo(int, int);
    CPhanSo(const CPhanSo &);
    ~CPhanSo();
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

CPhanSo CPhanSo::operator=(CPhanSo &x)
{
    _tuSo = x._tuSo;
    _mauSo = x._mauSo;
    return *this;
}

CPhanSo::CPhanSo()
{
    _tuSo = 0;
    _mauSo = 1;
}

CPhanSo::CPhanSo(int tuSo, int mauSo)
{
    _tuSo = tuSo;
    _mauSo = mauSo;
}

CPhanSo::CPhanSo(const CPhanSo &x)
{
    _tuSo = x._tuSo;
    _mauSo = x._mauSo;
}

CPhanSo::~CPhanSo()
{
    return;
}