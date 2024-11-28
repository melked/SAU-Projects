/*
*
* @author g211210003 Melike Demirtaş melike.demirtas@ogr.sakarya.edu.tr
* @since 24.04.2024
* <p>
* test.c
* </p>
*/
#include "Bitki.h"
#include "Pire.h"
#include "Sinek.h"
#include "Habitat.h"
#include "bagliListe.h"
#include "Dugum.h"

int** dosyaOkut(char* dosyaAdi, int* satir_sayisi, int* sutun_sayisi) {
    FILE *dosya = fopen(dosyaAdi, "r");
    if (dosya == NULL) {
        printf("Dosya acilamadi.");
        return NULL;
    }
*satir_sayisi = 0;
*sutun_sayisi = 0;
int karakter;
int satir_sutun_sayisi = 0; 
while ((karakter = fgetc(dosya)) != EOF && karakter != '\n') {
    if (karakter == ' ') {
        satir_sutun_sayisi++;
    }
}
*sutun_sayisi = satir_sutun_sayisi + 1; 

rewind(dosya);

while ((karakter = fgetc(dosya)) != EOF) {
    if (karakter == '\n') {
        (*satir_sayisi)++;
    }
}
    (*satir_sayisi)++;
  
    rewind(dosya);

    int **matris = (int **)malloc((*satir_sayisi) * sizeof(int *));
    for (int i = 0; i < (*satir_sayisi); i++) {
        matris[i] = (int *)malloc((*sutun_sayisi) * sizeof(int));
    }

    for (int i = 0; i < (*satir_sayisi); i++) {
        for (int j = 0; j < (*sutun_sayisi); j++) {
            if (fscanf(dosya, "%d", &matris[i][j]) != 1) {
                printf("Dosyadan veri okunurken hata oluştu veya dosya formati beklenenden farkli.");
                fclose(dosya);
                return NULL;
            }
        }
    }

    fclose(dosya);
    
    return matris;
}

void devamEt() {
    system("pause");
}

int main() {
   
  int satir_sayisi, sutun_sayisi;
  int** matris = dosyaOkut("Veri.txt", &satir_sayisi, &sutun_sayisi);
  BagliListe liste = BagliListeOlustur(); 
  if (matris != NULL) {
        BagliListe liste = BagliListeOlustur(); 

        for (int i = 0; i < satir_sayisi; i++) {
            for (int j = 0; j < sutun_sayisi; j++) {
                if (matris[i][j] > 0 && matris[i][j] < 10) {
                    Bitki bitki = bitkiOlustur(matris[i][j],i,j);
                    printf("%s ", bitki->super->toString(bitki->super, NULL));
                    bagliListeyeBitkiEkle(liste, bitki);
                   
                  
                } 
                 if (matris[i][j] > 9 && matris[i][j] < 21) {
                    Bocek bocek = bocekOlustur(matris[i][j],i,j);
                    printf("%s ", bocek->super->toString(bocek->super, NULL));
                    bagliListeyeBocekEkle(liste,bocek);
                   
                } 
                if (matris[i][j] > 20 && matris[i][j] <51 ) {
                    Sinek sinek = sinekOlustur(matris[i][j],i,j);
                    printf("%s ", sinek->super->super->toString(sinek->super->super, NULL));
                    bagliListeyeSinekEkle(liste,sinek);
                   
                } 
                if (matris[i][j] > 50 && matris[i][j] <100 ) {
                   Pire pire = pireOlustur(matris[i][j],i,j);
                    printf("%s ", pire->super->super->toString(pire->super->super, NULL));
                    bagliListeyePireEkle(liste,pire);
                } 
            }
        
        printf("\n");
        
        }

    for (int i = 0; i < satir_sayisi; i++) {
            free(matris[i]);
    }
    free(matris);
       
    devamEt();
     
    Habitat habitat = habitatOlustur();
    
    if (habitat == NULL) {
        printf("Habitat olusturma hatasi!\n");
        return 1;
    }
  
    habitat->yemeIslemleri(liste); 
    habitat->habitatYoket(habitat);
    
    return 0;
    
    }
}