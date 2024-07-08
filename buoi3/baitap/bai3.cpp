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
    CNgay operator=(CNgay &);
    CNgay();
    CNgay(int, int, int);
    CNgay(const CNgay &);
    ~CNgay();
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

CNgay CNgay::operator=(CNgay &x)
{
    _ngay = x._ngay;
    _thang = x._thang;
    _nam = x._nam;
    return *this;
}

CNgay::CNgay()
{
    _ngay = 1;
    _thang = 1;
    _nam = 1970;
}

CNgay::CNgay(int ngay, int thang, int nam)
{
    _ngay = ngay;
    _thang = thang;
    _nam = nam;
}

CNgay::CNgay(const CNgay &x)
{
    _ngay = x._ngay;
    _thang = x._thang;
    _nam = x._nam;
}

CNgay::~CNgay()
{
    return;
}