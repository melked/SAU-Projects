/*
*
* @author g211210003 Melike Demirtaş melike.demirtas@ogr.sakarya.edu.tr
* @since 24.04.2024
* <p>
* Bitki.c
* </p>
*/
#include "Bitki.h"

Bitki bitkiOlustur( int deger, int x, int y){
    
   Bitki this;
   this =(Bitki)malloc(sizeof(struct BITKI));
   this->super = canliOlustur(deger, x, y); 
   this->super->deger = deger; 
   this->sil= &bitkiyiSil;
   this->super->gorunum =&bitkiGorunum;
   
   return this;

}

char* bitkiGorunum(const Bitki this) {
   return "B";
}

void bitkiyiSil(const Bitki this){
if(this == NULL) return;
	this->super->sil(this->super);
	free(this);
}
