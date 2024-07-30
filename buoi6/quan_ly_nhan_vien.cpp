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
    string _ID;
    string _hoTen;
    string _ngaySinh;
    float _luongCoBan;

public:
    BaseNhanVien(string ID, string hoTen, string ngaySinh, float luongCoBan) : _ID(ID), _hoTen(hoTen), _ngaySinh(ngaySinh), _luongCoBan(luongCoBan) {};

    virtual void Xuat()
    {
        cout << "Nhan Vien | " << "ID: " << _ID << " | " << "Ho ten: " << _hoTen << " | " << "DOB: " << this->_ngaySinh << " | " << endl;
    };
    
    virtual float TinhLuong()
    {
        return _luongCoBan;
    };

    virtual float GetLuong()
    {
        return _luongCoBan;
    }
};

class NhanVienVanPhong : public BaseNhanVien
{
protected:
    float _soNgayDiLam;
    float _troCap;

public:
    NhanVienVanPhong(string ID, string hoTen, string ngaySinh, float luongCoBan, float soNgayDiLam, float troCap) : BaseNhanVien(ID, hoTen, ngaySinh, luongCoBan), _soNgayDiLam(soNgayDiLam), _troCap(troCap) {};
    float TinhLuong()
    {
        return _luongCoBan + (_soNgayDiLam * 100000) + _troCap;
    };
};

class NhanVienSanXuat : public BaseNhanVien
{
protected:
    int _soSanPham;

public:
    NhanVienSanXuat(string ID, string hoTen, string ngaySinh, float luongCoBan, int soSanPham) : BaseNhanVien(ID, hoTen, ngaySinh, luongCoBan), _soSanPham(soSanPham) {};
    float TinhLuong()
    {
        return _luongCoBan + (_soSanPham * 2000);
    };
};

class QuanLy : public BaseNhanVien
{
protected:
    float _heSoChucVu;
    float _thuong;

public:
    QuanLy(string ID, string hoTen, string ngaySinh, float luongCoBan, float heSoChucVu, float thuong) : BaseNhanVien(ID, hoTen, ngaySinh, luongCoBan), _heSoChucVu(heSoChucVu), _thuong(thuong) {};
    float TinhLuong()
    {
        return (_luongCoBan * _heSoChucVu) + _thuong;
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

    BaseNhanVien *ql1 = new QuanLy("NV001", "Nguyen Van A", "1985-05-20", 5000000, 1.2, 1000000);

    // vector<BaseNhanVien> *lstNhanVien = new vector<BaseNhanVien>;

    // lstNhanVien->push_back(*ql1);
    cout << ql1->TinhLuong() << endl;
    cout << ql1->GetLuong() << endl;
    ql1->Xuat();

    // lstNhanVien->push_back(ql2);
    // lstNhanVien->push_back(ql3);

    // CongTy *ct = new CongTy("CTY A", lstNhanVien);
    // ct->Xuat();
    // ct.Xuat();
    return 0;
}