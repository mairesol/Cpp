#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum NguongChiSo
{
    ChiSoThap = 30,
    ChiSoCao = 70
};

class Personality
{
protected:
public:
    int gia_tri;
    Personality(int = 0);
    ~Personality();

    virtual void DacDiem() = 0;
    int MucChiSo();
};

class Openness : public Personality
{
public:
    Openness(int = 0);
    ~Openness();

    void DacDiem();
};

class Coscientiouness : public Personality
{
public:
    Coscientiouness(int = 0);
    ~Coscientiouness();

    void DacDiem();
};

class Extraversion : public Personality
{
public:
    Extraversion(int = 0);
    ~Extraversion();

    void DacDiem();
};

class Agreeableness : public Personality
{
public:
    Agreeableness(int = 0);
    ~Agreeableness();

    void DacDiem();
};

class Neuroticism : public Personality
{
public:
    Neuroticism(int = 0);
    ~Neuroticism();

    void DacDiem();
};

class Person
{
private:
    vector<Personality *> l;

public:
    void nhap();
    void tinh_cach();
    bool luu_y();
};