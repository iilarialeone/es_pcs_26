#include <iostream>

int main(int argc, const char *argv[])
{
    int parametri = argc - 1;
    std::cout << "Numero di parametri: " << parametri << "\n";
    for (int i=0; i < parametri; i++) {
        std::cout << "Parametro " << i << " = " << argv[i+1] << "\n";
    }
    return 0;    
}