/*
*
* @author g211210003 Melike Demirtaş melike.demirtas@ogr.sakarya.edu.tr
* @since 24.04.2024
* <p>
* sinek.c
* </p>
*/
#include "Sinek.h"

Sinek sinekOlustur(int deger, int x, int y){
    
   Sinek this;
   this =(Sinek)malloc(sizeof(struct SINEK));
   this->super = bocekOlustur(deger,x, y); 
   this->super->super->deger = deger; 
   this->sil= &sinegiSil;
   this->super->super->gorunum =&sinekGorunum;
  
   return this;
   
}

char* sinekGorunum(const Sinek this) {
   return "S";
}

void sinegiSil(const Sinek this){
if(this == NULL) return;
	this->super->sil(this->super);
	free(this);
}

