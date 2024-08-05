#include <stdio.h>
#include <iostream>

using namespace std;

class CMaTranNguyen
{
private:
    int **a;
    int m;
    int n;

public:
    // Nhom Khoi tao
    void KhoiTao();
    void KhoiTao(int, int);
    void KhoiTao(CMaTranNguyen);
    // CMangNguyen();
    // CMangNguyen(int *, int);
    // Nhom cung cap thong tin
    int GetDong();
    int GetCot();
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

void CMaTranNguyen::KhoiTao()
{
    if (a != NULL)
    {
        for (int i = 0; i < m; i++)
        {
            delete[] a[i];
        }
        delete[] a;
    }
    a = NULL;
    m = 0;
    n = 0;
}

void CMaTranNguyen::KhoiTao(CMaTranNguyen x)
{
    m = x.m;
    n = x.n;
    a = new int *[m];
    for (int i = 0; i < m; i++)
    {
        a[i] = new int[n];
        for (int j = 0; i < n; j++)
        {
            a[i][j] = x.a[i][j];
        }
    }
}

void CMaTranNguyen::KhoiTao(int mm, int nn)
{
    if (a != NULL)
    {
        for (int i = 0; i < m; i++)
        {
            delete[] a[i];
        }
        delete[] a;
    }
    m = mm;
    n = nn;
    a = new int *[m];
    for (int i = 0; i < m; i++)
    {
        a[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            a[i][j] = 0;
        }
    }
}

int CMaTranNguyen::GetCot()
{
    return m;
}

int CMaTranNguyen::GetDong()
{
    return n;
}

void CMaTranNguyen::Xuat()
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void CMaTranNguyen::SapXepTangDan()
{
    for (int k = 0; k <= m * n - 2; k++)
    {
        for (int l = k + 1; l <= m * n - 1; l++)
        {
            if (a[k / n][k % n] > a[l / n][l % n])
            {
                int temp = a[k / n][k % n];
                a[k / n][k % n] = a[l / n][l % n];
                a[l / n][l % n] = temp;
            }
        }
    }
}

void CMaTranNguyen::SapXepGiamDan()
{
    for (int k = 0; k <= m * n - 2; k++)
    {
        for (int l = k + 1; l <= m * n - 1; l++)
        {
            if (a[k / n][k % n] < a[l / n][l % n])
            {
                int temp = a[k / n][k % n];
                a[k / n][k % n] = a[l / n][l % n];
                a[l / n][l % n] = temp;
            }
        }
    }
}

int CMaTranNguyen::TinhTong()
{
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum += a[i][j];
        }
    }
    return sum;
}

int CMaTranNguyen::CountGiaTriLe()
{
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] % 2 != 0)
            {
                count += 1;
            }
        }
    }
    return count;
}

bool CMaTranNguyen::KiemTraTonTai(int x)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == x)
            {
                return true;
            }
        }
    }
    return false;
}

bool CMaTranNguyen::KiemTraTangDan()
{
    for (int k = 0; k <= m * n - 2; k++)
    {
        if (a[k / n][k % n] > a[(k + 1) / n][(k + 1) % n])
        {
            return false;
        }
    }
    return true;
}