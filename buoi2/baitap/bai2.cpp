#include <stdio.h>
#include <iostream>
using namespace std;
// Khai bao ham va toan tu vao va toan tu ra cho: 2. Lop diem

class CDiem
{
private:
    string _hoTen;
    int _diem;

public:
    friend istream &operator>>(istream &is, CDiem &x);
    friend ostream &operator<<(ostream &os, CDiem &x);
};

istream &operator>>(istream &is, CDiem &x)
{
    cout << "Nhap ho ten:" << endl;
    is >> x._hoTen;
    cout << "Nhap diem:" << endl;
    is >> x._diem;
    return is;
};

ostream &operator<<(ostream &os, CDiem &x)
{
    os << "Ho ten: " << x._hoTen << " | " << "Diem: " << x._diem;
    return os;
};
