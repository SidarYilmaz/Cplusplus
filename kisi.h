#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

//dosyadan ogrenci adını okuduktan sonra bunu saklayacak class .
class kisi
{
public:
    //ders adını ve notu basan print fonks.
    void print() const;

    //ogrencinin adini dosyadan okuyan fonks.
    void isim_ata(string first, string last);

    //okunan ogrenci adını kaydeden fonks.
    void isim_al(string& first, string& last);

    kisi(string first, string last);

    //construction
    kisi(); 

 private:
    string firstName; 
    string lastName; 
};

