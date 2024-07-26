#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

/* Cong ty ABC sx kinh doanh
 * 3 bo phan: Quan ly, San xuat, Van Phong
 * Luong VP = LCB + Ngay * 100000 + Tro cap
 * Luong SX = LCB + SP * 2000
 * Luong QL = LCB * He so chuc vu + Thuong
 * Can quan ly them: Ho ten, ngay sinh
 * 1. Tinh luong nhan vien
 * 2. Xuat thong tin NV
 * 3. Tinh tong luong cty
 * 4. Tim hiem NV theo ho ten
 */

class BaseNhanVien
{
protected:
    string ID;
    string hoTen;
    string ngaySinh;
    float luongCoBan;

public:
    BaseNhanVien(string ID, string hoTen, string ngaySinh, float luongCoBan)
    {
        this->ID = ID;
        this->hoTen = hoTen;
        this->ngaySinh = ngaySinh;
        this->luongCoBan = luongCoBan;
    };
    virtual void Xuat()
    {
        cout << "Nhan Vien | " << "ID: " << this->ID << " | " << "Ho ten: " << this->hoTen << " | " << "DOB: " << this->ngaySinh << " | " << endl;
    };
};

class NhanVienVanPhong : public BaseNhanVien
{
protected:
    float soNgayDiLam;
    float troCap;

public:
    NhanVienVanPhong(float soNgayDiLam, float troCap) : BaseNhanVien(ID, hoTen, ngaySinh, luongCoBan)
    {
        this->soNgayDiLam = soNgayDiLam;
        this->troCap = troCap;
    };
    float TinhLuong()
    {
        return this->luongCoBan + (this->soNgayDiLam * 100000) + this->troCap;
    };
};

class NhanVienSanXuat : public BaseNhanVien
{
protected:
    int soSanPham;

public:
    NhanVienSanXuat(int soSanPham) : BaseNhanVien(ID, hoTen, ngaySinh, luongCoBan)
    {
        this->soSanPham = soSanPham;
    }
    float TinhLuong()
    {
        return this->luongCoBan + (this->soSanPham * 2000);
    };
};

class QuanLy : public BaseNhanVien
{
protected:
    float heSoChucVu;
    float thuong;

public:
    QuanLy(string ID, string hoTen, string ngaySinh, float luongCoBan, float heSoChucVu, float thuong) : BaseNhanVien(ID, hoTen, ngaySinh, luongCoBan)
    {
        this->heSoChucVu = heSoChucVu;
        this->thuong = thuong;
    };
    float TinhLuong()
    {
        return this->luongCoBan;
    };
};

class CongTy
{
protected:
    string tenCongTy;
    vector<BaseNhanVien> *listNhanVien;

public:
    CongTy(string tenCongTy, vector<BaseNhanVien> *listNhanVien)
    {
        this->tenCongTy = tenCongTy;
        this->listNhanVien = listNhanVien;
    };
    void Xuat()
    {
        cout << "-------- Danh sach nhan vien -------" << endl;
        for (vector<BaseNhanVien>::iterator i = this->listNhanVien->begin(); i != this->listNhanVien->end(); i++)
        {
            i->Xuat();
        }
    };
    float TongLuong();
    BaseNhanVien *TimKiem(string);
};

// float CongTy::TongLuong()
// {
//     float luong = 0;
//     for (int i = 0; i < this->listNhanVien.size(); i++)
//     {
//         luong += listNhanVien[i].TinhLuong();
//     }
//     return luong;
// }

int main()
{
    // QuanLy *ql1, ql2, ql3, ql4, ql5;

    QuanLy *ql1 = new QuanLy("NV001", "Nguyen Van A", "1985-05-20", 5000000, 1.2, 1000000);

    vector<BaseNhanVien> *lstNhanVien = new vector<BaseNhanVien>;

    QuanLy *ql = nullptr;
    lstNhanVien->push_back(*ql1);
    ql = ql1;
    cout << (*ql).TinhLuong() << endl;

    // lstNhanVien->push_back(ql2);
    // lstNhanVien->push_back(ql3);

    CongTy *ct = new CongTy("CTY A", lstNhanVien);
    ct->Xuat();
    // ct.Xuat();
    return 0;
}