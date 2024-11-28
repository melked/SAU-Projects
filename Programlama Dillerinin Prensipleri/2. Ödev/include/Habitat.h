#ifndef HABITAT_H
#define HABITAT_H

#include "Bitki.h"
#include "Pire.h"
#include "Sinek.h"
#include "bagliListe.h"

struct HABITAT {
    
    BagliListe* liste;
    void (*yemeIslemleri)(BagliListe liste); 
    void (*habitatYoket)(struct HABITAT* habitat);
};

typedef struct HABITAT* Habitat;

void yemeIslemleri(BagliListe liste);
Habitat habitatOlustur();
void habitatYoket(Habitat habitat);

#endif
