/**
 * Implementa una función
 * 
 * map<char, set<string>> agrupar_por_inicial(const set<string>& peliculas)
 * 
 * que dado un set<string> con títulos de películas, la función debe construir
 * un map <char, set<string>> donde:
 * 
 * - La clave (char) será la primera letra del título de la película (en minúscula)
 * - El valor (set<string>) serán todas las películas que comienzan por esa letra
 * 
 * El mapa resultante debe aparecer ordenado por clave (propio de map), y cada
 * conjunto de películas aparecerá ordenado automáticamente
 * 
 * EJEMPLO:
 * Entrada: 
 * { "Amelie", "Avatar", "Batman"}
 * 
 * Salida:
 * a: Amelie Avatar
 * b: Batman
 * 
 * - No se permite el uso de contenedores auxiliares de ningún tipo
 * - No se permite el uso del header <algorithm>
 * - El problema debe resolverse mediante iteradores, inserciones y búsquedas 
 *   en map y set
 */

#include <map>
#include <string>
#include <set>
#include <iostream>

using namespace std;


map<char, set<string>> agruparPorInicial(const set<string>& peliculas) {
    map<char, set<string>> out;
    for (string peli : peliculas) {
        out[tolower(peli[0])].insert(peli);
    }
    return out;
}

int main() {
    set<string> peliculas = { "Amelie", "DIBUJOS ANIMADOS", "ddddd", "Avatar", "Batman",
    "benhur" };

    map<char, set<string>> agrupadas = agruparPorInicial(peliculas);

    for (pair<char, set<string>> p : agrupadas) {
        cout << "Peliculas " << p.first << ":";
        for (string str : p.second) {
            cout << " " << str;
        }
        cout << endl;
    }
    
}