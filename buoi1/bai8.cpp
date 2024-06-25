#include <stdio.h>
#include <iostream>

using namespace std;
// Nhap ban kinh duong tron. Tinh chu vi va dien tich
int pi = 3.14;
struct _Point
{
    int x, y;
};

typedef struct _Point Point;

struct _Round
{
    Point center;
    float r;
};

typedef struct _Round Round;

void inputPoint(Point &);
void inputRound(Round &);
void chuVi(Round);
void dienTich(Round);

void inputPoint(Point &p)
{
    cout << "Nhap toa do x cua trong tam: " << endl;
    cin >> p.x;
    cout << "Nhap toa do y cua trong tam: " << endl;
    cin >> p.y;
}

void inputRound(Round &dtron)
{
    cout << "Nhap toa do trong tam: " << endl;
    inputPoint(dtron.center);
    cout << "Nhap ban kinh: " << endl;
    cin >> dtron.r;
}

void chuVi(Round dtron)
{
    cout << "Chu vi duong tron: " << dtron.r * 2 * pi;
}

void dienTich(Round dtron)
{
    cout << "Dien tich duong tron: " << dtron.r * dtron.r * pi;
}

int main()
{
    Round duongTron;
    inputRound(duongTron);
    chuVi(duongTron);
    dienTich(duongTron);
    cout << "End!";
    return 0;
}