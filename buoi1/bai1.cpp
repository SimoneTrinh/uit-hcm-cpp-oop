#include <stdio.h>
#include <iostream>

using namespace std;
// Viet chuong trinh nhap vao phan so, check phan so am hay duong hay == 0

struct _phanSo
{
    int tuSo;
    int mauSo;
};

typedef struct _phanSo PhanSo;

void Nhap(PhanSo &);
void Xuat(PhanSo &);
int XetDau(PhanSo &);

void Nhap(PhanSo &ps)
{
    cout << "Nhap tu so: " << endl;
    cin >> ps.tuSo;
    cout << "Nhap mau so: " << endl;
    cin >> ps.mauSo;
}

void Xuat(PhanSo &ps)
{
    cout << "Tu so: " << ps.tuSo << endl;
    cout << "Mau so: " << ps.mauSo << endl;
}

int XetDau(PhanSo &ps)
{
    if (ps.tuSo * ps.mauSo > 0)
    {
        return 1;
    }
    else if (ps.tuSo * ps.mauSo < 0)
    {
        return -1;
    }
    else
        return 0;
}

int main()
{
    PhanSo *a = new PhanSo();
    Nhap(*a);
    Xuat(*a);
    int result = XetDau(*a);
    switch (result)
    {
    case 1:
        cout << "PS da cho la PS duong" << endl;
        break;
    case -1:
        cout << "PS da cho la PS am" << endl;
        break;
    case 0:
        cout << "PS da cho == 0" << endl;
        break;
    default:
        cout << "PS da cho khong hop le" << endl;
        break;
    }
    return 0;
}