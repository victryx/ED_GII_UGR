/**
 * @file test_letras.cpp
 * @brief Programa principal del problema de las letras
 *
 * @author Victoria López
 * @author Alejandro Moreno
 */

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <map>
#include <unordered_set>
#include <algorithm>

#include "diccionario.h"
#include "letra.h"
#include "conjunto_letras.h"
#include "bolsa_letras.h"

/**
 * @brief Calcula la cantidad de puntos que se obtienen por una solución, devuelve -1 si
 * la solución no es válida. 
 * 
 * @param caracteres Lista con los caracteres que puede contener la solución
 * @param d Diccionario (palabras válidas)
 * @param cl ConjuntoLetras, para conocer la puntuación que otorga cada carácter
 * @param solucion solución a comprobar
 * @return Puntos obtenidos por la solucion @c solucion, o -1 si no es una solución válida
 */
int puntos_solucion(std::list<char> caracteres, const Diccionario& d, const ConjuntoLetras& cl, const std::string& solucion);

/**
 * @brief Función recursiva usada por posibles_soluciones.
 * Comprueba los posibles strings que se pueden formar con los caracteres
 * dados, si un string es solución válida, lo inserta en el mapa de soluciones.
 * 
 * Por ejemplo si la lista inicial de caracteres es c = {'a', 'b', 'c'} y d es el diccionario.
 * Esquema de las llamadas recursivas:
 * @code 
 * s = ""; c = {a, b, c}
 *      s = "a"; c = {b,c}          # "a" en d.palabras; "a" en d.prefijos => añado solución y sigo buscando
 *          s = "ab"; c = {c}       # "ab" en d.prefijos => sigo buscando
 *              s = "abc"; c = {}   # "abc"
 *          s = "ac"; c = {b}       # "ac" en d.prefijos => sigo buscando
 *              s = "acb"; c = {}   # "acb"
 *      s = "b"; c = {a,c}          # "b" en d.palabras, "b" en d.prefijos => añado solución y sigo buscando
 *          s = "ba"; c = {c}       # "ba" en d.prefijos => sigo buscando
 *              s = "bac"; c = {}   # "bac" 
 *          s = "bc"; c = {a}       # "bc" no está en d.prefijos => dejo de buscar
 *      s = "c"; c = {a,b}          # "c" en d.palabras, "c" en d.prefijos => añado solución y sigo buscando
 *          s = "ca"; c = {b}       # "ca" en d.palabras, "ca" en d.prefijos => añado solución y sigo buscando
 *              s = "cab"; c = {}   # "cab"
 *          s = "cb"; c = {a}       # "cb" no está en d.prefijos => dejo de buscar
 * @endcode
 *  
 * @param todas_soluciones @c map<string,int> en el que añadir las soluciones (solución -> puntuación)
 * @param caracteres lista de caracteres modificada por las llamadas recursivas
 * @param palabra combinación de caracteres generada por la llamada recursiva
 * @param d (constante) Diccionario
 * @param cl (constante) Conjunto de letras, para obtener puntuación de @c palabra 
 * @param caracteres_iniciales (constante) lista de caracteres iniciales, para obtener la puntuación de @c palabra 
 * @param visitados unordered_set de string, para evitar comprobar varias veces la misma combinación 
 *   (útil si la lista de caracteres tiene varios caracteres repetidos)
 * 
 */
void posibles_soluciones_util(std::map<std::string, int>& todas_soluciones, std::list<char> caracteres,
    std::string palabra, const Diccionario& d, const ConjuntoLetras& cl, const std::list<char>& caracteres_iniciales, std::unordered_set<std::string>& visitados);

/**
 * @brief Obtiene todas las palabras válidas que se pueden generar con una lista de caracteres
 * 
 * Esta función llama a la función recursiva @c posibles_soluciones_util
 * 
 * @param caracteres Lista de caracteres con los que se forman palabras
 * @param d Diccionario que contiene todas las palabras válidas
 * @param cl Conjunto de letras, para conocer la puntuación de cada solución
 * @return Un @c map<string,int> con todas las posibles soluciones (solucion -> puntuacion)
 */
std::map<std::string, int> posibles_soluciones(const std::list<char>& caracteres, const Diccionario& d, const ConjuntoLetras& cl);

