#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;

int main() {
    ifstream plik("../Dane_2205/liczby.txt");
    vector<int> liczby;
    int liczba;
    while (plik >> liczba) {
        liczby.push_back(liczba);
    }
    set<int> unikalne_liczby(liczby.begin(), liczby.end());
    liczby.assign(unikalne_liczby.begin(), unikalne_liczby.end());

    ofstream trojki("trojki.txt");
    int licznik_trojek = 0;

    for (int i = 0; i < liczby.size(); i++) {
        for (int j = 0; j < liczby.size(); j++) {
            if (i == j || liczby[j] % liczby[i] != 0) continue;

            for (int k = 0; k < liczby.size(); k++) {
                if (k == i || k == j || liczby[k] % liczby[j] != 0) continue;

                trojki << liczby[i] << " " << liczby[j] << " " << liczby[k] << endl;
                licznik_trojek++;
            }
        }
    }
    trojki.close();
    cout  << licznik_trojek << endl;
    int licznik_piatek = 0;

    for (int u = 0; u < liczby.size(); u++) {
        for (int w = 0; w < liczby.size(); w++) {
            if (u == w || liczby[w] % liczby[u] != 0) continue;

            for (int x = 0; x < liczby.size(); x++) {
                if (x == u || x == w || liczby[x] % liczby[w] != 0) continue;

                for (int y = 0; y < liczby.size(); y++) {
                    if (y == u || y == w || y == x || liczby[y] % liczby[x] != 0) continue;

                    for (int z = 0; z < liczby.size(); z++) {
                        if (z == u || z == w || z == x || z == y || liczby[z] % liczby[y] != 0) continue;

                        licznik_piatek++;
                    }
                }
            }
        }
    }
    cout << licznik_piatek << endl;

    return 0;
}
