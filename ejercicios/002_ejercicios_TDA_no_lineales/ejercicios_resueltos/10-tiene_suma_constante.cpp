/**
 * @file 10-tiene_suma_constante.cpp
 * 
 * Implementar una función
 * 
 * bool tiene_suma_constante(set<int>& s, int m)
 * 
 * que dado un conjunto de enteros s y un entero m, devuelve **true** si 
 * existe un subconjunto de elementos en s cuyos valores suman exáctamente m
 * 
 * EJEMPLO:
 * s = {1, 2, 3, 4, 5, 6};
 * tiene_suma_constante(s, 15) // => true
 * tiene_suma_constante(s, 22) // => true
 * 
 * 
 * PISTA: 
 * Puede resolverse de forma recursiva.
 * - Si s contiene un elemento con valor m, devuelve true
 * - Si todos los elementos de s son mayores que m [en valor absoluto], devuelve false
 * - Para cada cada elemento x de s, define
 *      (a) subconjunto s' = s - x
 *      (b) valor m' = m - x
 * - Si se cumple la propiedad con (a) y (b), devuelve true
 * 
 */

#include <set>
#include <iostream>

using namespace std;

bool tiene_suma_constante(const set<int>& s, int m) {
    if (s.count(m)) return true;

    for (int i : s) {
        set<int> new_set(s);
        new_set.erase(new_set.find(i));
        if (tiene_suma_constante(new_set, m - i)) return true;
    }

    return false; // cuando s esta vacío no entra en el bucle for
}

/**
 * Solución del PDF
 * 
 * creo que no funciona para valores negativos
 */
bool tiene_suma_constante_pdf(set<int> s, int M) {
    if (M == 0) return true;
    else {
        if (s.size() == 0) return false;
        for (auto it = s.begin(); it != s.end(); ++it) {
            if (*it <= M) { // AQUÍ habría que comparar valores absolutos
                set<int> aux = s;
                aux.erase(*it);
                if (tiene_suma_constante_pdf(aux, M - *it)) return true;
            }
        }
        return false;
    }
}

int main() {
    // Definimos un conjunto de ejemplo
    set<int> s = { 1, 2, 3, 4, 5, 6 };

    // Probar con la suma 15
    int M1 = 15;
    if (tiene_suma_constante(s, M1)) {
        cout << "Existe un subconjunto cuya suma es " << M1 << "." << endl;
    } else {
        cout << "No existe un subconjunto cuya suma sea " << M1 << "." << endl;
    }

    // Probar con la suma 22
    int M2 = 22;
    if (tiene_suma_constante(s, M2)) {
        cout << "Existe un subconjunto cuya suma es " << M2 << "." << endl;
    } else {
        cout << "No existe un subconjunto cuya suma sea " << M2 << "." << endl;
    }

    s = { -1, -2, 9 };
    M2 = -3;
    if (tiene_suma_constante(s, M2)) {
        cout << "Existe un subconjunto cuya suma es " << M2 << "." << endl;
    } else {
        cout << "No existe un subconjunto cuya suma sea " << M2 << "." << endl;
    }
    return 0;
}