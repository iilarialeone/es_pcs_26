#pragma once
#include <list>
template<typename T>
class Queue{
    std::list<T> elementi;

    public:
    //costruttore di default
    Queue() = default; //cioè genero una funzione con comportamento standard

    //costruttore di copia
    Queue(const Queue& other) = default;

    //metodi:
    void put(const T& nuovo){
        elementi.push_back(nuovo);
    }

    T get(){
        T primo = elementi.front();
        elementi.pop_front();
        return primo;
    }

    bool empty(){
        return elementi.empty();
    }
};