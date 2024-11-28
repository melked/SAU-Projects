#ifndef BagliListe_h
#define BagliListe_h

#include "Bitki.h" 
#include "Pire.h"
#include "Sinek.h"
#include "Dugum.h" 

struct BAGLILISTE {
    
    Dugum* ilk;
    void(*bagliListeyeBitkiEkle)(struct BAGLILISTE*);
    void(*BagliListeYazdir)(struct BAGLILISTE*);
    void(*kazananDugum)(struct BAGLILISTE*);
    void(*bagliListeyeBocekEkle)(struct BAGLILISTE*);
    void(*bagliListeyeSinekEkle)(struct BAGLILISTE*);
    void(*bagliListeyePireEkle)(struct BAGLILISTE*);
    void(*BagliListeYokEt)(struct BAGLILISTE*);
    void(*BagliListeEkle)(struct BAGLILISTE*);
    void(*BagliListeCikar)(struct BAGLILISTE*);
    int(*dugumSayisi)(struct BAGLILISTE*);
   
};

typedef struct BAGLILISTE* BagliListe;

BagliListe BagliListeOlustur();
void BagliListeYokEt(BagliListe liste);
void BagliListeEkle(BagliListe liste, int veri);
void BagliListeYazdir(BagliListe liste,int satir_sayisi, int sutun_sayisi );
void BagliListeCikar(BagliListe liste);
void bagliListeyeBitkiEkle(BagliListe liste, Bitki bitki);
void bagliListeyeBocekEkle(BagliListe liste, Bocek bocek);
void bagliListeyeSinekEkle(BagliListe liste, Sinek sinek);
void bagliListeyePireEkle(BagliListe liste, Pire pire);
int dugumSayisi(BagliListe liste);
void kazananDugum(BagliListe liste);

#endif
