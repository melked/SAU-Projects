/*
*
* @author g211210003 Melike Demirtaş melike.demirtas@ogr.sakarya.edu.tr
* @since 24.04.2024
* <p>
* canli.c
* </p>
*/
#include "Canli.h"
#include "math.h"
#include "string.h"
 
Canli canliOlustur(int deger, int x, int y){

    Canli this;
    this = (Canli)malloc(sizeof(struct CANLI));
    this->deger = deger;
    this->x = x; 
    this->y = y; 
    this->toString= NULL;
    this->toString = &toString;
	this->sil = &canliyiSil;
    
    return this;
}

char* toString(const Canli this, void* p) {
    int toplamUzunluk = 36;
    toplamUzunluk += strlen(this->gorunum(p));
    char* str = (char*)malloc(sizeof(char) * (toplamUzunluk + 1)); 
    sprintf(str, "%s", this->gorunum(p)); 
    free(p);
    
    return str;
}

void canliyiSil(const Canli this){
    if(this== NULL) return;
    free(this);
}