/**
 * @brief Dado un mapa de soluciones (solución-puntuación), devuelve solo las soluciones con
 * mejor valor de puntuación.
 * 
 * @param soluciones mapa de soluciones
 * @return mapa con las mejores soluciones por puntuación
 */
std::map<std::string, int> mejores_soluciones_puntuacion(std::map<std::string, int>& soluciones);

/**
 * @brief Dado un mapa de soluciones (solución-puntuación), devuelve solo las soluciones de mayor
 * longitud
 * 
 * @param soluciones mapa de soluciones
 * @return vector de strings con las mejores soluciones por longitud
 */
std::vector<std::string> mejores_soluciones_longitud(std::map<std::string, int>& soluciones);

/**
 * @brief Crea los objetos Diccionario, ConjuntoLetras y BolsaLetras a partir de archivos de 
 * texto almacenados en disco
 * 
 * @param d Objeto Diccionario que crear a partir del archivo de diccionario
 * @param cl Objeto ConjuntoLetras que crear a partir del archivo de letras
 * @param bl Objeto BolsaLetras
 * @param path_dic ruta al archivo de diccionario
 * @param path_letras ruta al archivo de letras
 * 
 * @retval 0 si se han leído correctamente 
 * @retval 1 si ha habido un error
 */
int read_files(Diccionario& d, ConjuntoLetras& cl, BolsaLetras& bl, std::string path_dic, std::string path_letras);

int main(int argc, char const* argv[]) {
    Diccionario diccionario;
    ConjuntoLetras conjuntoLetras;
    BolsaLetras bolsaLetras;
    bool sigue_jugando = true;

    if (argc != 5) {
        std::cerr << "uso: letras [diccionario] [letras] [longitud] [L|P]" << std::endl;;
        return 1;
    }

    // Leer modo
    char mode = argv[4][0];
    if (mode != 'L' && mode != 'P') {
        std::cerr << "modo incorrecto [L o P]" << std::endl;;
        return 1;
    }

    // Leer longitud de la lista de palabras
    int longitud_lista = atoi(argv[3]);
    if (longitud_lista <= 0) {
        std::cerr << "Longitud no válida" << std::endl;;
        return 1;
    }

    // Cargar archivos
    if (read_files(diccionario, conjuntoLetras, bolsaLetras, argv[1], argv[2])) {
        std::cerr << "Problema leyendo los archivos" << std::endl;;
        return 1;
    }

    // Bucle principal
    while (sigue_jugando) {

        // Seleccionar letras aleatorias
        std::list<char> letras_elegidas = bolsaLetras.obtener_letras(longitud_lista);

        // Mostrar por pantalla letras seleccionadas 
        std::cout << "\n\n--------------------------------\n";
        std::cout << "Letras: ";
        for (char c : letras_elegidas) {
            std::cout << c << '\t';
        }
        std::cout << std::endl;

        // Comprobar solución de usuario
        std::string solucion;
        std::cout << "Introduce tu solución: ";
        std::cin >> solucion;

        int puntuacion = puntos_solucion(letras_elegidas, diccionario, conjuntoLetras, solucion); // puntos de la solución del usuario
        int longitud_sol = solucion.size();
        std::cout << "Tu solución: " << solucion << " ";

        if (puntuacion == -1) {
            std::cout << "no válida";
        } else if (mode == 'P') {
            std::cout << "(" << puntuacion << " puntos)";
        } else if (mode == 'L') {
            std::cout << "(" << longitud_sol << " caracteres)";
        }
        std::cout << std::endl;

        // Obtener todas las posibles soluciones
        std::map<std::string, int> todas_soluciones = posibles_soluciones(letras_elegidas, diccionario, conjuntoLetras);

        std::cout << "Mis soluciones son: " << std::endl;
        if (mode == 'P') {
            std::map<std::string, int> mejores_puntuacion = mejores_soluciones_puntuacion(todas_soluciones);
            for (std::pair<std::string, int> p : mejores_puntuacion) {
                std::cout << p.first << " (" << p.second << " puntos)\n";
            }
        }
        if (mode == 'L') {
            std::vector<std::string> mejores_longitud = mejores_soluciones_longitud(todas_soluciones);
            for (std::string s : mejores_longitud) {
                std::cout << s << " (" << s.size() << " caracteres)\n";
            }
        }

        std::string respuesta;
        std::cout << "¿Quieres seguir jugando[S/N]? ";
        std::cin >> respuesta;
        sigue_jugando = respuesta == "S" || respuesta == "s";
    }

    return 0;
}

