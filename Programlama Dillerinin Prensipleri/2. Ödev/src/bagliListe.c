/*
*
* @author g211210003 Melike Demirtaş melike.demirtas@ogr.sakarya.edu.tr
* @since 24.04.2024
* <p>
* bagliliste.c
* </p>
*/
#include "BagliListe.h"
#include <stdio.h>
#include <stdlib.h>

BagliListe BagliListeOlustur() {
    BagliListe liste = (BagliListe)malloc(sizeof(struct BAGLILISTE));
    if (liste != NULL) {
        liste->ilk = NULL;
    }
    return liste;
}

void BagliListeYokEt(BagliListe liste) {
    if (liste != NULL) {
        Dugum* gecici = liste->ilk;
        while (gecici != NULL) {
            Dugum* silinecek = gecici;
            gecici = gecici->sonraki;
            free(silinecek);
        }
        free(liste);
    }
}

void BagliListeEkle(BagliListe liste, int veri) {
    if (liste == NULL)
        return;

    Dugum* yeni = (Dugum*)malloc(sizeof(Dugum));
    if (yeni == NULL)
        return;

    yeni->deger = veri;
    yeni->sonraki = NULL;

    if (liste->ilk == NULL) {
        liste->ilk = yeni;
        return;
    }

    Dugum* gecici = liste->ilk;
    while (gecici->sonraki != NULL)
        gecici = gecici->sonraki;
    gecici->sonraki = yeni;
}

void BagliListeYazdir(BagliListe liste, int satir_sayisi, int sutun_sayisi) {
    if (liste == NULL || liste->ilk == NULL)
        return;

    for (int satir = 0; satir < satir_sayisi; satir++) {
        for (int sutun = 0; sutun < sutun_sayisi; sutun++) {
            Dugum* gecici = liste->ilk;
            int ekrana_yazildi = 0; 
            while (gecici != NULL) {
                if ((gecici->bitki != NULL && gecici->bitki->super->x == satir && gecici->bitki->super->y == sutun) ||
                    (gecici->bocek != NULL && gecici->bocek->super->x == satir && gecici->bocek->super->y == sutun) ||
                    (gecici->sinek != NULL && gecici->sinek->super->super->x == satir && gecici->sinek->super->super->y == sutun) ||
                    (gecici->pire != NULL && gecici->pire->super->super->x == satir && gecici->pire->super->super->y == sutun)) {
                    if (gecici->bitki != NULL) printf(" %s ", gecici->bitki->super->toString(gecici->bitki->super, NULL));
                    else if (gecici->bocek != NULL) printf(" %s ", gecici->bocek->super->toString(gecici->bocek->super, NULL));
                    else if (gecici->sinek != NULL) printf(" %s ", gecici->sinek->super->super->toString(gecici->sinek->super->super, NULL));
                    else if (gecici->pire != NULL) printf(" %s ", gecici->pire->super->super->toString(gecici->pire->super->super, NULL));
                    ekrana_yazildi = 1;
                    break;
                }
                gecici = gecici->sonraki;
            }
            if (!ekrana_yazildi) printf(" X ");
        }
        printf("\n");
    }
    system("cls");
}

void kazananDugum(BagliListe liste) {
    if (liste == NULL || liste->ilk == NULL) {
        printf("Liste bos.\n");
        return;
    }
    
    Dugum* gecici = liste->ilk;
    while (gecici != NULL) {
        if (gecici->bitki != NULL) {
            printf("Kazanan : %s : (%d, %d)\n", gecici->bitki->super->toString(gecici->bitki->super, NULL), gecici->bitki->super->x, gecici->bitki->super->y);
        } else if (gecici->bocek != NULL) {
            printf("Kazanan : %s : (%d, %d)\n", gecici->bocek->super->toString(gecici->bocek->super, NULL), gecici->bocek->super->x, gecici->bocek->super->y);
        } else if (gecici->sinek != NULL) {
            printf("Kazanan : %s : (%d, %d)\n", gecici->sinek->super->super->toString(gecici->sinek->super->super, NULL), gecici->sinek->super->super->x, gecici->sinek->super->super->y);
        } else if (gecici->pire != NULL) {
            printf("Kazanan : %s : (%d, %d)\n", gecici->pire->super->super->toString(gecici->pire->super->super, NULL), gecici->pire->super->super->x, gecici->pire->super->super->y);
        } 
        gecici = gecici->sonraki;
    }
}



