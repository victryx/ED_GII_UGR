/**
 * @file test_cantidad_letras.cpp
 * @brief Programa de prueba del TDA ConjuntoLetras
 * 
 * @author Victoria López
 * @author Alejandro Moreno
 */

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include "diccionario.h"
#include "letra.h"
#include "conjunto_letras.h"


int main(int argc, char const *argv[]) {
    if (argc != 4) {
        std::cerr << "Uso: \ncantidad_letras [fichero_diccionario] [fichero_letras] [fichero_salida]" << std::endl;
        return 1;
    }

    std::ifstream f(argv[1]);
    if (!f) {
        std::cerr << "Imposible abrir el archivo" << std::endl;
        return 1;
    }

    Diccionario d;
    std::cout << "cargando diccionario..." << std::endl;
    f >> d;
    std::cout << "diccionario leído correctamente..." << std::endl;
    f.close();

    f.open(argv[2]);
    ConjuntoLetras cl;
    std::cout << "cargando letras..." << std::endl;

    f >> cl;
    f.close();

    std::cout << "conjunto de letras leído correctamente: " << std::endl;
    std::cout << cl;

    long frecuencia_letras[26];
    long puntuacion_letras[26];
    int total_letras = 0;

    for (int i = 0; i < 26; i++) {
        if (cl.esta_en_conjunto(i + 'a')) {
            frecuencia_letras[i] = 0;
            puntuacion_letras[i] = 0;
        } else {
            frecuencia_letras[i] = -1;
            puntuacion_letras[i] = -1;
        }
    }
    

    // Calcular frecuencias
    Diccionario::iterator it = d.begin();
    while (it != d.end()) {
        for (char c : *it) {
            if (cl.esta_en_conjunto(c)) {
                frecuencia_letras[c - 'a']++;
                total_letras++;
            }
        }

        ++it;
    }

    // Calcular puntuaciones
    int letra_mas_frecuente = 0;
    int letra_menos_frecuente = -1;
    for (int i = 0; i < 26; i++) {
        if (letra_menos_frecuente == -1 && frecuencia_letras[i] != -1) {
            letra_menos_frecuente = i;
        }
        if (frecuencia_letras[i] > frecuencia_letras[letra_mas_frecuente]) {
            letra_mas_frecuente = i;
        }
        if (frecuencia_letras[i] != -1 && frecuencia_letras[i] < frecuencia_letras[letra_menos_frecuente]) {
            letra_menos_frecuente = i;
        }
    }
    std::cout << "más frecuente: " << (char)('a'+letra_mas_frecuente);
    std::cout << " menos frecuente: " << (char)('a'+letra_menos_frecuente) << std::endl;

    for (int i = 0; i < 26; i++) {
        if (frecuencia_letras[i] != -1) {
            int val = frecuencia_letras[i] - frecuencia_letras[letra_menos_frecuente];
            int max = frecuencia_letras[letra_mas_frecuente] - frecuencia_letras[letra_menos_frecuente];

            val = abs(val - max);

            puntuacion_letras[i] = ((float)val / max) * 9 + 1;
        }
    }
    

    // Crear fichero de salida
    ConjuntoLetras salida;
    for (int i = 0; i < 26; i++) {
        if (frecuencia_letras[i] != -1) {
            int cantidad = ((float)frecuencia_letras[i] / total_letras) * 100;
            Letra l(i+'a', cantidad+1, puntuacion_letras[i]);
            salida.inserta_letra(l);
        }
    }
    

    std::cout << "Frecuencia de letras en el diccionario:" << std::endl;
    std::cout << salida;

    std::ofstream of(argv[3]);
    of << salida;
    of.close();
}