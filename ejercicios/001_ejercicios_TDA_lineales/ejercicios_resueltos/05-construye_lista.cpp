/**
 * Implementar una función que construya a partir de la lista de entrada L,
 * una lista ordenada de listas, de forma que en la lista resultante los
 * elementos que sean iguales se agrupen en la misma sublista
 * 
 * Ejemplo
 * L = {1, 3, 4, 5, 6, 3, 2, 1, 4, 5, 5, 1, 1, 7}
 * salida = { {1, 1, 1, 1}, {2}, {3, 3}, {4, 4}, {5, 5, 5}, {6}, {7} }
 */

#include <list>
#include <map>
#include <iostream>
#include <algorithm>


using namespace std;

// Solución sin ordenar (usando map)
list<list<int>> construye_lista(list<int> &l) {
    map<int, list<int>> result_map;
    list<list<int>> output;

    for(int i : l) {
        result_map[i].push_back(i);
    }

    for(pair<const int, list<int>> ls : result_map) {
        output.push_back(ls.second);
    }

    return output;
}

// si no queremos usar un map, podemos ordenar la lista
list<list<int>> construye_lista2(list<int> &l) { 
    l.sort();

    list<list<int>> output;
    list<int>::iterator next = l.begin();
    list<int>::iterator prev = next;

    output.push_back({ });
    next++;
    
    while (prev != l.end()) {
        output.back().push_back(*prev);
        if (next != l.end() && *prev != *next) {
            output.push_back({ });
        }
        prev++;
        next++;
    }

    return output;
}


int main() {
    list<int> l = {1, 3, 4, 5, 6, 3, 2, 1, 4, 5, 5, 1, 1, 7};
    list<list<int>> groups = construye_lista(l);

    for(list<int> ls : groups) {
        for(int i : ls) {
            cout << " " << i;
        }
        cout << "\n";
    }

    return 0;
}