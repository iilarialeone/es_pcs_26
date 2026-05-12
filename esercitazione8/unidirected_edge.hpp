#pragma once
#include <iostream>

template<typename T>
class unidirected_edge{
    T source;
    T destination;

    public:

    //Costruttore:
    unidirected_edge() : source(T()), destination(T()) {}
    
    //Costruttore con parametri:
    unidirected_edge(T s, T d) : source(s<d? s : d), destination(s<d? d : s) {}

    //Metodi getter: (uso const T& così che quando li chiamo il dato venga letto ma non duplicato)
    const T& from() const {
        return source;
    }

    const T& to() const {
        return destination;
    }

    //Metodi per l'operational overload:
    bool operator<(const unidirected_edge<T>& other) const{
        if(source < other.source){
            return true;
        }
        else if(source == other.source && destination < other.destination){
            return true;
        }
        else return false;
    }

    bool operator==(const unidirected_edge<T>& other) const{
        return source == other.source && destination == other.destination;
    }

    friend std::ostream& operator << (std::ostream& stream, const unidirected_edge<T>& other) {
        return stream << "(" << other.source << "," << other.destination << ")";
    }

};