#include <cstdlib>
#include <iostream>
#include <sstream>
#include "unidirected_edge.hpp"

int main() {
    // Test 1: il costruttore ordina sempre from() <= to()
    unidirected_edge<int> edge1(10, 3);
    unidirected_edge<int> edge2(3, 10);
    if (edge1.from() != 3 || edge1.to() != 10) return EXIT_FAILURE;
    if (edge2.from() != 3 || edge2.to() != 10) return EXIT_FAILURE;

    // Test 2: operator== — archi uguali indipendentemente dall'ordine dei nodi
    unidirected_edge<int> ab(4, 7);
    unidirected_edge<int> ba(7, 4);
    unidirected_edge<int> ac(4, 9);
    if (!(ab == ba)) return EXIT_FAILURE;  // stessi nodi → uguali
    if (ab == ac)   return EXIT_FAILURE;   // nodi diversi → non uguali

    // Test 3: operator< — ordinamento su (from, to)
    unidirected_edge<int> e1(2, 6);
    unidirected_edge<int> e2(2, 8);
    unidirected_edge<int> e3(5, 8);
    if (!(e1 < e2)) return EXIT_FAILURE;  // stesso from, to minore
    if (!(e2 < e3)) return EXIT_FAILURE;  // from minore
    if (e3 < e1)    return EXIT_FAILURE;  // e3 > e1, non deve essere minore

    // Test 4: operator<< — formato "(from,to)"
    unidirected_edge<int> stamp(9, 2);
    std::ostringstream oss;
    oss << stamp;
    if (oss.str() != "(2,9)") return EXIT_FAILURE;

    return EXIT_SUCCESS;
}
