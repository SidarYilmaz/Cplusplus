#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "kisi.h"
#include "dersler.h"

using namespace std;

//kisi'den miras alan yeni bir class
class ogrenci : public kisi{

public:
    //diğer nesnelere erişip okuma ve atama yapan fonk.
    void initialize(string ogrenci_ismi, string ogrenci_soyismi, int ID, int ders_sayisi, bool isTPaid, DERS ders_isimleri[]);

    //sonuçları konsola basan fonk.
    void print(double harc_ucreti);

    //dosyaya yazma islemi yapan fonk.
    void print(ofstream& panda, double harc_ucreti);

    //construction 
    ogrenci();

    int top_ders_sayisi();
    double Ort_hesaplama();
    double odenecek_harc_ucreti(double harc_ucreti);

private:
    void ders_sırala();
    int sId;
    int alinana_ders_sayisi; 
    bool ogrenim_ucreti_odendi;	
    DERS kayitli_dersler[6];
};