void BagliListeCikar(BagliListe liste) {
    if (liste == NULL || liste->ilk == NULL)
        return;

    if (liste->ilk->sonraki == NULL) {
        free(liste->ilk);
        liste->ilk = NULL;
    } else {
        Dugum* gecici = liste->ilk;
        while (gecici->sonraki->sonraki != NULL) {
            gecici = gecici->sonraki;
        }
        free(gecici->sonraki);
        gecici->sonraki = NULL;
    }
}
void bagliListeyeBitkiEkle(BagliListe liste, Bitki bitki) {
    if (liste == NULL || bitki == NULL)
        return;

    Dugum* yeni = (Dugum*)malloc(sizeof(Dugum));
    if (yeni == NULL)
        return;
  
    yeni->bitki = bitki;
    yeni->bocek = NULL;
    yeni->sinek = NULL;
    yeni->pire = NULL;
    yeni->sonraki = NULL;
   
    if (liste->ilk == NULL) {
        liste->ilk = yeni;
        return;
    }

    Dugum* gecici = liste->ilk;
    while (gecici->sonraki != NULL)
        gecici = gecici->sonraki;
    gecici->sonraki = yeni;
}

void bagliListeyeBocekEkle(BagliListe liste, Bocek bocek) {
    if (liste == NULL || bocek == NULL)
        return;

    Dugum* yeni = (Dugum*)malloc(sizeof(Dugum));
    if (yeni == NULL)
        return;

    yeni->bocek = bocek;
    yeni->bitki = NULL;
    yeni->sinek = NULL;
    yeni->pire = NULL;
    yeni->sonraki = NULL;
   
   
   if (liste->ilk == NULL) {
        liste->ilk = yeni;
        return;
    }

    Dugum* gecici = liste->ilk;
    while (gecici->sonraki != NULL)
        gecici = gecici->sonraki;
    gecici->sonraki = yeni;
}

void bagliListeyeSinekEkle(BagliListe liste, Sinek sinek) {
    if (liste == NULL || sinek == NULL)
        return;

    Dugum* yeni = (Dugum*)malloc(sizeof(Dugum));
    if (yeni == NULL)
        return;

    yeni->sinek = sinek;
    yeni->bocek = NULL;
    yeni->bitki = NULL;
    yeni->pire = NULL;
    yeni->sonraki = NULL;
   
   
    if (liste->ilk == NULL) {
        liste->ilk = yeni;
        return;
    }

    Dugum* gecici = liste->ilk;
    while (gecici->sonraki != NULL)
        gecici = gecici->sonraki;
    gecici->sonraki = yeni;
}

void bagliListeyePireEkle(BagliListe liste, Pire pire) {
    if (liste == NULL || pire == NULL)
        return;

    Dugum* yeni = (Dugum*)malloc(sizeof(Dugum));
    if (yeni == NULL)
        return;

    yeni->pire = pire;
    yeni->bocek = NULL;
    yeni->sinek = NULL;
    yeni->bitki = NULL;
    yeni->sonraki = NULL;
    if (liste->ilk == NULL) {
        liste->ilk = yeni;
        return;
    }

    Dugum* gecici = liste->ilk;
    while (gecici->sonraki != NULL)
    gecici = gecici->sonraki;
    gecici->sonraki = yeni;
}

int dugumSayisi(BagliListe liste) {
    if (liste == NULL || liste->ilk == NULL) {
        return 0; // Boş liste, düğüm sayısı 0
    }

    int sayac = 0;
    Dugum* gecici = liste->ilk;

    // Listenin sonuna kadar ilerle ve her bir düğüm için sayacı artır
    while (gecici != NULL) {
        sayac++;
        gecici = gecici->sonraki;
    }

    return sayac;
}