#ifndef SINEK_H
#define SINEK_H

#include "Bocek.h"

struct SINEK{
    
    Bocek super;
    void(*sil)(struct SINEK*);
};

typedef struct SINEK* Sinek;

Sinek sinekOlustur(int, int, int);
char* sinekGorunum(const Sinek);
void sinegiSil(const Sinek);


#endif