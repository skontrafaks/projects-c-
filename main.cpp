#include <iostream>
#include <algorithm>
#include <array>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
using namespace std;

int main() {

    cout << "Pokrenili ste lotto 4/42!\nMolimo vas unesite 4 brojeva od 1 do 42.\nBrojevi se ne smiju ponavljati.\n" << endl;
    int lista[4] = { 0 };
    int x;

    for (int i = 0; i < sizeof(lista) / sizeof(int); i++) {
        cout << "Unesite " << i + 1 << ". broj: " << endl;
        cin >> x;
        bool exist = find(begin(lista), end(lista), x) != end(lista);
        bool opsegBrojeva = (x <= 0 || x >= 43);


        while (exist || opsegBrojeva) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Broj ili vec postoji ili nije u opsegu od 1 do 42.\nMolimo vas unesite novi " << i + 1 << ". broj: " << endl;
            cin >> x;
            exist = find(begin(lista), end(lista), x) != end(lista);
            opsegBrojeva = (x <= 0 || x >= 43);

        }

        lista[i] = x;
    }
    cout << "Uneseni brojevi su:\n";

    for (int i = 0; i < sizeof(lista) / sizeof(int); i++) {
        cout << lista[i] << endl;

    }
    cout << "generiranje dobitnih brojeva... up to 2 seconds" << endl;
    cout << "\nDobitni brojevi su:\n";
    int dobitniBrojevi[4] = { 0 };
    for (int i = 0; i < sizeof(dobitniBrojevi) / sizeof(int); i++) {
        srand(time(nullptr));
        dobitniBrojevi[i] = rand() % 42 + 1;
        this_thread::sleep_for(std::chrono::seconds(1));
    }

    for (int i = 0; i < sizeof(dobitniBrojevi) / sizeof(int); i++) {
        cout << dobitniBrojevi[i] << endl;
    }

    int brojPoklapanja = 0;
    cout << "\nBrojevi koji se poklapaju su:\n";
    for (int i = 0; i < sizeof(lista) / sizeof(int); i++) {
        for (int j = 0; j < sizeof(dobitniBrojevi) / sizeof(int); j++) {
            if (lista[i] == dobitniBrojevi[j]) {
                cout << lista[i] << endl;
                brojPoklapanja++;
            }
        }
    }
    switch (brojPoklapanja) {
        case 0:
        cout << "\nNiste pogodili niti jedan broj.\n" << endl;
        break;
        case 1:
        cout << "\nPogodili ste 1 broj, nije lose\n" << endl;
        break;
        case 2:
        cout << "\nOsvoji ste razor mis\n" << endl;
        break;
        case 3:
        cout << "\nOSVOJILI STE 10 000 eura\n" << endl;
        break;
        case 4:
        cout << "\nLUTRIJAAAAA... OSVOJILE STE 3 BILIJONA!\n" << endl;
        break;

    }
    cout << "\nHvala vam na sudjelovanju!\n" << endl;



    return 0;
}
