/**
 * @file 02-subconjunto_propio.cpp
 * 
 * Implementar una función
 * 
 * bool subconjunto_propio(vector<set<int>> &l)
 * 
 * Que devuelve true si los conjuntos del vector l son subconjuntos
 * propios de forma consecutiva:
 * l[0] contenido en l[1]
 * l[1] contenido en l[2]
 * l[2] contenido en l[3]
 * ...
 * 
 * Ejemplo
 * l = {{ 1, 2, 3}; {1,2,3,4}; {1,2,3,4,6}} => TRUE
 * 
 * l = {{ 1, 2, 3}; {1,2,3,4}; {1,3,4,6}}   => FALSE
 * 
 */

#include <vector>
#include <set>
#include <iostream>

using namespace std;


/**
 * Mi solución
 */
bool subconjunto_propio(const vector<set<int>>& l) {
    for (size_t i = 0; i < l.size() - 1; i++) {
        for (auto it = l[i].begin(); it != l[i].end(); ++it) {
            if (!l[i + 1].count(*it)) {
                return false;
            }
        }
    }
    return true;
}

/**
 * Solución del pdf
 * (Funciona exáctamente igual)
 */
bool incluido_en(const set<int>& A, const set<int>& B) {
    if (A.size() >= B.size()) return false;
    for (auto x : A)
        if (B.find(x) == B.end())
            return false;
    return true;
}
bool subconjunto_propio(vector< set<int> >& VS) {
    for (int i = 0;i < VS.size() - 1;i++)
        if (!incluido_en(VS[i], VS[i + 1]))
            return false;
    return true;
}

int main() {

    // Ejemplo 1: Lista de conjuntos que cumple con la propiedad de
    //subconjuntos propios consecutivos
    vector<set<int>> L1 = {
    {1, 2, 3},
    {1, 2, 3, 4},
    {1, 2, 3, 4, 6}
    };
    // Ejemplo 2: Lista de conjuntos que NO cumple con la propiedad
    vector<set<int>> L2 = {
    {1, 2, 3},
    {1, 2, 3, 4},
    {1, 3, 4, 6}
    };

    // Comprobamos el primer ejemplo
    if (subconjunto_propio(L1)) {
        cout << "L1 es un conjunto de subconjuntos propios consecutivos." << endl;
    } else {
        cout << "L1 NO es un conjunto de subconjuntos propios consecutivos." << endl;
    }

    // Comprobamos el segundo ejemplo
    if (subconjunto_propio(L2)) {
        cout << "L2 es un conjunto de subconjuntos propios consecutivos." << endl;
    } else {
        cout << "L2 NO es un conjunto de subconjuntos propios consecutivos." << endl;
    }
    return 0;
}