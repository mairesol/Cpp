#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class NotNhac
{

private:
    string cao_do;
    string truong_do;

public:
    NotNhac(string = "", string = "");
    ~NotNhac();
    virtual char get_cao_do();
    double get_truong_do();
    friend ostream &operator<<(ostream &, const NotNhac &);
};

class DauLang : public NotNhac
{
public:
    DauLang(string = "");
    ~DauLang();
    char get_cao_do();
    void output();
};

class BanNhac
{
private:
    string ten;
    string tac_gia;
    unsigned int nam_sang_tac;
    vector<NotNhac *> ban_nhac;

public:
    ~BanNhac();

    void nhap();
    void xuat();
    int so_dau_lang_den();
    NotNhac cao_do_lon_nhat();
};

int bac_cao_do(NotNhac *);