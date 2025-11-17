/**
 * @file 04-corta_map.cpp
 * 
 * Implementa una función
 * void corta_map(map<int, list<int>>& m, int p, int q)
 * Que:
 * 
 * 1. Elimina entradas del mapa con clave no incluida en el rango [p, q)
 * 2. Elimina elementos del valor del mapa (list<int>) que no estén en el rango [p,q)
 * 3. Elimina entradas del mapa cuyo valor no contenga elementos (lista vacía)
 * 
 * No se permite el uso de contenedores auxiliares
 * 
 * EJEMPLO:
 * ENTRADA
 * m = {1 -> (2, 3, 4), 
 *      5 -> (6, 7, 8),
 *      8 -> (4, 5),
 *      3 -> (1, 3, 7)},
 * p = 1
 * q = 6
 * 
 * SALIDA
 * m = {1 -> (2, 3, 4)
 *      3 -> (1, 3)}
 */

#include<map>
#include<list>
#include<iostream>


using namespace std;

void corta_map(map<int, list<int>>& m, int p, int q) {
    auto it_map = m.begin();
    // Elimina pares con clave incorrecta
    while (it_map != m.end()) {
        if (it_map->first < p || it_map->first >= q) {
            it_map = m.erase(it_map);
        } else {
            ++it_map;
        }
    }

    // Elimina pares con valor incorrecto
    it_map = m.begin();
    while (it_map != m.end()) {
        it_map->second.remove_if([p, q](int val) {
            return val < p || val >= q;
        });

        if (it_map->second.empty()) {
            it_map = m.erase(it_map);
        } else {
            ++it_map;
        }
    }
}


int main() {
    // Creamos un mapa con claves y listas asociadas
    map<int, list<int>> M = {
        {1, {2, 3, 4}},
        {5, {6, 7, 8}},
        {8, {4, 5}},
        {3, {1, 3, 7}}
    };// Imprimimos el mapa original
    cout << "Mapa original:" << endl;
    for (const auto& entry : M) {
        cout << entry.first << " -> (";
        for (const int& val : entry.second) {
            cout << val << " ";
        }
        cout << ")" << endl;
    }
    // Llamamos a la función corta_map con el rango [1, 6)
    corta_map(M, 1, 6);
    // Imprimimos el mapa modificado
    cout << "\nMapa despues de corta_map(1, 6):" << endl;
    for (const auto& entry : M) {
        cout << entry.first << " -> (";
        for (const int& val : entry.second) {
            cout << val << " ";
        }
        cout << ")" << endl;
    }
    return 0;
}

