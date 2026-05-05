//Confronto sui vettori piccoli per capire fino a che dimensione gli
//algoritmi quadratici battono quicksort/mergesort
#include "randfiller.h"
#include "timecounter.h"
#include "algoritmi.hpp"
#include <vector>
#include <iostream>

#define C 200
int main(){
    int dimensioni[] = {4, 8, 16, 32, 64, 100, 150, 200};
    int n_dim = 8;
    randfiller rf;
    timecounter tc;

    std::cout << "size\tbubble\tselect\tinsert\tquick\tmerge\t(microsecondi)\n";

    for(int d = 0; d < n_dim; d++){
        int sz = dimensioni[d];
        std::vector<std::vector<int>> base(C);
        for(int i = 0; i<C; i++){
            base[i].resize(sz);
            rf.fill(base[i], -1000, 1000);
        }

        std::vector<std::vector<int>> v1 = base;
        tc.tic();
        for(int i = 0; i<C; i++) bubblesort(v1[i]);
        double tb = tc.toc()/C * 1000000;

        std::vector<std::vector<int>> v2 = base;
        tc.tic();
        for(int i = 0; i<C; i++) selectionsort(v2[i]);
        double ts = tc.toc()/C * 1000000;

        std::vector<std::vector<int>> v3 = base;
        tc.tic();
        for(int i = 0; i<C; i++) insertionsort(v3[i]);
        double ti = tc.toc()/C * 1000000;

        std::vector<std::vector<int>> v4 = base;
        tc.tic();
        for(int i = 0; i<C; i++) quicksort(v4[i], 0, v4[i].size()-1);
        double tq = tc.toc()/C * 1000000;

        std::vector<std::vector<int>> v5 = base;
        tc.tic();
        for(int i = 0; i<C; i++) mergesort(v5[i], 0, v5[i].size()-1);
        double tm = tc.toc()/C * 1000000;

        std::cout << sz << "\t" << tb << "\t" << ts << "\t" << ti
                  << "\t" << tq << "\t" << tm << "\n";
    }
}
