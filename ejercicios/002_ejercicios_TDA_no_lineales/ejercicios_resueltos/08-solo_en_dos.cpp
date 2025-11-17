/**
 * @file 08-solo_en_dos.cpp
 */


#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <map>

using namespace std;

void solo_en_2(vector<set<int>>& vs, set<int>& s1) {
    // Conjunto de los elementos que solo están en dos conjuntos
    map<int, int> frequency;
    for (int i = 0; i < vs.size(); i++) {
        for (auto it = vs[i].begin(); it != vs[i].end(); ++it) {
            frequency[*it]++;
        }
    }


    for (pair<int, int> p : frequency) {
        if (p.second == 2) {
            s1.insert(p.first);
        }
    }

}

int main() {
    // Ejemplo de conjuntos en el vector VS
    vector<set<int>> VS = {
        {0, 1, 2, 3},
        {1, 3, 4, 5},
        {1, 3, 6, 7},
        {2, 4, 7, 9},
        {0, 7, 8, 9}
    };
    // Conjunto que almacenará los elementos que están en exactamente dos conjuntos
    set<int> S1;
    solo_en_2(VS, S1);

    // Imprimimos el conjunto S1
    cout << "Elementos que están en exactamente dos conjuntos: ";
    for (auto it = S1.begin(); it != S1.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}