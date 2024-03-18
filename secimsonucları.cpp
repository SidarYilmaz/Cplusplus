#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int MaxAday = 10;   
const int MaxBolge = 4;   

struct ADAY
{
    string adaylar;
};

int aday = 0;
int bolge = 0;
ADAY isimler[MaxAday];
int Secim_Sunucları[MaxAday][MaxBolge];
int toplam_oy[MaxAday];

void Adayİsimleri(const string& fileName);
void Oy(const string& fileName);
void Sonuc_Bastırma();

int main()
{
    string candData = "candData.txt";
    string voteData = "voteData.txt";
    Adayİsimleri(candData);
    Oy(voteData);
    Sonuc_Bastırma();
}

void Oy(const string& fileName) {
    ifstream file(fileName);
    string Aday_ismi;
    int eyalet, oylar;
    bool eyaletInitialized[MaxBolge] = { false };

    while (file >> Aday_ismi >> eyalet >> oylar) {
        if (eyalet > bolge) {
            bolge = eyalet;
            eyaletInitialized[eyalet - 1] = true;
        }

        for (int i = 0; i < aday; i++) {
            if (isimler[i].adaylar == Aday_ismi) {
                Secim_Sunucları[i][eyalet - 1] += oylar;
                break;
            }
        }
    }
    
    for (int i = 0; i < aday; i++) {
        for (int j = 0; j < bolge; j++) {
                toplam_oy[i] += Secim_Sunucları[i][j]; 
        }
    }
    file.close();
}

void Adayİsimleri(const string& fileName) {
    ifstream file(fileName);
    string katılımcı;
    while (file >> katılımcı && aday < MaxAday)
    {
        isimler[aday++].adaylar = katılımcı;
    }
    file.close();
}

void Sonuc_Bastırma() {
    cout << "-------------------Secim Sonuclari--------------------\n";
    cout << "Adaylar\t\t\tOylar\n---------\t--------------------------------------\nIsimler\t";
    for (int r = 1; r <= bolge; r++) {
        cout << "\tBolge" << r;
    }
    cout << "\tToplam\n";
    cout << "---------";
    for (int r = 1; r <= bolge; r++) {
        cout << "\t-------";
    }
    cout << "\t-----\n";

    int toplam_oy_sayisi = 0;
    int MaxOy = 0;
    string kazanan;

    for (int i = 0; i < aday; i++) {
        cout << isimler[i].adaylar;
        int tabCount = isimler[i].adaylar.length() > 7 ? 1 : 2;  // İsim 7 karakterden uzunsa 1 tab, değilse 2 tab
        for (int t = 0; t < tabCount; t++) {
            cout << "\t";
        }

        for (int j = 0; j < bolge; j++) {
            cout << Secim_Sunucları[i][j] << "\t";
        }
        cout << toplam_oy[i] << "\n";

        toplam_oy_sayisi += toplam_oy[i];
        if (toplam_oy[i] > MaxOy) {
            MaxOy = toplam_oy[i];
            kazanan = isimler[i].adaylar;
        }
    }

    cout << "Kazanan: " << kazanan << ", Aldigi oy: " << MaxOy << "\n";
    cout << "Toplam oy: " << toplam_oy_sayisi << "\n";
}
