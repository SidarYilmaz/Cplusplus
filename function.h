#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> 
#include "dersler.h"
#include "kisi.h"
#include "ogrenci.h"

using namespace std;

//----------------------------------dersler------------------------------------------------
void DERS::ders__kayit(string ders_isimleri, string ders_no, char ders_notu, int ders_kredisi) {
    dersAdi = ders_isimleri;
    dersNotu = ders_notu;
    dersKredisi = ders_kredisi;
    dersNo = ders_no;
}

void DERS::print(bool notlar_) {
    cout << left;
    cout << setw(8) << dersNo << "  ";
    cout << setw(15) << dersAdi;

    cout.unsetf(ios::left);

    cout << setw(3) << dersKredisi << "  ";

    if (notlar_)
        cout << setw(4) << dersNotu << endl;
    else
        cout << setw(4) << "***" << endl;
}

void DERS::print(ofstream& panda, bool notlar_) {
    panda << left;
    panda << setw(8) << dersNo << "  ";
    panda << setw(15) << dersAdi;

    panda.unsetf(ios::left);

    panda << setw(3) << dersKredisi << "  ";

    if (notlar_)
        panda << setw(4) << dersNotu << endl;
    else
        panda << setw(4) << "***" << endl;
}

DERS::DERS(string ders_isimleri, string ders_no, char ders_notu, int ders_kredisi) {
    dersAdi = ders_isimleri;
    dersNotu = ders_notu;
    dersKredisi = ders_kredisi;
    dersNo = ders_no;
}

void DERS::ders_no_oku(string& ders_no) {
    dersNo = ders_no;
}

char DERS::not_oku() {
    return dersNotu;
}

int  DERS::not_ata() {
    return dersKredisi;
}
//---------------------------------------kisi-------------------------------------------
void kisi::print() const
{
    cout << firstName << " " << lastName;
}

void kisi::isim_ata(string first, string last)
{
    firstName = first;
    lastName = last;
}

void kisi::isim_al(string& first, string& last)
{
    first = firstName;
    last = lastName;
}

kisi:: kisi() {
    firstName = "";
    lastName = "";
}
//----------------------------------------------ogrenci-----------------------------------------
void ogrenci::initialize(string fName, string lName, int ID, int ders_sayisi, bool harc_odendi, DERS courses[]) {

    int i;
    sId = ID;

    kisi::isim_ata(fName, lName);

    ogrenim_ucreti_odendi = harc_odendi;
    alinana_ders_sayisi = ders_sayisi;

    for (i = 0; i < alinana_ders_sayisi; i++)
        kayitli_dersler[i] = courses[i];

    ders_sırala(); //dersleri hexografik sıraya koyan fonk.
}

void ogrenci::print(double ogrenim__ucreti) {
    int i;

    cout << "Ogrenci ismi: ";
    kisi::print();
    cout << endl;

    cout << "Ogrenci ID: " << sId << endl;

    cout << "Kayit olunan ders sayisi " << alinana_ders_sayisi << endl;
    cout << endl;

    cout << left;

    cout << "Ders kodu" << setw(15) << "Dersin adi" << setw(8) << "Kredi" << setw(6) << "Not" << endl;

    cout.unsetf(ios::left);

    for (i = 0; i < alinana_ders_sayisi; i++)
        kayitli_dersler[i].print(ogrenim_ucreti_odendi);
    cout << endl;

    cout << "Toplam ders saati " << top_ders_sayisi() << endl;

    cout << fixed << showpoint << setprecision(2);

    if (ogrenim_ucreti_odendi)
        cout << "Donem ortalamasi: " << Ort_hesaplama() << endl;
    else
    {
        cout << "***  Acilen ucretinizi odeyiniz  ;)  ***" << endl;
        cout << "Odemeniz gereken ucret " << odenecek_harc_ucreti(ogrenim__ucreti)<< " Dollar" << endl;
    }
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
}

void ogrenci::print(ofstream& panda, double ogrenim__ucreti) {
    int i;
    string first;
    string last;

    kisi::isim_al(first, last);

    panda << "Ogrencinin adi: " << first << " " << last << endl;

    panda << "Ogrenci ID: " << sId << endl;

    panda << "Kayit olunan ders sayisi "<< alinana_ders_sayisi << endl;
    panda << endl;

    panda << left;
    panda << "Ders kodu" << setw(15) << "  Dersin adi"<< setw(8) << "Ders kredisi"<< setw(6) << "Not" << endl;

    panda.unsetf(ios::left);
    for (i = 0; i < alinana_ders_sayisi; i++)
        kayitli_dersler[i].print(panda, ogrenim_ucreti_odendi);
    panda << endl;

    panda << "Alinan toplam ders sayisi:  "  << top_ders_sayisi() << endl;

    panda << fixed << showpoint << setprecision(2);

    if (ogrenim_ucreti_odendi)
        panda << "Donem ortalamasi:  " << Ort_hesaplama() << endl;
    else
    {
        panda << "***  Acilen ucretinizi odeyiniz  ;)  ***" << endl;
        panda << "Anlik borcunuz: " << odenecek_harc_ucreti(ogrenim__ucreti) << "Lira" << endl;
    }

    panda << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
}

ogrenci::ogrenci() {

}

int ogrenci::top_ders_sayisi() {
    int toplam_kredi = 0;

    for (int i = 0; i < alinana_ders_sayisi; i++)
        toplam_kredi += kayitli_dersler[i].not_ata();

    return toplam_kredi;
}

double ogrenci::Ort_hesaplama() {
    int i;
    double sum = 0.0;

    for (i = 0; i < alinana_ders_sayisi; i++)
    {
        char not_value = kayitli_dersler[i].not_oku();
        double not_ata_value = kayitli_dersler[i].not_ata();

        if (not_value == 'A') {
            sum += not_ata_value * 4;
        }
        else if (not_value == 'B') {
            sum += not_ata_value * 3;
        }
        else if (not_value == 'C') {
            sum += not_ata_value * 2;
        }
        else if (not_value == 'D') {
            sum += not_ata_value * 1;
        }
        else if (not_value == 'F') {
            sum += not_ata_value * 0;
        }
        else {
            cout << " HATALI NOT GIRILDI :( " << not_value << endl;
        }
    }
    return sum / top_ders_sayisi();
}



double ogrenci::odenecek_harc_ucreti(double ogrenim__ucreti) {
    return ogrenim__ucreti * top_ders_sayisi();
}


void ogrenci::ders_sırala() {
    int i, j;
    int minIndex;
    DERS temp_ders;
    string ders_1;
    string ders_2;

    for (i = 0; i < alinana_ders_sayisi - 1; i++)
    {
        minIndex = i;
        for (j = i + 1; j < alinana_ders_sayisi; j++)
        {
            kayitli_dersler[minIndex].ders_no_oku(ders_1);
            kayitli_dersler[j].ders_no_oku(ders_2);

            if (ders_1 > ders_2)
                minIndex = j;
        }//end for
        temp_ders = kayitli_dersler[minIndex];
        kayitli_dersler[minIndex] = kayitli_dersler[i];
        kayitli_dersler[i] = temp_ders;
    }
}


