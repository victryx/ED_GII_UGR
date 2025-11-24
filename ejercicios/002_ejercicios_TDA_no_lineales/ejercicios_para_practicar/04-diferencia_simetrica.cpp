/**
 * @file 04-diferencia_simetrica.cpp
 *
 *
 */

#include <list>
#include <set>
#include <iostream>

using namespace std;

int solo_en_uno(const list<set<int>>& l, int x) {
    int count = 0;
    for (set<int> s : l) {
        if (s.count(x) && ++count == 2) {
            return false;
        }
    }
    return count == 1;
}

void diff_sym(const list<set<int>>& l, set<int>& s) {
    set<int> vistos; // Elementos ya comprobados

    for (auto it_list = l.cbegin(); it_list != l.cend(); ++it_list) {
        for (auto it_set = it_list->cbegin(); it_set != it_list->cend(); ++it_set) {
            if (!vistos.count(*it_set)) {
                if (solo_en_uno(l, *it_set)) {
                    s.insert(*it_set);
                }
                vistos.insert(*it_set);
            }
        }
    }
}

// Función para imprimir un set
void imprimir_set(const set<int>& s) {
    for (const auto& elem : s) {
        cout << elem << " ";
    }
    cout << endl;
}
int main() {
    // Ejemplo de uso
    list<set<int>> l = {
        { 1, 2, 5 },
        { 2, 3, 6 },
        { 4, 6, 9 } 
    };
    set<int> resultado;
    diff_sym(l, resultado);
    cout << "Diferencia simétrica: ";
    imprimir_set(resultado);
    return 0;
}