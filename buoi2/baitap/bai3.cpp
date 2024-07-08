#include <stdio.h>
#include <iostream>
using namespace std;
// Khai bao ham va toan tu vao va toan tu ra cho: 3. Lop ngay

class CNgay
{
private:
    int _ngay;
    int _thang;
    int _nam;

public:
    friend istream &operator>>(istream &is, CNgay &x);
    friend ostream &operator<<(ostream &os, CNgay &x);
};

istream &operator>>(istream &is, CNgay &x)
{
    cout << "Nhap ngay:" << endl;
    is >> x._ngay;
    cout << "Nhap thang:" << endl;
    is >> x._thang;
    cout << "Nhap nam:" << endl;
    is >> x._nam;
    return is;
};

ostream &operator<<(ostream &os, CNgay &x)
{
    os << "Ngay: " << x._ngay << " | " << "Thang: " << x._thang << " | " << "Nam: " << x._nam;
    return os;
};
