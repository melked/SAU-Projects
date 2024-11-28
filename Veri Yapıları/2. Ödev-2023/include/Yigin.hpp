#ifndef Yigin_hpp
#define Yigin_hpp
#include<iostream>
#include "Dugum.hpp"

using namespace std;

class Yigin
{
public:
	Yigin();
	~Yigin();
	void ekle(int veri);
	void cikar();
    bool bosmu();
    bool dolumu();
	int getir();
	int elemanSayisi();
	int elemanlariTopla();
    void temizle();
    friend ostream& operator<<(ostream& os,Yigin& yigin);
private:
	void genislet(int boyut);
	int kapasite;
    int tepe;
	int* veriler;
};

#endif