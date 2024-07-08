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
    CSoPhuc CSoPhuc::operator=(CSoPhuc &);
    CSoPhuc();
    CSoPhuc(int, int);
    CSoPhuc(const CSoPhuc &);
    ~CSoPhuc();
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

CSoPhuc CSoPhuc::operator=(CSoPhuc &x)
{
    a = x.a;
    b = x.b;
}

CSoPhuc::CSoPhuc()
{
    a = 1;
    b = 1;
}

CSoPhuc::CSoPhuc(int x, int y)
{
    a = x;
    b = y;
}

CSoPhuc::CSoPhuc(const CSoPhuc &x)
{
    a = x.a;
    b = x.b;
}

CSoPhuc::~CSoPhuc()
{
    return;
}