/*
*
* @author g211210003 Melike Demirtaş melike.demirtas@ogr.sakarya.edu.tr
* @since 24.04.2024
* <p>
* pire.c
* </p>
*/
#include "Pire.h"

Pire pireOlustur(int deger, int x, int y){
    
   Pire this;
   this =(Pire)malloc(sizeof(struct PIRE));
   this->super = bocekOlustur(deger, x, y); 
   this->super->super->deger = deger; 
   this->sil= &pireyiSil;
   this->super->super->gorunum =&pireGorunum;
   
   return this;
   
}

char* pireGorunum(const Pire this) {
   return "P";
}

void pireyiSil(const Pire this){
if(this == NULL) return;
	this->super->sil(this->super);
	free(this);
}
