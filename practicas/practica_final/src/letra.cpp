/**
 * @file letra.cpp
 * @brief Fichero de implementación del TDA letra
 * 
 * @author Victoria López
 * @author Alejandro Moreno
 */
#include "letra.h"

Letra::Letra() {}

Letra::Letra(char c, int r, int p)
        : caracter(c), repeticiones(r), puntuacion(p) {};

char Letra::get_caracter() const {
    return caracter;
}

int Letra::get_repeticiones() const {
    return repeticiones;
}

int Letra::get_puntuacion() const {
    return puntuacion;
}

std::istream& operator>>(std::istream& is, Letra& l) {
    is >> l.caracter >> l.repeticiones >> l.puntuacion;
    l.caracter = tolower(l.caracter);
    return is;
}

std::ostream& operator<<(std::ostream& os, const Letra& l) {
    return (os << (char)toupper(l.caracter) << '\t' << l.repeticiones << '\t' << l.puntuacion);
}