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
