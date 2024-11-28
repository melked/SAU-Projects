/*
*
* @author g211210003 Melike Demirtaş melike.demirtas@ogr.sakarya.edu.tr
* @since 24.04.2024
* <p>
* Dugum.c
* </p>
*/
#include "Dugum.h"

Dugum* DugumOlustur(int deger) {
    Dugum* dugum = (Dugum*)malloc(sizeof(Dugum));
    if (dugum != NULL) {
        dugum->deger = deger;
        dugum->sonraki = NULL;
    }
    return dugum;
}
