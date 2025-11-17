/**
 * Dada una secuencia de enteros, se define su máxima desviación como la máxima 
 * diferencia (en valor absoluto) entre dos valores. (max(lista) - min(lista))
 * 
 * Implementar una función 
 * suaviza_lista(list<int> &L, int m, int maxdif);
 * Que elimina la cantidad mínima de elementos de L de tal manera que la máxima
 * desviación de una subsecuencia de m elementos consecutivos es menor que 
 * maxdif. L se modifica y la función devuelve el número de elementos eliminados
 * 
 * Ejemplo
 * Entrada: L = {1,3,5,4,2,3,7,4} m = 3, maxdif = 3
 * Salida:  L = {1,3,4,2,3,4}, función devuelve 2 (eliminados 5 y 7)
 */

#include <list>
#include <iostream>

using namespace std;

void desviacion(list<int>::iterator begin, list<int>::iterator end, int &max, int &min, int &dev) {
    --end;
    int min, max = *begin;
    while (begin != end) {
        min = *begin < min ? *begin : min;
        max = *begin > max ? *begin : max;
        ++begin;
    }
    dev = max - min;
}


int suaviza_lista(list<int> &l, int m, int maxdif) {

    auto left = l.begin();
    auto right = left;
    advance(right, m-1);

    int max, min, dev;
    while (right != l.end()) {
        desviacion(left, right, max, min, dev);
        if (dev >= m) {
            // Eliminar el máximo o el mínimo de la subsecuencia

            ++right;
        } else {
            ++left;
            ++right;
        }
    }
}