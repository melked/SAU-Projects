/**
 * @file        G211210003
 * @description Yığın ve AVL ağacı kullanarak program yazma
 * @course      2. öğretim B grubu
 * @assignment  2. Ödev
 * @date        21.12.2023
 * @author      Melike Demirtaş
 */

#include "Yigin.hpp"
#include <iomanip>

Yigin::Yigin()
{
    tepe = -1;
    veriler=0;
    kapasite = 5;
    genislet(kapasite);
}

Yigin::~Yigin()
{
    delete[] veriler;
}

bool Yigin::bosmu()
{
    if(tepe==-1)
        return true;
    return false;
}
bool Yigin::dolumu()
{
    if(tepe==kapasite-1)
        return true;
    return false;
}

void Yigin::ekle(int veri)
{
    if(tepe==kapasite-1)
        genislet(kapasite);

    tepe++;
    veriler[tepe]=veri;
}

void Yigin::cikar()
{
    if(tepe!=-1)
    {
        tepe--;
    }
}

int Yigin::getir()
{
    if(tepe!=-1)
        return veriler[tepe];
    throw std::out_of_range("Yigin Bos");
}
int Yigin::elemanSayisi(){
    return tepe+1;
}

void Yigin::genislet(int boyut)
{
    int *yeniAlan = new int[boyut+kapasite];
    for(int i=0;i<=tepe;i++)
    {
        
         yeniAlan[i] = veriler[i];   
        
    }
    if(veriler)
        delete[] veriler;
    veriler = yeniAlan;
    kapasite += boyut;
   
}

int Yigin::elemanlariTopla() {
    int toplam = 0;

    for (int i = 0; i <= tepe; i++) {
        toplam += veriler[tepe - i];
    }

    return toplam;
}
void Yigin::temizle() {
    if (veriler) {
        
        tepe = -1;
        kapasite = 5;
    }
}