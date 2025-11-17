/**
 * @file 03-contiene_parejas.cpp
 *
 * Implementar una función
 *
 * bool contiene_parejas(vector<set<int>> &sw, int n)
 *
 * Que para cada par de enteros i, j, con (0 <= i < j)  y j < n.
 * Compruebe si (i,j) está contenido en al menos uno de los conjuntos de sw.
 *
 *
 * Nota: Si k = 5, las parejas son:
 * (0; 1)
 * (0; 2)
 * (0; 3)
 * (0; 4)
 * (1; 2)
 * (1; 3)
 * (1; 4)
 * (2; 3)
 * (2; 4)
 * (4; 1)
 *
 * EJEMPLO
 *
 * sw = {{0; 1; 2; 3; 4}, {0; 1; 5; 6; 7}, {2; 3; 4; 5; 6; 7}}
 * contiene_parejas(sw, 8) => true
 *
 * sw = {{0; 2; 3; 4}, {0; 1; 5; 7}, {2; 3; 5; 6; 7}}
 * contiene_parejas(sw, 8) => false
 * (Faltan los pares (0, 6,), (1, 2), (1, 3), ...)
 *
 */

#include <iostream>
#include <vector>
#include <set>

using namespace std;

/**
 * Mi solución
 *
 * Recorre cada par de números (i,j) entre 0 y n. Comprueba
 * si la pareja (i,j) está en alguno de los conjuntos
 */
bool contiene_parejas(vector<set<int>>& sw, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << "Pareja :" << i << " " << j << "\n";

            bool couple_found = false;
            for (int k = 0; k < sw.size() && !couple_found; ++k) {
                couple_found = sw[k].count(i) && sw[k].count(j);
            }

            if (!couple_found) {
                return false;
            }
        }
    }

    return true;
}

/**
 * Solución del pdf
 * Funciona igual
 */
bool contieneparejas(vector< set<int> >& sw, int n) {
    for (int i = 0;i < n - 1;i++)
        for (int j = i + 1;j < n;j++) {
            bool enc = false;
            for (auto it = sw.begin();it != sw.end() && !enc; ++it) {
                if (it->find(i) != it->end() && it->find(j) != it->end())
                    enc = true;
            }
            if (!enc) return false;
        }
    return true;
}

int main() {
    // Ejemplo 1: Los pares están contenidos en los conjuntos
    vector<set<int>> sw1 = {
        {0, 1, 2, 3, 4},
        {0, 1, 5, 6, 7},
        {2, 3, 4, 5, 6, 7}
    };
    // Ejemplo 2: Algunos pares no están contenidos en los
    //conjuntos
    vector<set<int>> sw2 = {
        {0, 2, 3, 4},
        {0, 1, 5, 7},
        {2, 3, 5, 6, 7}
    };
    // Comprobamos el primer ejemplo
    if (contiene_parejas(sw1, 8)) {
        cout << "Ejemplo 1: Todos los pares están contenidos en al menos un conjunto." << endl;
    } else {
        cout << "Ejemplo 1: Hay pares que no están contenidos en ningún conjunto." << endl;
    }
    // Comprobamos el segundo ejemplo
    if (contiene_parejas(sw2, 8)) {
        cout << "Ejemplo 2: Todos los pares están contenidos en al menos un conjunto." << endl;
    } else {
        cout << "Ejemplo 2: Hay pares que no están contenidos en ningún conjunto." << endl;
    }

    return 0;
}