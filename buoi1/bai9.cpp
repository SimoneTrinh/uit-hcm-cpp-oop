#include <stdio.h>
#include <iostream>

using namespace std;
// Nhap vao 2 phan so. Tinh tong hieu tich thuong

struct _PhanSo
{
    int tuSo, mauSo;
};

typedef struct _PhanSo PhanSo;

void NhapPS(PhanSo &);
void XuatPS(PhanSo);
void TongPS(PhanSo, PhanSo);
void HieuPS(PhanSo, PhanSo);
void TichPS(PhanSo, PhanSo);
void ThuongPS(PhanSo, PhanSo);

void NhapPS(PhanSo &ps)
{
    cout << "Nhap tu so: " << endl;
    cin >> ps.tuSo;
    cout << "Nhap mau so: " << endl;
    cin >> ps.mauSo;
}

void XuatPS(PhanSo ps)
{
    cout << "Phan so: " << ps.tuSo << "/" << ps.mauSo << endl;
}

void TongPS(PhanSo ps1, PhanSo ps2)
{
    PhanSo result;
    result.tuSo = ps1.tuSo * ps2.mauSo + ps1.mauSo * ps2.tuSo;
    result.mauSo = ps1.mauSo * ps2.mauSo;
    cout << "Tong 2 phan so la: ";
    XuatPS(result);
}

void HieuPS(PhanSo ps1, PhanSo ps2)
{
    PhanSo result;
    result.tuSo = ps1.tuSo * ps2.mauSo - ps1.mauSo * ps2.tuSo;
    result.mauSo = ps1.mauSo * ps2.mauSo;
    cout << "Hieu 2 phan so la: ";
    XuatPS(result);
}

void TichPS(PhanSo ps1, PhanSo ps2)
{
    PhanSo result;
    result.tuSo = ps1.tuSo * ps2.tuSo;
    result.mauSo = ps1.mauSo * ps2.mauSo;
    cout << "Tich 2 phan so la: ";
    XuatPS(result);
}

void ThuongPS(PhanSo ps1, PhanSo ps2)
{
    PhanSo result;
    result.tuSo = ps1.tuSo * ps2.mauSo;
    result.mauSo = ps1.mauSo * ps2.tuSo;
    cout << "Thuong 2 phan so la: ";
    XuatPS(result);
}

int main()
{
    PhanSo ps1, ps2;
    cout << "Nhap phan so 1: " << endl;
    NhapPS(ps1);
    cout << "Nhap phan so 2: " << endl;
    NhapPS(ps2);
    TongPS(ps1, ps2);
    HieuPS(ps1, ps2);
    TichPS(ps1, ps2);
    ThuongPS(ps1, ps2);
    return 0;
}