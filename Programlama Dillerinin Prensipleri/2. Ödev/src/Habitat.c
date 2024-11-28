/*
*
* @author g211210003 Melike Demirtaş melike.demirtas@ogr.sakarya.edu.tr
* @since 24.04.2024
* <p>
* habitat.c
* </p>
*/
#include "Habitat.h"
#include "Bitki.h"
#include "Pire.h"
#include "Sinek.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bagliListe.h"
#include "Dugum.h"

void yemeIslemleri(BagliListe liste);
int** dosyaOkut(const char* dosyaAdi, int* satir_sayisi, int* sutun_sayisi);

Habitat habitatOlustur() {
    Habitat this = (Habitat)malloc(sizeof(struct HABITAT));
    if (this == NULL) {
        printf("Bellek tahsisi basarisiz.\n");
        return NULL;
    }
    this->liste = NULL;
    this->yemeIslemleri = &yemeIslemleri;
    this->habitatYoket = &habitatYoket;
    return this;
}
      
void yemeIslemleri(BagliListe liste) { 
   
    char* dosyaAdi = "Veri.txt";
    int satir_sayisi = 0;
    int sutun_sayisi = 0;
    int** matris = dosyaOkut(dosyaAdi, &satir_sayisi, &sutun_sayisi);

    if (matris == NULL) {
        printf("Dosya okuma hatasi!");
        return;
    }

    int canliSayisi = dugumSayisi(liste);

    Dugum* gecici =liste->ilk;
    
    while (gecici != NULL) {

        if(gecici->bitki != NULL)
        {
            Dugum* temp = liste->ilk;
            while (temp != NULL) {
                if(temp->pire!= NULL){
                    temp->pire->sil;
                    temp->pire=NULL;
                    BagliListeYazdir(liste,satir_sayisi,sutun_sayisi);
                    canliSayisi--;
                    break;
                }
                else if(temp->sinek!= NULL){
                    temp->sinek->sil;
                    temp->sinek=NULL;
                    BagliListeYazdir(liste,satir_sayisi,sutun_sayisi);
                    canliSayisi--;
                    break;
                }
                else if(temp->bocek!= NULL){
                    gecici->bitki->sil;
                    gecici->bitki=NULL;
                    BagliListeYazdir(liste,satir_sayisi,sutun_sayisi);
                    canliSayisi--;
                    break;
                }
                else if (temp->sonraki != NULL && temp->bitki != NULL && (gecici->bitki != temp->bitki)) {
                    if (gecici->bitki->super->deger > temp->bitki->super->deger) {
                        temp->bitki->sil;
                        temp->bitki = NULL;
                        BagliListeYazdir(liste,satir_sayisi,sutun_sayisi);
                        canliSayisi--;
                        break;
                        } 
                    else if (temp->sonraki != NULL && temp->sonraki->bitki != NULL && (gecici->bitki != temp->bitki)) {
                    
                        if (gecici->bitki->super->deger == temp->bitki->super->deger) {
                            while (gecici != NULL){
                                if(gecici->sonraki->bitki == temp->bitki)
                                gecici->sonraki->bitki->sil;
                                gecici->sonraki->bitki=NULL;
                                BagliListeYazdir(liste,satir_sayisi,sutun_sayisi);
                                canliSayisi--;
                                break;
                                
                                if(temp->sonraki->bitki == gecici->bitki){
                                    temp->sonraki->bitki->sil;
                                    temp->sonraki->bitki=NULL;
                                    BagliListeYazdir(liste,satir_sayisi,sutun_sayisi);
                                    canliSayisi--;
                                    break;
                                }
                            }
                        }
                    }
                    else {
                            gecici->bitki->sil;
                            gecici->bitki = NULL;
                            BagliListeYazdir(liste,satir_sayisi,sutun_sayisi);
                            canliSayisi--;
                            break;
                        }
                }
                temp = temp->sonraki;

            }
        }
        else if(gecici->bocek != NULL){
            
            Dugum* temp = liste->ilk;
            while (temp != NULL) {
           
                if(temp->pire!= NULL){
                    temp->pire->sil;
                    temp->pire=NULL;
                    BagliListeYazdir(liste,satir_sayisi,sutun_sayisi);
                    canliSayisi--;
                    break;
                }
                
                else if(temp->bitki!= NULL){
                    temp->bitki->sil;
                    temp->bitki=NULL;
                    BagliListeYazdir(liste,satir_sayisi,sutun_sayisi);
                    canliSayisi--;
                    break;
                }
                else if(temp->sinek!= NULL){
                    gecici->bocek->sil;
                    gecici->bocek=NULL;
                    BagliListeYazdir(liste,satir_sayisi,sutun_sayisi);
                    canliSayisi--;
                    break;
                }
                else if (temp->sonraki != NULL && temp->bocek != NULL && (gecici->bocek != temp->bocek)) {
                        if (gecici->bocek->super->deger > temp->bocek->super->deger) {
                            temp->bocek->sil;
                            temp->bocek = NULL;
                            BagliListeYazdir(liste,satir_sayisi,sutun_sayisi);
                            canliSayisi--;
                            break;
                        } 
                }
                        else if (temp->sonraki != NULL && temp->bocek != NULL && (gecici->bocek != temp->bocek)) {
                            if (gecici->bocek->super->deger == temp->bocek->super->deger){
                                while(gecici!=NULL){
                                    if(gecici->sonraki->bocek == temp->bocek){
                                        gecici->sonraki->bocek->sil;
                                        gecici->sonraki->bocek=NULL;
                                        BagliListeYazdir(liste,satir_sayisi,sutun_sayisi);
                                        canliSayisi--;
                                        break;
                                }   }
                                    while(gecici != NULL){
                                        if(temp->sonraki->bocek == gecici->bocek){
                                            temp->sonraki->bocek->sil;
                                            temp->sonraki->bocek=NULL;
                                            BagliListeYazdir(liste,satir_sayisi,sutun_sayisi);
                                            canliSayisi--;
                                            break;
                                        }
                                    }
                                
                               }   
                        }
                    else {
                            gecici->bocek->sil;
                            gecici->bocek = NULL;
                            BagliListeYazdir(liste,satir_sayisi,sutun_sayisi);
                            canliSayisi--;
                            break;
                        }
               
                temp = temp->sonraki;
            }
        }
        else if(gecici->sinek != NULL){
            
            Dugum* temp = liste->ilk;
            while (temp != NULL) {
           
                if(temp->pire!= NULL){
                    temp->pire->sil;
                    temp->pire=NULL;
                    BagliListeYazdir(liste,satir_sayisi,sutun_sayisi);
                    canliSayisi--;
                    break;
                }
                
                else if(temp->bocek!= NULL){
                    temp->bocek->sil;
                    temp->bocek=NULL;
                    BagliListeYazdir(liste,satir_sayisi,sutun_sayisi);
                    canliSayisi--;
                    break;
                }
                else if(temp->bitki!= NULL){
                    gecici->sinek->sil;
                    gecici->sinek=NULL;
                    BagliListeYazdir(liste,satir_sayisi,sutun_sayisi);
                    canliSayisi--;
                    break;
                }

                else if (temp->sonraki != NULL && temp->sinek != NULL && (gecici->sinek != temp->sinek)) {
                    if (gecici->sinek->super->super->deger > temp->sinek->super->super->deger) {
                        temp->sinek->sil;
                        temp->sinek = NULL;
                        BagliListeYazdir(liste,satir_sayisi,sutun_sayisi);
                        canliSayisi--;
                        break;
                    
                    }
                }    else if (temp->sonraki != NULL && temp->sinek != NULL && (gecici->sinek != temp->sinek)) {
                        
                        if(gecici->sinek->super->super->deger == temp->sinek->super->super->deger){
                            while(gecici!= NULL){
                                if(gecici->sonraki->sinek == temp->sinek){
                                gecici->sinek->sil;
                                gecici->sonraki->sinek=NULL;
                                BagliListeYazdir(liste,satir_sayisi,sutun_sayisi);
                                canliSayisi--;
                                break;
                                }
                                while(gecici!=NULL){
                                    if(temp->sonraki->sinek == gecici->sinek){
                                        temp->sinek->sil;
                                        temp->sonraki->sinek=NULL;
                                        BagliListeYazdir(liste,satir_sayisi,sutun_sayisi);
                                        canliSayisi--;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    else {
                        gecici->sinek->sil;
                        gecici->sinek = NULL;
                        BagliListeYazdir(liste,satir_sayisi,sutun_sayisi);
                        canliSayisi--;
                        break;
                        }
                }
                    temp = temp->sonraki;
            }
        
    
        else if (gecici->pire != NULL) {
        Dugum* temp = liste->ilk;
       
            while (temp != NULL) {
            
                if(temp->bocek!= NULL){
                    gecici->pire->sil;
                    gecici->pire=NULL;
                    BagliListeYazdir(liste,satir_sayisi,sutun_sayisi);
                    canliSayisi--;
                    break;
                }
                else if(temp->bitki!= NULL){
                    gecici->pire->sil;
                    gecici->pire=NULL;
                    BagliListeYazdir(liste,satir_sayisi,sutun_sayisi);
                    canliSayisi--;
                    break;
                }
                if(temp->sinek!= NULL){
                    gecici->pire=NULL;
                    gecici->pire->sil;
                    BagliListeYazdir(liste,satir_sayisi,sutun_sayisi);
                    canliSayisi--;
                    break;
                }
                
                if (temp->sonraki != NULL && temp->pire != NULL && (gecici->pire != temp->pire)) {
                if (gecici->pire->super->super->deger > temp->pire->super->super->deger) {
                    temp->pire->sil;
                    temp->pire = NULL;
                    BagliListeYazdir(liste,satir_sayisi,sutun_sayisi);
                    canliSayisi--;
                    break;
                
                } 
                if (temp->sonraki != NULL && temp->pire != NULL && (gecici->pire != temp->pire)) {
                    if(gecici->pire->super->super->deger == temp->pire->super->super->deger){
                        while(gecici !=NULL){
                            if(gecici->sonraki->pire == temp->pire){
                                gecici->sonraki->pire->sil;
                                gecici->sonraki->pire=NULL;
                                BagliListeYazdir(liste,satir_sayisi,sutun_sayisi);
                                canliSayisi--;
                                break;
                            }
                            while(gecici!=NULL)
                            if(temp->sonraki->pire == gecici->pire){
                                temp->sonraki->pire->sil;
                                temp->sonraki->pire=NULL;     
                                BagliListeYazdir(liste,satir_sayisi,sutun_sayisi);
                                canliSayisi--;
                                break;
                            }
                        
                        }
                    }
                } 
                else {
                    gecici->pire->sil;
                    gecici->pire = NULL;
                    BagliListeYazdir(liste,satir_sayisi,sutun_sayisi);
                    canliSayisi--;
                    break;
                }
            }
            temp = temp->sonraki;
        }
    }

        gecici = gecici->sonraki;
       
        if (canliSayisi < dugumSayisi(liste)) {
            gecici = liste->ilk; 
            canliSayisi = dugumSayisi(liste); 
        }
    }
    
    kazananDugum(liste);
    BagliListeYokEt(liste);
}

void habitatYoket(Habitat habitat) {
    if (habitat != NULL) {
        free(habitat); 
    }
}
    