#include <iostream>
#include <algorithm>
#include <cmath>

double minimo(double *a, int n) { //Creo la funzione con parametri: il puntatore relativo all'array e la dimensione
    double m = a[0];              //m è il "minimo relativo"
    for(int i=1; i<n; i++){       //confronto m con tutti gli elementi dell'array
        m = std::min(m, a[i]);
    }
    return m;                     //Restituisco m dopo averlo confrontato con tutto
}

double massimo(double *a, int n) { //È lo stesso ragionamento del minimo ma con il massimo
    double M = a[0];
    for(int i=1; i<n; i++){
        M = std::max(M, a[i]);
    }
    return M;
}

double media(double *a, int n) { //Creo la funzione media inserendo come parametri: il puntatore riferito all'array e la dimensione
    double s = 0;                //Definisco s che sarà la somma
    for(int i=0; i<n; i++){      //Creo un for per sommare tutti i termini
        s += a[i];
    }
    return s/n;                  //Restituisco la somma finale diviso il numero di elementi che ho sommato
}

double dev_s(double *a, int n) { //Creo la funzione per calcolare la deviazione standard con parametri il puntatore riferito all'array e la dimensione
    double somma = 0;            //Definisco un double dove sommerò tutti gli elementi
    double m = media(a, n);      //Calcolo la media dell'array
    for(int i=0; i<n; i++){      //Creo poi un for che sommi tutti i quadrati delle differenze tra elemento e media
        double quadrato = std::pow(a[i]-m, 2); 
        somma += quadrato;
    }
    double d= std::sqrt(somma/n); //Faccio la radice della somma, divisa per il numero di elementi che ho sommato

    return d;                    //Restituisco il valore
}


// Esercizio 2.1 - Bubblesort
void ordine(double *a, int n){   //Definisco la funzione per il bubblesort e i parametri sono il puntatore relativo all'array e la dimensione
    bool scambiato = true;       //Definisco un bool per capire quando iterare e quando no e lo imposto a true per entrare nel while
    while(scambiato){
        scambiato = false;      //Imposto il bool a false in modo da non rientrare più nel while se non faccio scambi
        for(int i=1; i< n; i++){ //Faccio un if per scambiare quando necessario
            if(a[i-1]>a[i]){
                double t = a[i];
                a[i] = a[i-1];
                a[i-1]= t;
                scambiato = true; //Reimposto il bool a true perchè se faccio scambi devo fare un'altra iterazione
            }
        }
    }
    
}
// 


int main() {
    static const int N=7;
    double arr[N]={2.3, 11.6, 5.0, 7.1, 2.5, 9.9, 5.6};
     
    std::cout << "Il minimo è " << minimo(arr, N) << "\n";
    std::cout << "Il massimo è " << massimo(arr, N) << "\n";
    std::cout << "La media è " << media(arr, N) << "\n";
    std::cout << "La deviazione standard è " << dev_s(arr, N) << "\n";
    std::cout << "L'array ordinato è ";
    ordine(arr, N);
    for(int i=0; i<N; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    return 0;
}    

