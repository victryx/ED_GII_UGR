#include <iostream>
#include <list>
#include <cassert>
using namespace std;

/**
 * @brief Determina si la cola contiene una única subida y una única bajada estricta.
 * Se considera que una secuencia tiene forma de montaña si:
 * 
 * - Los elementos aumentan estrictamente hasta un punto máximo
 * - Después de ese punto, los elementos disminuyen estrictamente
 * - No puede haber valores iguales
 * - No puede volver a subir una vez que empieza a bajar
 * - Debe haber mínimo 3 elementos en la lista
 */
bool hayMontana(const list<int>& l) {
    if (l.size() < 3) return false;

    bool valid; // para comprobar el caso en el que la lista es estrictamente descendente
    list<int>::const_iterator max;
    list<int>::const_iterator it = l.begin();
    list<int>::const_iterator prev = it;
    ++it;

    while (it != l.end() && *prev < *it) {
        ++prev;
        ++it;
        valid = true; 
    }

    max = prev;

    while (it != l.end() && *prev > *it) {
        ++prev;
        ++it;
    }

    return max != prev && it == l.end() && valid;
}

/****************************
 *         TESTS
 ****************************/
int main() {
    cout << "=== TEST hayZigZag con assert ===" << endl;

    int testNum = 1;

    cout << "Pasando el test " << testNum++ << endl;
    assert(hayMontana({1,3,5,4,3}) == true);

    cout << "Pasando el test " << testNum++ << endl;
    assert(hayMontana({5,4,3,2}) == false);

    cout << "Pasando el test " << testNum++ << endl;
    assert(hayMontana({1,2,3,4}) == false);

    cout << "Pasando el test " << testNum++ << endl;
    assert(hayMontana({1,3,3,2}) == false);

    cout << "Pasando el test " << testNum++ << endl;
    assert(hayMontana({1,3}) == false);

    cout << "Pasando el test " << testNum++ << endl;
    assert(hayMontana({-3,4,10,21,22,13,12,5,3,1}) == true);

    cout << "✅ Todos los tests pasaron correctamente." << endl;

    return 0;
}
