/**
 * @file maxstack.h
 * @brief  Archivo de especificación del TDA MaxStack
 * @author []
 * @author []
 */


#include <iostream>
#include <queue>
using namespace std;

#ifndef MAXSTACK_H
#define MAXSTACK_H

/**
 * @struct element
 * @brief Estructura para representar una pila con máximos
 */
struct element
{
    int value;   /**< Valor real almacenado */
    int maximum; /**< Valor máximo alcanzado en la estructura*/
};

/**
 * @brief TDA MaxStack
 * 
 * Estructura que almacena una pila de elementos y su máximo
 */
class MaxStack
{
private:
    queue<element> elementos; /**< Cola que almacena los elementos */
    queue<int> nMaximos;      /**< Cola para almacenar los máximos */
    int contador = 0;

public:
    /** 
     * @brief Inserta un nuevo elemento en la pila
     * @param value Elemento a añadir
     */
    void push(int value);

    /**
     * @brief Elimina el elemento en la cima de la pila
     */
    void pop();

    /**
     * @brief Devuelve el elemento en la cima de la pila
     * @return la cima de la pila
     */
    element top() const;

    /**
     * @brief Devuelve el valor máximo actual en la pila
     * @return El valor máximo
     */
    int max() const;

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
ostream &operator<<(ostream &os, const element &e);

#endif // MAXSTACK_H