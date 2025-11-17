/**
 * @file 09-union.cpp
 * 
 * Dados dos mapas `map<string,int> m1, m2`
 * que representan "nombre de usuario" -> número de seguidores
 * implementar una función
 * 
 * map<string, int> union(const map<string, int>& m1, const map<string, int>& m2)
 * 
 * Que obtenga la unión de los dos mapas de entrada
 * 
 * EJEMPLO:
 * m1 = {
 *     "Alice"   -> 100
 *     "Bob"     -> 150
 *     "Charlie" -> 200
 * }
 * 
 * m2 = {
 *     "Bob"     -> 50
 *     "David"   -> 120
 *     "Charlie" -> 30
 * }
 * 
 * union(m1, m2) = {
 *     "Alice"   -> 100
 *     "Bob"     -> 200
 *     "Charlie" -> 230
 *     "David"   -> 120
 * }
 */

#include <map>
#include <string>
#include <iostream>

using namespace std;

map<string, int> unir(const map<string, int>& m1, const map<string, int>& m2) {
    map<string, int> join(m1);
    for (pair<string, int> p : m2) {
        join[p.first] += p.second;
    }
    return join;
}

int main() {
    // Inicializamos dos mapas de personas y seguidores
    map<string, int> M1 = { {"Alice", 100}, {"Bob", 150}, {"Charlie", 200} };
    map<string, int> M2 = { {"Bob", 50}, {"David", 120}, {"Charlie", 30} };

    // Mostramos los mapas originales
    cout << "Mapa M1:" << endl;
    for (auto& p : M1)
        cout << p.first << ": " << p.second << " seguidores" << endl;
    cout << "\nMapa M2:" << endl;
    for (auto& p : M2)
        cout << p.first << ": " << p.second << " seguidores" << endl;

    // Llamamos a la función Union para obtener el mapa combinado
    map<string, int> M3 = unir(M1, M2);
    // Mostramos el mapa resultante de la unión
    cout << "\nMapa resultante de la unión (M3):" << endl;
    for (auto& p : M3)
        cout << p.first << ": " << p.second << " seguidores" << endl;
    return 0;
}