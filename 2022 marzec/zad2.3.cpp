#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream plik;
    plik.open("genetyka.txt");
    if (!plik.is_open()) {
        cerr << "Nie mo¿na otworzyæ pliku!" << endl;
        return 1;
    }

    string linia;
    int licznik = 0;

    while (plik >> linia) {
        cout << "Wczytana linia: " << linia << endl; // Debug
        bool flaga = false;

        // Sprawdzanie nieparzystej liczby znaków
        if (linia.length() % 2 != 0) {
            flaga = true;
            cout << "Linia nieparzysta, oznaczona jako b³êdna." << endl;
        }

        // Sprawdzanie genów
        for (size_t i = 0; i + 1 < linia.length(); i += 2) {
            string gen = "";
            gen += linia[i];
            gen += linia[i + 1];

            cout << "Sprawdzany gen: " << gen << endl; // Debug

            if (gen != "BD" && gen != "CA" && gen != "CD" && gen != "DD" && gen != "BC") {
                flaga = true;
                cout << "Niepoprawny gen wykryty: " << gen << endl;
                break;
            }
        }

        if (flaga) {
            cout << "Linia b³êdna." << endl; // Debug
            licznik++;
        } else {
            cout << "Linia poprawna." << endl; // Debug
        }

        cout << "------------------------------------" << endl;
    }

    cout << "Liczba linii z niepoprawnymi genami: " << licznik << endl;

    return 0;
}
