/**
 * @file diccionario.h
 * @brief Fichero de cabecera del TDA diccionario
 * 
 * @author Victoria López
 * @author Alejandro Moreno
 */

#ifndef __DICCIONARIO_H__
#define __DICCIONARIO_H__

#include <string>
#include <iostream>
#include <unordered_set>
#include <vector>

/**
 * @class Diccionario
 * @brief Almacena las palabras leídas de un fichero de texto y permite iterar 
 * sobre ellas
 * 
 * El diccionario está representado con un @c unordered_set de @c string, para 
 * poder comprobar en tiempo constante si el diccionario contiene una palabra 
 * determinada. 
 * 
 * Para agilizar la búsqueda en el juego de las palabras, contiene otro @c unordered_set
 * con los prefijos de cada palabra.
 */
class Diccionario {
private:
    /**
     * @brief Set con todas las palabras del diccionario
     */
    std::unordered_set<std::string> palabras;   

    /**
     * @brief Set con los prefijos de cada palabra del diccionario
     * 
     * Por ejemplo, si se inserta la palabra 'sonata' en el set palabras,
     * en el set prefijos se insertan ['s', 'so', 'son', 'sona', 'sonat']
     * 
     * El propósito de esta estructura es agilizar la búsqueda en el juego 
     * de las palabras
     */
    std::unordered_set<std::string> prefijos;

public:

    /**
     * @brief Construye un diccionario sin elementos
     */
    Diccionario();

    /**
     * @brief Devuelve el tamaño (cantidad de palabras) del diccionario
     * 
     * @return cantidad de palabras en el diccionario
     */
    int size() const;

    /**
     * @brief Devuelve todas las palabras del diccionario que contienen @c longitud caracteres
     * 
     * @param longitud número de caracteres de las palabras de salida
     * @return Un vector con las palabras de longitud especificada
     */
    std::vector<std::string> palabrasLongitud(int longitud) const;

    /**
     * @brief indica si una palabra está o no en el diccionario
     * 
     * @param palabra palabra a comprobar
     * @retval true si la palabra está contenida en el diccionario
     * @retval false si la palabra no está contenida en el diccionario
     */
    bool esta(std::string palabra) const;

    /**
     * @brief comprueba si alguna palabra del diccionario empieza por @c prefijo 
     * 
     * @param prefijo prefijo a comprobar
     * @retval true si alguna palabra del diccionario comienza por @c prefijo
     * @retval false si ninguna palabra del diccionario comienza por @c prefijo
     */
    bool contiene_prefijo(std::string prefijo) const;

    /**
     * @brief Escribe un diccionario en un stream de salida
     * 
     * @param os stream de salida
     * @param d objeto diccionario
     * @return el stream de salida
     */
    friend std::ostream& operator<<(std::ostream& os, const Diccionario& d);

    /**
     * @brief Lee un diccionario de un stream de entrada
     *
     * @param os stream de entrada
     * @param d objeto diccionario
     * @return el stream de entrada
     */
    friend std::istream& operator>>(std::istream& is, Diccionario& d);

    /**
     * @brief clase iterador para recorrer las palabras del diccionario de forma
     * DESORDENADA
     */
    class iterator {
    private:
        std::unordered_set<std::string>::iterator it;
    public:
        iterator();
        std::string operator *();
        iterator& operator ++();
        bool operator ==(const iterator& i);
        bool operator !=(const iterator& i);
        friend class Diccionario;
    };

    /**
     * @brief Devuelve un iterador que apunta al primer elemento del diccionario
     * los elementos NO están ordenados por orden alfabético
     * 
     * @return un iterador al primer elemento del diccionario
     */
    iterator begin();

    /**
     * @brief Devuelve un iterador que apunta al último elemento del diccionario
     * los elementos NO están ordenados por orden alfabético
     * 
     * @return un iterador al último elemento del diccionario
     */
    iterator end();
};


#endif
