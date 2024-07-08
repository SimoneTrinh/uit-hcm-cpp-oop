#include <stdio.h>
#include <iostream>
using namespace std;
// Khai bao ham va toan tu vao va toan tu ra cho: 9. Lop so phuc z = a + bi;

class CSoPhuc
{
private:
    int a;
    int b;

public:
    friend istream &operator>>(istream &is, CSoPhuc &x);
    friend ostream &operator<<(ostream &os, CSoPhuc &x);
};

istream &operator>>(istream &is, CSoPhuc &x)
{
    cout << "Nhap a:" << endl;
    is >> x.a;
    cout << "Nhap b:" << endl;
    is >> x.b;
    return is;
};

ostream &operator<<(ostream &os, CSoPhuc &x)
{
    os << "So phuc: z = " << x.a << " + " << x.b << "*i";
    return os;
};
