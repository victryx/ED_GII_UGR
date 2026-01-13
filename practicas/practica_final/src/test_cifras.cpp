/**
 * @file test_cifras.cpp
 * @brief Fichero principal del problema de las cifras
 *
 * @author Victoria López
 * @author Alejandro Moreno
 */
#include <iostream>
#include <ctime>    // Para inicializar la semilla aleatoria
#include "cifras.h"

using namespace std;

/**
 * @brief Realiza operaciones dados dos enteros y un operador (+, -, *, /),
 * sirve para la parte de interacción con usuario
 * 
 * @param val1 valor izquierdo
 * @param val2 valor derecho
 * @param op operador (+, -, *, /)
 * @param resultado entero por referencia donde se asigna el resultado de la operacion
 * 
 * @retval true si se ha podido realizar la operación
 * @retval false si la operación no es válida
 *   (resultado negativo, división no entera, división entre 0, operador no válido)
 */
bool operate(int val1, int val2, char op, int &resultado);

int main() {
    // Inicializamos el generador de números aleatorios una sola vez
    srand(time(NULL));

    Cifras juego;

    // Tets 1: REPLICAR EL EJEMPLO DEL PDF
    cout << "=== TEST 1: Ejemplo del Documento PDF ===" << endl;

    juego.insertar(6);
    juego.insertar(8);
    juego.insertar(10);
    juego.insertar(9);
    juego.insertar(4);
    juego.insertar(75);

    int objetivo = 835;

    // Mostramos la situación inicial
    juego.imprimir();
    cout << "Objetivo a conseguir: " << objetivo << endl;
    cout << "----------------------------------------" << endl;

    // Resolvemos
    cout << "Buscando soluciones..." << endl;
    bool exito = juego.resolver(objetivo);

    // Mostramos resultados
    if (exito) {
        cout << "¡ÉXITO! Se encontró el número exacto." << endl;
    } else {
        cout << "No se encontró exacto. Se muestra la aproximación." << endl;
    }

    cout << "Mejor valor conseguido: " << juego.getMejorValor() << endl;
    cout << "Pasos para conseguirlo: " << endl;
    cout << juego.getMejorExpresion() << endl;


    // Test 2: PARTIDA ALEATORIA
    cout << "\n\n=== TEST 2: Partida Aleatoria ===" << endl;

    // Generamos números nuevos aleatorios
    juego.limpiar();
    juego.generarAleatorio();

    // Generamos un objetivo aleatorio entre 100 y 999
    int objetivo_random = 100 + rand() % 900;

    juego.imprimir();
    cout << "Objetivo aleatorio: " << objetivo_random << endl;
    cout << "----------------------------------------" << endl;

    juego.resolver(objetivo_random);

    cout << "Mejor valor conseguido: " << juego.getMejorValor() << endl;
    cout << "Pasos:" << endl;
    cout << juego.getMejorExpresion() << endl;

    cout << "\n\n=== TEST 3: Interacción con el usuario===" << endl;

    string modo;
    cout << "\nIntroduce el modo: aleatorio o combinacion mágica (A|C): ";
    cin >> modo;
    bool modo_magia = modo[0] == 'C' || modo[0] == 'c';

    juego.limpiar(); // eliminar conjunto anterior.
    if (modo_magia) {
        // Insertar combinación mágica
        juego.insertar(6);
        juego.insertar(8);
        juego.insertar(10);
        juego.insertar(9);
        juego.insertar(4);
        juego.insertar(75);
    } else {
        // Insertar aleatorios
        juego.generarAleatorio();
    }
    // Generamos un objetivo aleatorio entre 100 y 999
    int objetivo_usuario = 100 + rand() % 900;

    cout << "El objetivo es: " << objetivo_usuario << endl;

    cout << "Los números generados son:\n";
    juego.imprimir();
    cout << "----------------------------------------\n";

    multiset<int> numeros = juego.getConjunto();
    set<char> operaciones = { '+', '-', '*', '/' };

    int resultado;
    int numero;
    char operacion;
    bool juego_valido = true;
    string pasos = "";

    cout << "No se permite la división no entera ni los resultados intermedios negativos\n";
    cout << "Elige un número (";
    for (int n : numeros) {
        cout << " " << n;
    }
    cout << " ): ";
    cin >> resultado;

    juego_valido = numeros.count(resultado);
    if (juego_valido) {
        numeros.erase(numeros.lower_bound(resultado)); // para eliminar una sola clave, no todas
    }

    while (!numeros.empty() && juego_valido) {
        cout << "Elige una operación (+ - / *): ";
        cin >> operacion;

        cout << "Elige otro número (";
        for (int n : numeros) {
            cout << " " << n;
        }
        cout << " ): ";
        cin >> numero;

        juego_valido = numeros.count(numero) && operaciones.count(operacion);
        if (juego_valido) {
            numeros.erase(numeros.lower_bound(numero)); // para eliminar una sola clave, no todas
            int prev_resultado = resultado;
            juego_valido = operate(resultado, numero, operacion, resultado);
            string paso = to_string(prev_resultado) + operacion + to_string(numero) + " = " + to_string(resultado);
            pasos += paso + '\n';
            if (juego_valido) {
                cout << paso << '\n';
            }
        }

    }

    if (juego_valido) {
        cout << "\n\nLa solución del usuario es: " << resultado << " y ha realizado los pasos:\n" << pasos;
        int distancia = abs(objetivo_usuario - resultado);
        cout << "La distancia al objetivo es " << distancia << "\n";

    } else {
        cout << "\n\nLa solución del usuario NO ES VÁLIDA\n";
    }

    juego.resolver(objetivo_usuario);

    cout << "\nMi solución es: " << juego.getMejorValor() << endl;
    cout << "Pasos:" << endl;
    cout << juego.getMejorExpresion() << endl;

    return 0;
}


bool operate(int val1, int val2, char op, int &resultado) {
    if (op == '+') {
        resultado = val1 + val2;
        return true;  
    }
    if (op == '-') {
        resultado = val1 - val2;
        return resultado >= 0;  // No se permiten los resultados intermedios negativos
    }
    if (op == '*') {
        resultado = val1 * val2;
        return true;
    }
    if (op == '/' && val2 != 0 && val1 % val2 == 0) {
        resultado = val1 / val2;
        return true;
    }
    return false;
}