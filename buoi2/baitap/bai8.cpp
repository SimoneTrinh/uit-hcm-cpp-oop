#include <stdio.h>
#include <iostream>
using namespace std;
// Khai bao ham va toan tu vao va toan tu ra cho: 8. Lop hon so a:(b/c)

class CHonSo
{
private:
    int nguyen;
    int tuSo;
    int mauSo;

public:
    friend istream &operator>>(istream &is, CHonSo &x);
    friend ostream &operator<<(ostream &os, CHonSo &x);
};

istream &operator>>(istream &is, CHonSo &x)
{
    cout << "Nhap phan nguyen:" << endl;
    is >> x.nguyen;
    cout << "Nhap tu so:" << endl;
    is >> x.tuSo;
    cout << "Nhap mau so:" << endl;
    is >> x.mauSo;
    return is;
};

ostream &operator<<(ostream &os, CHonSo &x)
{
    os << "Hon so: " << x.nguyen << ":(" << x.tuSo << "/" << x.mauSo << ")";
    return os;
};
