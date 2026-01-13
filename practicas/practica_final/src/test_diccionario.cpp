/**
 * @file test_diccionario.cpp
 * @brief Programa para probar las funcionalidades del TDA diccionario

 * @author Victoria López 
 * @author Alejandro Moreno
 */

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "diccionario.h"

int main(int argc, char const* argv[]) {
    if (argc != 2) {
        std::cerr << "Uso: \ntestdiccionario [fichero_diccionario]" << std::endl;
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

    int longitud;

    std::cout << "longitud de las palabras a mostrar: ";
    std::cin >> longitud;
    std::vector<std::string> palabras = d.palabrasLongitud(longitud);
    std::cout << "\nPalabras de longitud " << longitud << ":" << std::endl;
    for (std::string p : palabras) {
        std::cout << p << "\n";
    }

    std::string p;
    std::cout << "\nIntroduce una palabra: ";
    std::cin >> p;

    std::cout << "\nla palabra " << p << " ";
    if (!d.esta(p)) {
        std::cout << "no ";
    }
    std::cout << "está en el diccionario" << p;


}

