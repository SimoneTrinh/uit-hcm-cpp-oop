#include <stdio.h>
#include <iostream>

using namespace std;

/* Yeu cau: Thiet ke Class thuc hien yc sau
 * Chi tiet co the co Chi tiet don va Chi tiet phuc
 * Chi tiet phuc co nhieu Chi tiet don
 * 1. Nhap cac chi tiet cho may
 * 2. Tim chi tiet may theo ma so
 * 3. Tinh tien cho mot chi tiet may hoac cho may
 * 4. Xuat cac chi tiet may
 * 5. Dem so luong chi tiet don trong may
 */

class CChiTiet
{
protected:
    long ID;

public:
    void Nhap();
    void Xuat();
    float TinhTien();
    CChiTiet TimKiem(long);
};

class CChiTietDon : public CChiTiet
{
protected:
    float giaTien;

public:
    void Nhap();
    void Xuat();
    float TinhTien();
    CChiTiet TimKiem(long);
};

class CChiTietPhuc : public CChiTiet
{
protected:
    int n;
    CChiTiet danhSach[100];
    CChiTietPhuc *array[10];

public:
    void Nhap();
    void Xuat();
    float TinhTien();
    CChiTiet TimKiem(long);
};

class CMay
{
protected:
    int n;
    CChiTiet danhSach[100];

public:
    void Nhap();
    void Xuat();
    float TinhTien();
    CChiTiet TimKiem(long);
};

int main()
{
    return 0;
}