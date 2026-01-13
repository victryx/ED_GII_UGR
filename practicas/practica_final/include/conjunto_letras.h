/**
 * @file conjunto_letras.h
 * @brief Fichero de cabecera del TDA ConjuntoLetras
 * 
 * @author Victoria López
 * @author Alejandro Moreno
 */

#ifndef __CONJUNTO_LETRAS_H__
#define __CONJUNTO_LETRAS_H__
#include "letra.h"
#include <map>
#include <string>
#include <iostream>


/**
 * @brief representa un conjunto de letras, asocia cada caracter
 * a un objeto Letra que contiene repeticiones y puntuacińo
 *
 * Este TDA representa un conjunto de letras, con la información necesaria para
 * jugar una partida al juego de las letras, es decir, el número de repeticiones
 * que tenemos de la letra y la puntuación que dicha letra otorga cuando se
 * utiliza en una palabra
 */
class ConjuntoLetras {
private:
    std::map<char, Letra> datos; /*< Mapa que representa el conjunto de letras */

public:
    /**
     * @brief Constructor por defecto de @c ConjuntoLetras
     */
    ConjuntoLetras();

    /**
     * @brief Comprueba si un carácter está en el conjunto
     * 
     * @param ch caracter a comprobar
     * @retval true si el caracter @c ch está en el conjunto
     * @retval false si el caracter @c ch no está en el conjunto
     */
    bool esta_en_conjunto(char ch) const;

    /**
     * @brief Devuelve la puntuación asociada a un caracter
     * 
     * @param ch caracter a comprobar
     * @return La puntuación asociada al caracter @c ch
     */
    int get_puntuacion(char ch) const;

    /**
     * @brief Devuelve el número de repeticiones de un caracter
     * 
     * @param ch caracter a comprobar
     * @return Número de repeticiones del caracter @c ch
     */
    int get_repeticiones(char ch) const;

    /**
     * @brief Inserta una letra en el conjunto
     * 
     * Asocia un caracter con un objeto letra
     * 
     * @param letra Letra a insertar
     */
    void inserta_letra(const Letra& letra);

    /**
     * @brief Escribe un objeto @c ConjuntoLetras en un stream de salida
     * 
     * @param os stream de salida
     * @param cl objeto @c ConjuntoLetras
     * @return el stream de salida
     */
    friend std::ostream& operator<<(std::ostream& os, const ConjuntoLetras& cl);

    /**
     * @brief Lee un objeto @c ConjuntoLetras de un stream de entrada
     *
     * @param os stream de entrada
     * @param cl objeto @c ConjuntoLetras
     * @return el stream de entrada
     */
    friend std::istream& operator>>(std::istream& is, ConjuntoLetras& cl);
};

#endif
