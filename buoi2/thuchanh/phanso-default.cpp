#include <stdio.h>
#include <iostream>
using namespace std;
// Khai bao ham va toan tu vao va toan tu ra cho: 1. Lop Phan so

struct _PhanSo
{
    int tuSo;
    int mauSo;
};

typedef struct _PhanSo PhanSo;

void Nhap(PhanSo &x)
{
    cout << "Nhap tu: ";
    cin >> x.tuSo;
    cout << "Nhap mau: ";
    cin >> x.mauSo;
}

void Xuat(PhanSo x)
{
    cout << x.tuSo << "/" << x.mauSo;
}