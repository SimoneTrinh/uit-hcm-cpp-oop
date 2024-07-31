#include <stdio.h>
#include <iostream>
#include <vector>
#include <iomanip>

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

class Employee
{
protected:
    string _ID;
    string _hoTen;
    string _ngaySinh;
    float _luongCoBan;

public:
    Employee(string ID, string hoTen, string ngaySinh, float luongCoBan) : _ID(ID), _hoTen(hoTen), _ngaySinh(ngaySinh), _luongCoBan(luongCoBan) {}

    virtual void Xuat()
    {
        cout << "Nhan Vien | " << "ID: " << _ID << " | " << "Ho ten: " << _hoTen << " | " << "DOB: " << _ngaySinh << " | " << endl;
    };

    virtual float TinhLuong()
    {
        return _luongCoBan;
    };

    string getID()
    {
        return _ID;
    }
};

class NhanVienVanPhong : public Employee
{
private:
    float _soNgayDiLam;
    float _troCap;

public:
    NhanVienVanPhong(string ID, string hoTen, string ngaySinh, float luongCoBan, float soNgayDiLam, float troCap) : Employee(ID, hoTen, ngaySinh, luongCoBan), _soNgayDiLam(soNgayDiLam), _troCap(troCap) {}
    float TinhLuong()
    {
        return _luongCoBan + (_soNgayDiLam * 100000) + _troCap;
    };
};

class NhanVienSanXuat : public Employee
{
private:
    int _soSanPham;

public:
    NhanVienSanXuat(string ID, string hoTen, string ngaySinh, float luongCoBan, int soSanPham) : Employee(ID, hoTen, ngaySinh, luongCoBan), _soSanPham(soSanPham) {}
    float TinhLuong()
    {
        return _luongCoBan + (_soSanPham * 2000);
    };
};

class QuanLy : public Employee
{
private:
    float _heSoChucVu;
    float _thuong;

public:
    QuanLy(string ID, string hoTen, string ngaySinh, float luongCoBan, float heSoChucVu, float thuong) : Employee(ID, hoTen, ngaySinh, luongCoBan), _heSoChucVu(heSoChucVu), _thuong(thuong) {}
    float TinhLuong()
    {
        return (_luongCoBan * _heSoChucVu) + _thuong;
    };
};

class CongTy
{
private:
    string _tenCongTy;
    vector<Employee *> *_listNhanVien; // Employee here is Pointer because of need Polymorphism

public:
    CongTy(string tenCongTy, vector<Employee *> *listNhanVien) : _tenCongTy(tenCongTy), _listNhanVien(listNhanVien) {}
    void Xuat()
    {
        cout << "-------- Danh sach nhan vien -------" << endl;
        for (int i = 0; i < _listNhanVien->size(); i++)
        {
            _listNhanVien->at(i)->Xuat();
        }
    };

    float TongLuong()
    {
        float luong = 0;
        for (int i = 0; i < _listNhanVien->size(); i++)
        {
            luong += _listNhanVien->at(i)->TinhLuong();
        }
        return luong;
    }

    Employee *TimKiem(string ID)
    {
        for (int i = 0; i < _listNhanVien->size(); i++)
        {
            if (_listNhanVien->at(i)->getID() == ID)
            {
                return _listNhanVien->at(i);
                break;
            }
        }
        return NULL;
    };
};

int main()
{
    Employee *ql1 = new QuanLy("QL001", "Nguyen QL A", "1985-05-20", 5000000, 1.2, 2000000);
    Employee *ql2 = new QuanLy("QL002", "Nguyen QL B", "1985-05-20", 8000000, 1.5, 3000000);
    Employee *ql3 = new QuanLy("QL003", "Nguyen QL C", "1985-05-20", 10000000, 1.7, 3500000);
    Employee *nvvp1 = new NhanVienVanPhong("NVVP001", "Nguyen VP A", "1985-05-20", 5000000, 22, 300000);
    Employee *nvvp2 = new NhanVienVanPhong("NVVP002", "Nguyen VP B", "1985-05-20", 5500000, 22.5, 350000);
    Employee *nvvp3 = new NhanVienVanPhong("NVVP003", "Nguyen VP C", "1985-05-20", 6000000, 21, 300000);
    Employee *nvsx1 = new NhanVienSanXuat("NVSX001", "Nguyen SX A", "1985-05-20", 2000000, 3000);
    Employee *nvsx2 = new NhanVienSanXuat("NVSX002", "Nguyen SX B", "1985-05-20", 2100000, 3500);
    Employee *nvsx3 = new NhanVienSanXuat("NVSX003", "Nguyen SX C", "1985-05-20", 2200000, 3800);

    vector<Employee *> *lstNhanVien = new vector<Employee *>;

    lstNhanVien->push_back(ql1);
    lstNhanVien->push_back(ql2);
    lstNhanVien->push_back(ql3);
    lstNhanVien->push_back(nvvp1);
    lstNhanVien->push_back(nvvp2);
    lstNhanVien->push_back(nvvp3);
    lstNhanVien->push_back(nvsx1);
    lstNhanVien->push_back(nvsx2);
    lstNhanVien->push_back(nvsx3);

    cout.precision(2);

    ql1->Xuat();
    cout << fixed << "Luong Quan Ly 1: " << ql1->TinhLuong() << endl;
    nvvp1->Xuat();
    cout << fixed << "Luong NV van phong 1: " << nvvp1->TinhLuong() << endl;
    nvsx1->Xuat();
    cout << fixed << "Luong NV san xuat 1: " << nvsx1->TinhLuong() << endl;

    CongTy *ct = new CongTy("CTY A", lstNhanVien);
    ct->Xuat();
    cout << fixed << "Tong luong cua cong ty: " << ct->TongLuong() << endl;

    cout << "------- Tim kiem nhan vien ma NV QL003 --------" << endl;
    ct->TimKiem("QL003")->Xuat();

    cout << "------- Tim kiem nhan vien ma NV NVVP002 --------" << endl;
    ct->TimKiem("NVVP002")->Xuat();

    return 0;
}