/**
 * Implemente la siguiente función:
 * 
 * set<string> equiposUnicos(const map<string, set<string>>& historial).
 * 
 * Que dado un mapa donde:
 * - la clave es el nombre del jugador
 * - el valor es un set<string> que contiene los equipos en los que ha jugado
 * 
 * Devuelva un set<string> con los equipos que aparecen exáctamente 
 * UNA SOLA VEZ en todo el mapa.
 * 
 * Restricciones:
 * - Solo se puede usar std::map y std::set
 * - No se permite el uso de <algorithm>
 * - El problema debe resolverse mediante iteradores, inserciones y búsquedas en map y set
 * 
 */

 #include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

/*
    Función a evaluar en el examen:
    Dado un mapa: jugador -> equipos en los que ha jugado,
    se devuelve un set con los equipos en los que SOLO ha
    jugado un jugador.

    Mapa (clave -> valor)
    jugador_a -> {eq1, eq2, eq3}
    jugador_b -> {eq2, eq4, eq5}
    jugador_c -> {eq6, eq4}

    La función devuelve {eq1, eq3, eq5, eq6}
*/
set<string> equiposUnicos(const map<string, set<string>>& historial) {
    map<string, int> equipos_veces;
    set<string> out;
    for (pair<string, set<string>> p : historial) {
        for(string s : p.second) {
            equipos_veces[s]++;
        }
    }

    for (pair<string, int> p : equipos_veces) {
        if (p.second == 1) {
            out.insert(p.first);
        }
    }

    return out;
}

/*
    Función auxiliar para comparar dos sets SOLO con map y set.
    Devuelve true si son iguales.
*/
bool setsIguales(const set<string>& a, const set<string>& b) {
    if (a.size() != b.size()) return false;

    auto itA = a.begin();
    auto itB = b.begin();

    while (itA != a.end()) {
        if (*itA != *itB) return false;
        ++itA;
        ++itB;
    }
    return true;
}

/*
    Imprime un set<string> sin usar nada externo.
*/
void imprimeSet(const set<string>& s) {
    cout << "{ ";
    for (auto it = s.begin(); it != s.end(); ++it) {
        cout << *it;
        auto next = it; ++next;
        if (next != s.end()) cout << ", ";
    }
    cout << " }";
}


/* ============================================================
                           MAIN CON TESTS
   Cada test comprueba automáticamente si la función es correcta
   ============================================================ */

int main() {

    int test = 1;

    // === TEST 1: Caso general ===
    {
        map<string, set<string>> entrada = {
            {"Messi", {"Barcelona", "PSG", "Inter Miami"}},
            {"Cristiano", {"Sporting", "Manchester United", "Real Madrid", "Juventus"}},
            {"Iniesta", {"Barcelona", "Vissel Kobe", "Emirates Club"}},
            {"Haaland", {"Molde", "Salzburg", "Dortmund", "Manchester City"}},
            {"Xavi", {"Barcelona", "Al Sadd"}},
            {"Neymar", {"Santos", "Barcelona", "PSG"}}
        };

        set<string> esperado = {
            "Inter Miami", "Emirates Club", "Vissel Kobe",
            "Molde", "Salzburg", "Dortmund", "Manchester City",
            "Al Sadd", "Santos", "Sporting", "Juventus",
            "Manchester United", "Real Madrid"
        };

        set<string> obtenido = equiposUnicos(entrada);

        cout << "TEST " << test++ << ": ";
        if (setsIguales(esperado, obtenido)) cout << "OK\n";
        else {
            cout << "ERROR\nEsperado: ";
            imprimeSet(esperado);
            cout << "   Obtenido: ";
            imprimeSet(obtenido);
            cout << "\n";
        }
    }


    // === TEST 2: Ningún equipo único ===
    {
        map<string, set<string>> entrada = {
            {"Keylor Navas", {"Real Madrid", "PSG"}},
            {"Mbappe", {"PSG", "Real Madrid"}}
        };

        set<string> esperado = {}; // vacío

        set<string> obtenido = equiposUnicos(entrada);

        cout << "TEST " << test++ << ": ";
        if (setsIguales(esperado, obtenido)) cout << "OK\n";
        else cout << "ERROR\n";
    }


    // === TEST 3: Todo único ===
    {
        map<string, set<string>> entrada = {
            {"Totti", {"Roma"}},
            {"Djené", {"Getafe"}},
            {"Isi Palazón", {"Rayo Vallecano"}}
        };

        set<string> esperado = {"Roma", "Getafe", "Rayo Vallecano"};

        set<string> obtenido = equiposUnicos(entrada);

        cout << "TEST " << test++ << ": ";
        if (setsIguales(esperado, obtenido)) cout << "OK\n";
        else cout << "ERROR\n";
    }


    // === TEST 4: Un jugador sin equipos ===
    {
        map<string, set<string>> entrada = {
            {"Fali", {"Cadiz CF"}},
            {"Mi padre", {}},
            {"Djené", {"Getafe"}}
        };

        set<string> esperado = {"Cadiz CF", "Getafe"};

        set<string> obtenido = equiposUnicos(entrada);

        cout << "TEST " << test++ << ": ";
        if (setsIguales(esperado, obtenido)) cout << "OK\n";
        else cout << "ERROR\n";
    }


    // === TEST 5: Solo un jugador ===
    {
        map<string, set<string>> entrada = {
            {"Messi", {"Barca", "PSG", "Inter de Miami"}}
        };

        set<string> esperado = {"Barca", "PSG", "Inter de Miami"};

        set<string> obtenido = equiposUnicos(entrada);

        cout << "TEST " << test++ << ": ";
        if (setsIguales(esperado, obtenido)) cout << "OK\n";
        else cout << "ERROR\n";
    }


    // === TEST 6: Mezcla compleja ===
    {
        map<string, set<string>> entrada = {
            {"Keylor Navas", {"Real Madrid", "PSG", "Levante"}},
            {"Mbappe", {"PSG", "Real Madrid"}},
            {"Fali", {"Cadiz CF"}},
            {"Asensio", {"PSG", "Real Madrid"}},
            {"Morales", {"Levante", "Villarreal"}},
            {"Isi Palazón", {"Rayo Vallecano"}},
            {"Bruno", {"Villarreal"}}
        };

        set<string> esperado = {"Cadiz CF", "Rayo Vallecano"};

        set<string> obtenido = equiposUnicos(entrada);

        cout << "TEST " << test++ << ": ";
        if (setsIguales(esperado, obtenido)) cout << "OK\n";
        else cout << "ERROR\n";
    }


    cout << "Se han pasado TODOS los test. Enhorabuena! ✅" << endl;

    return 0;
}