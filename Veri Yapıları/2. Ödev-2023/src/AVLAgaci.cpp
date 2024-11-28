/**
 * @file        G211210003
 * @description Yığın ve AVL ağacı kullanarak program yazma
 * @course      2. öğretim B grubu
 * @assignment  2. Ödev
 * @date        21.12.2023
 * @author      Melike Demirtaş
 */

#include "AVLAgaci.hpp"
#include "Yigin.hpp"
#include <cmath>
#include <iomanip>
#include<iostream>
#include<queue>
using namespace std;
AVLAgaci::AVLAgaci()
{
    kok= 0;
}
AVLAgaci::~AVLAgaci()
{
    temizleYardimci(kok);

}
bool AVLAgaci::varmi(int veri) 
{
    varmi(veri,kok);
}
void AVLAgaci::ekle(int eklenecek)
{
    kok = ekle(eklenecek,kok);
}
void AVLAgaci::sil(int veri) 
{
	kok = sil(veri,kok);
}
int AVLAgaci::yukseklik() 
{
	return yukseklik(kok);
}

void AVLAgaci::postOrder() {
    postOrder(kok);  
    cout<<endl;
}


void AVLAgaci::postOrder(Dugum* aktif) {
    if (aktif) {
        postOrder(aktif->sol);
        postOrder(aktif->sag);
        cout << aktif->veri << "  ";
    }
}


int AVLAgaci::yukseklik(Dugum* aktifDugum) 
{
	if(aktifDugum)
    {
        return 1+max(   yukseklik(aktifDugum->sol),
                        yukseklik(aktifDugum->sag));
    }
    return -1;
}
Dugum* AVLAgaci::ekle(int veri,Dugum* aktifDugum) 
{
    if(aktifDugum==0)
    return new Dugum(veri);

	else if(aktifDugum->veri<veri)
    {
        aktifDugum->sag=ekle(veri,aktifDugum->sag);
        if(yukseklik(aktifDugum->sag)-yukseklik(aktifDugum->sol)>1)
        {   
            if(veri>aktifDugum->sag->veri)
                aktifDugum = solaDondur(aktifDugum);
                
            else
            {
                aktifDugum->sag = sagaDondur(aktifDugum->sag);
                aktifDugum =solaDondur(aktifDugum);
            }
        }
    }
    else if(aktifDugum->veri>veri)
    {
        aktifDugum->sol = ekle(veri,aktifDugum->sol);
        if(yukseklik(aktifDugum->sol)-yukseklik(aktifDugum->sag)>1)
        {

            if(veri<aktifDugum->sol->veri)
                aktifDugum = sagaDondur(aktifDugum);
            else
            {
                aktifDugum->sol = solaDondur(aktifDugum->sol);
                aktifDugum =sagaDondur(aktifDugum);
            }
        }

    }
    return aktifDugum;
}
Dugum* AVLAgaci::solaDondur(Dugum* buyukEbeveyn) 
{
	Dugum* sagCocuk = buyukEbeveyn->sag;
    buyukEbeveyn->sag = sagCocuk->sol;
    sagCocuk->sol = buyukEbeveyn;
    return sagCocuk;
}
Dugum* AVLAgaci::sagaDondur(Dugum* buyukEbeveyn) 
{
	Dugum* solCocuk = buyukEbeveyn->sol;
    buyukEbeveyn->sol = solCocuk->sag;
    solCocuk->sag = buyukEbeveyn;
    return solCocuk;
}
int AVLAgaci::maxDeger(Dugum* aktif) 
{
    if(aktif->sag)
        return maxDeger(aktif->sag);
    
    return aktif->veri;
}
bool AVLAgaci::varmi(int aranan,Dugum* aktif)
{
    if(aktif->veri<aranan)
    {
        if(aktif->sag)
            return varmi(aranan,aktif->sag);
        else
            return 0;
    }
    else if(aktif->veri>aranan)
    {
        if(aktif->sol)
            return varmi(aranan,aktif->sol);
        return 0;
    }
    else
    {
        return aktif;
    }
}
Dugum* AVLAgaci::sil(int veri,Dugum* aktif) 
{
	if(aktif==0)
        return 0;
    
    if(veri<aktif->veri)
    {
        aktif->sol = sil(veri,aktif->sol);
    }
    else if(veri>aktif->veri)
    {
        aktif->sag = sil(veri,aktif->sag);
    }
    else//aradığımız düğümü bulduk
    {
        if(aktif->sol==0&&aktif->sag==0)
        {
            delete aktif;
            aktif= 0;
        }
        else if(aktif->sol==0)
        {
            Dugum* sil = aktif->sag;
            *aktif = *aktif->sag;
            delete sil;
        }
        else if(aktif->sag==0)
        {
            Dugum* sil  = aktif->sol;
            *aktif=*aktif->sol;
            delete sil;
        }
        else 
        {
            aktif->veri = minDeger(aktif->sag);
            sil(aktif->veri,aktif->sag);
        }

        
    }
    
    
    int denge = dengesizlikYonu(aktif);

    if(denge>1) //sol tarafta dengesizlik
    {
        //sol sol dengesizliği
        if(dengesizlikYonu(aktif->sol)>=0)
        {
            return sagaDondur(aktif);
        }
        //sol sag durumu
        if(dengesizlikYonu(aktif->sol)<0)
        {
            aktif->sol=solaDondur(aktif->sol);
            return sagaDondur(aktif);
        }
    }
    else if(denge<-1)//sag tarafta dengesizlik
    {
        //sağ sağ durumu
        if(dengesizlikYonu(aktif->sag)<=0)
        {
            return solaDondur(aktif);
        }
        //sağ sol durumu
        if(dengesizlikYonu(aktif->sag)>0)
        {
            aktif->sag = sagaDondur(aktif->sag);
            return solaDondur(aktif);
        }
    }    
    return aktif;
}
int AVLAgaci::minDeger(Dugum* aktif) 
{
    if(aktif->sol)
        return maxDeger(aktif->sol);
    
    return aktif->veri;
}
void AVLAgaci::boslukBirak(int adet) {
     int baslangicBosluk = pow(2,adet)-1;
     for(int i=0;i<baslangicBosluk;i++)
	    cout<<"  ";
}
int AVLAgaci::dengesizlikYonu(Dugum* aktif) 
{
    if(aktif==0)
        return 0;
    return yukseklik(aktif->sol)- yukseklik(aktif->sag);
}


