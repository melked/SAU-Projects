#ifndef BOCEK_H
#define BOCEK_H
#include "Canli.h"

struct BOCEK{
    
    Canli super;
    void(*sil)(struct BOCEK*);
};

typedef struct BOCEK* Bocek;
    
    Bocek bocekOlustur(int, int, int);
    char* bocekGorunum(const Bocek);
    void bocegiSil(const Bocek);

#endif
