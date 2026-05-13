#pragma once
#include <iostream>
#include <set>
#include <vector>
#include "unidirected_edge.hpp"

template<typename T>
class undirected_graph{
    //I nodi sono unici
    std::set<T> nodes;
    
    //Definisco gli edges
    std::vector<unidirected_edge<T>> edges;

    public:
    //Costruttori:
    undirected_graph() = default; //di default
    undirected_graph(const undirected_graph& other) = default; //di copia

    //Definisco i vicini, ipotizzando che possano esistere degli archi da
    //un nodo in se stesso, e in questo caso il nodo è vicino di se stesso
    std::vector<T> neighbours(const T& vertice) const{
        std::vector<T> result;
        for(const auto& edge : edges) {
            if (edge.from() == vertice) {
                result.emplace_back(edge.to());
            }
            else if (edge.to() == vertice) {
                result.emplace_back(edge.from());
            }
        }
        
        return result;
    }

    //Metodo per aggiungere gli archi, per prima cosa aggiungo i nodi
    //che se non presenti nel set vengono aggiunti, altrimenti
    //non vengono duplicati. Non prevedo di aggiungere nodi senza
    //collegare almeno un arco
    void add_edge(const T& nodo1, const T& nodo2) {
        nodes.insert(nodo1);
        nodes.insert(nodo2);
        edges.emplace_back(unidirected_edge<T>(nodo1, nodo2));
        }

    std::vector<unidirected_edge<T>> all_edges() const {
        return edges;
    }

    std::set<T> all_nodes() const {
        return nodes;
    }

    //Come number di un arco uso la posizione nel vettore. Se quell'arco
    //non dovesse esserci allora restituisco la size del vettore
    size_t edge_number(const unidirected_edge<T>& edge) const{
        for(size_t i = 0; i < edges.size(); i++){
            if(edges[i]== edge) return i;
        }
        return edges.size();
    }

    unidirected_edge<T> edge_at(size_t number) const {
        return edges.at(number); //Se il numero è fuori range mi dà eccezione
    }

    std::vector<unidirected_edge<T>> operator-(const undirected_graph& other) const {
        std::vector<unidirected_edge<T>> result;
        for (const auto& edge : edges) {
            if (other.edge_number(edge) == other.edges.size()) { //Prendo tutti gli archi del grafo 1 e 
                result.emplace_back(edge);                       //controllo qual è il loro indice nel grafo
            }                                                    //2, se ottengo la size allora non ci sono
        }
        return result;
    }
};