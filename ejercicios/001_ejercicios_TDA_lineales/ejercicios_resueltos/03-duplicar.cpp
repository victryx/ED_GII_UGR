/**
 * Implementar función que duplique el tamaño de una lista inicial
 * rellenando los elementos de la siguiente forma:
 * - Tras el primero se pone el último
 * - Tras el segundo se pone el penúltimo
 * - ...
 * - Tras el último se pone el primero
 * 
 * Ejemplo
 * {5 ,2, 3, 4} => {5, 4, 2, 3, 3, 2, 4, 5}
 */

#include <list>
#include <iostream>

using namespace std;

void duplicar (const list<int> & lista_inicial, list<int> & lista_final) {
    list<int>::const_iterator left = lista_inicial.begin();
    auto right = lista_inicial.end(); // NOTA: se puede usar rbegin y reverse_iterator aquí
    right--;

    while (left != lista_inicial.end()) {
        lista_final.push_back(*left);
        lista_final.push_back(*right);
        left++;
        right--;
    }
}

int main() {
    list<int> inicial = {2, 3, 4};
    list<int> final;
    duplicar(inicial, final);

    for (int i : final)
    {
        cout << i << endl;
    }
    cout << endl;
    return 0;
}