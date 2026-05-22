#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

double x;
double y;

struct Ebike {
    int id;
    double x;
    double y;
    bool disponibile;
    double autonomia;
};

double distanza(Ebike bike) {
    return sqrt(pow(bike.x - x, 2) + pow(bike.y - y, 2));
}

bool confronta(Ebike bike1, Ebike bike2) {
    return distanza(bike1) < distanza(bike2);
}

int main() {
    srand(time(0));

    Ebike array_bici[3];
    array_bici[0] = {0, 1.5, 2.8, true, 12.4};
    array_bici[1] = {1, 3.9, 1.8, true, 2.4};
    array_bici[2] = {2, 3.2, 1.5, true, 15.7};
    array_bici[3] = {3, 4.6, 2.0, true, 15.0};
    array_bici[4] = {4, 12.0, 10.0, true, 50.0};

    cout << "Inserisci la tua coordinata X: ";
    cin >> x;
    cout << "Inserisci la tua coordinata Y: ";
    cin >> y;

    sort(array_bici, array_bici + 5, confronta);

    cout << "\n--- Elenco Bici Disponibili ---" << endl;
    for (int i = 0; i < 5; i++) {
        if (array_bici[i].disponibile) {
            cout << "ID: " << array_bici[i].id << endl; 
            cout << "  \nDistanza: " << distanza(array_bici[i]) << endl; 
            cout << "  \nAutonomia: " << array_bici[i].autonomia << endl;
        }
    }

    int Id_scelto;
    cout << "\nInserisci l'ID della bici: ";
    cin >> Id_scelto;

    int i;
    bool trovato = false;
    
    for (i = 0; i < 5; i++) {
        if (array_bici[i].id == Id_scelto && array_bici[i].disponibile) {
            trovato = true;
            break;
        }
    }

    if (!trovato) {
        cout << "La bici non è disponibile" << endl;
        return 0;
    }

    double percorso_km;
    cout << "Quanti km vuoi percorrere? ";
    cin >> percorso_km;

    if (percorso_km > array_bici[i].autonomia) {
        cout << "Autonomia insufficiente" << endl;
    } else {
        double velocita_media = 20.0;
        int ritardo_casuale = rand() % 15 + 1;
        double tempo_minuti = (percorso_km / velocita_media) * 60 + ritardo_casuale;

        double costo_finale = tempo_minuti * 0.20;
        array_bici[i].autonomia -= percorso_km;

        cout << "\n--- Noleggio ---" << endl;
        cout << "Tempo totale: " << tempo_minuti << " minuti" << endl;
        cout << "Percorso: " << percorso_km << " km" << endl;
        cout << "Costo: " << costo_finale << " Euro" << endl;
        cout << "Autonomia residua: " << array_bici[i].autonomia << " km" << endl;
    }

    return 0;
}
