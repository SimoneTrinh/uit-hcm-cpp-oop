#include <stdio.h>
#include <iostream>

using namespace std;
// Viet chuong trinh nhap vao 1 ngay. Tim ngay truoc do

struct _Date
{
    int DD, MM, YYYY;
};

typedef struct _Date Date;

void Nhap(Date &x, int &LastDay)
{
    cout << "Nhap ngay: ";
    cin >> x.DD;
    cout << "Nhap thang: ";
    cin >> x.MM;
    cout << "Nhap nam: ";
    cin >> x.YYYY;
    switch (x.MM)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        LastDay = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        LastDay = 30;
        break;
    case 2:
        if (x.YYYY % 400 == 0 || (x.YYYY % 4 == 0 && x.YYYY % 100 != 0))
            LastDay = 29;
        else
            LastDay = 28;
        break;
    default:
        LastDay = 0;
    }
    if (LastDay == 0 || x.YYYY < 1 || (LastDay != 0 && (x.DD > LastDay || x.DD < 1)))
    {
        cout << "Ngay thanh nam khong hop le, vui long nhap lai:" << '\n';
        Nhap(x, LastDay);
    }
}
bool laNamNhuan(int nYear)
{
    if ((nYear % 4 == 0 && nYear % 100 != 0) || nYear % 400 == 0)
    {
        return true;
    }
    return false;

    // <=> return ((nYear % 4 == 0 && nYear % 100 != 0) || nYear % 400 == 0);
}

int tinhSoNgayTrongThang(int nMonth, int nYear)
{
    int nNumOfDays;

    switch (nMonth)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        nNumOfDays = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        nNumOfDays = 30;
        break;
    case 2:
        if (laNamNhuan(nYear))
        {
            nNumOfDays = 29;
        }
        else
        {
            nNumOfDays = 28;
        }
        break;
    }

    return nNumOfDays;
}

void PreviousDay(Date x, Date &y, int n)
{
    if (x.DD < n && x.DD > 1)
    {
        y.DD = x.DD - 1;
        y.MM = x.MM;
        y.YYYY = x.YYYY;
    }
    else if (x.DD == 1)
    {
        if (x.MM == 1)
        {
            y.DD = 31;
            y.MM = 12;
            y.YYYY = x.YYYY - 1;
        }
        else
        {
            y.DD = tinhSoNgayTrongThang(x.MM - 1, x.YYYY);
            y.MM = x.MM - 1;
            y.YYYY = x.YYYY;
        }
    }
}
int main()
{
    Date Day1, Day2;
    int LastDay;
    Nhap(Day1, LastDay);
    PreviousDay(Day1, Day2, LastDay);
    cout << "Ngay ke truoc la: " << Day2.DD << "/" << Day2.MM << "/" << Day2.YYYY;
    return 0;
}