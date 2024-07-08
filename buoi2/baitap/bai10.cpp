#include <stdio.h>
#include <iostream>
using namespace std;
// Khai bao ham va toan tu vao va toan tu ra cho: 10. Lop duong tron r;

class CDuongTron
{
private:
    float r;
    float pi = 3.14;

public:
    friend istream &operator>>(istream &is, CDuongTron &x);
    friend ostream &operator<<(ostream &os, CDuongTron &x);
};

istream &operator>>(istream &is, CDuongTron &x)
{
    cout << "Nhap ban kinh:" << endl;
    is >> x.r;
    return is;
};

ostream &operator<<(ostream &os, CDuongTron &x)
{
    os << "Duong tron co ban kinh: r = " << x.r;
    return os;
};
