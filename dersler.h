#pragma once
#include <fstream>
#include <string>
using namespace std;

//ogrencinin ders bilgilerini saklayan class
class DERS{
public:
      //verilen parametreleri nesnenin değişken kısmına atayan fonk.
      void ders__kayit(string ders_isimleri, string ders_no, char ders_notu, int ders_kredisi);

      //ogrenci notunu ders ıd sini yazdıran fonk.
      void print(bool isGrade);

      //alınan  veriyi dosyaya bastıran fonk.
      void print(ofstream& panda, bool isGrade);

      //Kursların kredilerini değiştirmek veya göremk için kullanılan fonk.
      int  not_ata();

      //ders_no-->ders sayisi na atayan fonsk.
      void ders_no_oku(string& ders_no);

      //dosyadan okunan değeri nesnenin not değişkenine atayan fonk. 
      char not_oku();

      //consturctor 
      DERS(string ders_isimleri = "", string ders_no = "", char ders_notu = '*', int ders_kredisi = 0);

private:
     string dersAdi;
     char   dersNotu;
     int    dersKredisi;
     string dersNo;
};

