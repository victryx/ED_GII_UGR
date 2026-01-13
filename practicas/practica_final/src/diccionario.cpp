/**
 * @file diccionario.cpp
 * @brief Fichero de implementación del TDA diccionario
 * 
 * @author Victoria López
 * @author Alejandro Moreno
 */

#include "diccionario.h"

#include <string>
#include <fstream>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>


int Diccionario::size() const {
    return palabras.size();
}

Diccionario::Diccionario() {}

std::vector<std::string> Diccionario::palabrasLongitud(int longitud) const {
    std::vector<std::string> out;
    for(std::string s : palabras) {
        if (s.size() == longitud) {
            out.push_back(s);
        }
    }
    return out;
}

bool Diccionario::esta(std::string palabra) const {
    transform(palabra.begin(), palabra.end(), palabra.begin(), ::tolower); // a minúsculas
    return palabras.count(palabra);
}

bool Diccionario::contiene_prefijo(std::string prefijo) const {
    return prefijos.count(prefijo);
}

Diccionario::iterator::iterator() { }

std::string Diccionario::iterator::operator*() {
    return *it;
}

Diccionario::iterator& Diccionario::iterator::operator++() {
    ++it;
    return *this;
}

bool Diccionario::iterator::operator==(const iterator& i) {
    return it == i.it;
}

bool Diccionario::iterator::operator!=(const iterator& i) {
    return it != i.it;
}

Diccionario::iterator Diccionario::begin() {
    iterator i;
    i.it = palabras.begin();
    return i;
}

Diccionario::iterator Diccionario::end() {
    iterator i;
    i.it = palabras.end();
    return i;
}

std::istream& operator>>(std::istream& in, Diccionario& d) {
    std::string palabra;
    while (getline(in, palabra)) {
        d.palabras.insert(palabra); // insertar palabra
        for (int i = palabra.size() - 1; i >= 0; i--) {
            d.prefijos.insert(palabra.substr(0,i)); // insertar prefijos
        }
    }
    return in;
}

std::ostream& operator<<(std::ostream& os, const Diccionario& d) {
    for (std::string s : d.palabras) {
        os << s << std::endl;
    }
    return os;
}

