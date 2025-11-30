#include <iostream>
#include <map>
#include <set>

using namespace std;

/**
 * permite almacenar conjuntos de dias de interes
 * cada fecha es una cadena con formato dia-mes-año
 */
typedef set<string> ConjuntoDias;

/**
 * tipo de almacen para los eventos: la clave son dias y el valor el titulo de los
 * eventos
 */
typedef multimap<string, string> Agenda;

/**
 *  Imprime todos los elementos de un std::set<std::string> en la consola.
 *  @param s conjunto de cadenas a visualizar. Se pasa por referencia constante.
 */
void visualizarSet(const set<string> & s);

/**
 * metodo para seleccionar los dias con eventos de interes
 * @param agenda conjunto de eventos entre los que buscar
 * @param dias dias de interes para los que se hace la busqueda
 * @param prefijo prefijo para la busqueda
 * @param resultado almacen de resultados
 */
void dias_con_eventos_interes(const Agenda & agenda, const ConjuntoDias & dias,
                              const string & prefijo, set<string> & resultado);

int main(){
   Agenda agenda;

   // Enero
    agenda.insert({"10-01-2026", "Concierto: Sinfonía del Hielo (cuarteto Ártico"});
    agenda.insert({"25-01-2026", "Exposición: Retratos Olvidados de la era Neón"});

    // Febrero
    agenda.insert({"10-02-2026", "Estreno Película: El Laberinto de Papel"});
    agenda.insert({"25-02-2026", "Presentación de Libro: Crónicas del Sol Cero de Elena Márquez"});

    // Marzo
    agenda.insert({"10-03-2026", "Concierto: Ritmos del Despertar (Jazz Fusión)"});
    agenda.insert({"25-03-2026", "Exposición: Figuras Flotantes (Arte cinético)"});

    // Abril
    agenda.insert({"10-04-2026", "Estreno Película: La Semilla del Tiempo"});
    agenda.insert({"25-04-2026", "Presentación de Libro: El Código Silencioso de Daniel Soto"});

    // Mayo
    agenda.insert({"10-05-2026", "Concierto: Ópera Astral en el Teatro de las Nubes"});
    agenda.insert({"25-05-2026", "Exposición: Jardines de Cristal (Escultura botánica)"});

    // Junio
    agenda.insert({"10-06-2026", "Estreno Película: Escape a Terravista"});
    agenda.insert({"25-06-2026", "Presentación de Libro: Poemas del Meridiano de Sofía Cruz"});

    // Julio
    agenda.insert({"10-07-2026", "Festival Ondas Sonoras (Música electrónica al aire libre)"});
    agenda.insert({"25-07-2026", "Exposición: Arena y Sombra (Fotografía de paisajes áridos)"});

    // Agosto
    agenda.insert({"10-08-2026", "Estreno Película: Viento Cobre (Western futurista)"});
    agenda.insert({"25-08-2026", "Presentación de Libro: Bitácora del Último Faro de Iker Ruiz"});

    // Septiembre
    agenda.insert({"10-09-2026", "Concierto: Regreso a la Raíz (Música folclórica andina)"});
    agenda.insert({"25-09-2026", "Exposición: Maquinaria de Sueños (Instalaciones steampunk)"});

    // Octubre
    agenda.insert({"10-10-2026", "Estreno Película: Los Guardianes del Eco (Thriller psicológico)"});
    agenda.insert({"25-10-2026", "Presentación de Libro: Manual de Invenciones Absurdas\""});

    // Noviembre
    agenda.insert({"10-11-2026", "Concierto: Baladas de Medianoche por Luna Roja"});
    agenda.insert({"25-11-2026", "Exposición: Abstracciones de Humo (Pintura contemporánea)"});

    // Diciembre
    agenda.insert({"10-12-2026", "Estreno Película: El Regalo Estelar (Familiar)"});
    agenda.insert({"25-12-2026", "Presentación de Libro: Recetas para un Solsticio (Gastronomía)"});

   // se incluye un conjunto de dias de interes
   ConjuntoDias dias_interes = {"10-01-2026", "10-02-2026", "10-05-2026",
                                 "25-07-2026","10-08-2026", "25-09-2026"};

   // se crea el conjunto resultado para estrenos
   set<string> resultadoEstreno;
   dias_con_eventos_interes(agenda, dias_interes, "Estreno",resultadoEstreno);

   // se visualiza el resultado
   visualizarSet(resultadoEstreno);

   // conjunto para presentaciones
   set<string> resultadoPresentacion;
   dias_con_eventos_interes(agenda, dias_interes, "Presentación",resultadoPresentacion);

   // se visualiza el resultado
   visualizarSet(resultadoPresentacion);

   // conjunto para conciertos
   set<string> resultadoConcierto;
   dias_interes.insert("25-01-2026");
   dias_interes.insert("25-02-2026");
   dias_interes.insert("10-03-2026");
   dias_con_eventos_interes(agenda, dias_interes, "Concierto",resultadoConcierto);

   // se visualiza el resultado
   visualizarSet(resultadoConcierto);
}

/**
 *  Imprime todos los elementos de un std::set<std::string> en la consola.
 *  @param s conjunto de cadenas a visualizar. Se pasa por referencia constante.
 */
void visualizarSet(const set<string> & s) {
    for (string s : s) {
        cout << s << " ";
    }
    cout << endl;
}

/**
 * FUNCIÓN A IMPLEMENTAR
 * 
 * metodo para seleccionar los dias con eventos de interes
 * @param agenda conjunto de eventos entre los que buscar
 * @param dias dias de interes para los que se hace la busqueda
 * @param prefijo prefijo para la busqueda
 * @param resultado almacen de resultados
 */
void dias_con_eventos_interes(const Agenda & agenda, const ConjuntoDias & dias,
                              const string & prefijo, set<string> & resultado) {
    for (pair<string, string> p : agenda) {
        if (dias.count(p.first) && p.second.substr(0, prefijo.size()) == prefijo) {
            resultado.insert(p.first);
        }
    }
}