/**
 * @file cifras.cpp
 * @brief Fichero de implementación del TDA Cifras
 * 
 * @author Victoria López
 * @author Alejandro Moreno
 */
#include "cifras.h"

Cifras::Cifras() {
    minima_distancia = INT_MAX;
    mejor_valor = 0;
    mejor_expresion = "";
}

void Cifras::buscarSoluciones(multiset<int> estado_actual, int objetivo, string historial) {
    // Revisamos si lo que tenemos ahora es mejor que lo anterior
    for (int num : estado_actual) {
        int distancia = abs(num - objetivo);

        // Si estamos más cerca que antes, guardamos este resultado
        if (distancia < minima_distancia) {
            minima_distancia = distancia;
            mejor_valor = num;
            mejor_expresion = historial;
        }

        // Si ya tenemos el número exacto retornamos
        if (minima_distancia == 0) {
            return;
        }
    }

    if (estado_actual.size() <= 1) {
        return;
    }

    // Probamos todas las parejas de números 
    auto it1 = estado_actual.begin();

    for (it1; it1 != estado_actual.end(); ++it1) {

        auto it2 = it1;
        ++it2;

        for (; it2 != estado_actual.end(); ++it2) {

            int a = *it1;
            int b = *it2;

            // Creamos una copia del conjunto SIN los números 'a' y 'b'
            multiset<int> siguiente = estado_actual;

            siguiente.erase(siguiente.find(a));
            siguiente.erase(siguiente.find(b));

            // --- SUMA ---
            siguiente.insert(a + b);
            buscarSoluciones(siguiente, objetivo, historial + to_string(a) + "+" + to_string(b) + "=" + to_string(a + b) + "\n");
            siguiente.erase(siguiente.find(a + b)); // Borramos la suma para probar la siguiente operación

            // --- MULTIPLICACIÓN ---
            if (a != 1) {
                siguiente.insert(a * b);
                buscarSoluciones(siguiente, objetivo, historial + to_string(a) + "*" + to_string(b) + "=" + to_string(a * b) + "\n");
                siguiente.erase(siguiente.find(a * b));
            }

            // --- RESTA ---
            // Hacemos b - a (el grande menos el pequeño) para evitar negativos
            int resta = b - a;
            siguiente.insert(resta);
            buscarSoluciones(siguiente, objetivo, historial + to_string(b) + "-" + to_string(a) + "=" + to_string(resta) + "\n");
            siguiente.erase(siguiente.find(resta));

            // --- DIVISIÓN ---
            // Solo si es exacta y no dividimos por 0 ni por 1
            if (a > 1 && (b % a == 0)) {
                int div = b / a;
                siguiente.insert(div);
                buscarSoluciones(siguiente, objetivo, historial + to_string(b) + "/" + to_string(a) + "=" + to_string(div) + "\n");
                siguiente.erase(siguiente.find(div));
            }
        }
    }
}

void Cifras::insertar(int n) {
    conjunto.insert(n);
}

void Cifras::generarAleatorio() {
    conjunto.clear();
    // Posibles números según las reglas
    // vector<int> bolsa = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 25, 50, 75, 100};

    for (int i = 0; i < 6; i++) {
        // Elige una posición al azar de la bolsa
        // int pos = rand() % bolsa.size();
        conjunto.insert((rand() % 100) + 1);

    }
}

void Cifras::imprimir() const {
    for (int n : conjunto) {
        cout << n << " ";
    }
    cout << endl;
}

bool Cifras::resolver(int objetivo) {
    // Reiniciamos todo
    minima_distancia = INT_MAX;
    mejor_expresion = "No encontrada";
    mejor_valor = 0;

    buscarSoluciones(conjunto, objetivo, "");

    // Si la distancia es 0, es que encontramos el exacto (return true)
    return (minima_distancia == 0);
}

string Cifras::getMejorExpresion() const {
    return mejor_expresion;
}

int Cifras::getMejorValor() const {
    return mejor_valor;
}

multiset<int> Cifras::getConjunto() const {
    multiset<int> copia(conjunto);
    return copia;
}

int Cifras::tamano() const {
    return conjunto.size();
}

void Cifras::limpiar() {
    conjunto.clear();
}