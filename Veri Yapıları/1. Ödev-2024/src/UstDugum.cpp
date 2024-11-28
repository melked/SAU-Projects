/**
* @file UstDugum.cpp
* @description Bağlı listeler ile işlemler
* @course 2. öğrenim C grubu
* @assignment 1. ödev
* @date 25.11.2024
* @author Melike Demirtaş melike.demirtas@ogr.sakarya.edu.tr
*/
#include "UstDugum.hpp"

UstDugum::UstDugum(BagliListe* veri) {
    this->AltListe = veri;
    sonraki = nullptr;
}
