#include <stdio.h>
#include <iostream>
using namespace std;
class CPhanSo
{
private:
    int _tuSo;
    int _mauSo;

public:
    friend istream &operator>>(istream &is, CPhanSo &x);
    friend ostream &operator<<(ostream &os, CPhanSo &x);
    CPhanSo();
    CPhanSo(int, int);
    CPhanSo(const CPhanSo &);
    void print();
    CPhanSo operator=(CPhanSo &);
    CPhanSo operator+(CPhanSo x);
    CPhanSo operator-(CPhanSo x);
    CPhanSo operator*(CPhanSo x);
    CPhanSo operator/(CPhanSo x);
    CPhanSo operator++();
    CPhanSo operator--();
    bool operator>(CPhanSo x);
    bool operator<(CPhanSo x);
    bool operator>=(CPhanSo x);
    bool operator<=(CPhanSo x);
    bool operator==(CPhanSo x);
    bool operator!=(CPhanSo x);
    ~CPhanSo();
};

istream &operator>>(istream &is, CPhanSo &x)
{
    cout << "Nhap tu:" << endl;
    is >> x._tuSo;
    cout << "Nhap mau:" << endl;
    is >> x._mauSo;
    return is;
};

ostream &operator<<(ostream &os, CPhanSo &x)
{
    os << x._tuSo << "/" << x._mauSo;
    return os;
};

CPhanSo CPhanSo::operator=(CPhanSo &x)
{
    _tuSo = x._tuSo;
    _mauSo = x._mauSo;
    return *this;
}

CPhanSo::CPhanSo()
{
    _tuSo = 2;
    _mauSo = 3;
}

CPhanSo::CPhanSo(int tuSo, int mauSo)
{
    _tuSo = tuSo;
    _mauSo = mauSo;
}

CPhanSo::CPhanSo(const CPhanSo &x)
{
    _tuSo = x._tuSo;
    _mauSo = x._mauSo;
}

CPhanSo::~CPhanSo()
{
    return;
}

void CPhanSo::print()
{
    cout << "Phan so: " << _tuSo << "/" << _mauSo << endl;
}

CPhanSo CPhanSo::operator+(CPhanSo x)
{
    CPhanSo result;
    result._tuSo = _tuSo * x._mauSo + _mauSo * x._tuSo;
    result._mauSo = _mauSo * x._mauSo;
    return result;
}

CPhanSo CPhanSo::operator-(CPhanSo x)
{
    CPhanSo result;
    result._tuSo = _tuSo * x._mauSo - _mauSo * x._tuSo;
    result._mauSo = _mauSo * x._mauSo;
    return result;
}

CPhanSo CPhanSo::operator*(CPhanSo x)
{
    CPhanSo result;
    result._tuSo = _tuSo * x._tuSo;
    result._mauSo = _mauSo * x._mauSo;
    return result;
}

CPhanSo CPhanSo::operator/(CPhanSo x)
{
    CPhanSo result;
    result._tuSo = _tuSo * x._mauSo;
    result._mauSo = _mauSo * x._tuSo;
    return result;
}

CPhanSo CPhanSo::operator++()
{
    CPhanSo result;
    result._tuSo = _tuSo + _tuSo;
    result._mauSo = _mauSo;
    return result;
}

CPhanSo CPhanSo::operator--()
{
    CPhanSo result;
    result._tuSo = _tuSo - _tuSo;
    result._mauSo = _mauSo;
    return result;
}

bool CPhanSo::operator>(CPhanSo x)
{
    CPhanSo temp = *this - x;
    if (temp._tuSo * temp._mauSo > 0)
    {
        return true;
    }
    else
        return false;
}

bool CPhanSo::operator<(CPhanSo x)
{
    CPhanSo temp = *this - x;
    if (temp._tuSo * temp._mauSo < 0)
    {
        return true;
    }
    else
        return false;
}

bool CPhanSo::operator>=(CPhanSo x)
{
    CPhanSo temp = *this - x;
    if (temp._tuSo * temp._mauSo >= 0)
    {
        return true;
    }
    else
        return false;
}

bool CPhanSo::operator<=(CPhanSo x)
{
    CPhanSo temp = *this - x;
    if (temp._tuSo * temp._mauSo <= 0)
    {
        return true;
    }
    else
        return false;
}

bool CPhanSo::operator==(CPhanSo x)
{
    CPhanSo temp = *this - x;
    if (temp._tuSo * temp._mauSo == 0)
    {
        return true;
    }
    else
        return false;
}

bool CPhanSo::operator!=(CPhanSo x)
{
    CPhanSo temp = *this - x;
    if (temp._tuSo * temp._mauSo != 0)
    {
        return true;
    }
    else
        return false;
}

int main()
{
    CPhanSo ps;
    ps.print();
    return 0;
}