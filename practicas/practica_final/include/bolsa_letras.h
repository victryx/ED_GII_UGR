/**
 * @file bolsa_letras.h
 * @brief fichero cabecera del TDA bolsa_letras
 * 
 * @author Victoria López
 * @author Alejandro Moreno
 */

#ifndef __BOLSA_LETRAS_H__
#define __BOLSA_LETRAS_H__

#include "conjunto_letras.h"
#include "letra.h"
#include <list>
#include <vector>

/**
 * @brief Almacena caracteres correspondientes a una letra de un conjunto de letras
 *
 * Cada carácter aparece en un objeto BolsaLetras tantas veces como indique 
 * el atributo @c repeticiones del objeto @c Letra. Las letras de la bolsa de letras
 * están en orden aleatorio.
 */
class BolsaLetras {
private:
    std::vector<char> letras; /*< Vector con las letras del conjunto */
public:
    /**
     * @brief constructor de @c BolsaLetras a partir de @c ConjuntoLetras
     * 
     * Un objeto BolsaLetras se construye a partir de un ConjuntoLetras
     */
    BolsaLetras(const ConjuntoLetras& cl);

    /**
     * @brief Constructor por defector de @c BolsaLetras
     */
    BolsaLetras();

    /**
     * @brief Devuelve una lista de letras en orden aleatorio
     * 
     * @param cantidad tamaño de la lista de letras generada
     * @return Una lista con @c cantidad letras
     */
    std::list<char> obtener_letras(int cantidad);

    /**
     * @brief Escribe un objeto @c BolsaLetras en un stream de salida
     * 
     * @param os stream de salida
     * @param bl objeto @c BolsaLetras
     * @return el stream de salida
     */
    friend std::ostream& operator<<(std::ostream& os, const BolsaLetras& bl);
};

#endif