void AVLAgaci::yiginaEkle(Yigin& yigin) {
    yiginaEkle(kok,yigin);  
}

void AVLAgaci::yiginaEkle(Dugum* aktif, Yigin& yigin) {
    if (aktif == nullptr) {
        return;
    }

   yiginaEkle(aktif->sol, yigin);
    yiginaEkle(aktif->sag, yigin);

    if (aktif->sol == nullptr && aktif->sag == nullptr) {
        yigin.ekle(aktif->veri);
    }
}

void AVLAgaci::yaprakOlmayanDugumVerileriniYiginaEkle(Yigin& yigin) {
    yaprakOlmayanDugumVerileriniYiginaEkle(kok, yigin);
}

void AVLAgaci::yaprakOlmayanDugumVerileriniYiginaEkle(Dugum* aktif, Yigin& yigin) {
    if (aktif) {
        if (aktif->sol || aktif->sag) {
            // Eğer düğümün sol veya sağ alt ağacında en az bir çocuk varsa,
            // bu düğüm yaprak değildir.
            yigin.ekle(aktif->veri);
        }

        yaprakOlmayanDugumVerileriniYiginaEkle(aktif->sol, yigin);
        yaprakOlmayanDugumVerileriniYiginaEkle(aktif->sag, yigin);
    }
}

void AVLAgaci::temizle() {
    temizleYardimci(kok);
}

void AVLAgaci::temizleYardimci(Dugum* &aktif) {
    if (aktif) {
        temizleYardimci(aktif->sol);
        temizleYardimci(aktif->sag);
        delete aktif;
        aktif=nullptr;
    }
}

 bool AVLAgaci::bosmu()  {
    return (kok == nullptr);
}
