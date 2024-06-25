#include <stdio.h>
#include <iostream>

using namespace std;
// Nhap vao 2 so phuc, tinh tong, hieu, tich
// z = a + bi
// Tong: z1 + z2 = (a1 + a2) + (b1 + b2)i
// Hieu: z1 - z2 = (a1 - a2) + (b1 - b2)i
// Tich: z1 * z2 = (a1a2 - b1b2) + (a1b2 + a2b1)i

struct _CNumber
{
    int a, b;
};

typedef struct _CNumber CNumber;
void inputCNumber(CNumber &);
void sumCNumber(CNumber, CNumber);
void difCNumber(CNumber, CNumber);
void multiCNumber(CNumber, CNumber);

void inputCNumber(CNumber &z1)
{
    cout << "Nhap a: " << endl;
    cin >> z1.a;
    cout << "Nhap b: " << endl;
    cin >> z1.b;
}

void sumCNumber(CNumber z1, CNumber z2)
{
    cout << "Tong 2 so phuc z1 z2 la: z = " << z1.a + z2.a << " + " << z1.b + z2.b << "i" << endl;
}

void difCNumber(CNumber z1, CNumber z2)
{
    cout << "Hieu 2 so phuc z1 z2 la: z = " << z1.a - z2.a << " + " << z1.b - z2.b << "i" << endl;
}

void multiCNumber(CNumber z1, CNumber z2)
{
    cout << "Tich 2 so phuc z1 z2 la: z1z2 = " << (z1.a * z2.a) - (z1.b * z2.b) << " + " << (z1.a * z2.b + z2.a * z1.b) << "i" << endl;
}

int main()
{
    CNumber z1, z2;
    cout << "Nhap so phuc z1:" << endl;
    inputCNumber(z1);
    cout << "Nhap so phuc z2:" << endl;
    inputCNumber(z2);
    sumCNumber(z1, z2);
    difCNumber(z1, z2);
    multiCNumber(z1, z2);
    cout << "End!";
    return 0;
}