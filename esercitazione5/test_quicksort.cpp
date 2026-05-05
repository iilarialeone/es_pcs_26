#include "is_sorted.hpp"
#include "algoritmi.hpp"
#include "randfiller.h"
#include <iostream>
#include <vector>
#include <string>

#define C 100
int main(){
    std::vector<int> lunghezze(C);
    randfiller rf;
    rf.fill(lunghezze, 50, 150);
    for(int i=0; i<C; i++){
        std::vector<int> vettore;
        vettore.resize(lunghezze[i]);
        rf.fill(vettore, -1000, 1000);
        quicksort(vettore, 0, lunghezze[i]-1);
        if(!is_sorted(vettore)){
            for (int k = 0; k < vettore.size(); k++) {
                std::cout << vettore[k] << " ";
            }
            std::cout << "\n";
            return EXIT_FAILURE;
        }
    }
    std::vector<std::string> stringhe = {"calzino", "fazzoletto", "mare", "stendino", "bottiglia", "vasca", "computer", 
        "parola", "google", "cavo", "sedia", "pantaloni"};
    quicksort(stringhe, 0, stringhe.size()-1);
    if(!is_sorted(stringhe)){
        return EXIT_FAILURE;
    }

    std::cout << "QUICK: Tutti i test passati :)\n";
    return  EXIT_SUCCESS;
}