#include <stdio.h>
#include <iostream>

using namespace std;

class CMangNguyen
{
private:
    int *arr;
    int num;

public:
    // Nhom Khoi tao
    void KhoiTao();
    void KhoiTao(int *, int);
    void KhoiTao(CMangNguyen);
    // CMangNguyen();
    // CMangNguyen(int *, int);
    // Nhom cung cap thong tin
    int getSoPhanTu();
    void Xuat();
    // Nhom cap nhat thong tin
    void SapXepTangDan();
    void SapXepGiamDan();
    // Nhom Xu ly
    int TinhTong();
    int CountGiaTriLe();
    // int DemXuatHien(int);
    // Nhom Kiem Tra
    bool KiemTraTonTai(int);
    // int KiemTraToanChan();
    bool KiemTraTangDan();
};

void CMangNguyen::KhoiTao()
{
    if (arr != NULL)
    {
        delete[] arr;
    }
    arr = NULL;
    num = 0;
}

void CMangNguyen::KhoiTao(int *pArr, int n)
{
    if (arr != NULL)
    {
        delete[] arr;
    }
    num = n;
    arr = new int[num];
    for (int i = 0; i < num; i++)
    {
        arr[i] = pArr[i];
    }
}

void CMangNguyen::KhoiTao(CMangNguyen cMangNguyen)
{
    if (arr != NULL)
    {
        delete[] arr;
    }
    num = cMangNguyen.num;
    arr = new int[num];
    for (int i = 0; i < num; i++)
    {
        arr[i] = cMangNguyen.arr[i];
    }
}

int CMangNguyen::getSoPhanTu()
{
    return num;
}

void CMangNguyen::Xuat()
{
    for (int i = 0; i < num; i++)
    {
        cout << arr[i] << " | ";
    }
}

void CMangNguyen::SapXepTangDan()
{
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void CMangNguyen::SapXepGiamDan()
{
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            if (arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int CMangNguyen::TinhTong()
{
    int result = 0;
    for (int i = 0; i < num; i++)
    {
        result += arr[i];
    }
    return result;
};

int CMangNguyen::CountGiaTriLe()
{
    int count = 0;
    for (int i = 0; i < num; i++)
    {
        if (arr[i] % 2 == 1)
        {
            count += 1;
        }
    }
    return count;
}

bool CMangNguyen::KiemTraTonTai(int x)
{
    for (int i = 0; i < num; i++)
    {
        if (arr[i] == x)
        {
            return true;
            break;
        }
    }
    return false;
}

bool CMangNguyen::KiemTraTangDan()
{
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            if (arr[i] > arr[j])
            {
                return false;
            }
        }
    }
    return true;
}

main()
{
    CMangNguyen cMangNguyen;
    int arr[] = {552, 535, 380, 963, 520, 79, 39, 986, 623, 817, 890, 853, 574, 828, 60, 90, 809, 598, 643, 591};
    int *pArr = arr;
    int num = 20;

    cMangNguyen.KhoiTao(pArr, num);
    cMangNguyen.Xuat();
    cout << endl;
    printf("So phan tu cua mang: %d \n", cMangNguyen.getSoPhanTu());

    cMangNguyen.SapXepGiamDan();
    cout << "Mang sau khi sap xep giam dan: ";
    cMangNguyen.Xuat();
    cout << endl;

    cMangNguyen.SapXepTangDan();
    cout << "Mang sau khi sap xep tang dan: ";
    cMangNguyen.Xuat();
    cout << endl;

    printf("Tong cac gia tri cua mang: %d \n", cMangNguyen.TinhTong());
    printf("So cac gia tri le cua mang: %d \n", cMangNguyen.CountGiaTriLe());
    printf("Ton tai gia tri 90 khong: %d \n", cMangNguyen.KiemTraTonTai(90));
    printf("Ton tai gia tri 33 khong: %d \n", cMangNguyen.KiemTraTonTai(33));
    printf("Mang co phai tang dan khong: %d \n", cMangNguyen.KiemTraTangDan());

    cMangNguyen.SapXepGiamDan();
    cout << "Mang sau khi sap xep giam dan: ";
    cMangNguyen.Xuat();
    cout << endl;
    printf("Mang co phai tang dan khong: %d \n", cMangNguyen.KiemTraTangDan());

    return 0;
}
