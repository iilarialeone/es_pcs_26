#include "randfiller.h"
#include "timecounter.h"
#include "algoritmi.hpp"
#include "quicksort_ibrido.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

#define C 100
int main(){
    std::vector<std::vector<int>> vettore_merge(C);
    std::vector<std::vector<int>> vettore_quick(C);
    std::vector<std::vector<int>> vettore_ibrido(C);
    std::vector<std::vector<int>> vettore_std(C);
    std::vector<int> lunghezze(C);
    randfiller rf;
    rf.fill(lunghezze, 200, 500);
    for(int i = 0; i<C; i++){
        vettore_merge[i].resize(lunghezze[i]);
        rf.fill(vettore_merge[i], -1000, 1000);
    }
    vettore_quick = vettore_merge;
    vettore_ibrido = vettore_merge;
    vettore_std = vettore_merge;
    timecounter tc;
    tc.tic();
    for(int i = 0; i<C; i++){
        mergesort(vettore_merge[i], 0, vettore_merge[i].size()-1);
    }
    double secs = tc.toc();
    std::cout << "Il tempo totale per il mergesort è " << secs << " secondi.\n";
    std::cout << "Il tempo medio per il mergesort è " << secs/C << " secondi.\n";

    tc.tic();
    for(int j = 0; j<C; j++){
        quicksort(vettore_quick[j], 0, vettore_quick[j].size()-1);
    }
    double seconds = tc.toc();
    std::cout << "Il tempo totale per il quicksort è " << seconds << " secondi.\n";
    std::cout << "Il tempo medio per il quicksort è " << seconds/C << " secondi.\n";

    tc.tic();
    for(int k = 0; k<C; k++){
        quicksort_ibrido(vettore_ibrido[k], 0, vettore_ibrido[k].size()-1);
    }
    double sec_ibrido = tc.toc();
    std::cout << "Il tempo totale per il quicksort ibrido è " << sec_ibrido << " secondi.\n";
    std::cout << "Il tempo medio per il quicksort ibrido è " << sec_ibrido/C << " secondi.\n";

    tc.tic();
    for(int h = 0; h<C; h++){
        std::sort(vettore_std[h].begin(), vettore_std[h].end());
    }
    double sec_std = tc.toc();
    std::cout << "Il tempo totale per std::sort è " << sec_std << " secondi.\n";
    std::cout << "Il tempo medio per std::sort è " << sec_std/C << " secondi.\n";

}
