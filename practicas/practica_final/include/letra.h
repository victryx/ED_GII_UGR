/**
 * @file letra.h
 * @brief Fichero de cabecera del TDA letra
 * 
 * @author Victoria López
 * @author Alejandro Moreno
 */
#ifndef __LETRA_H__
#define __LETRA_H__

#include <iostream>

/**
 * @brief Contiene información sobre una letra en el juego
 *
 * Contiene información sobre un determinado carácter del juego de las
 * letras. En concreto, almacena información sobre el número de repeticiones de
 * la letra en la partida y de la puntuación que otorga al utilizarse en una
 * palabra
 */
class Letra {
private:
    char caracter;    /**< Caracter representado */
    int repeticiones; /**< Repeticiones del carácter en el conjunto de letras*/
    int puntuacion;   /**< Puntuación obtenida por la letra*/
public:
    /**
     * @brief Constructor por defecto de Letra
     */
    Letra();
    /**
     * @brief Constructor de letra

     * @param c Caracter
     * @param r Repeticiones
     * @param p Puntuación
     */
    Letra(char c, int r, int p);

    /**
     * @brief Getter del atributo caracter
     * @return Caracter representado
     */
    char get_caracter() const;

    /**
     * @brief Getter del atributo repeticiones
     * @return Número de veces que se repite el caracter
     */
    int get_repeticiones() const;

    /**
     * @brief Getter del atributo puntuación
     * @return Puntuación asociada a la letra
     */
    int get_puntuacion() const;

    /**
     * @brief Sobrecarga del operador de extracción para la clase @c Letra
     * @param is stream de entrada
     * @param l letra
     */
    friend std::istream& operator>>(std::istream& is, Letra& l);

    /**
     * @brief Sobrecarga del operador de inserción para la clase @c Letra
     * @param is stream de salida
     * @param l letra
     */
    friend std::ostream& operator<<(std::ostream& os, const Letra& l);
};

#endif
