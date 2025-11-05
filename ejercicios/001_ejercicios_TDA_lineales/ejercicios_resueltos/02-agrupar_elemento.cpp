/**
 * Implementar una función que agrupe de forma consecutiva una lista
 * de enteros todas las apariciones del entero k en la lista a
 * partir de la primera ocurrencia
 *
 * Ejemplo:
 * ls = {1,3,4,1,4}, k=1 => ls={1,1,3,4,4}
 * ls = {3,1,4,1,4,1,1}, k=1 => ls={3,1,1,1,1,4,4}
 */

#include <list>
#include <algorithm>
#include <iostream>

using namespace std;

void agrupar_elemento(list<int> &in, int k) {
    list<int>::iterator first_occurence = find(in.begin(), in.end(), k);
    list<int>::iterator it = first_occurence;

    while (it != in.end()) {
        if (*it == k) {
            in.splice(first_occurence, in, it);
        }
        it++;
    }
}


int main()
{
    list<int> l = {3, 1, 4, 1, 4, 1, 1};
    agrupar_elemento(l, 1);

    for (int i : l)
    {
        cout << i << endl;
    }
    cout << endl;

    l = {1, 3,4,1,4};
    agrupar_elemento(l, 1);

    for (int i : l) {
        cout << i << endl;
    }

}
