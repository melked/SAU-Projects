#ifndef BITKI_H
#define BITKI_H


#include "Canli.h"


#include <stdio.h>
#include <stdlib.h>

struct BITKI{
    
    Canli super;
    void (*sil)(struct BITKI*);
   
};

typedef struct BITKI* Bitki;

Bitki bitkiOlustur(int, int, int);
char* bitkiGorunum(const Bitki);
void bitkiyiSil(const Bitki);

#endif
