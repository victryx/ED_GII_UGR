/**
 * @file 03-conjunto_potencia.cpp
 *
 * El conjunto potencia es el conjunto que contiene a todos
 * los subconjuntos de
 */

#include <set>
#include <iostream>

using namespace std;

/**
 * Mi solución
 *
 * Es mucho más corta pero menos eficiente
 */
void conjunto_potencia_iter(const set <int>& a, set<set<int>>& output) {
    output.insert(a);
    for (auto it = a.begin(); it != a.end(); ++it) {
        set<int> new_set(a);
        new_set.erase(new_set.find(*it));
        conjunto_potencia_iter(new_set, output);
    }
}

set<set<int>> conjunto_potencia(const set <int>& a) {
    set<set<int>> output;
    conjunto_potencia_iter(a, output);
    return output;
}

/**
 * Solución del pdf
 */
set<set<int>> conjunto_potencia_pdf(const set<int>& A) {
    set<set<int>> potencia = { { } }; // Inicialmente contiene el conjunto vacío

    for (set<int>::iterator it = A.begin(); it != A.end(); ++it) {
        int elem = *it; 

        set<set<int>> nuevos;
        // Recorrer los subconjuntos de potencia utilizando un iterador
        for (set<set<int>>::iterator sub_it = potencia.begin(); sub_it != potencia.end(); ++sub_it) {
            set<int> nuevo_sub = *sub_it; // Obtener el subconjunto actual
            nuevo_sub.insert(elem); // Insertar el nuevo elemento
            nuevos.insert(nuevo_sub); // Insertar el subconjunto modificado en 'nuevos'
        }
        // Insertar todos los nuevos subconjuntos generados en potencia
        for (set<set<int>>::iterator new_it = nuevos.begin(); new_it != nuevos.end(); ++new_it) {
            potencia.insert(*new_it);
        }
    }
    return potencia;
}



void imprimir_conjunto_potencia(const set<set<int>>& conjuntoPotencia) {
    cout << "{ ";
    for (set<set<int>>::iterator it = conjuntoPotencia.begin(); it !=
        conjuntoPotencia.end(); ++it) {
        cout << "{ ";
        for (set<int>::iterator sub_it = it->begin(); sub_it != it->end(); ++sub_it) {
            cout << *sub_it << " ";
        }
        cout << "} ";
    }
    cout << "}" << endl;
}

int main() {
    set<int> A = { 1, 2, 3 };
    // Obtenemos el conjunto potencia
    set<set<int>> potencia = conjunto_potencia(A);
    // Imprimimos el conjunto potencia
    imprimir_conjunto_potencia(potencia);
    return 0;
}