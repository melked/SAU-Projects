#ifndef AVLAgaci_hpp
#define AVLAgaci_hpp
#include<iostream>
#include "Dugum.hpp"
#include "Yigin.hpp" 
using namespace std;


class AVLAgaci
{
public:

	AVLAgaci();
	~AVLAgaci();
	bool varmi(int veri);
	bool bosmu();
	void ekle(int veri);
	void sil(int veri);
    friend ostream& operator<<(ostream& os,AVLAgaci& kuyruk);
	int yukseklik();
	void postOrder();
    void boslukBirak(int adet);
	void yiginaEkle(Yigin& yigin);
	void yiginaEkle(Dugum* aktif, Yigin& yigin);
	void yaprakOlmayanDugumVerileriniYiginaEkle(Yigin& yigin);
	void yaprakOlmayanDugumVerileriniYiginaEkle(Dugum* aktif, Yigin& yigin);
	void temizle();
	void temizleYardimci(Dugum* &aktif);
private:
	int dengesizlikYonu(Dugum* aktif);
	Dugum* solaDondur(Dugum* dugum);
	Dugum* sagaDondur(Dugum* dugum);
	int minDeger(Dugum* aktif);	
	void postOrder(Dugum* index);
	
int yukseklik(Dugum* aktifDugum);
	Dugum* ekle(int veri,Dugum* aktifDugum);
	bool varmi(int aranan,Dugum* aktif);
	Dugum* sil(int veri,Dugum* aktif);
	int maxDeger(Dugum* aktif);
	Dugum* kok;
};

#endif