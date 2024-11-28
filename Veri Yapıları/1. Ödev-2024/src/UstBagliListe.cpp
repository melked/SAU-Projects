/**
* @file UstBagliListe.cpp
* @description Bağlı listeler ile işlemler
* @course 2. öğrenim C grubu
* @assignment 1. ödev
* @date 25.11.2024
* @author Melike Demirtaş melike.demirtas@ogr.sakarya.edu.tr
*/
#include "UstBagliListe.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

UstBagliListe::UstBagliListe() {
    ilk = nullptr;
    satirSayisi = 0;
}

UstBagliListe::~UstBagliListe() {
    UstDugum* gecici = ilk;
    while (gecici != nullptr) {
        UstDugum* silinecek = gecici;
        gecici = gecici->sonraki;
        delete silinecek->AltListe; // Alt bağlı listeyi siliyor bu nedenle mainde sadece üst listenin yıkıcısını çağırmam yeterli oluyor.
        delete silinecek;       // Üst düğüm siliniyor.
    }
}

void UstBagliListe::ekle(BagliListe* yeniListe) {
    
    UstDugum* yeniDugum = new UstDugum(yeniListe);
    if (ilk == nullptr) {
        ilk = yeniDugum;
    } else {
        UstDugum* gecici = ilk;
        while (gecici->sonraki != nullptr) {
            gecici = gecici->sonraki;
        }

        gecici->sonraki = yeniDugum;
        satirSayisi++;
    }
    
}

void UstBagliListe::yazdir() {
    
    UstDugum* gecici = ilk;
    
    while (gecici != nullptr) {
      
        gecici->AltListe->yazdir(); // Alt bağlı listeyi yazdır
        gecici = gecici->sonraki;
        std::cout<<std::endl; //her bağlı listeyi yazdırdıktan sonra bir alt satıra gider.
    }
}

int UstBagliListe::sutunSayisiDondur()
{
    int sayac = 0;
    UstDugum* gecici = ilk;

    while (gecici != 0)
    {
        sayac++; //her düğüm dolaşıldığında bir artar.
        gecici = gecici->sonraki;
    }

    return sayac;
}

int UstBagliListe::satirSayisiDondur() {
    return satirSayisi; //ekleme yaparken hesaplandı zaten sadece değer döndürüyorum.
}

void UstBagliListe::mutasyon(int satirSayisi, int sutunSayisi) {
    int mevcutSatir = 0, mevcutSutun = 0;
    UstDugum* geciciSatir = ilk;
    
    // Sırasıyla satırlar ve sütunlar dolaşılıyor ve aranan sütuna kadar ulaşıldığında oradaki veri X ile değiştirilir.
    while (geciciSatir != nullptr) {
        
        if (mevcutSatir == satirSayisi) {
            BagliListe* liste = geciciSatir->AltListe; 

            // Bağlı listedeki sütunları dolaş
            Dugum* geciciSutun = liste->ilk;
            while (geciciSutun != nullptr) {
                if (mevcutSutun == sutunSayisi) {
                    geciciSutun->gen = 'X';
                    return;
                }
                mevcutSutun++;
                geciciSutun = geciciSutun->sonraki;
            }

            std::cout << "Dosyada girilen sutunda veri yok!" << std::endl;
            return;
        }

        mevcutSatir++;
        geciciSatir = geciciSatir->sonraki;
    }

    std::cout << "Dosyada girilen satirda veri yoki!" << std::endl;
}


