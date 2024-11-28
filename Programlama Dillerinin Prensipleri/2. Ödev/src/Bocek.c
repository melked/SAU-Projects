/*
*
* @author g211210003 Melike Demirtaş melike.demirtas@ogr.sakarya.edu.tr
* @since 24.04.2024
* <p>
* bocek.c
* </p>
*/
#include "Bocek.h"

Bocek bocekOlustur(int deger, int x, int y){
    
   Bocek this;
   this =(Bocek)malloc(sizeof(struct BOCEK));
   this->super = canliOlustur(deger, x, y); 
   this->super->deger = deger; 
   this->sil= &bocegiSil;
   this->super->gorunum =&bocekGorunum;
   
   return this;
}

char* bocekGorunum(const Bocek this) {
   return "C";
}

void bocegiSil(const Bocek this){
if(this == NULL) return;
	this->super->sil(this->super);
	free(this);
}
