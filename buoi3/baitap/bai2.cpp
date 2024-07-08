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
    CDiem operator=(CDiem &);
    CDiem();
    CDiem(string, int);
    CDiem(const CDiem &);
    ~CDiem();
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

CDiem CDiem::operator=(CDiem &x)
{
    _hoTen = x._hoTen;
    _diem = x._diem;
    return *this;
}

CDiem::CDiem()
{
    _hoTen = "Nguyen Van A";
    _diem = 9;
}

CDiem::CDiem(string hoTen, int diem)
{
    _hoTen = hoTen;
    _diem = diem;
}

CDiem::CDiem(const CDiem &x)
{
    _hoTen = x._hoTen;
    _diem = x._diem;
}

CDiem::~CDiem()
{
    return;
}