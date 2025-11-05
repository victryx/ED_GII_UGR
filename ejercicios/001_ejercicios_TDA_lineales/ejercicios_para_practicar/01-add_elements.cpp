/**
 * Construir una función que inserta cada uno de los elementos de la
 * pila S en la lista ordenada L, de forma que L permanezca ordenada
 * tras la inserción. La función debe devolver el número de elementos
 * repetidos en la lista L tras la inserción. Si hay más de dos
 * ocurrencias del mismo número, dicho número cuenta una única vez en
 * la suma de elementos repetidos
 *
 * Ejemplo
 *
 * S={-3, 4} L={-1, 4, 4, 7} => L = [-3, -1, 4, 4, 4, 7] (devuelve 1)
 * S={-3, 4} L={-1, 4, 7}    => L = [-3, -3, -1, 4, 4, 7] (devuelve 2)
 */

#include <list>
#include <stack>
#include <iostream>

using namespace std;

int addElements(list<int> &l, stack<int> &s) {
    // Add stack elements
    while (!s.empty()) {
        int elem = s.top();
        s.pop();

        list<int>::iterator insert_pos = l.begin();
        while (insert_pos != l.end() && *insert_pos < elem) {
            ++insert_pos;
        }

        l.insert(insert_pos, elem);
    }

    // Count non-unique elements
    list<int>::iterator next = l.begin();
    list<int>::iterator prev = l.begin();
    ++next;
    int repeated = 0;
    while (next != l.end()) {
        if (*next == *prev) {
            repeated++;
            while (next != l.end() && *next == *prev) {
                ++next;
                ++prev;
            }
        } else {
            ++next;
            ++prev;
        }

    }
    return repeated;

}

int main() {
    stack<int> s;
    s.push(4);
    s.push(-3);

    list<int> l = {-3, 4, 7, 10, 10};

    int r = addElements(l, s);

    for(int e : l) {
        cout << e << " ";
    }
    cout << endl << r << endl;

    return 0;
}