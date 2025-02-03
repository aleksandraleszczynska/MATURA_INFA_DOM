#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
bool czyRosnacy(const vector<int>& tab, int start, int end) {
    for (int i = start + 1; i <= end; i++) {
        if (tab[i - 1] >= tab[i]) {
            return false;
        }
    }
    return true;
}
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
    vector<int> cyfry;
    int c;
    while (plik >> c)
        {
            cyfry.push_back(c);
        }

    int licznik = 0;
    for (size_t i = 0; i <= cyfry.size() - 6; i++) {
        vector<int> szostka(cyfry.begin() + i, cyfry.begin() + i + 6);
        bool znaleziono = false;
        for (int k = 2; k <= 4; k++) {
            if (czyRosnacy(szostka, 0, k - 1) && czyMalejacy(szostka, k, 5)) {
                znaleziono = true;
                break;
            }
        }

        if (znaleziono) {
            licznik++;
        }
    }

    cout << licznik << endl;

    return 0;
}
