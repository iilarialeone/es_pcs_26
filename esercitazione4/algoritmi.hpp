#pragma once
#include <vector>

//1. Bubble-sort
template <typename T>
void bubblesort(std::vector<T>& vettore){
    for(int i=0; i< static_cast<int>(vettore.size()); i++){               //vettore.size() chiama il metodo
        for(int j = static_cast<int>(vettore.size())-1; j > i; j--){
            if(vettore[j] < vettore[j-1]){
                T temporary = vettore[j];
                vettore[j] = vettore[j-1];
                vettore[j-1] = temporary;
            }
        }
    }

}

//2. Insertion-sort
template <typename T>
void insertionsort(std::vector<T>& vettore){
    for(int j = 1; j < static_cast<int>(vettore.size()); j++){
        T key = vettore[j];
        int i = j-1;
        while(i >= 0 && vettore[i] > key){
            vettore[i+1] = vettore[i];
            i = i-1;
        }
    vettore[i+1] = key;
    }

}

//3. Selection-sort
template <typename T>
void selectionsort(std::vector<T>& vettore){
    for(int i = 0; i < static_cast<int>(vettore.size()); i++){
        int min = i;
        for(int j = i+1; j < static_cast<int>(vettore.size()); j++){
            if(vettore[j] < vettore[min]){
                min = j;
            }
        }
        T temporary = vettore[i];
        vettore[i] = vettore[min];
        vettore[min] = temporary;
    }
    
}