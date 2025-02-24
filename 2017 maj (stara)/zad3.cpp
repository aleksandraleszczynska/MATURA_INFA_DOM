#include <iostream>
#include <fstream>
#include <string>
using namespace std;

unsigned long long na_dziesietny(string liczba) {
    int pot = 1;
    unsigned long long liczba2 = 0;
    for (int i = liczba.length() - 1; i >= 0; i--) {
        if (liczba[i] == '1') {
            liczba2 += pot;
        }
        pot = pot * 2;
    }
    return liczba2;
}
int main() {
    ifstream plik;
    plik.open("binarne.txt");
    string liczba;
    string maxi;
    unsigned long long maxid = 0;

    while (plik >> liczba) {
        unsigned long long liczba2 = na_dziesietny(liczba);
        if (liczba2 <= 65535) {
            if (liczba2 > maxid) {
                maxid = liczba2;
                maxi = liczba;
            }
        }
    }
    cout << maxi << " " << maxid << endl;
    return 0;
}
