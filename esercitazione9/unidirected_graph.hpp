#pragma once
#include <iostream>
#include <set>
#include <vector>
#include <limits>
#include "unidirected_edge.hpp"

template<typename T>
class unidirected_graph{
    //I nodi sono unici
    std::set<T> nodes;
    
    //Definisco gli edges
    std::vector<unidirected_edge<T>> edges;

    public:
    //Costruttori:
    unidirected_graph() = default; //di default
    unidirected_graph(const unidirected_graph& other) = default; //di copia

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
    void add_edge(const T& nodo1, const T& nodo2, double peso = 1.0) {
        nodes.insert(nodo1);
        nodes.insert(nodo2);
        edges.emplace_back(unidirected_edge<T>(nodo1, nodo2, peso));
        }

    std::vector<unidirected_edge<T>> all_edges() const {
        return edges;
    }

    // Restituisce il peso dell'arco tra nodo1 e nodo2 (+∞ se non esiste)
    double weight_of(const T& nodo1, const T& nodo2) const {
        for (const auto& e : edges) {
            if ((e.from() == nodo1 && e.to() == nodo2) ||
                (e.from() == nodo2 && e.to() == nodo1))
                return e.get_weight();
        }
        return std::numeric_limits<double>::infinity();
    }

    std::set<T> all_nodes() const {
        return nodes;
    }

    //Serializzo il grafo in formato DOT (GraphViz)
    void to_dot(std::ostream& os, const std::string& nome = "G") const {
        os << "graph " << nome << " {\n";
        // nodi isolati (nel caso non abbiano archi)
        for (const auto& v : nodes)
            os << "  " << v << ";\n";
        // archi
        for (const auto& e : all_edges())
            os << "  " << e.from() << " -- " << e.to() << ";\n";
        os << "}\n";
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

    std::vector<unidirected_edge<T>> operator-(const unidirected_graph& other) const {
        std::vector<unidirected_edge<T>> result;
        for (const auto& edge : edges) {
            if (other.edge_number(edge) == other.edges.size()) { //Prendo tutti gli archi del grafo 1 e 
                result.emplace_back(edge);                       //controllo qual è il loro indice nel grafo
            }                                                    //2, se ottengo la size allora non ci sono
        }
        return result;
    }
};