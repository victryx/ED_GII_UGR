/**
 * Implemente la siguiente función
 *
 * set<int> interseccionesExclusivas(const set<int>& A, const set<int>& B, const set<int>& C)
 * 
 * La función debe devolver un set<int> con los elementos pertenecen exáctamente
 * a dos de los tres conjuntos:
 * - Están en A y B, pero no en C
 * - Están en A y C, pero no en B
 * - Están en B y C, pero no en A
 * 
 * Restricciones:
 * - Solo se permite el uso de set<int> y operaciones con iteradores
 * - No se permite usar vector, list, deque, algorithm, ni estructuras auxiliares.
 * - No se permite copiar sets a contenedores externos
 * - Solo se permite insertar, buscar, borrar y recorrer con iteradores
 * 
 */
#include <iostream>
#include <set>

using namespace std;

string serializar(const set<int>& s) {
    string out = "{";
    for (auto it = s.begin(); it != s.end(); ++it) {
        out += to_string(*it);
        out += ",";
    }
    out += "}";
    return out;
}

bool setsIguales(const set<int>& a, const set<int>& b) {
    return serializar(a) == serializar(b);
}


/*
    FUNCION A IMPLEMENTAR
    Devuelve un set con los elementos que estén en exactamente
    DOS de los tres sets A, B y C.
*/
set<int> interseccionesExclusivas(const set<int>& A, const set<int>& B, const set<int>& C) {
    set<int> out;
    for (int num : A) {
        if (B.count(num) + C.count(num) == 1) {
            out.insert(num);
        }
    }

    for (int num : B) {
        if (A.count(num) + C.count(num) == 1) {
            out.insert(num);
        }
    }

    return out;
}





/* ===================== MAIN (TESTS) ===================== */

int main() {

    bool todoGuchi = true;
    int t = 1;

    // TEST 1: caso del ejemplo
    {
        set<int> A = { 1,2,3,4 };
        set<int> B = { 3,4,5 };
        set<int> C = { 4,5,6 };

        set<int> esperado = { 3,5 };

        auto obtenido = interseccionesExclusivas(A, B, C);

        cout << "TEST " << t++ << ": ";
        if (setsIguales(esperado, obtenido)) cout << "OK\n";
        else {
            cout << "ERROR" << endl;
            todoGuchi = false;
        }
    }

    // TEST 2: todos exclusivos
    {
        set<int> A = { 1,2 };
        set<int> B = { 2,3 };
        set<int> C = { 3,4 };

        set<int> esperado = { 2,3 };

        auto obtenido = interseccionesExclusivas(A, B, C);

        cout << "TEST " << t++ << ": ";
        if (setsIguales(esperado, obtenido)) cout << "OK\n";
        else {
            cout << "ERROR\n";
            todoGuchi = false;
        }
    }

    // TEST 3: no hay intersecciones exclusivas
    {
        set<int> A = { 1 };
        set<int> B = { 1 };
        set<int> C = { 1 };

        set<int> esperado = {}; // vacío

        auto obtenido = interseccionesExclusivas(A, B, C);

        cout << "TEST " << t++ << ": ";
        if (setsIguales(esperado, obtenido)) cout << "OK\n";
        else {
            cout << "ERROR\n";
            todoGuchi = false;
        }
    }

    // TEST 4: solo A y B comparten
    {
        set<int> A = { 10,20 };
        set<int> B = { 20,30 };
        set<int> C = { };

        set<int> esperado = { 20 };

        auto obtenido = interseccionesExclusivas(A, B, C);

        cout << "TEST " << t++ << ": ";
        if (setsIguales(esperado, obtenido)) cout << "OK\n";
        else {
            cout << "ERROR\n";
            todoGuchi = false;
        }
    }

    // TEST 5: combinaciones mixtas
    {
        set<int> A = { 1,5,7 };
        set<int> B = { 5,8,9 };
        set<int> C = { 1,8,10 };

        set<int> esperado = { 1,5,8 }; // 1 (A,C), 5 (A,B), 8 (B,C)

        auto obtenido = interseccionesExclusivas(A, B, C);

        cout << "TEST " << t++ << ": ";
        if (setsIguales(esperado, obtenido)) cout << "OK\n";
        else {
            cout << "ERROR\n";
            todoGuchi = false;
        }
    }

    if (todoGuchi) { cout << "✅ Todos los tests pasaron correctamente" << endl; } else { cout << "❌ Revisa un poco la lógica... y lo tienes!" << endl; }

    return 0;
}
