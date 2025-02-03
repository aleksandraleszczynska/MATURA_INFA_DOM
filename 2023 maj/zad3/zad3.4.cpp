#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Funkcja sprawdzaj¹ca, czy ci¹g jest rosn¹cy na przedziale [start, end]
bool czyRosnacy(const vector<int>& tab, int start, int end) {
    for (int i = start + 1; i <= end; i++) {
        if (tab[i - 1] >= tab[i]) {
            return false;
        }
    }
    return true;
}

// Funkcja sprawdzaj¹ca, czy ci¹g jest malej¹cy na przedziale [start, end]
bool czyMalejacy(const vector<int>& tab, int start, int end) {
    for (int i = start + 1; i <= end; i++) {
        if (tab[i - 1] <= tab[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    ifstream plik("../Dane_2305/pi.txt");

    if (!plik.is_open()) {
        cerr << "Nie uda³o siê otworzyæ pliku!" << endl;
        return 1;
    }

    vector<int> cyfry;
    char c;

    // Wczytujemy cyfry z pliku
    while (plik >> c) {
        if (isdigit(c)) {
            cyfry.push_back(c - '0');
        }
    }

    int najdluzsza_dlugosc = 0; // Najwiêksza d³ugoœæ znalezionego ci¹gu
    int pozycja_poczatkowa = 0; // Pozycja startowa najd³u¿szego ci¹gu
    vector<int> najlepszy_ciag; // Najd³u¿szy ci¹g rosn¹co-malej¹cy

    // Analizujemy wszystkie mo¿liwe pozycje startowe
    for (size_t start = 0; start < cyfry.size(); start++) {
        for (size_t koniec = start + 3; koniec < cyfry.size(); koniec++) {
            // Tworzymy podci¹g [start, koniec]
            vector<int> podciag(cyfry.begin() + start, cyfry.begin() + koniec + 1);

            // Szukamy podzia³u k, który spe³nia warunki
            bool znaleziono = false;
            for (size_t k = 1; k < podciag.size() - 1; k++) {
                if (czyRosnacy(podciag, 0, k) && czyMalejacy(podciag, k + 1, podciag.size() - 1)) {
                    znaleziono = true;
                    break;
                }
            }

            // Jeœli znaleziono rosn¹co-malej¹cy ci¹g, sprawdzamy jego d³ugoœæ
            if (znaleziono && podciag.size() > najdluzsza_dlugosc) {
                najdluzsza_dlugosc = podciag.size();
                pozycja_poczatkowa = start;
                najlepszy_ciag = podciag;
            }
        }
    }

    // Wynik
    cout << pozycja_poczatkowa + 1 << endl; // Pozycja pocz¹tkowa (1-indexed)
    for (int cyfra : najlepszy_ciag) {
        cout << cyfra;
    }
    cout << endl;

    return 0;
}
