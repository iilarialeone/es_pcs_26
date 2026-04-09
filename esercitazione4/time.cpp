#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#include "timecounter.h"
#include "algoritmi.hpp"
#include "randfiller.h"



int main(){
    randfiller rf;
    timecounter tc;
    for(int i = 2; i < 14; i++){
        std::vector<int> vettore;
        vettore.resize(std::exp2(i));
        rf.fill(vettore, -1000, 1000);
        std::vector<int> bubble = vettore;
        std::vector<int> selection = vettore;
        std::vector<int> insertion = vettore;

        std::cout << "Il vettore è lungo " << vettore.size() << " elementi.\n";
        tc.tic();
        bubblesort(bubble);        
        double secs = tc.toc();
        std::cout << "Il bubblesort ha impiegato " << secs << " secondi.\n";

        tc.tic();
        selectionsort(selection);
        secs = tc.toc();
        std::cout << "Il selectionsort ha impiegato " << secs << " secondi.\n";

        tc.tic();
        insertionsort(insertion);
        secs = tc.toc();
        std::cout << "L'insertionsort ha impiegato " << secs << " secondi.\n";

        tc.tic();
        std::sort(vettore.begin(), vettore.end());
        secs = tc.toc();
        std::cout << "Il sort ha impiegato " << secs << " secondi.\n";

    }
    return 0;
}