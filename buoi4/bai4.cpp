#include <stdio.h>
#include <iostream>
using namespace std;

class CHonSo
{
private:
    int nguyen;
    int tuSo;
    int mauSo;

public:
    friend istream &operator>>(istream &is, CHonSo &x);
    friend ostream &operator<<(ostream &os, CHonSo &x);
    CHonSo();
    CHonSo(int, int, int);
    CHonSo(const CHonSo &);
    ~CHonSo();
    CHonSo CHonSo::operator=(CHonSo &);
    CHonSo CHonSo::operator+(CHonSo x);
    CHonSo CHonSo::operator-(CHonSo x);
    CHonSo CHonSo::operator*(CHonSo x);
    CHonSo CHonSo::operator/(CHonSo x);
    CHonSo CHonSo::operator++();
    CHonSo CHonSo::operator--();
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

CHonSo CHonSo::operator=(CHonSo &x)
{
    nguyen = x.nguyen;
    tuSo = x.tuSo;
    mauSo = x.mauSo;
    return *this;
}

CHonSo::CHonSo()
{
    nguyen = 1;
    tuSo = 2;
    mauSo = 3;
}

CHonSo::CHonSo(int nguyen1, int tuSo1, int mauSo1)
{
    nguyen = nguyen1;
    tuSo = tuSo1;
    mauSo = mauSo1;
}

CHonSo::CHonSo(const CHonSo &x)
{
    nguyen = x.nguyen;
    tuSo = x.tuSo;
    mauSo = x.mauSo;
}

CHonSo::~CHonSo()
{
    return;
}

CHonSo CHonSo::operator+(CHonSo x)
{
    CHonSo result;
    result.nguyen = nguyen + x.nguyen;
    result.tuSo = tuSo * x.mauSo + x.tuSo * mauSo;
    result.mauSo = mauSo * x.mauSo;
    return result;
}

CHonSo CHonSo::operator-(CHonSo x)
{
    CHonSo result;
    result.nguyen = nguyen - x.nguyen;
    result.tuSo = tuSo * x.mauSo - x.tuSo * mauSo;
    result.mauSo = mauSo * x.mauSo;
    return result;
}

CHonSo CHonSo::operator*(CHonSo x)
{
    CHonSo result;
    result.nguyen = nguyen * x.nguyen;
    result.tuSo = tuSo * x.tuSo;
    result.mauSo = mauSo * x.mauSo;
    return result;
}

CHonSo CHonSo::operator/(CHonSo x)
{
    CHonSo result;
    result.nguyen = nguyen / x.nguyen;
    result.tuSo = tuSo * x.mauSo;
    result.mauSo = mauSo * x.tuSo;
    return result;
}

CHonSo CHonSo::operator++()
{
    CHonSo result;
    result.nguyen = nguyen + nguyen;
    result.tuSo = tuSo + tuSo;
    result.mauSo = mauSo;
    return result;
}

CHonSo CHonSo::operator--()
{
    CHonSo result;
    result.nguyen = nguyen - nguyen;
    result.tuSo = tuSo - tuSo;
    result.mauSo = mauSo;
    return result;
}