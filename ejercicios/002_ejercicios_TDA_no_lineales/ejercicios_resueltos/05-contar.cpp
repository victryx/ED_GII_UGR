/**
 * @file 05-contar.cpp
 */

#include<vector>
#include<set>
#include<map>
#include<iostream>

using namespace std;

void contar(const vector<set<int>>& v, map<int, int>& veces) {
    for (int i = 0; i < v.size(); i++) {
        for (auto it = v[i].begin(); it != v[i].end(); ++it) {
            veces[*it]++;
        }
    }
}

int main() {
    vector<set<int>> V = {
        {1, 2, 3},
        {2, 4},
        {3, 4, 5, 9}
    };
    // Mapa para almacenar cuántos conjuntos contienen cada número
    map<int, int> veces;

    contar(V, veces);
    cout << "Recuento de elementos en los conjuntos:" << endl;
    for (auto it = veces.begin(); it != veces.end(); ++it) {
        cout << "<" << it->first << ", " << it->second << ">" << endl;
    }
    return 0;
}