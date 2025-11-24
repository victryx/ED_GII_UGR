/**
 * @file vector_pilas.h
 * @brief Fichero cabecera del TDA vector_pilas
 */

#ifndef VECTOR_PILAS
#define VECTOR_PILAS

#include <vector>

using namespace std;

/**
 * @class vector_pilas vector_pilas.h
 * @brief Definición del TDA @c vector_pilas, varias pilas almacenadas
 *   en un mismo vector
 * 
 * Definición del TDA @c vector_pilas. Un objeto @c vector_pilas
 * almacena una cantidad de pilas (pila 1, pila 2, ..., pila n) 
 * en una única estructura de datos de tipo @c vector. Se encarga de
 * gestionar el espacio libre en el vector para cada pila. 
 * 
 * @date November 2025
 * @author Victoria
 */
template <typename T>
class vector_pilas {

private:
    vector<T> data; /**< Vector en el que se almacenan todos los datos */
    unsigned n;     /**< Número de pilas almacenadas en el vector*/

    vector<unsigned> tops;  /**< índices de los topes de las pilas */
    vector<unsigned> bases; /**< índices de las bases de las pilas */
    vector<unsigned> sizes; /**< tamaños de las pilas */

    /**
     * @brief Genera espacio entre pilas del vector
     * 
     * Desplaza el vector @c times veces hacia la derecha desde el
     * índice @c position. Se encarga de actualizar los vectores @c tops,
     * @c bases y @c sizes para las pilas que han sido desplazadas.
     * Se usa este método para generar espacio libre entre pilas.
     * 
     * @param position índice a partir del que se genera el espacio libre
     *                 ( @c data[position] no se modifica)
     * @param times    espacio libre a generar
     * @pre @c position es el tope de alguna pila o una posición no ocupada
     */
    void shift_right(unsigned position, unsigned times);

    /**
     * @brief Elimina todos los elementos de @c data entre @c first y 
     * @c last (ambos incluidos) y reduce el tamaño del vector @c data.
     * 
     * Usado para eliminar espacio vacío entre pilas, se encarga de
     * actualizar * los vectores de índices @c tops y @c bases para 
     * las pilas desplazadas
     * 
     * @param first Primer índice a eliminar
     * @param last  Último índice a eliminar
     * @pre   first <= last < data.size()
     */
    void remove_range(unsigned first, unsigned last);

    /**
     * @brief Espacio disponible para la pila pasada por parámetro
     * 
     * @param numpila Pila sobre la que opera el método 
     * @return espacio disponible para la pila @c numpila
     * @pre numpila >= 0 y numpila < n
     */
    int available_space(unsigned numpila);
public:
    /**
     * @brief Constructor por defecto
     */
    vector_pilas()

    /**
     * @brief Constructor con número de pilas
     * @param n número inicial de pilas
     */
    vector_pilas(unsigned n);

    /**
     * @brief Añade una nueva pila al vector de pilas, 
     * @return Índice de la pila recién creada
     */
    unsigned nueva_pila();

    /**
     * @brief Inserta un elemento en la pila indicada por parámetro
     * 
     * Si no hay más espacio disponible para esta pila, se desplaza
     * el vector @c data a la derecha @c sizes[numpila] veces
     * 
     * @param numpila Pila sobre la que opera el método 
     * @param elem    Elemento a insertar
     * @pre numpila >= 0 y numpila < n
     */
    void push(unsigned numpila, const T & elem);

    /**
     * @brief Elimina el elemento en el tope de la pila indicada 
     *   por parámetro. Si la pila está vacía, no hace nada.
     * 
     * Si la pila está ocupando menos de un cuarto del espacio que
     * tiene disponible, se reduce a la mitad su espacio disponible 
     * y se redimensiona el vector
     * 
     * @param numpila pila sobre la que opera el método
     * @pre numpila >= 0 y numpila < n
     */
    void pop(unsigned numpila);

    /**
     * @brief Devuelve el tope de la pila indicada por parámetro.
     *   Si la pila está vacía, el valor de retorno no está definido.
     * 
     * @param numpila pila sobre la que opera el método 
     * @return tope de la pila indicada por parámetro
     * @pre numpila >= 0 y numpila < n, 
     */
    T top(unsigned numpila);

    /**
     * @brief Comprueba si la pila indicada por parámetro está vacía
     * 
     * @param numpila pila sobre la que opera el método 
     * @retval true  La pila @c numpila está vacía
     * @retval false La pila @c numpila no está vacía
     * @pre numpila >= 0 y numpila < n
     */
    bool empty(unsigned numpila);
};

#endif // VECTOR_PILAS