#pragma once
#include <vector>
using namespace std;

//0. Merge
template <typename T>
void merge(vector<T>& vettore, int inizio, int centro, int fine){
    int dimensione1 = centro - inizio + 1;
    int dimensione2 = fine - centro;
    vector<T> L(dimensione1);
    for(int i=0; i < dimensione1; i++){
        L[i] = vettore[inizio +i];
    }
    vector<T> R(dimensione2);
    for(int j=0; j < dimensione2; j++){
        R[j] = vettore[centro + j + 1];
    }
    //Controllo che i due indici non sforino la dimensione tramite un while
    int i = 0;
    int j = 0;
    int k = inizio;
    while(i < dimensione1 && j < dimensione2){
        if(L[i]<=R[j]){
            vettore[k]=L[i];
            i++;
        }
        else{
            vettore[k] = R[j];
            j++;
        }
        k++;
    }

    //Se sono arrivata alla fine di uno dei due vettori, finisco di inserire il rimanente
    while(i < dimensione1){
        vettore[k]=L[i];
        i++;
        k++;
    }
    while(j < dimensione2){
        vettore[k]=R[j];
        j++;
        k++;
    }
}

//1. MergeSort
template <typename T>
void mergesort(vector<T>& vettore, int inizio, int fine){
    if(inizio < fine){
        int centro = (inizio + fine)/2;
        mergesort(vettore, inizio, centro);
        mergesort(vettore, centro + 1, fine);
        merge(vettore, inizio, centro, fine);
    }
}

//00. Partition
template <typename T>
int partition(vector<T>& vettore, int inizio, int fine){
    T x = vettore[fine];
    int i= inizio -1;
    for(int j= inizio; j < fine; j++){
        if(vettore[j]<= x){
            //Se
            i++;
            T temporanea = vettore[i];
            vettore[i] = vettore[j];
            vettore[j] = temporanea;
        }
    }
    T temporanea = vettore[i+1];
    vettore[i+1] = vettore[fine];
    vettore[fine] = temporanea;
    return i+1;
}

//2. QuickSort
template <typename T>
void quicksort(vector<T>& vettore, int inizio, int fine){
    if(inizio < fine){
        int pivot = partition(vettore, inizio, fine);
        quicksort(vettore, inizio, pivot -1);
        quicksort(vettore, pivot +1, fine);
    }
}

//3. BubbleSort
template <typename T>
void bubblesort(vector<T>& vettore){
    int n = vettore.size();
    for(int i = 0; i < n; i++){
        for(int j = n-1; j > i; j--){
            if(vettore[j] < vettore[j-1]){
                T temporanea = vettore[j];
                vettore[j] = vettore[j-1];
                vettore[j-1] = temporanea;
            }
        }
    }
}

//4. SelectionSort
template <typename T>
void selectionsort(vector<T>& vettore){
    int n = vettore.size();
    for(int i = 0; i < n; i++){
        int minimo = i;
        for(int j = i+1; j < n; j++){
            if(vettore[j] < vettore[minimo]){
                minimo = j;
            }
        }
        T temporanea = vettore[i];
        vettore[i] = vettore[minimo];
        vettore[minimo] = temporanea;
    }
}

//5. InsertionSort
template <typename T>
void insertionsort(vector<T>& vettore){
    int n = vettore.size();
    for(int j = 1; j < n; j++){
        T chiave = vettore[j];
        int i = j-1;
        while(i >= 0 && vettore[i] > chiave){
            vettore[i+1] = vettore[i];
            i--;
        }
        vettore[i+1] = chiave;
    }
}

//6. InsertionSort su una porzione del vettore (usato dal quicksort ibrido)
template <typename T>
void insertionsort_porzione(vector<T>& vettore, int inizio, int fine){
    for(int j = inizio + 1; j <= fine; j++){
        T chiave = vettore[j];
        int i = j-1;
        while(i >= inizio && vettore[i] > chiave){
            vettore[i+1] = vettore[i];
            i--;
        }
        vettore[i+1] = chiave;
    }
}