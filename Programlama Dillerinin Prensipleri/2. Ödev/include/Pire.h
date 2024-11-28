#ifndef PIRE_H
#define PIRE_H

#include "Bocek.h"

struct PIRE{
    
    Bocek super;
    void(*sil)(struct PIRE*);
};

typedef struct PIRE* Pire;

Pire pireOlustur(int, int, int);
char* pireGorunum(const Pire);
void pireyiSil(const Pire);

#endif