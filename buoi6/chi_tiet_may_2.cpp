#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

/* Yeu cau: Thiet ke Class thuc hien yc sau
 * Chi tiet co the co Chi tiet don va Chi tiet phuc
 * Chi tiet phuc co nhieu Chi tiet don
 * 1. Nhap cac chi tiet cho may
 * 2. Tim chi tiet may theo ma so
 * 3. Tinh tien cho mot chi tiet may hoac cho may
 * 4. Xuat cac chi tiet may
 * 5. Dem so luong chi tiet don trong may
 */
class ChiTiet
{
private:
    string _ID;
    string _TenChiTiet;

public:
    ChiTiet(string ID, string tenChiTiet)
    {
        this->_ID = ID;
        this->_TenChiTiet = tenChiTiet;
    }
    string getID()
    {
        return this->_ID;
    }
};

class ChiTietDon : public ChiTiet
{
private:
    float _GiaTien = 0;

public:
    ChiTietDon(string ID, string tenChiTiet, float giaTien) : ChiTiet(ID, tenChiTiet)
    {
        this->_GiaTien = giaTien;
    }
    float getGiaTien()
    {
        return this->_GiaTien;
    }
};

class ChiTietPhuc : public ChiTiet
{
private:
    vector<ChiTietDon> _lstChiTietDon;
    vector<ChiTietPhuc> _lstChiTietPhuc;
    float _giaTien = 0;

public:
    ChiTietPhuc(string ID, string tenChiTiet, vector<ChiTietDon> lstChiTietDon) : ChiTiet(ID, tenChiTiet)
    {
        this->_lstChiTietDon = lstChiTietDon;
        for (vector<ChiTietDon>::iterator i = lstChiTietDon.begin(); i != lstChiTietDon.end(); i++)
        {
            this->_giaTien += i->getGiaTien();
        }
    }
    ChiTietPhuc(string ID, string tenChiTiet, vector<ChiTietPhuc> lstChiTietPhuc) : ChiTiet(ID, tenChiTiet)
    {
        this->_lstChiTietPhuc = lstChiTietPhuc;
        for (vector<ChiTietPhuc>::iterator i = lstChiTietPhuc.begin(); i != lstChiTietPhuc.end(); i++)
        {
            for (vector<ChiTietDon>::iterator j = i->getListChiTietDon().begin(); j != i->getListChiTietDon().end(); j++)
            {
                this->_giaTien += j->getGiaTien();
            }
        }
    }
    ChiTietPhuc(string ID, string tenChiTiet, vector<ChiTietDon> lstChiTietDon, vector<ChiTietPhuc> lstChiTietPhuc) : ChiTiet(ID, tenChiTiet)
    {
        this->_lstChiTietDon = lstChiTietDon;
        this->_lstChiTietPhuc = lstChiTietPhuc;

        for (vector<ChiTietDon>::iterator i = lstChiTietDon.begin(); i != lstChiTietDon.end(); i++)
        {
            this->_giaTien += i->getGiaTien();
        }

        for (vector<ChiTietPhuc>::iterator i = lstChiTietPhuc.begin(); i != lstChiTietPhuc.end(); i++)
        {
            for (vector<ChiTietDon>::iterator j = i->getListChiTietDon().begin(); j != i->getListChiTietDon().end(); j++)
            {
                this->_giaTien += j->getGiaTien();
            }
        }
    }

    vector<ChiTietDon> getListChiTietDon()
    {
        return this->_lstChiTietDon;
    }

    float getGiaTien()
    {
        return this->_giaTien;
    }
};

