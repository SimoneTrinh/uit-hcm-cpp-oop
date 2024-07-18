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
    CSoPhuc();
    CSoPhuc(int, int);
    CSoPhuc(const CSoPhuc &);
    ~CSoPhuc();
    CSoPhuc CSoPhuc::operator=(CSoPhuc &);
    CSoPhuc CSoPhuc::operator+(CSoPhuc x);
    CSoPhuc CSoPhuc::operator-(CSoPhuc x);
    CSoPhuc CSoPhuc::operator*(CSoPhuc x);
    CSoPhuc CSoPhuc::operator/(CSoPhuc x);
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

CSoPhuc CSoPhuc::operator+(CSoPhuc x)
{
    CSoPhuc result;
    result.a = a + x.a;
    result.b = b + x.b;
    return result;
}

CSoPhuc CSoPhuc::operator-(CSoPhuc x)
{
    CSoPhuc result;
    result.a = a - x.a;
    result.b = b - x.b;
    return result;
}

CSoPhuc CSoPhuc::operator*(CSoPhuc x)
{
    CSoPhuc result;
    result.a = a * x.a - b * x.b;
    result.b = a * x.b + b * x.a;
    return result;
}

CSoPhuc CSoPhuc::operator/(CSoPhuc x)
{
    CSoPhuc result;
    result.a = (a * x.a + b * x.b) / (x.a * x.a + x.b * x.b);
    result.b = (b * x.a - a * x.b) / (x.a * x.a + x.b * x.b);
    return result;
}