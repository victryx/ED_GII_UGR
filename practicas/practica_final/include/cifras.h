/**
 * @file cifras.h
 * @brief Fichero de cabecera del TDA Cifras
 * 
 * @author Victoria López
 * @author Alejandro Moreno
 */
#ifndef __CIFRAS_SET_H__
#define __CIFRAS_SET_H__

#include <iostream>
#include <vector>
#include <string>
#include <set>       // Necesario para multiset
#include <cmath>    
#include <climits>   
#include <cstdlib> // rand, srand

using namespace std;

class Cifras {
private:
    multiset<int> conjunto;      /**< Almacena los números disponibles para jugar (ej: 6, 8, 10, 9, 4, 75)*/

    string mejor_expresion;      /**< Guarda los pasos */
    int mejor_valor;             /**< Mejor valor obtenido (más cercano al objetivo)*/
    int minima_distancia;        /**< distancia entre el objetivo y el valor obtenido*/

    /**
     * @brief Función auxiliar recursiva
     * Busca combinaciones de operaciones para llegar al objetivo.
     *
     * @param estado_actual Los números disponibles en este paso de la recursión.
     * @param objetivo El número que queremos alcanzar.
     * @param historial String con las operaciones realizadas hasta ahora.
     */
    void buscarSoluciones(multiset<int> estado_actual, int objetivo, string historial);

public:
    /**
     * @brief Constructor por defecto. Crea un conjunto vacío.
     */
    Cifras();

    /**
     * @brief Inserta un número manualmente en el conjunto.
     *
     * @param n Número a insertar.
     */
    void insertar(int n);

    /**
     * @brief Genera los 6 números aleatorios siguiendo las reglas del juego.
     */
    void generarAleatorio();

    /**
     * @brief Imprime los números disponibles actualmente en el conjunto.
     */
    void imprimir() const;

    /**
     * @brief Intenta resolver el juego para llegar al número objetivo.
     * Busca la solución exacta o la más cercana posible.
     * 
     * @param objetivo El número de 3 cifras a conseguir.
     * @retval true si encontró el número exacto, 
     * @retval false si es una aproximación.
     */
    bool resolver(int objetivo);

    /**
     * @brief Devuelve la cadena con las operaciones de la mejor solución.
     * 
     * @return cadena que representa las operaciones realizadas para llegar a la solución
     */
    string getMejorExpresion() const;

    /**
     * @brief Devuelve el valor numérico de la mejor solución conseguida.
     * 
     * @return Valor numérico de la solución obtenida
     */
    int getMejorValor() const;

    /**
     * @brief Devuelve una copia del conjunto de números
     */
    multiset<int> getConjunto() const;

    /**
     * @brief Devuelve cuántos números hay disponibles en el conjunto.
     * 
     * @return tamaño del conjunto
     */
    int tamano() const;

    /**
     * @brief Elimina todos los elementos del conjunto
     */
    void limpiar();
};

#endif
