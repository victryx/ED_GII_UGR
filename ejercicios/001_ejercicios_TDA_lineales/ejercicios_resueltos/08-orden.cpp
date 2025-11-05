/**
 * Función que dada una lista l devuelve:
 * 1 => si l está ordenada de forma ascendente
 * 2 => si l está ordenada de forma descendente
 * 0 => en otro caso
 */
#include <list>
#include <iostream>

using namespace std;

/**
 * Solución del pdf
 */
int orden_sol(list<int> &l)
{
    if (l.size() <= 1) {
        return 1; // Una lista vacía o con un solo elemento se
    }

    list<int>::iterator it1 = l.begin();
    list<int>::iterator it2 = it1;
    ++it2;

    bool ascendente = true;
    bool descendente = true;
    
    while (it2 != l.end())
    {
        if (*it1 < *it2) {
            descendente = false; 
        } else if (*it1 > *it2) {
            ascendente = false; 
        }
        it1++; // Avanzamos el primer iterador
        it2++; // Avanzamos el segundo iterador
    }
    if (ascendente)
        return 1;
    if (descendente)
        return 2;
    return 0;
}

/**
 * Solución propia
 */
int orden(list<int> &l) {
    bool asc = true;
    bool desc = true;
    auto prev = l.begin();
    auto next = prev;
    ++next;

    while (next != l.end()) {
        asc = asc && *prev < *next;
        desc = desc && *prev > *next;
        if (!asc && !desc) return 0;
        
        ++prev;
        ++next;
    }
    return asc ? 1 : 2;
}

int main() {
    list<int> L1 = {1, 3, 6, 7, 9}; // Lista ascendente
    list<int> L2 = {8, 6, 4, 3, 2}; // Lista descendente
    list<int> L3 = {6, 5, 9, 8, 3}; // Lista desordenada

    // Imprimir los resultados para cada lista
    cout << "L1: " << orden(L1) << endl; // 1 (ascendente)
    cout << "L2: " << orden(L2) << endl; // 2 (descendente)
    cout << "L3: " << orden(L3) << endl; // 0 (no está ordenada)
    return 0;
}