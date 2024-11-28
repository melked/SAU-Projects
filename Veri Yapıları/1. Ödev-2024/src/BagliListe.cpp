/**
* @file BagliListe.cpp
* @description Bağlı listeler ile işlemler
* @course 2. öğrenim C grubu
* @assignment 1. ödev
* @date 05.11.2024
* @author Melike Demirtaş melike.demirtas@ogr.sakarya.edu.tr
*/
#include "BagliListe.hpp"
#include <iostream>
using namespace std;

BagliListe::BagliListe() {
    ilk = nullptr;
}

BagliListe::~BagliListe() {
    Dugum* gecici = ilk;
    while (gecici != nullptr) {
        Dugum* silinecek = gecici;
        gecici = gecici->sonraki;
        delete silinecek;
    }
}

void BagliListe::ekle(char veri)
{
    Dugum* yeni = new Dugum(veri);
    if(ilk==0)
    {
        ilk = yeni;
        return;
    }
   
    Dugum* gecici = ilk;
    while(gecici->sonraki!=0)
        gecici= gecici->sonraki;
    gecici->sonraki = yeni;
}
void BagliListe::yazdir()
{
    using namespace std;
    Dugum* gecici = ilk;
    
    
    while(gecici!=0)
    {
        cout<<gecici->gen<<" ";
       
        gecici= gecici->sonraki;  
    }
          
}
int BagliListe::sutunSayisiDondur()
{
    int sayac = 0;
    Dugum* gecici = ilk;

    while (gecici != 0)
    {
        sayac++;
        gecici = gecici->sonraki;
    }

    return sayac;
}
int BagliListe::satirSayisiDondur() {
    return satirSayisi;
}