void UstBagliListe::caprazlama(int ilkSatir, int ikinciSatir) {
  
    int mevcutSatir = 0;
    UstDugum* ilkSatirDugum = nullptr;
    UstDugum* ikinciSatirDugum = nullptr;

    UstDugum* geciciSatir = ilk;

    // Belirtilen satırlar ve sütunlar bulunur. Devamında çaprazlama yapılır.
    while (geciciSatir != nullptr) {
        if (mevcutSatir == ilkSatir) {
            ilkSatirDugum = geciciSatir;
        }
        if (mevcutSatir == ikinciSatir) {
            ikinciSatirDugum = geciciSatir;
        }
        if (ilkSatirDugum && ikinciSatirDugum) break;

        mevcutSatir++;
        geciciSatir = geciciSatir->sonraki;
    }

    if (!ilkSatirDugum || !ikinciSatirDugum) {
        std::cout << "Girilen satir yok!" << std::endl;
        return;
    }

    // İki bağlı listeyi al
    BagliListe* ilkListe = ilkSatirDugum->AltListe;
    BagliListe* ikinciListe = ikinciSatirDugum->AltListe;

    int ilkGenSayisi = ilkListe->sutunSayisiDondur();
    int ikinciGenSayisi = ikinciListe->sutunSayisiDondur();

    if (ilkGenSayisi <= 1 || ikinciGenSayisi <= 1) { // dosyadaki satirlarda bir tane veya daha az veri varsa çaprazlama yapılmaz. (En az iki veri olmasını çaprazlama yapılması için şart olarak kabul ettim)
        std::cout << "Caprazlamaya yetecek kadar gen yok!" << std::endl;
        return;
    }

    int ilkKromozomYarisi = ilkGenSayisi / 2;
    int ikinciKromozomYarisi = ikinciGenSayisi / 2;

    // Yeni kromozomları oluşturdum.
    BagliListe* yeniKromozom1 = new BagliListe();
    BagliListe* yeniKromozom2 = new BagliListe();

    // İlk yeni kromozomu oluşturdum.
    Dugum* gecici = ilkListe->ilk;
    for (int i = 0; i < ilkKromozomYarisi; i++) {
        yeniKromozom1->ekle(gecici->gen);
        gecici = gecici->sonraki;
    }

    gecici = ikinciListe->ilk;
    for (int i = 0; i < ikinciKromozomYarisi; i++) {
        gecici = gecici->sonraki;
    }
    if (ikinciGenSayisi % 2 != 0) { //tek sayıda gen olanlarda ortadaki geni atlıyorum.
        gecici = gecici->sonraki;
    }
    while (gecici != nullptr) {
        yeniKromozom1->ekle(gecici->gen);
        gecici = gecici->sonraki;
    }

    // İkinci yeni kromozomu oluştırdum.
    gecici = ilkListe->ilk;
    for (int i = 0; i < ilkKromozomYarisi; i++) {
        gecici = gecici->sonraki;
    }
    if (ilkGenSayisi % 2 != 0) {
        gecici = gecici->sonraki;
    }
    while (gecici != nullptr) {
        yeniKromozom2->ekle(gecici->gen);
        gecici = gecici->sonraki;
    }
    
    gecici = ikinciListe->ilk;
    for (int i = 0; i < ikinciKromozomYarisi; i++) {
        yeniKromozom2->ekle(gecici->gen);
        gecici = gecici->sonraki;
    }

    // Yeni kromozomları listeye ekledim.
    UstDugum* yeniDugum1 = new UstDugum(yeniKromozom1); 
    UstDugum* yeniDugum2 = new UstDugum(yeniKromozom2);

    UstDugum* sonDugum = ilk;
    while (sonDugum->sonraki != nullptr) {
        sonDugum = sonDugum->sonraki;
    }
    sonDugum->sonraki = yeniDugum1;
    yeniDugum1->sonraki = yeniDugum2;
}

void UstBagliListe::OtomatikIslemler() {
    using namespace std;

    ifstream dosya("Islemler.txt");
    if (!dosya.is_open()) {
        cout << "Islemler.txt dosyasi acilamadi!" << endl;
        return;
    }

    char islem;
    int satir1, satir2;

    while (dosya >> islem >> satir1 >> satir2) {
        
        if (islem == 'C' || islem == 'c') {
            caprazlama(satir1, satir2);

        } else if (islem == 'M' || islem == 'm') {
            
            mutasyon(satir1, satir2);

        } else {
            cout << "Otomatik islemlerde yalnizca mutasyon ve caprazlama yapilir. " << islem << endl;
            continue;
        }
    }
    dosya.close();
    cout << "Otomatik islemler tamamlandi." << endl;
}
void UstBagliListe::ekranaYaz() {
    
    UstDugum* geciciSatir = ilk;

    // Satirlar tek tek dolaşılır. 
    while (geciciSatir != nullptr) {
        BagliListe* liste = geciciSatir->AltListe;
        Dugum* geciciSutun = liste->ilk;

          // Eğer satır boşsa sıradaki satıra geçtim.
        if (geciciSutun == nullptr) {
            geciciSatir = geciciSatir->sonraki;
            continue;
        }

        // Satırdaki ilk gen tutulur 
        char ilkGen = geciciSutun->gen;
        
          // dosyada boşluk olursa derleme hatası vermesin.
        while (ilkGen == ' ' && geciciSutun != nullptr) {
            geciciSutun = geciciSutun->sonraki;
            if (geciciSutun != nullptr) {
                ilkGen = geciciSutun->gen;
            }
        }

        // Eğer hala boş bir satırsa sıradaki satıra geçmek istedim eğer dosyada boşuk olursa diye boşluğun asciisi olmadığı için.
        if (geciciSutun == nullptr) {
            geciciSatir = geciciSatir->sonraki;
            continue;
        }

        int ilkGenAscii = static_cast<int>(ilkGen);
        bool kucukGen = false;

        // Sağdan sola doğru gezmemiz lazım karşılaştırma yapabilmek için bu nedenle yığıt gibi çalışan bir algoritma yazdım.
        Dugum* sonDugum = nullptr;
        while (geciciSutun != nullptr) {
            Dugum* yeniDugum = new Dugum(geciciSutun->gen);
            yeniDugum->sonraki = sonDugum; 
            sonDugum = yeniDugum;
            geciciSutun = geciciSutun->sonraki;
        }

        // düğümleri sağdan sola kontrol ettim. İlk gen ile sağdan sola karşılaştırma yaptım. ilk genden küçük gen varsa onu yazdırdım yoksa ilk geni
        Dugum* geciciGeriSutun = sonDugum;
        while (geciciGeriSutun != nullptr) {

            if (static_cast<int>(geciciGeriSutun->gen) < ilkGenAscii) {
                std::cout << geciciGeriSutun->gen;  
                kucukGen = true;
                break; 
            }
            geciciGeriSutun = geciciGeriSutun->sonraki;
        }

        if (!kucukGen) {
            std::cout << ilkGen;
        }

        std::cout <<" "; //arada bir boşluk olsun diye.
        geciciSatir = geciciSatir->sonraki;
    }
}
