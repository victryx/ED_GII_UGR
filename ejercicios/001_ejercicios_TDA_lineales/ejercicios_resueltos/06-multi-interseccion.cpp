/**
 * Implementar función que dadas 2 listas con elementos repetidos y ordenadas
 * calcule su multiintersección y la devuelva en otra lista.
 * 
 * La multiintersección se construye con los elementos que están en ambas listas 
 * repetidos tantas veces como estén repetidos en la lista en que menos se repiten
 */

#include <list>
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Solución propia
 */
list<int> multi_interseccion(list<int> l1, list <int> l2) {
    list<int> output;
    auto it1 = l1.begin();
    auto it2 = l2.begin();

    while (it1 != l1.end() && it2 != l2.end()) {
        while(*it1 < *it2 && it1 != l1.end()) {
            it1++;
        }
        while(*it2 < *it1 && it2 != l2.end()) {
            it2++;
        }

        while(*it1 == *it2 && it1 != l1.end() && it2 != l2.end()) {
            output.push_back(*it1);
            ++it1;
            ++it2;
        }
    }

    return output;
}

/**
 * Solución del pdf
 */
list<int> multi_interseccion2(list<int> l1, list <int> l2) {
    list<int> output;
    auto it1 = l1.begin();
    auto it2 = l2.begin();

    while (it1 != l1.end() && it2 != l2.end()) {
        if (*it1 < *it2) ++it1;
        if (*it2 < *it1) ++it2;

        if (*it1 == *it2) {
            output.push_back(*it1);
            ++it1;
            ++it2;
        }
    }

    return output;
}

/**
 * Variante del ejercicio: 
 * 
 * Implementar función que dadas 2 listas con elementos repetidos y ordenadas
 * calcule su multiintersección y la devuelva en otra lista.
 * 
 * La multiintersección se construye con los elementos que están en ambas listas 
 * repetidos tantas veces como estén repetidos en la lista en que MÁS se repiten
 * 
 * NOTA: esta solución falla en algunos casos. No es válida.
 */
list<int> multi_interseccion_grande(list<int> l1, list<int> l2) {
    list<int> output;
    auto it1 = l1.begin();
    auto it2 = l2.begin();

    while (it1 != l1.end() && it2 != l2.end()) {
        while(*it1 < *it2 && it1 != l1.end()) {
            it1++;
        }
        while(*it2 < *it1 && it2 != l2.end()) {
            it2++;
        }

        if (it1 != l1.end() && it2 != l2.end()) {
            int val = *it1;
            auto lastl1 = it1;
            auto lastl2 = it2;

            while (*lastl1 == *it1) lastl1++;
            while (*lastl2 == *it2) lastl2++;

            int dist1 = distance(it1, lastl1);
            int dist2 = distance(it2, lastl2);

            int occurrences = dist1 > dist2 ? dist1 : dist2;

            output.insert(output.end(), occurrences, val);

            it1 = lastl1;
            it2 = lastl2;
        }
    }
    return output;
}

int main() {
    list<int> l1 = {2, 2, 3, 3, 4, 4, 4, 4, 9, 10, 12, 14, 16, 22};
    list<int> l2 = {1, 2, 3, 3, 3, 4, 4, 11, 14};

    list<int> multi_inter = multi_interseccion_grande(l1, l2);

    for (int i : multi_inter) {
        cout << " " << i;
    }
    cout << endl;

    return 0;
}