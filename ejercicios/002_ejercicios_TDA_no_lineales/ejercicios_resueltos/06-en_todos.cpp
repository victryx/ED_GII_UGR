/**
 * @file 06-en_todos.cpp
 */

#include <vector>
#include <set>
#include <iostream>

using namespace std;

bool en_todos(const vector<set<int>>& v) {
    for (int num : v[0]) {

        bool todos = true;
        for (int i = 1; i < v.size() && todos; ++i) {
            todos = v[i].count(num);
        }
        if (todos) return true;

    }
    return false;
}

set<int> interseccion(const set<int>& s1, const set<int>& s2) {
    set<int>r;
    for (auto it = s1.begin(); it != s1.end(); ++it) {
        if (s2.find(*it) != s2.end()) {
            r.insert(*it);
        }
    }
    return r;
}
bool en_todos_pdf(const vector< set<int> >& V) {
    set<int>s_i(V[0]);
    for (int i = 1;i < V.size();i++) {
        s_i = interseccion(s_i, V[i]);
        if (s_i.size() == 0) return false;
    }

    return true;
}

int main() {
    // Ejemplo 1: El 5 está en todos los conjuntos
    vector<set<int>> V1 = {
        {0, 2, 3, 4, 5},
        {0, 1, 5, 7},
        {2, 3, 5, 6, 7}
    };

    // Ejemplo 2: No hay ningún elemento común
    vector<set<int>> V2 = {
        {0, 2, 3, 4, 5},
        {0, 1, 7},
        {2, 3, 5, 6, 7}
    };
    // Comprobamos el primer ejemplo
    if (en_todos(V1)) {
        cout << "Existe al menos un elemento común en todos los conjuntos de V1." << endl;
    } else {
        cout << "No existe un elemento común en todos los conjuntos de V1." << endl;
    }

    // Comprobamos el segundo ejemplo
    if (en_todos(V2)) {
        cout << "Existe al menos un elemento común en todos los conjuntos de V2." << endl;
    } else {
        cout << "No existe un elemento común en todos los conjuntos de V2." << endl;
    }
    return 0;
}