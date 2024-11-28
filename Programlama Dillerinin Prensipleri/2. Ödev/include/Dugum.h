#ifndef Dugum_h
#define Dugum_h

#include "Bitki.h" 
#include "Pire.h"
#include "Sinek.h"



struct Dugum {
    
    int deger;
    struct Dugum* sonraki;
    Bitki bitki;
    Bocek bocek;
    Sinek sinek;
    Pire pire;
};

typedef struct Dugum Dugum;

Dugum* DugumOlustur(int deger);


#endif
