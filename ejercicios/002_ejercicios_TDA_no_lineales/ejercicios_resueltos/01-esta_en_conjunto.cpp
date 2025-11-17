/**
 * Dado un vector de conjuntos (vector<set<int>>)
 * 
 * implementar función
 * 
 * que devuelve a través del mapa `recuento` cada uno de los elementos
 * que aparecen en algún conjunto y una lista de las posiciones del 
 * vector en las que se puede encontrar.
 * 
 * EJEMPLO
 * v = [ {1, 20, 3}, {20,3,45}, {3,45,5,93}, {20,45,6,8}, {93}, {1,3,5}]
 * salida = 
 * [ 1 -> {0, 5}, 3 -> {0, 1, 2, 5}, 5 -> {2, 5}, 6 -> {3}, 8 -> {3},
 * 20 -> {0, 1, 3} 45 -> {1, 2, 3}, 93 -> {2, 4} ]
 */
#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <map>

using namespace std;

/**
 * Mi solución
 */
void esta_en_conjunto(vector<set<int>>& v, map<int, list<int>>& recuento) {
    for (size_t i = 0; i < v.size(); i++) {
        for (auto it = v[i].cbegin(); it != v[i].cend(); ++it) {
            recuento[*it].push_back(i);
        }
    }
}

/**
 * Solución del pdf
 * 
 * Esta solución tiene sentido si v es un vector<vector<int>>
 */
void esta_en_conjunto_pdf(vector<set<int>>& v, map<int, list<int>>& recuento) {
    set<int> diferentes_ele; //obtenemos los elementos de forma única

    for (int i = 0; i < v.size(); i++) {
        for (auto it = v[i].begin(); it != v[i].end(); ++it) {
            diferentes_ele.insert(*it);
        }
    }

    //recorremos los diferentes elementos y lo contabilizamos
    // los conjuntos en los que se encuentran
    for (auto it = diferentes_ele.begin();it != diferentes_ele.end(); ++it) {
        recuento[*it] = list<int>();
        for (int i = 0;i < v.size();i++) {
            if (v[i].count(*it) > 0) {
                recuento[*it].push_back(i);
            }
        }
    }
}

/**
 * Función para imprimir el map<int, list<int>>
 */
void imprimir_recuento(const map<int, list<int>>& recuento) {
    for (const auto& par : recuento) {
        cout << par.first << " -> {";
        for (auto it = par.second.begin(); it != par.second.end();
            ++it) {
            if (it != par.second.begin()) cout << ", ";
            cout << *it;
        }
        cout << "}" << endl;
    }
}

int main() {
    vector<set<int>> v = {
    {1, 20, 3},
    {20, 3, 45},
    {3, 45, 5, 93},
    {20, 45, 6, 8},
    {93},
    {1, 3, 5}
    };
    map<int, list<int>> recuento;
    map<int, list<int>> recuento_pdf;
    esta_en_conjunto(v, recuento);
    esta_en_conjunto_pdf(v, recuento_pdf);
    cout << "Contenido del mapa recuento:" << endl;
    imprimir_recuento(recuento);
    cout << endl;
    cout << "Contenido del mapa recuento (solución pdf):" << endl;
    imprimir_recuento(recuento_pdf);
    return 0;
}