#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

// Nhap toa do 3 dinh A, B, C 1 tam giac. Tinh chu vi, dien tich, tim toa do trong tam

struct _Point
{
    int x, y;
};

typedef struct _Point Point;

struct _Triangle
{
    Point A, B, C;
};

typedef struct _Triangle Triangle;

void inputPoint(Point &);
void inputPoint(Point &p)
{
    cout << "Nhap toa do x: " << endl;
    cin >> p.x;
    cout << "Nhap toa do y: " << endl;
    cin >> p.y;
}

void initTriangle(Triangle &t)
{
    cout << "Nhap toa do Ax: " << endl;
    cin >> t.A.x;
    cout << "Nhap toa do Ay: " << endl;
    cin >> t.A.y;
    cout << "Nhap toa do Bx: " << endl;
    cin >> t.B.x;
    cout << "Nhap toa do By: " << endl;
    cin >> t.B.y;
    cout << "Nhap toa do Cx: " << endl;
    cin >> t.C.x;
    cout << "Nhap toa do Cy: " << endl;
    cin >> t.C.y;
}

float caculateDistance(Point, Point);
float caculateDistance(Point p1, Point p2)
{
    float distance = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.x, 2));
    return distance;
}

float chuVi(Triangle t)
{
    return caculateDistance(t.A, t.B) + caculateDistance(t.A, t.C) + caculateDistance(t.B, t.C);
}

float dienTich(Triangle t)
{
    float a = caculateDistance(t.A, t.B);
    float b = caculateDistance(t.A, t.C);
    float c = caculateDistance(t.B, t.C);
    float avg = (a + b + c) / 2;
    return sqrt(avg * (avg - a) * (avg - b) * (avg - c));
}

void findCenter(Triangle t)
{
    Point p;
    p.x = (t.A.x + t.B.x + t.C.x) / 3;
    p.y = (t.A.y + t.B.y + t.C.y) / 3;
    cout << "Center of triangle x: " << p.x << " y: " << p.y << endl;
}

int main()
{
    Triangle tamGiac;
    initTriangle(tamGiac);
    cout << "Chu vi tam giac: " << chuVi(tamGiac) << endl;
    cout << "Dien tich tam giac: " << dienTich(tamGiac) << endl;
    findCenter(tamGiac);
    cout << "End!";
    return 0;
}