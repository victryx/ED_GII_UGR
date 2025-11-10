/**
 * @file maxqueue.h
 * @brief  Archivo de especificación del TDA MaxQueue
 * @author []
 * @author []
 */

#ifndef MAXQUEUE_H
#define MAXQUEUE_H

#include <list>
#include <iostream>

/**
 * @struct element
 * @brief Estructura para representar una cola con máximos
 */
struct element {
    int value;   /**< Valor real almacenado */
    int maximum; /**< Valor máximo alcanzado en la estructura*/
};


/**
 * @brief TDA MaxQueue
 * 
 * Estructura que almacena una cola de elementos y su máximo
 */
class MaxQueue {
private:
    std::list<element> queue; /**< Lista empleada para almacenar la cola*/

    /**
     * @brief Actualiza el máximo en todos los elementos de la cola
     */
    void updateMax(int max);

    /**
     * @brief Para encontrar el nuevo máximo cuando se elimina un elemento
     */
    int findMax();

public:

    /**
     * @brief Método para consultar el frente de la cola
     * @return El frente de la cola
     */
    element & front();

    /**
     * @brief Método para consultar el frente de la cola
     * @return El frente de la cola
     */
    const element & front() const;

    /**
     * @brief Elimina el elemento en el frente de la cola
     */
    void pop();

    /**
     * @brief Inserta un elemento en el final de la cola
     * @param val Elemento a añadir
     */
    void push(int val);

    /**
     * @brief Devuelve el número de elementos que contiene la cola
     * @return Número de elementos en la cola
     */
    int size() const;

    /**
     * @brief Comprueba si la cola esta vacía
     * @retval true si la cola está vacía
     * @retval false si la cola no está vacía
     */
    bool empty() const;
    
};

/** 
 * @brief Sobrecarga del operador << para imprimir elementos
 */
std::ostream& operator<<(std::ostream& outStream, const element& e);

#endif // MAXQUEUE_H
