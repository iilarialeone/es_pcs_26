#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
#include "unidirected_graph.hpp"

int main() {
    // Test 1: nodi unici e archi (incluso duplicato)
    unidirected_graph<int> g1;
    g1.add_edge(5, 6);
    g1.add_edge(6, 7);
    g1.add_edge(7, 5);
    g1.add_edge(5, 6); // duplicato — deve essere inserito (no dedup sugli archi)
    if (g1.all_nodes().size() != 3) return EXIT_FAILURE;
    if (g1.all_edges().size() != 4) return EXIT_FAILURE;

    // Test 2: neighbours
    unidirected_graph<int> g2;
    g2.add_edge(10, 20);
    g2.add_edge(10, 30);
    g2.add_edge(10, 40);
    g2.add_edge(20, 30);
    if (g2.neighbours(10).size() != 3)  return EXIT_FAILURE;
    auto n40 = g2.neighbours(40);
    if (n40.size() != 1 || n40.front() != 10) return EXIT_FAILURE;
    if (!g2.neighbours(99).empty())     return EXIT_FAILURE;

    // Test 3: edge_number e edge_at
    unidirected_graph<int> g3;
    g3.add_edge(2, 4);
    g3.add_edge(6, 8);
    g3.add_edge(1, 9);
    if (g3.edge_number(unidirected_edge<int>(2, 4)) != 0) return EXIT_FAILURE;
    if (g3.edge_number(unidirected_edge<int>(6, 8)) != 1) return EXIT_FAILURE;
    if (g3.edge_number(unidirected_edge<int>(1, 9)) != 2) return EXIT_FAILURE;
    if (!(g3.edge_at(0) == unidirected_edge<int>(2, 4)))  return EXIT_FAILURE;
    if (!(g3.edge_at(2) == unidirected_edge<int>(1, 9)))  return EXIT_FAILURE;
    // arco assente → restituisce size()
    if (g3.edge_number(unidirected_edge<int>(3, 7)) != g3.all_edges().size()) return EXIT_FAILURE;

    // Test 4: operator- (differenza di archi)
    unidirected_graph<int> ga, gb;
    ga.add_edge(1, 2);
    ga.add_edge(3, 4);
    ga.add_edge(5, 6);
    gb.add_edge(3, 4);
    gb.add_edge(7, 8);
    auto diff = ga - gb; // archi in ga ma non in gb
    if (diff.size() != 2) return EXIT_FAILURE;
    auto has = [&](int x, int y) {
        unidirected_edge<int> target(x, y);
        return std::any_of(diff.begin(), diff.end(),
                           [&](const auto& e){ return e == target; });
    };
    if (!has(1, 2) || !has(5, 6) || has(3, 4)) return EXIT_FAILURE;

    // Test 5: copia indipendente
    unidirected_graph<int> orig;
    orig.add_edge(11, 22);
    unidirected_graph<int> copy(orig);
    copy.add_edge(33, 44);
    if (orig.all_edges().size() != 1) return EXIT_FAILURE;
    if (copy.all_edges().size() != 2) return EXIT_FAILURE;

    // Test 6: grafo su stringhe
    unidirected_graph<std::string> gs;
    gs.add_edge("mario", "luigi");
    gs.add_edge("luigi", "peach");
    if (gs.neighbours("luigi").size() != 2) return EXIT_FAILURE;
    if (gs.all_nodes().size() != 3)         return EXIT_FAILURE;

    return EXIT_SUCCESS;
}
