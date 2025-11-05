/**
 * Implementar una función que compruebe si una lista l1 está contenida
 * en otra lista l2 (elementos iguales, consecutivos y en el mismo orden)
 * 
 * Ejemplo
 * l1 = {1, 2, 3} l2 = {0, 1, 2, 3} => devuelve 1
 * l1 = {1, 2, 3} l2 = {1, 2, 2, 3} => devuelve 1
 */

#include <list>
#include <algorithm>
#include <iostream>

using namespace std;

/**
 * Solución propia
 */
bool secuencia (list<int> & l1, list<int> & l2) {
    auto it1 = l1.begin();
    auto it2 = l2.begin();

    while (it2 != l2.end()) {
        if (*it1 == *it2) {
            ++it1;
        } else {
            it1 = l1.begin();
        }
        ++it2;
        
        if (it1 == l1.end()) return true;
    }

    return false;
}

int main() {
    list<int> l1 = {1, 70};
    list<int> l2 = {0, 1, 2, 3, 1, 70};
    cout << secuencia(l1, l2) << endl;
    return 0;
}