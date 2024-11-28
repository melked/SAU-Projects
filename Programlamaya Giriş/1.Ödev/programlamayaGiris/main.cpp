#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <math.h>

using namespace std;

struct ogrenci
{
    string adi, soyadi;
    int no, kisaSinav1, kisaSinav2, odev1, odev2, proje, vize, finalSinavi, yiliciNotu, basariNotu;
};

struct tarih
{
    int gun, ay , yil, dogumTarihi;
};

void notHesaplama(ogrenci ogrenciler[])
{
    string adi[30] =
    {
        "Ahmet", "Ayşe", "Mehmet", "Zeynep", "Hasan", "Elif", "Emre", "Sibel", "Murat", "Fatma",
        "Selim", "Hande", "Cem", "Yasemin", "Oğuzhan", "Duygu", "İsmail", "Gülcan", "Erkan", "Melike",
        "Ali", "Burcu", "Volkan", "Serap", "Orhan", "Büşra", "Erdem", "Sevil", "Hakan", "Merve"
    };
        
    string soyadi[30] =
    {
        "Yıldırım", "Demir", "Çelik", "Kara", "Aydın", "Arslan", "Şahin", "Koç", "Yavuz", "Özkan",
        "Doğan", "Kaya", "Korkmaz", "Aksoy", "Güngör", "Uçar", "Sarı", "Güneş", "Bayrak", "Topal",
        "Öztürk", "Aslan", "Polat", "Çakır", "Şen", "Tekin", "Eren", "Başar", "Aktaş", "Türkmen"
    };
        
    for(int i = 0; i<100; i++)
    {
       
        ogrenciler[i].kisaSinav1 = rand() %100;
        ogrenciler[i].kisaSinav2 = rand() %100;
        ogrenciler[i].odev1 = rand() %100;
        ogrenciler[i].odev2 = rand() %100;
        ogrenciler[i].vize = rand() %100;
        ogrenciler[i].proje = rand() %100;
        ogrenciler[i].finalSinavi = rand() %100;
        int adIndex= rand()%30;
        int soyadIndex= rand()%30;
        ogrenciler[i].adi=adi[adIndex];
        ogrenciler[i].soyadi=soyadi[soyadIndex];
        
        ogrenciler[i].yiliciNotu = (ogrenciler[i].vize* 50/100) + (ogrenciler[i].kisaSinav1*7/100) + (ogrenciler[i].kisaSinav2*7/100) + (ogrenciler[i].odev1*10/100) + (ogrenciler[i].odev2*10/100) + (ogrenciler[i].proje*16/100);
            
        ogrenciler[i].basariNotu = (ogrenciler[i].yiliciNotu*55/100) + (ogrenciler[i].finalSinavi*45/100);
            
    }
}

void listeYazdir(ogrenci ogrenciler[])
{
    for(int i = 0 ; i<100; i++)
    {
       
        if (i % 20 == 0) 
        {
            //system("clear"); terminal tabanlı çalıştığı için oluyormuş uğraşmıyorum.
            cout << "\nDevam etmek için Enter'a basın..." <<endl;
            cin.get();
               }
        cout<<i+1<<". "<<ogrenciler[i].adi<<" "<<ogrenciler[i].soyadi<<" "<<ogrenciler[i].basariNotu<<endl;
    }
}
void enYuksek(ogrenci ogrenciler[]){
   
    int enYuksek = 0 ;
    int temp;
    int enYuksekIndex = 0;
    for(int i = 0; i< 100; i++)
    {
        temp = ogrenciler[i].basariNotu;
        if(temp>enYuksek){
            enYuksek = temp;
            enYuksekIndex = i;
        }
    }
    cout<<"en yüksek not :"<<ogrenciler[enYuksekIndex].basariNotu;
}

void enDusuk(ogrenci ogrenciler[]){
   
    int enDusuk = 0 ;
    int temp;
    int enDusukIndex = 0;
    for(int i = 0; i< 100; i++)
    {
        temp = ogrenciler[i].basariNotu;
        if(temp< enDusuk){
            enDusuk = temp;
            enDusukIndex = i;
        }
    }
    cout<<"en düşük not  :"<<ogrenciler[enDusukIndex].basariNotu;
}

void sinifOrtalamasi(ogrenci ogrenciler[])
{
    int toplam =0;
    int ortalama;
    for(int i =0; i<100; i++)
    {
        toplam += ogrenciler[i].basariNotu;
    }
    ortalama = toplam/100;
    cout<<"\n ortalama: "<<ortalama<<endl;
    
}

void standartSapma(ogrenci ogrenciler[])
{
    int toplam =0;
    int ortalama;
    int sapmaToplami=0;
    for(int i =0; i<100; i++)
    {
        toplam += ogrenciler[i].basariNotu;
    }
    ortalama = toplam/100;
    
    for(int i = 0 ; i<100 ; i++)
    {
       sapmaToplami += (ogrenciler[i].basariNotu - ortalama) * (ogrenciler[i].basariNotu - ortalama);
        
    }
    int sapma = sapmaToplami/99;
    cout<<"Sınıfın standart sapması: "<< sqrt(sapma);
}
int main() {
   
    ogrenci ogrenciler[100];
    
    bool dogruMu = true;
    while(dogruMu)
    {
        cout <<"\n seçim listesi: \n"
        <<"1. liste yazdır \n"
        <<"2. En yüksek notu yazdir \n"
        <<"3. En düşük notu yazdir \n"
        <<"4. ortalama \n"
        <<"5. Standart sapma \n"
        <<"6. Çıkış"<<endl;
        
        int seçim;
        cin>>seçim;
        switch (seçim)
        {
            case 1:
                notHesaplama(ogrenciler);
                listeYazdir(ogrenciler);
                break;
            
            case 2 :
                notHesaplama(ogrenciler);
                enYuksek(ogrenciler);
                break;
            
            case 3:
                notHesaplama(ogrenciler);
                enDusuk(ogrenciler);
                break;
            
            case 4:
                notHesaplama(ogrenciler);
                sinifOrtalamasi(ogrenciler);
                break;
            
            case 5:
                notHesaplama(ogrenciler);
                standartSapma(ogrenciler);
                break;
            
            case 6 :
                dogruMu = false;
                break;
            
            default:
                break;
        }
        
    }
}
