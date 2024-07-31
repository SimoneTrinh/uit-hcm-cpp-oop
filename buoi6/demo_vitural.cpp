#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Buffalo
{
public:
    int old = 22;
    virtual void action() { printf("I'm eating grass\n"); };
};
class YoungBuffalo : public Buffalo
{
public:
    int year = 13;
    void action() { printf("I'm typing keyboard\n"); };
};
void takeAnBuffalo(Buffalo *buffalo)
{
    buffalo->action();
}
int main()
{
    Buffalo *elon = new Buffalo();
    YoungBuffalo *andy = new YoungBuffalo();
    Buffalo *cdy = new YoungBuffalo();
    takeAnBuffalo(elon);
    takeAnBuffalo(andy);
    cout << elon->old << endl;
    cout << andy->year << endl;
    // vector<Buffalo> _lstChiTietDon;
    // _lstChiTietDon.push_back(elon);
    // _lstChiTietDon.push_back(andy);
    // _lstChiTietDon.push_back(cdy);
    // _lstChiTietDon.push_back(2);
    // cout << _lstChiTietDon.empty();

    // for (vector<Buffalo>::iterator i = _lstChiTietDon.begin(); i != _lstChiTietDon.end(); i++)
    // {
    //     cout << *i << " ";
    // }
}