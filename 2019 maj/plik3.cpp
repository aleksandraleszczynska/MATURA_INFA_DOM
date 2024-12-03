#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int NWD(int a, int b)
{
    if (a == b)
    {
        return a;
    }
    while (a != b)
    {
        if (a < b)
        {
            b = b - a;
        }
        else
        {
            a = a - b;
        }
    }
    return a;
}

int main()
{
    fstream plik;
    ofstream zapis;
    plik.open("C:/Users/DELL/Desktop/MATURA_INFA/2019 maj/Dane_PR/liczby.txt");
    zapis.open("C:/Users/DELL/Desktop/MATURA_INFA/2019 maj/wyniki6.txt");
    vector<int> liczby;
    vector<int> finalneLiczby;
    int all[500];
    string line;
    int count = 0;
    while (getline(plik, line))
    {
        all[count] = stoi(line);
        count++;
    }
    int n = all[0];
    int dzielnik;
    for (int i = 1; i < 500; i++)
    {
        int nwd = NWD(n, all[i]);
        if (nwd != 1)
        {
            if (liczby.empty())
            {                        // sprawdzamy najpierw czy pomocniczy zbior liczb jest pusty (co oznaczaloby, ze w n jest przechowana liczba, a nie dzielnik)
                liczby.push_back(n); // jezeli tak to od razu dodajemy ta liczbe do zbioru (aby jej nie pominac)
            }
            liczby.push_back(all[i]); // nastepnie dodajemy liczbe z aktualnego wiersza
            n = nwd;                  // i przypisujemy za n nowy dzielnik
        }
        else
        {
            if (liczby.size() > finalneLiczby.size())
            {                           // sprawdzamy czy pomocniczy zbior jest dluzszy, niz ten finalny
                finalneLiczby = liczby; // jezeli tak to zapisujemy go jako finalny
                dzielnik = n;           // i zapisujemy finalny dzielnik
            }
            if (!liczby.empty())
            { // jezeli zas pomocniczy zbior nie jest pusty (co oznacza, ze wlasnie znalezlismy koniec ciagu)

                if (NWD(liczby[liczby.size() - 1], all[i]) > 1)
                {                                      // musimy sprawdzic, czy ostatnia liczba ze zbioru pomocniczego nie posiada wspolnych dzielnikow z aktualnie sprawdzana liczba (musimy to zrobic, dlatego ze za n przypisany jest dzielnik, a nie liczba)
                    int a = liczby[liczby.size() - 1]; // jezeli liczby maja wspolny dzielnik
                    liczby.clear();                    // czyscimy zbior pomocniczy
                    liczby.push_back(a);               // a nastepnie dodajemy do niego od razu dwie liczby
                    liczby.push_back(all[i]);          // ktore spelniaja warunki zadania
                }
                else
                {
                    liczby.clear();
                }
            }

            n = all[i];
        }
    }

    zapis << finalneLiczby[0] << " " << finalneLiczby.size() << " " << dzielnik;
    zapis.close();
    return 0;
}
