/**
 * Dado un vcector <list<int>> vl, implementar una función:
 * void interlaced_join(vector< list<int> >&vl, list<int>&l);
 * Que una las listas contenidas en vl en una sola lista l, tomando primero
 * los primeros elementos de las listas en vl, después los segundos, luego
 * los terceros, hasta que se acaben todas las listas
 * 
 * EJEMPLOS
 * 
 * vl = { {0,4,8}, {1,5}, {2,6}, {3,7}}
 * output = {0,1,2,3,4,5,6,7,8}
 * ---
 * vl = { {0,1}, {2}, {3,4}, {5,6}, {7}}
 * output = {0,2,3,5,7,1,4,6}
 * 
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

// <FUNCIÓN A IMPLEMENTAR>
void interlaced_join(vector< list<int> >& vl, list<int>& l) {
    bool remaining_elements;
    do {
        remaining_elements = false;
        for (int i = 0; i < vl.size(); i++) {
            if (!vl[i].empty()) {
                l.push_back(vl[i].front());
                vl[i].pop_front();
                remaining_elements = true;
            }
        }
    } while (remaining_elements);
}


ostream& operator<<(ostream& os, const list<int>& l) {
    for (auto it = l.cbegin(); it != l.cend();++it)
        os << *it << " ";
    os << endl;
    return os;
}
// Imprime los elementos comprendidos entre dos iteratores
template <class T>
void Imprime(T first, T second) {
    for (auto it = first; it != second;++it) {
        for_each(it->begin(), it->end(), [](int a) { cout << a << " ";});
        cout << endl;
    }
}

bool operator == (const list<int>& e1, const list<int>& e2) {
    if (e1.size() != e2.size()) return false;
    for (auto it1 = e1.cbegin(), it2 = e2.cbegin(); it1 != e1.cend();++it1, ++it2)
        if ((*it1) != (*it2)) return false;
    return true;
}


// Simplemente comprueba que la solución para "in" es correcta
void test_sol(vector<list<int> > in, list<int> sol) {
    cout << "Entrada:   " << endl;
    Imprime(in.begin(), in.end());
    cout << "Resultado: ";
    list<int> res;
    interlaced_join(in, res);
    cout << "Solución:  ";
    cout << endl << res << endl;

    cout << "Solución correcta?: " << (res == sol ? "YES" : "NO") << endl;
}

int main() {
    vector<list<int> > vl = { {0, 4, 8},{1, 5},{2, 6},{3, 7} };
    list<int> l = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
    test_sol(vl, l);

    vector<list<int> > VL2={{0,1},{2},{3, 4},{5, 6},{7}};
    list<int> L2={0, 2, 3, 5, 7, 1, 4, 6};
    test_sol(VL2,L2);

}