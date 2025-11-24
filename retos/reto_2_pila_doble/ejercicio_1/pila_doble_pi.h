/**
 * @file pila_doble_par_impar.h
 * @brief Fichero cabecera del TDA pila_doble
 */

#ifndef PILA_DOBLE
#define PILA_DOBLE

#include <vector>

using namespace std;

/**
 * @brief Definición del TDA @c pila_doble, dos pilas almacenadas
 *   en un mismo vector
 * 
 * Definición del TDA @c pila_doble. Un objeto @c pila_doble
 * almacena dos pilas (pila_0 y pila_1) en una única estructura de
 * datos de tipo @c vector.
 *
 * - Los elementos de pila_0 se almacenan en los índices pares del vector
 *   (0, 2, 4, ...)
 * - Los elementos de pila_1 se almacenan en los índices impares del vector
 *   (1, 3, 5, ...)
 *
 * El inconveniente de esta solución es que hará un uso menos eficiente del
 * espacio cuanto mayor sea la diferencia de tamaño entre las dos pilas.
 * Por otra parte, la implementación será muy sencilla.
 *
 * @author Victoria
 * @date Noviembre 2025
 */
template <typename T>
class pila_doble {
private:
    const int INITIAL_SIZE = 20; /**< Tamaño inicial del vector @c data*/

    vector<T> data;              /**< Vector en el que se almacenan los datos */

    /**
     * Tope de la pila de índices pares (pila_0)
     */
    int even_stack_top;

    /**
     * Tope de la pila de índices impares (pila_1)
     */
    int odd_stack_top;


    /**
     * @brief Número de celdas libres disponibles para la pila 
     *   pasada por parámetro
     * 
     * @param numpila Pila sobre la que opera el método (0 o 1)
     * @return Espacio disponible para la pida indicada por parámetro
     * @pre numpila = 0 o numpila = 1
     */
    int free_space(int numpila);

    /**
     * @brief Inserta un elemento en el índice @c even_stack_top del vector 
     *   @c data, duplica el tamaño del vector si no hay más espacio libre
     * @param elem Elemento a insertar en la pila de pares (pila_0)
     */
    void push_even_stack(const T& elem);

    /**
     * @brief Inserta un elemento en el índice @c even_stack_top del vector 
     *   @c data duplica el tamaño del vector si no hay más espacio libre
     * @param elem Elemento a insertar en la pila de pares (pila_0)
     */
    void push_odd_stack(const T& elem);

    /**
     * @brief Elimina el elemento en el tope de la pila de índices pares
     */
    void pop_even_stack();

    /**
     * @brief Elimina el elemento en el tope de la pila de índices impares
     */
    void pop_odd_stack();

    /**
     * @brief Devuelve el elemento en la posición even_stack_top - 2
     *   del vector @c data
     * @return Tope de la pila de pares (pila_0)
     */
    T top_even_stack();

    /**
     * @brief Devuelve el elemento en la posición odd_stack_top - 2
     *   del vector @c data
     * @return Tope de la pila de impares (pila_1)
     */
    T top_odd_stack();


public:

    /**
     * @brief Constructor por defecto, inicializa el vector con tamaño
     *   @c INITIAL_SIZE
     */
    pila_doble();

    /**
     * @brief Inserta un elemento en la pila indicada por parámetro
     *
     * @param numpila Pila sobre la que opera el método (0 o 1)
     * @param elem Elemento a insertar
     * @pre numpila = 0 o numpila = 1
     */
    void push(int numpila, const T& elem);

    /**
     * @brief Elimina el elemento en el tope de la pila indicada
     *   por parámetro
     *
     * @param numpila pila sobre la que opera el método (0 o 1)
     * @pre numpila = 0 o numpila = 1
     */
    void pop(int numpila);

    /**
     * @brief Devuelve el tope de la pila indicada por parámetro
     *
     * @param numpila pila sobre la que opera el método (0 o 1)
     * @return tope de la pila indicada por parámetro
     * @pre numpila = 0 o numpila = 1
     */
    T top(int numpila);

    /**
     * @brief Comprueba si la pila indicada por parámetro está vacía
     *
     * @param numpila pila sobre la que opera el método (0 o 1)
     * @retval true La pila @c numpila está vacía
     * @retval false La pila @c numpila no está vacía
     * @pre numpila = 0 o numpila = 1
     */
    bool empty(int numpila);

};

#endif // PILA_DOBLE