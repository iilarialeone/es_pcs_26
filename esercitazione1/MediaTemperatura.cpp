#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
    // Controllo che sia stato effettivamente inserito un argomento
    if (argc != 2) {
        cerr << "Inserire uno e un solo argomento.\n";
        return -1;
    }

    // Controllo che il file sia stato aperto correttamente
    ifstream file(argv[1]);
    if (!file.is_open()) {
        cerr << "C'è stato un errore nell'apertura del file.\n";
        return -1;
    }

    // Se il file è stato aperto correttamente, continuo
    string location;
    double t1, t2, t3, t4;
    while (file >> location >> t1 >> t2 >> t3 >> t4) {
        double media = (t1 + t2 + t3 + t4) / 4.0;
        cout << "La temperatura media di " << location << " è " << media << "°C\n";
    }
}
