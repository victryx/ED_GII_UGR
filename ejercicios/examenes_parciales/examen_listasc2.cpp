#include <iostream>
#include <list>
#include <cassert>
using namespace std;

/**
 * @brief Determina si la cola contiene una única bajada y una única subida estricta.
 * Se considera que una secuencia tiene forma de valle si:
 * 
 * - Los elementos disminuyen estrictamente hasta un punto mínimo
 * - Después de ese punto, los elementos aumentan estrictamente
 * - No puede haber valores iguales
 * - No puede volver a bajar una vez que empieza a subir
 * - Debe haber mínimo 3 elementos en la lista
 */
bool hayValle(const list<int>& l) {
    if (l.size() < 3) return false;

    bool valid; // para comprobar el caso en el que la lista es estrictamente ascendente
    list<int>::const_iterator min;
    list<int>::const_iterator prev = l.cbegin();
    list<int>::const_iterator it = next(prev);

    while (it != l.end() && *prev > *it) {
        ++prev;
        ++it;
        valid = true; 
    }

    min = prev;

    while (it != l.end() && *prev < *it) {
        ++prev;
        ++it;
    }

    return min != prev && it == l.end() && valid;
}

/****************************
 *         TESTS
 ****************************/
int main() {
    cout << "=== TEST HayValle con assert ===" << endl;

    int testNum = 1;

    cout << "Pasando el test " << testNum++ << endl;
    assert(hayValle({1,3,5,4,3}) == false);

    cout << "Pasando el test " << testNum++ << endl;
    assert(hayValle({5,4,3,2,1,3,5}) == true);

    cout << "Pasando el test " << testNum++ << endl;
    assert(hayValle({25,1,2,3,4}) == true);

    cout << "Pasando el test " << testNum++ << endl;
    assert(hayValle({1,3,3,2}) == false);

    cout << "Pasando el test " << testNum++ << endl;
    assert(hayValle({1,3}) == false);

    cout << "Pasando el test " << testNum++ << endl;
    assert(hayValle({5,4,3,2,1}) == false);

    cout << "Pasando el test " << testNum++ << endl;
    assert(hayValle({1,2,3,4,5}) == false);

    cout << "Pasando el test " << testNum++ << endl;
    assert(hayValle({-3,4,10,21,22,13,12,5,3,1}) == false);

    cout << "Pasando el test " << testNum++ << endl;
    assert(hayValle({20, 15, 10, -1, -10, -5, -1, 0}) == true);

    cout << "✅ Todos los tests pasaron correctamente." << endl;

    return 0;
}
