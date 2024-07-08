#include <stdio.h>
#include <iostream>
using namespace std;
// Khai bao ham va toan tu vao va toan tu ra cho: 4. Lop thoi gian

class CThoiGian
{
private:
    int _gio;
    int _phut;
    int _giay;

public:
    friend istream &operator>>(istream &is, CThoiGian &x);
    friend ostream &operator<<(ostream &os, CThoiGian &x);
};

istream &operator>>(istream &is, CThoiGian &x)
{
    cout << "Nhap gio:" << endl;
    is >> x._gio;
    cout << "Nhap phut:" << endl;
    is >> x._phut;
    cout << "Nhap giay:" << endl;
    is >> x._giay;
    return is;
};

ostream &operator<<(ostream &os, CThoiGian &x)
{
    os << "Gio: " << x._gio << " | " << "Phut: " << x._phut << " | " << "Giay: " << x._giay;
    return os;
};
