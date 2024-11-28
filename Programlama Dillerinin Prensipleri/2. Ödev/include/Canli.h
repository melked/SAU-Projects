#ifndef CANLI_H
#define CANLI_H

#include <stdio.h>
#include <stdlib.h>

struct CANLI
{
    int deger;
    int x; 
    int y; 
    char* (*toString)(struct CANLI*,void*);
    void(*sil)(struct CANLI*);
    char* (*gorunum)();
};

typedef struct CANLI* Canli;
    
    Canli canliOlustur(int, int, int);
    char* toString(const Canli, void*);
    void canliyiSil(const Canli);
    

#endif