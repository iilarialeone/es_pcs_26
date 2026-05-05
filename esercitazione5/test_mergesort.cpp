#include "is_sorted.hpp"
#include "algoritmi.hpp"
#include "randfiller.h"
#include <vector>
#include <string>
#include <iostream>
#define C 100
int main(){
    std::vector<int> lunghezze(C);
    randfiller rf;
    rf.fill(lunghezze, 50, 150);
    for(int i=0; i<C; i++){
        std::vector<int> vettore;
        vettore.resize(lunghezze[i]);
        rf.fill(vettore, -1000, 1000);
        mergesort(vettore, 0, lunghezze[i]-1);
        if(!is_sorted(vettore)){
            for (int k = 0; k < vettore.size(); k++) {
                std::cout << vettore[k] << " ";
            }
            std::cout << "\n";
            return EXIT_FAILURE;
        }
    }
    std::vector<std::string> stringhe = {"ciao", "cavallo", "banana", "gino", "patata", "carota", "cipolla", "sedano",
        "zorro", "zoccolo", "piede", "parola"};
    mergesort(stringhe, 0, stringhe.size()-1);
    if(!is_sorted(stringhe)){
        return EXIT_FAILURE;
    }

    std::cout << "MERGE: Tutti i test passati :)\n";
    return EXIT_SUCCESS;
}
