#pragma once
#include <map>
#include <queue>
#include <vector>
#include <utility>
#include "unidirected_graph.hpp"

template<typename T>
unidirected_graph<T> dijkstra(const unidirected_graph<T>& g, const T& nodo_partenza, const T& nodo_arrivo) {
    unidirected_graph<T> risultato;

    //Uso le mappe dist e pred per tenere traccia delle distanze minime e dei predecessori
    //Un nodo assente in dist => dist è infinito
    std::map<T, double> dist;
    std::map<T, T> pred;

    //La distanza del nodo di partenza da se stesso è 0, e il suo predecessore è se stesso
    dist[nodo_partenza] = 0.0;
    pred[nodo_partenza] = nodo_partenza;

    //Uso una priority queue come min-heap su coppie (distanza, nodo)
    //std::priority_queue è un max-heap di default, quindi uso std::greater per invertirlo
    std::priority_queue<std::pair<double, T>, std::vector<std::pair<double, T>>, std::greater<std::pair<double, T>>> PQ;

    //Inserisco solo il nodo di partenza nella coda
    PQ.push({0.0, nodo_partenza});

    while (!PQ.empty()) {
        //Estraggo il nodo u con costo p: se p > dist[u] allora non aggiorno
        auto [p, u] = PQ.top();
        PQ.pop();
        if (p > dist[u]) continue;

        //Per ogni vicino w di u controllo se posso migliorare la sua distanza
        for (const T& w : g.neighbours(u)) {
            double w_uw = g.weight_of(u, w);
            double nuova_dist = dist[u] + w_uw;

            //Se w non è ancora stato raggiunto oppure troviamo un cammino più corto:
            if (!dist.contains(w) || nuova_dist < dist[w]) {
                dist[w] = nuova_dist;
                pred[w] = u;

                //Reinserisco w nella coda con la nuova distanza
                PQ.push({dist[w], w});
            }
        }
    }

    //Ricostruisco il cammino minimo risalendo i predecessori dal nodo di arrivo
    if (!pred.contains(nodo_arrivo)) return risultato;

    //Se nodo_partenza == nodo_arrivo il while non esegue e risultato è un grafo vuoto
    T attuale = nodo_arrivo;
    while (attuale != nodo_partenza) {
        T p = pred.at(attuale);
        risultato.add_edge(p, attuale, g.weight_of(p, attuale));
        attuale = p;
    }

    return risultato;
}