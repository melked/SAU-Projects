/**
* @file main.cpp
* @description Bağlı listeler ile işlemler
* @course 2. öğrenim C grubu
* @assignment 1. ödev
* @date 05.11.2024
* @author Melike Demirtaş melike.demirtas@ogr.sakarya.edu.tr
*/
#include <iostream>
#include <fstream>
#include "BagliListe.hpp"
#include "UstBagliListe.hpp"
using namespace std;


void dosyayiBagliListeyeOku(BagliListe* liste, UstBagliListe* UstListe, const string& dosyaAdi) {
    
    ifstream dosyaOku(dosyaAdi);
    if (!dosyaOku) {
        cerr << "Dosya okunamiyor!" << endl;
        return;
    }

    char ch;
    while (dosyaOku.get(ch)) {
        if (ch == '\n') {
            UstListe->ekle(liste);
            liste = new BagliListe(); 
        } else if (ch != ' ') {
            
            liste->ekle(ch);
        }
    }

    if (liste != nullptr) {
        UstListe->ekle(liste);
    }
    
    dosyaOku.close();
}


int main(){
   
    BagliListe* liste = new BagliListe();
    UstBagliListe* UstListe = new UstBagliListe();
    
    dosyayiBagliListeyeOku(liste,UstListe, "Dna.txt"); //Dosya içeriği okundu. Bağlı listelere aktarıldı.

    bool devam = true;
    while (devam) {
        cout << "\nSecim yapiniz:"
             << "\n1. Caprazlama"
             << "\n2. Mutasyon Yap"
             << "\n3. Otomatik Islemler"
             << "\n4. Ekrana Yaz"
             << "\n5. Cikis"
             << endl;

        int secim;
        cin >> secim;

        switch (secim) {
            case 1:
                int ilkSatir, ikinciSatir;
                cout << "ilk satir numarasi: ";
                cin >> ilkSatir;
                cout << "ikinci satir numarasi: ";
                cin >> ikinciSatir;
                UstListe->caprazlama(ilkSatir, ikinciSatir);
                UstListe->yazdir(); // yazdırmalı mıyım emin olamadım.
                break;
            case 2: {
                int satir, sutun;
                cout << "ilk satir numarasi: ";
                cin >> satir;
                cout << "ikinci sutun numarasi: ";
                cin >> sutun;
                UstListe->mutasyon(satir, sutun);
                UstListe->yazdir();
                break;
            }
            case 3: {
               UstListe->OtomatikIslemler();
               UstListe->yazdir();
                break;
            }
            case 4:{
                UstListe->ekranaYaz();
            } break;
            case 5:{
                devam = false;
            }break;
            default:
                cout << "Gecersiz secim! Lutfen tekrar deneyin." << endl;
        }
    }

    delete UstListe; 
    
    return 0;
}