#include <stdio.h>
#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

// Nhap vap toa do 2 diem trong khong gian, tinh khoang cach giua chung
// sqrt(pow(xB - xA) + pow(yB - yA))
// sqrt(pow(xB - xA) + pow(yB - yA) + pow(zB - zA))

struct _Point
{
    int x, y, z;
};

typedef struct _Point Point;

void inputPoint(Point &);
void caculateDistance(Point, Point);

void inputPoint(Point &p)
{
    cout << "Nhap toa do x: " << endl;
    cin >> p.x;
    cout << "Nhap toa do y: " << endl;
    cin >> p.y;
    cout << "Nhap toa do z: " << endl;
    cin >> p.z;
}

float roundToTwoDecimal(float value)
{
    return floor(value * 100 + 0.5) / 100;
}

void caculateDistance(Point p1, Point p2)
{
    float distance = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.x, 2) + pow(p2.z - p1.z, 2));
    cout << "Khoang cach giua 2 diem da cho la: " << roundToTwoDecimal(distance) << endl;
}

int main()
{
    Point *p1 = new Point();
    Point *p2 = new Point();
    cout << "Nhap toa do A:" << endl;
    inputPoint(*p1);
    cout << "Nhap toa do B:" << endl;
    inputPoint(*p2);
    caculateDistance(*p1, *p2);
    cout << "End!";
    return 0;
}