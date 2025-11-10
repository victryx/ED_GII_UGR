#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include "maxqueue.h"

using namespace std;

/**
 * Usado en el ejercicio de examen
 */
int max(int a, int b) {
    return a > b ? a : b;
}

/**
 * EJERCICIO DE EXAMEN (no incluido en la práctica original)
 * Función que compara por posiciones q1 y q2 y añade en una q auxiliar
 * el valor más grande
 */
MaxQueue enfrentamiento(MaxQueue q1, MaxQueue q2) {
    MaxQueue aux;

    while (!q1.empty() && !q2.empty()) {
        int max_val = max(q1.front().value, q2.front().value);
        aux.push(max_val);

        q1.pop();
        q2.pop();
    }

    while (!q1.empty()) {
        aux.push(q1.front().value);
        q1.pop();
    }
    
    while (!q2.empty()) {
        aux.push(q2.front().value);
        q2.pop();
    }

    return aux;
}

int main(int argc, char *argv[]){

    // Run the current exercise
    MaxQueue queue;

    for(int i = 1; i < argc; i++){
        if (argv[i][0] == '.'){
            cout << queue.front() << endl;
            queue.pop();
        } else {
            queue.push(atoi(argv[i]));
        }
    }
    return 0;
}