class MayMoc
{
private:
    string _ID;
    string _TenMayMoc;
    vector<ChiTietDon> _lstChiTietDon;
    vector<ChiTietPhuc> _lstChiTietPhuc;

public:
    MayMoc(string ID, string tenMayMoc, vector<ChiTietDon> lstChiTietDon)
    {
        this->_ID = ID;
        this->_TenMayMoc = tenMayMoc;
        this->_lstChiTietDon = lstChiTietDon;
    }
    MayMoc(string ID, string tenMayMoc, vector<ChiTietPhuc> lstChiTietPhuc)
    {
        this->_ID = ID;
        this->_TenMayMoc = tenMayMoc;
        this->_lstChiTietPhuc = lstChiTietPhuc;
    }
    MayMoc(string ID, string tenMayMoc, vector<ChiTietDon> lstChiTietDon, vector<ChiTietPhuc> lstChiTietPhuc)
    {
        this->_ID = ID;
        this->_TenMayMoc = tenMayMoc;
        this->_lstChiTietDon = lstChiTietDon;
        this->_lstChiTietPhuc = lstChiTietPhuc;
    }
    bool findChiTiet(string chiTietID)
    {
        if (this->_lstChiTietDon.empty() == false)
        {
            for (vector<ChiTietDon>::iterator i = this->_lstChiTietDon.begin(); i != this->_lstChiTietDon.end(); i++)
            {
                if (i->getID() == chiTietID)
                {
                    return true;
                };
            }
        }
        if (this->_lstChiTietPhuc.empty() == false)
        {
            for (vector<ChiTietPhuc>::iterator i = this->_lstChiTietPhuc.begin(); i != this->_lstChiTietPhuc.end(); i++)
            {
                if (i->getID() == chiTietID)
                {
                    return true;
                };

                for (vector<ChiTietDon>::iterator j = i->getListChiTietDon().begin(); j != i->getListChiTietDon().end(); j++)
                {
                    if (j->getID() == chiTietID)
                    {
                        return true;
                    };
                }
            }
        }
        return false;
    }

    int countChiTietDon()
    {
        int count = 0;
        if (this->_lstChiTietDon.empty() == false)
        {
            count += this->_lstChiTietDon.size();
        }
        if (this->_lstChiTietPhuc.empty() == false)
        {
            for (vector<ChiTietPhuc>::iterator i = this->_lstChiTietPhuc.begin(); i != this->_lstChiTietPhuc.end(); i++)
            {
                count += i->getListChiTietDon().size();
            }
        }
        return count;
    }

    int countChiTietPhuc()
    {
        int count = 0;
        if (this->_lstChiTietPhuc.empty() == false)
        {
            count = this->_lstChiTietPhuc.size();
        }
        return count;
    }

    float getGiaTien()
    {
        float price = 0;
        for (vector<ChiTietDon>::iterator i = this->_lstChiTietDon.begin(); i != this->_lstChiTietDon.end(); i++)
        {
            price += i->getGiaTien();
        }
        for (vector<ChiTietPhuc>::iterator i = this->_lstChiTietPhuc.begin(); i != this->_lstChiTietPhuc.end(); i++)
        {
            price += i->getGiaTien();
        }
        return price;
    }
};

int main()
{
    ChiTietDon ctd1 = ChiTietDon({"D1", "oc vit", 10000});
    ChiTietDon ctd2 = ChiTietDon({"D2", "oc vit 2", 20000});
    ChiTietDon ctd3 = ChiTietDon({"D3", "oc vit 3", 30000});

    vector<ChiTietDon> lstCtd1;
    lstCtd1.push_back(ctd1);
    lstCtd1.push_back(ctd2);

    vector<ChiTietDon> lstCtd2;
    lstCtd2.push_back(ctd2);
    lstCtd2.push_back(ctd3);

    vector<ChiTietDon> lstCtd3;
    lstCtd3.push_back(ctd1);
    lstCtd3.push_back(ctd3);

    ChiTietPhuc ctp1 = ChiTietPhuc({"P1", "motor", lstCtd1});
    ChiTietPhuc ctp2 = ChiTietPhuc({"P2", "motor 2", lstCtd2});

    vector<ChiTietPhuc> lstCtp1;
    lstCtp1.push_back(ctp1);
    lstCtp1.push_back(ctp2);

    ChiTietPhuc ctp3 = ChiTietPhuc({
        "P3",
        "motor 3",
        lstCtp1,
    });

    ChiTietPhuc ctp4 = ChiTietPhuc({
        "P4",
        "motor 4",
        lstCtd1,
        lstCtp1,
    });

    MayMoc m1 = MayMoc({"M1", "May 1", lstCtd3, lstCtp1});

    cout << endl;
    cout << ctd1.getGiaTien() << endl;
    cout << ctd3.getGiaTien() << endl;
    cout << ctp4.getGiaTien() << endl;
    cout << ctp4.getGiaTien() << endl;
    cout << m1.countChiTietDon() << endl;
    cout << m1.countChiTietPhuc() << endl;
    cout << m1.findChiTiet("D1") << endl;
    cout << m1.getGiaTien() << endl;
    return 0;
}