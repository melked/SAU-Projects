#ifndef BagliListe_hpp
#define BagliListe_hpp

#include "Dugum.hpp"

class BagliListe {
public:
    BagliListe();
    ~BagliListe();
    void ekle(char veri);     
    void yazdir(); 
    int sutunSayisiDondur();
    int satirSayisiDondur();
    Dugum* ilk;  
private:

    int satirSayisi;
};

#endif
