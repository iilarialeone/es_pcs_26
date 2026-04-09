#include <iostream>
#include <vector>
#include <string>

#include "algoritmi.hpp"
#include "is_sorted.hpp"
#include "randfiller.h"

#define C 100 //Definisco una costante per il numero di prove che devo fare.


int main(){
    randfiller rf;                        //creo un oggetto di tipo randfiller
    std::vector<int> lunghezze;           //creo un vettore di lunghezza 100 che definirà le lunghezze dei miei 100 vettori
    lunghezze.resize(C);
    rf.fill(lunghezze, 0, 200);           //riempio il vettore lunghezze con elementi randomici

    for(int i = 0; i < C; i++){           //creo per 100 volte un vettore, lo ordino e controllo che sia ordinato
        // std::vector<int> vettore;
        std::vector<int> vettore;
        vettore.resize(lunghezze[i]);
        rf.fill(vettore, -1000, 1000);    //i valori del vettore vanno da -1000 a 1000

        selectionsort(vettore);

        if(!is_sorted(vettore)){
            return EXIT_FAILURE;          //appena trovo un vettore che non è ordinato interrompo
        }

    }

    std::vector<std::string> vettorino = {
        "ciao", "fagiolo", "collana", "giallo", "apollo", "zerbino", "ramo", "hudie", "naso", "minnie"
    };

    selectionsort(vettorino);

    if(!is_sorted(vettorino)){
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;                  //altrimenti, dopo averli testati tutti, interrompo con successo
}