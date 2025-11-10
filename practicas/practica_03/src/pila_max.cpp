#include <iostream>
#include "maxstack.h"

using namespace std;

/**
 * Usado en el ejercicio de examen
 */
bool contains(MaxStack stack, int val) {
    bool found = false;
    while (!stack.empty() && !found) {
        found = stack.top().value == val;
        stack.pop();
    }
    return found;
}

/**
 * EJERCICIO DE EXAMEN (no incluido en la práctica original)
 * Función que realiza la unión de elementos de las pilas SIN REPETIDOS
 */
MaxStack unir(MaxStack p1, MaxStack p2) {
    MaxStack join;

    while(!p2.empty()) {
        int val = p2.top().value;
        if (!contains(join, val)) { 
            join.push(val);
        }
        p2.pop();
    }

    while(!p1.empty()) {
        int val = p1.top().value;
        if (!contains(join, val)) { 
            join.push(val);
        }
        p1.pop();
    }

    return join;
}

/**
 * EJERCICIO DE EXAMEN (no incluido en la práctica original)
 * Función que comprueba si p1 y p2 son pilas inversas
 */
bool esInversa(MaxStack p1, MaxStack p2) {
    MaxStack aux; 
    bool inversa = true;

    while (!p1.empty()) {
        aux.push(p1.top().value);
        p1.pop();
    }

    while (!p2.empty() && !aux.empty() && inversa) {
        inversa = p2.top().value == aux.top().value;
        p2.pop();
        aux.pop();
    }

    return p2.empty() && aux.empty() && inversa;
}

int main(int argc, char *argv[]){

    // Run the current exercise
    MaxStack stack;

    for(int i = 1; i < argc; i++){
        if (argv[i][0] == '.'){
            cout << stack.top() << endl;
            stack.pop();
        } else {
            stack.push(atoi(argv[i]));
        }
    }
    return 0;
}
