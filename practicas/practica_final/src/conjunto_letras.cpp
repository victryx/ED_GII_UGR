/**
 * @file conjunto_letras.cpp
 * @brief Fichero de implementación del TDA ConjuntoLetras
 *
 * @author Victoria López 
 * @author Alejandro Moreno
 */

#include "conjunto_letras.h"
#include "letra.h"

ConjuntoLetras::ConjuntoLetras() {}

int ConjuntoLetras::get_puntuacion(char ch) const {
    if (datos.count(ch)) {
        return datos.at(ch).get_puntuacion();
    }
    return -1;
}

int ConjuntoLetras::get_repeticiones(char ch) const {
    ch = tolower(ch);
    if (datos.count(ch)) {
        return datos.at(ch).get_repeticiones();
    }
    return -1;
}

bool ConjuntoLetras::esta_en_conjunto(char ch) const {
    return datos.count(tolower(ch));
}

void ConjuntoLetras::inserta_letra(const Letra& letra) {
    datos[letra.get_caracter()] = letra;
}

std::ostream& operator<<(std::ostream& os, const ConjuntoLetras& cl) {
    os << "Letra Cantidad Puntos\n";
    for (std::pair<char, Letra> p : cl.datos) {
        os << p.second << '\n';
    }
    return os;
}

std::istream& operator>>(std::istream& is, ConjuntoLetras& cl) {
    std::string linea;
    int num_linea;
    while (getline(is, linea)) {
        Letra l;
        is >> l;
        cl.datos[l.get_caracter()] = l;
    }
    return is;
}