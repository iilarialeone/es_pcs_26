#pragma once
#include <vector>
#include "algoritmi.hpp"
using namespace std;

#define SOGLIA 32

//Quicksort ibrido: sotto la SOGLIA passo a insertionsort
template <typename T>
void quicksort_ibrido(vector<T>& vettore, int inizio, int fine){
    if(inizio < fine){
        if(fine - inizio + 1 <= SOGLIA){
            insertionsort_porzione(vettore, inizio, fine);
            return;
        }
        int pivot = partition(vettore, inizio, fine);
        quicksort_ibrido(vettore, inizio, pivot -1);
        quicksort_ibrido(vettore, pivot +1, fine);
    }
}
