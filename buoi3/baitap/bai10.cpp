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
    CDuongTron CDuongTron::operator=(CDuongTron &);
    CDuongTron();
    CDuongTron(float, float);
    CDuongTron(CDuongTron &);
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

CDuongTron CDuongTron::operator=(CDuongTron &x)
{
    r = x.r;
    pi = x.pi;
    return *this;
};

CDuongTron::CDuongTron()
{
    r = 1.0;
    pi = 3.14;
}

CDuongTron::CDuongTron(float r1, float pi1)
{
    r = r1;
    pi = pi1;
}

CDuongTron::CDuongTron(CDuongTron &x)
{
    r = x.r;
    pi = x.pi;
}

// CDuuongTron