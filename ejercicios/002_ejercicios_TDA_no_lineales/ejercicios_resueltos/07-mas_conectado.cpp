/**
 * @file 07-mas_conectado.cpp
 */

#include <set>
#include <vector>
#include <iostream>

using namespace std;

bool conectados(const set<int>& s1, const set<int>& s2) {
    for (int num : s1) {
        if (s2.count(num)) { // Existe intersección no vacía
            return true;
        }
    }
    return false;
}

int mas_conectado(vector<set<int>>& vs) {
    vector<int> conexiones(vs.size(), 0);
    for (int i = 0; i < vs.size() - 1; ++i) {
        for (int j = i + 1; j < vs.size(); ++j) {
            if (conectados(vs[i], vs[j])) {
                conexiones[i]++;
                conexiones[j]++;
            }
        }
    }

    int indice_mas_conectado = 0;
    for (int i = 1; i < conexiones.size(); i++) {
        if (conexiones[i] > conexiones[indice_mas_conectado]) {
            indice_mas_conectado = i;
        }
    }
    return indice_mas_conectado;

}

int main() {
    // Ejemplo 1: El conjunto 3 ({0,1,2}) está conectado con 3 conjuntos
    vector<set<int>> VS1 = {
        {0},
        {1},
        {2},
        {0, 1, 2}
    };
    cout << "Índice del conjunto más conectado en VS1: " << mas_conectado(VS1) << endl;

    // Ejemplo 2: El conjunto 0 ({0, 1, 2}) está conectado con 3 conjuntos
    vector<set<int>> VS2 = {
        {0, 1, 2},
        {0},
        {1},
        {2}
    };
    cout << "Índice del conjunto más conectado en VS2: " << mas_conectado(VS2) << endl;

    // Ejemplo 3: El conjunto 1 ({5, 6, 9}) está conectado con 4 conjuntos
    vector<set<int>> VS3 = {
        {0, 6, 9},
        {5, 6, 9},
        {5},
        {1},
        {5, 9},
        {5},
        {1, 5, 7}
    };
    cout << "Índice del conjunto más conectado en VS3: " << mas_conectado(VS3) << endl;
    return 0;
}