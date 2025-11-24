/**
 * @file 02-flat.cpp
 *
 */

#include <vector>
#include <set>
#include <iostream>

using namespace std;

bool flat(vector<set<int>>& conexiones, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            bool couple_found = false;
            for (int k = 0; k < conexiones.size() && !couple_found; k++) {
                couple_found = conexiones[k].count(i) && conexiones[k].count(j);
            }
            if (!couple_found)
                return false;
        }
    }

    return true;
}

int main() {
    vector<set<int>> sw1 = { {0, 1, 2, 3, 4}, {0, 1, 5, 6, 7}, {2, 3, 4, 5, 6, 7} };
    bool resultado1 = flat(sw1, 8); // Retorna true
    cout << (resultado1 ? "True" : "False") << endl;
    vector<set<int>> sw2 = { {0, 2, 3, 4}, {0, 1, 5, 7}, {2, 3, 5, 6, 7} };
    bool resultado2 = flat(sw2, 8); // Retorna false
    cout << (resultado2 ? "True" : "False") << endl;
    return 0;
}