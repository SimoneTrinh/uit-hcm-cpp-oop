#include <stdio.h>
#include <iostream>

using namespace std;
// Nhap vao 2 phan so. Tim phan so lon nhat va xuat ket qua

struct _PhanSo
{
    int tuSo, mauSo;
};

typedef struct _PhanSo PhanSo;

void NhapPhanSo(PhanSo &);
void Compare2PhanSo(PhanSo, PhanSo);

void NhapPhanSo(PhanSo &ps)
{
    cout << "Nhap tu so: " << endl;
    cin >> ps.tuSo;
    cout << "Nhap mau so: " << endl;
    cin >> ps.mauSo;
}

void Compare2PhanSo(PhanSo ps1, PhanSo ps2)
{
    float valuePs1 = (float)ps1.tuSo / ps1.mauSo;
    float valuePs2 = (float)ps2.tuSo / ps2.mauSo;
    if (valuePs1 > valuePs2)
    {
        cout << "Phan so A lon hon phan so B" << endl;
    }
    else if (valuePs1 < valuePs2)
    {
        cout << "Phan so A nho hon phan so B" << endl;
    }
    else
        cout << "2 Phan so bang nhau" << endl;
}

int main()
{
    PhanSo *ps1 = new PhanSo();
    PhanSo *ps2 = new PhanSo();
    cout << "Nhap phan so A: " << endl;
    NhapPhanSo(*ps1);
    cout << "Nhap phan so B: " << endl;
    NhapPhanSo(*ps2);
    Compare2PhanSo(*ps1, *ps2);
    cout << "End!";
    return 0;
}