/**
 * @file KillerSudoku.h
 * @brief Fichero cabecera del TDA Killer Sudoku 
 */

#ifndef KILLER_SUDOKU_H
#define KILLER_SUDOKU_H

#include <string>

/**
 * @brief Definición del TDA @c KillerSudoku. el Killer Sudoku es una 
 *   variante del sudoku original que añade una limitación.
 *   Un tablero de sudoku clásico tiene 81 celdas, repartidas en 
 *   9 filas, 9 columnas y 9 cajas.
 * 
 *   En el Killer Sudoku hay además una cantidad indefinida de áreas,
 *   que deben cumplir:
 *      - El mismo número no puede aparecer más de una vez en cada área
 *      - La suma de todos los números dentro de un área debe alcanzar 
 *        un valor determinado
 *      - Cada celda del tablero debe formar parte de un solo área
 * 
 * @author Victoria
 * @date Octubre 2025
 */
class KillerSudoku {

private:
    static const int ROWS = 9;   /**< número de filas (el tablero del sudoku siempre tiene 9 filas)*/
    static const int COLS = 9;   /**< número de columnas (el tablero del sudoku siempre tiene 9 columnas)*/
    
    int **mainBoard;             /**< Tablero principal*/
    int **sumRestriction;        /**< Matriz que define la suma que se debe alcanzar en cada área*/
    int **sumRestrictionArea;    /**< Matriz que define las áreas de las restricciones*/

    /**
     * Matriz sobre la que se realizan los cálculos para resolver 
     * el sudoku. Cuando se construye un objeto @c KillerSudoku,
     * @c solvedSudoku será igual a @c mainBoard. Se hace esto porque
     * puede que el sudoku contenga pistas, y no interesa sobreescribir 
     * estas pistas.
     */
    int **solvedSudoku;

    /**
     * @brief Una fila es válida si contiene todos los números del 1 al 9 sin repeticiones
     * 
     * @param c fila a comprobar
     * 
     * @return @c true si la fila es válida, @c false si no
     */
    bool validRow(int row);

    /**
     * @brief Una columna es válida si contiene todos los números del 1 al 9 sin repeticiones
     * 
     * @param col columna a comprobar
     * 
     * @return @c true si la columna es válida, @c false si no
     */
    bool validColumn(int col);

    /**
     * @brief Una caja (box) es válida si contiene todos los números del 1 al 9 sin repeticiones.
     *   Una caja es un conjunto de 9 celdas, el tablero contiene 9 cajas.
     * 
     * @code
     * validBox(0,0) // comprueba si la caja de la esquina superior izquierda es válida
     * validBox(1,1) // comprueba si la caja central es válida
     * validBox(1,2) // comprueba si la caja derecho es válida
     * validBox(2,2) // comprueba si la caja de la esquina inferior derecha es válida
     * @endcode
     * 
     * @pre @c 0<=row<3
     * @pre @c 0<=col<3
     * 
     * @param boxRow fila de la caja (valor entre 0 y 2)
     * @param boxCol columna de la caja (valor entre 0 y 2)
     * 
     * @return @c true si la caja es válida, @c false si no
     */
    bool validBox(int boxRow, int boxCol);

    /**
     * @brief Comprueba si se cumple la restricción de suma en el área 
     *   que ocupa la posición dada
     * 
     * @param row fila a comprobar
     * @param col columna a comprobar
     * 
     * @return @c true si se cumple la restricción, @c false si no
     */
    bool sumRestrictionMet(int row, int col);

    /**
     * @brief Comprueba si un número @c value puede estar en una posición ( @c row, @c col ) sin 
     *   romper ninguna restricción
     * 
     * @param row fila
     * @param col columna
     * 
     * @return @c true si el valor es válido, @c false si no.
     */
    bool isNumberValidAtPosition(int row, int col, int value);

    /**
     * @brief Comprueba si la fila @c row contiene el valor @c value.
     * 
     * @return @c true, si la fila contiene el valor, @c false si no
     */
    bool rowHasValue(int row, int value);

    /**
     * @brief Comprueba si la columna @c col contiene el valor @c value
     * 
     * @return @c true, si la columna contiene el valor, @c false si no
     */
    bool colHasValue(int col, int value);

    /**
     * @brief Comprueba si la caja definida por ( @c row, @c col ) contiene el valor @c value
     * 
     * @pre @c 0<=row<3
     * @pre @c 0<=col<3
     * 
     * @param boxRow fila de la caja (valor entre 0 y 2)
     * @param boxCol columna de la caja (valor entre 0 y 2)
     * 
     * @return @c true, si la caja contiene el valor, @c false si no
     */
    bool boxHasValue(int boxRow, int boxCol, int value);

public:

    /**
     * @brief Genera un nuevo sudoku de forma aleatoria
     * 
     * @param solved Determina si se genera un sudoku resuelto o sin resolver
     */
    KillerSudoku(bool solved = false);

    /**
     * @brief Genera un sudoku a partir de un fichero de texto
     * 
     * @param file Ruta al fichero de texto
     */
    KillerSudoku(std::string file);

    /**
     * @brief Resuelve el sudoku. Por cada una de las celdas del tablero, 
     *   busca un valor que cumpla con todas las restricciones. Si ese
     *   valor no existe, da un paso atrás y repite la operación con un
     *   valor distinto.
     * 
     * @return @c true, si el sudoku se ha resuelto con éxito, 
     *   @c false si no es posible resolver el sudoku
     * 
     * @note En caso de que el sudoku ya esté resuelto, devuelve @c true sin modificar nada
     */
    bool solve();

    /**
     * @brief Devuelve una representación en texto del killer sudoku
     * 
     * @return Representación string del killer sudoku
     */
    std::string toString();
};

#endif