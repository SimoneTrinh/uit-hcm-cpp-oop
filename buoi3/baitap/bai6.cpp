#include <stdio.h>
#include <iostream>
using namespace std;
// Khai bao ham va toan tu vao va toan tu ra cho: 6. Lop diem khong gian

class CDiemKhongGian
{
private:
    int x;
    int y;
    int z;

public:
    friend istream &operator>>(istream &is, CDiemKhongGian &x);
    friend ostream &operator<<(ostream &os, CDiemKhongGian &x);
    CDiemKhongGian CDiemKhongGian::operator=(CDiemKhongGian &);
    CDiemKhongGian();
    CDiemKhongGian(int, int, int);
    CDiemKhongGian(const CDiemKhongGian &);
    ~CDiemKhongGian();
};

istream &operator>>(istream &is, CDiemKhongGian &x)
{
    cout << "Nhap x:" << endl;
    is >> x.x;
    cout << "Nhap y:" << endl;
    is >> x.y;
    cout << "Nhap z:" << endl;
    is >> x.z;
    return is;
};

ostream &operator<<(ostream &os, CDiemKhongGian &x)
{
    os << "Diem: " << "(" << x.x << ";" << x.y << ";" << x.z << ")";
    return os;
};

CDiemKhongGian CDiemKhongGian::operator=(CDiemKhongGian &p1)
{
    x = p1.x;
    y = p1.y;
    z = p1.z;
    return *this;
}

CDiemKhongGian::CDiemKhongGian()
{
    x = 1;
    y = 1;
    z = 1;
}

CDiemKhongGian::CDiemKhongGian(int x1, int y1, int z1)
{
    x = x1;
    y = y1;
    z = z1;
}

CDiemKhongGian::CDiemKhongGian(const CDiemKhongGian &p1)
{
    x = p1.x;
    y = p1.y;
    z = p1.z;
}

CDiemKhongGian::~CDiemKhongGian()
{
    return;
}