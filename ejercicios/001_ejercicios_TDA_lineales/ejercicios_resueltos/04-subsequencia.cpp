/**
 * Implementa un método que dada una lista de enteros elimine todos
 * aquellos que no sean mayores que todos los anteriores
 * 
 * Ejemplo:
 * {1, 3, 4, 2, 4, 7, 7, 1} => {1, 3, 4, 7}
 */


#include <list>
#include <iostream>

using namespace std;

void subsequencia(list<int> & l) {
    list<int>::iterator prev = l.begin();
    list<int>::iterator next = l.begin();

    ++next;

    while (next != l.end()) {
        if (*next <= *prev) {
            next = l.erase(next);
        } else {
            ++next;
            ++prev;
        }
    }
}

int main() {
    list<int> lista = {1, 3, 4, 2, 4, 7, 7, 1};


    subsequencia(lista);

    for (int i : lista)
    {
        cout << i << endl;
    }

    cout << endl;
    return 0;
}