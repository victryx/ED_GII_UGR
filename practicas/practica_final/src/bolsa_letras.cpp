/**
 * @file bolsa_letras.cpp
 * @brief Fichero de implementación del TDA BolsaLetras
 * 
 * @author Victoria López
 * @author Alejandro Moreno
 */
#include "bolsa_letras.h"
#include <algorithm>
#include <random>

BolsaLetras::BolsaLetras() { }

BolsaLetras::BolsaLetras(const ConjuntoLetras &cl) {
    for (int i = 0; i < 26; i++) {
        int repeticiones = cl.get_repeticiones(i+'a');
        for (int j = 0; j < repeticiones; j++) {
            letras.push_back(i+'a');
        }
    }
}

std::list<char> BolsaLetras::obtener_letras(int cantidad) {
    if (cantidad > letras.size()) {
        cantidad = letras.size();
    }

    // Generar número aleatorio para usar shuffle en el vector
    std::random_device rd;   // Obtener número aleatorio (semilla)
    std::mt19937 g(rd());    // Seed the generator
    std::shuffle(letras.begin(), letras.end(), g);

    std::list<char> out;
    auto it = letras.begin();
    for (int i = 0; i < cantidad; i++, it++) {
        out.push_back(*it);
    }
    return out;
}

std::ostream& operator<<(std::ostream& os, const BolsaLetras& bl) {
    for (char c : bl.letras) {
        os << c << " ";
    }
    return os;
}