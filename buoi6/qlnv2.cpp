#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BaseNhanVien
{
protected:
    string ID;
    string hoTen;
    string ngaySinh;
    float luongCoBan;

public:
    BaseNhanVien(string ID, string hoTen, string ngaySinh, float luongCoBan)
        : ID(ID), hoTen(hoTen), ngaySinh(ngaySinh), luongCoBan(luongCoBan) {}

    virtual void Xuat()
    {
        cout << "Nhan Vien | " << "ID: " << this->ID << " | " << "Ho ten: " << this->hoTen << " | " << "DOB: " << this->ngaySinh << " | " << endl;
    }

    virtual float TinhLuong() const = 0;
};

class NhanVienVanPhong : public BaseNhanVien
{
protected:
    float soNgayDiLam;
    float troCap;

public:
    NhanVienVanPhong(string ID, string hoTen, string ngaySinh, float luongCoBan, float soNgayDiLam, float troCap)
        : BaseNhanVien(ID, hoTen, ngaySinh, luongCoBan), soNgayDiLam(soNgayDiLam), troCap(troCap) {}

    float TinhLuong() const override
    {
        return this->luongCoBan + (this->soNgayDiLam * 100000) + this->troCap;
    }

    void Xuat() override
    {
        BaseNhanVien::Xuat();
        cout << "So ngay di lam: " << this->soNgayDiLam << " | Tro cap: " << this->troCap << endl;
    }
};

class NhanVienSanXuat : public BaseNhanVien
{
protected:
    int soSanPham;

public:
    NhanVienSanXuat(string ID, string hoTen, string ngaySinh, float luongCoBan, int soSanPham)
        : BaseNhanVien(ID, hoTen, ngaySinh, luongCoBan), soSanPham(soSanPham) {}

    float TinhLuong() const override
    {
        return this->luongCoBan + (this->soSanPham * 2000);
    }

    void Xuat() override
    {
        BaseNhanVien::Xuat();
        cout << "So san pham: " << this->soSanPham << endl;
    }
};

class QuanLy : public BaseNhanVien
{
protected:
    float heSoChucVu;
    float thuong;

public:
    QuanLy(string ID, string hoTen, string ngaySinh, float luongCoBan, float heSoChucVu, float thuong)
        : BaseNhanVien(ID, hoTen, ngaySinh, luongCoBan), heSoChucVu(heSoChucVu), thuong(thuong) {}

    float TinhLuong() const override
    {
        return this->luongCoBan * this->heSoChucVu + this->thuong;
    }

    void Xuat() override
    {
        BaseNhanVien::Xuat();
        cout << "He so chuc vu: " << this->heSoChucVu << " | Thuong: " << this->thuong << endl;
    }
};

class CongTy
{
protected:
    string tenCongTy;
    vector<BaseNhanVien *> listNhanVien;

public:
    CongTy(string tenCongTy, const vector<BaseNhanVien *> &listNhanVien)
        : tenCongTy(tenCongTy), listNhanVien(listNhanVien) {}

    ~CongTy()
    {
        for (auto nv : listNhanVien)
        {
            delete nv;
        }
    }

    void Xuat() const
    {
        cout << "-------- Danh sach nhan vien -------" << endl;
        for (const auto &nv : listNhanVien)
        {
            nv->Xuat();
        }
    }

    float TongLuong() const
    {
        float tongLuong = 0;
        for (const auto &nv : listNhanVien)
        {
            tongLuong += nv->TinhLuong();
        }
        return tongLuong;
    }
};

int main()
{
    QuanLy *ql1 = new QuanLy("NV001", "Nguyen Van A", "1985-05-20", 5000000, 1.2, 1000000);
    NhanVienVanPhong *nvvp1 = new NhanVienVanPhong("NV002", "Tran Thi B", "1990-03-15", 3000000, 22, 500000);
    NhanVienSanXuat *nvsx1 = new NhanVienSanXuat("NV003", "Le Van C", "1992-07-10", 2500000, 1200);

    vector<BaseNhanVien *> lstNhanVien;
    lstNhanVien.push_back(ql1);
    lstNhanVien.push_back(nvvp1);
    lstNhanVien.push_back(nvsx1);

    cout << "Luong Quan Ly: " << ql1->TinhLuong() << endl;
    cout << "Luong Nhan Vien Van Phong: " << nvvp1->TinhLuong() << endl;
    cout << "Luong Nhan Vien San Xuat: " << nvsx1->TinhLuong() << endl;

    CongTy *ct = new CongTy("CTY A", lstNhanVien);
    ct->Xuat();
    cout << "Tong Luong: " << ct->TongLuong() << endl;

    delete ct; // Clean up dynamically allocated memory

    return 0;
}
