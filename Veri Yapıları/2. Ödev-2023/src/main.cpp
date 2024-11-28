/**
 * @file        G211210003
 * @description Yığın ve AVL ağacı kullanarak program yazmak
 * @course      2. öğretim B grubu
 * @assignment  2. Ödev
 * @date        21.12.2023
 * @author      Melike Demirtaş
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "Dugum.hpp"
#include "AVLAgaci.hpp"
#include "Yigin.hpp"

using namespace std;

int yiginToplamEleman(Yigin yigin[]) //Yığındaki toplam eleman sayısını hesaplamak için fonksiyon
{   
    int toplam = 0;
    for(int i = 0 ; i < 500 ; i++){
        toplam+=yigin[i].elemanSayisi();
    }
    return toplam;
}

void karakterYazdir(Yigin asciiYigin[], Yigin yigin[]) //Düğüm değerleri toplamını hesaplayan fonksiyon
{
   for(int i = 0 ; i<500 ; i++)
   {
       if(!asciiYigin[i].bosmu())
       {
        int ascii = asciiYigin[i].elemanlariTopla() % (90 - 65 + 1) + 65;
        char karakter = static_cast<char>(ascii);
        cout<<karakter;
       }
    }
    system("cls");
}

void cikarVeYazdir(Yigin yigin[], Yigin asciiYigin[], AVLAgaci Agac[]) //Karakterleri yazdırıp ağacı ve yığıtları silip yazdıran fonksiyon
{
  do 
  {
       int minTopValue = 1000;
       int minTopIndex = -1; 

       for (int j = 0; j < 500;j++) 
       {
  
        if (!yigin[j].bosmu() && yigin[j].getir() < minTopValue) 
        {
          minTopValue = yigin[j].getir();
          minTopIndex = j;
        }
       }
    
        if(yiginToplamEleman(yigin)==1)
          return;
           
        yigin[minTopIndex].cikar();
        
        if(yiginToplamEleman(yigin)==1)
          return;
         
        if(yigin[minTopIndex].bosmu())
        { 
          karakterYazdir(asciiYigin,yigin);
          yigin[minTopIndex].temizle();
          Agac[minTopIndex].temizle();
          asciiYigin[minTopIndex].temizle();

          for(int i =0; i<500;i++)
          { 
            if(!Agac[i].bosmu())
            { 
              yigin[i].temizle();
              asciiYigin[i].temizle();
              Agac[i].yiginaEkle(yigin[i]);
              Agac[i].yaprakOlmayanDugumVerileriniYiginaEkle(asciiYigin[i]);
            }
          }
    
            cikarVeYazdir(yigin, asciiYigin, Agac);
          }    
   
          int maxTopValue = 0; 
          int maxTopIndex = -1;

          for (int k = 0; k < 500; k++) 
          {
            if (!yigin[k].bosmu() && yigin[k].getir() > maxTopValue) 
            {
                maxTopValue = yigin[k].getir();
                maxTopIndex = k;
            }
          }
     
          if(yiginToplamEleman(yigin)==1)
           return;
        
          yigin[maxTopIndex].cikar();
      
          if(yiginToplamEleman(yigin)==1)
            return;
      
          if(yigin[maxTopIndex].bosmu())
          {   
            karakterYazdir(asciiYigin,yigin);
            yigin[maxTopIndex].temizle();
            Agac[maxTopIndex].temizle();
            asciiYigin[maxTopIndex].temizle();
          
            for(int i =0; i<500;i++)
            {  
              if(!Agac[i].bosmu())
              {
                yigin[i].temizle();
                asciiYigin[i].temizle();
                Agac[i].yiginaEkle(yigin[i]);
                Agac[i].yaprakOlmayanDugumVerileriniYiginaEkle(asciiYigin[i]);
              }
            }
          }  
  }while(yiginToplamEleman(yigin)>0);
}

int main() 
{
 
  AVLAgaci Agac[500];
  Yigin yigin[500];
  Yigin asciiYigin[500];

  ifstream dosya("Veri.txt");

    if (!dosya.is_open()) 
    {
      cerr << "Dosya acilamadi: " << "Veri.txt" << std::endl;
      return 1; 
    }
    
  string satir;
  int SatirSayac = 0;

  while (getline(dosya, satir)) 
  {
    istringstream okuma(satir);
    int veri;

      while (okuma >> veri) 
      {
        Agac[SatirSayac].ekle(veri);
      }

    SatirSayac++;
  }

  dosya.close();

  for (int  i = 0; i<500; i++)
    {
      Agac[i].yiginaEkle(yigin[i]);
      Agac[i].yaprakOlmayanDugumVerileriniYiginaEkle(asciiYigin[i]);
    }

  
  cikarVeYazdir(yigin,asciiYigin,Agac);
  
  cout<<"=============================="<<endl; 
  cout<<"|                            |"<<endl;
  cout<<"|                            |"<<endl;
    
  for(int i = 0 ; i<500 ; i++)
  {
    if(!asciiYigin[i].bosmu())
    {
      int ascii = asciiYigin[i].elemanlariTopla() % (90 - 65 + 1) + 65;
      char karakter = static_cast<char>(ascii);
      cout<<"|     Son Karakter:"<<karakter<<"         |"<<endl; 
      
     }
  }
 
  for(int i = 0; i<500; i++)
  {
    if(!asciiYigin[i].bosmu())
      cout<<"|     AVL NO     :"<<i+1 <<"        |"<<endl;
  }
 
  cout<<"|                            |"<<endl;
  cout<<"|                            |"<<endl;
  cout<<"==============================";
  
     
  return 0;

} 