int puntos_solucion(std::list<char> caracteres, const Diccionario& d, const ConjuntoLetras& cl, const std::string& solucion) {
    if (!d.esta(solucion)) {
        return -1;
    }

    int puntuacion = 0;
    for (int i = 0; i < solucion.size() && puntuacion != -1; i++) {
        std::list<char>::iterator it = std::find(caracteres.begin(), caracteres.end(), solucion[i]);

        if (it != caracteres.end()) {
            caracteres.erase(it);
            puntuacion += cl.get_puntuacion(solucion[i]);
        } else {
            puntuacion = -1;
        }
    }

    return puntuacion;
}

void posibles_soluciones_util(std::map<std::string, int>& todas_soluciones, std::list<char> caracteres,
    std::string palabra, const Diccionario& d, const ConjuntoLetras& cl, const std::list<char>& caracteres_iniciales, std::unordered_set<std::string>& visitados) {

    for (int i = 0; i < caracteres.size(); i++) {
        std::string nueva_palabra = palabra;
        std::list<char> nuevos_caracteres(caracteres);

        auto it_erase = nuevos_caracteres.begin();
        advance(it_erase, i);
        nueva_palabra += *it_erase;
        nuevos_caracteres.erase(it_erase);  // borra

        int puntuacion = puntos_solucion(caracteres_iniciales, d, cl, nueva_palabra);
        if (puntuacion != -1) {
            todas_soluciones[nueva_palabra] = puntuacion;
        }

        // Si el diccionario contiene el prefijo y no lo hemos mirado ya, seguimos buscando.
        bool no_visitado = visitados.count(nueva_palabra) == 0;
        visitados.insert(nueva_palabra);
        if (d.contiene_prefijo(nueva_palabra) && no_visitado) {
            posibles_soluciones_util(todas_soluciones, nuevos_caracteres, nueva_palabra, d, cl, caracteres_iniciales, visitados);
        }
    }
}

std::map<std::string, int> posibles_soluciones(const std::list<char>& caracteres, const Diccionario& d, const ConjuntoLetras& cl) {
    std::map<std::string, int> solucion_puntuacion;
    std::unordered_set<std::string> visitados;
    posibles_soluciones_util(solucion_puntuacion, caracteres, "", d, cl, caracteres, visitados); // llamada a la función recursiva
    return solucion_puntuacion;
}

std::map<std::string, int> mejores_soluciones_puntuacion(std::map<std::string, int>& soluciones) {
    std::map<std::string, int> mejores_por_puntuacion;
    int mejor_puntuacion = 0;
    for (std::pair<std::string, int> p : soluciones) {
        if (p.second > mejor_puntuacion) {
            mejor_puntuacion = p.second;
        }
    }

    for (std::pair<std::string, int> p : soluciones) {
        if (p.second == mejor_puntuacion) {
            mejores_por_puntuacion.insert(p);
        }
    }

    return mejores_por_puntuacion;
}

std::vector<std::string> mejores_soluciones_longitud(std::map<std::string, int>& soluciones) {
    std::vector<std::string> mejores_por_longitud;
    int mejor_longitud = 0;
    for (std::pair<std::string, int> p : soluciones) {
        if (p.first.size() > mejor_longitud) {
            mejor_longitud = p.first.size();
        }
    }

    for (std::pair<std::string, int> p : soluciones) {
        if (p.first.size() == mejor_longitud) {
            mejores_por_longitud.push_back(p.first);
        }
    }

    return mejores_por_longitud;
}

int read_files(Diccionario& d, ConjuntoLetras& cl, BolsaLetras& bl, std::string path_dic, std::string path_letras) {

    // Leer diccionario
    std::ifstream file_diccionario(path_dic);
    if (!file_diccionario) {
        std::cerr << "Imposible abrir el diccionario" << std::endl;
        return 1;
    }
    file_diccionario >> d;
    file_diccionario.close();

    // Leer conjunto de letras y puntuaciones
    std::ifstream file_letras(path_letras);
    if (!file_letras) {
        std::cerr << "Imposible abrir el fichero de letras" << std::endl;
        return 1;
    }
    file_letras >> cl;
    file_letras.close();

    bl = BolsaLetras(cl);

    return 0;
}
