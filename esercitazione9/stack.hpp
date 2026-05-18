#pragma once
#include <list>
template<typename T>
class Stack{
    std::list<T> elementi;

    public:
    //costruttore di default
    Stack() = default; //cioè genero una funzione con comportamento standard

    //costruttore di copia
    Stack(const Stack& other) = default;

    //metodi:
    void put(const T& nuovo){
        elementi.push_back(nuovo);
    }

    T get(){
        T ultimo = elementi.back();
        elementi.pop_back();
        return ultimo;
    }

    bool empty(){
        return elementi.empty();
    }
};