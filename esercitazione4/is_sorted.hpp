#pragma once
#include <vector>

template <typename T>
bool is_sorted(std::vector<T>& vettore){
    for(int i = 0; i < static_cast<int>(vettore.size())-1; i++){
        if(vettore[i] > vettore[i+1]){
            return false;
        }
    }

    return true;
} //Se il vettore ha lunghezza 0 non entro nel for e restituisco true di default. Considero un
//vettore di lunghezza 0 sempre ordinato.