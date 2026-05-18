#pragma once
#include "unidirected_graph.hpp"

template<typename Policy, typename T>
unidirected_graph<T> graph_visit(const unidirected_graph<T>& grafo, const T& nodo, Policy& policy){
    unidirected_graph<T> risultato;
    std::set<T> reached; //creo un set per mappare i nodi già visitati
    policy.put(nodo);
    reached.insert(nodo);
    while(!policy.empty()){
        T nodo2 = policy.get();
        for (const auto& v : grafo.neighbours(nodo2)){
            if(reached.contains(v)) continue;
            reached.insert(v);
            risultato.add_edge(nodo2,v);
            policy.put(v);
        }
    }
    return risultato;
}

template<typename T>
void dfs_visit(const unidirected_graph<T>& grafo, const T& nodo, std::set<T>& reached, unidirected_graph<T>& risultato){
    for (const auto& v : grafo.neighbours(nodo)){
        if(reached.contains(v)) continue;
        reached.insert(v);
        risultato.add_edge(nodo,v);
        dfs_visit(grafo,v,reached,risultato);
    }
}

template<typename T>
unidirected_graph<T> recursive_dfs(const unidirected_graph<T>& grafo, const T& nodo){
    unidirected_graph<T> risultato;
    std::set<T> reached;
    reached.insert(nodo);
    dfs_visit(grafo, nodo, reached, risultato);
    return risultato;
}