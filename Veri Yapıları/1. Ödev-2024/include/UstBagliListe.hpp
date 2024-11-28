#ifndef UstBagliListe_hpp
#define UstBagliListe_hpp

#include "UstDugum.hpp"

class UstBagliListe {
public:
    
    UstBagliListe();
    ~UstBagliListe();
    void ekle(BagliListe* yeniListe); //Bağlı liste türünden düğümler tutuyor.
    void yazdir();     
    int sutunSayisiDondur();
    int satirSayisiDondur();
    void mutasyon(int satir, int sutun); 
    void caprazlama(int ilkSatir, int ikinciSatir);
    void OtomatikIslemler();
    void ekranaYaz();
    UstDugum* ilk  ;  // İlk üst düğümü tuttum.

private:
   
    int satirSayisi; 
     
};

#endif
