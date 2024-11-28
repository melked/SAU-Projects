#ifndef UstDugum_hpp
#define UstDugum_hpp

#include "BagliListe.hpp"

class UstDugum {
public:
   
    UstDugum(BagliListe* veri);
    BagliListe* AltListe; 
    UstDugum* sonraki;
};

#endif
