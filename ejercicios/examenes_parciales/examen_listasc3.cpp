#include <iostream>
#include <list>
#include <cassert>
using namespace std;

/**
 * @brief Devuelve true si la lista sigue un zigzag estricto (> < > < o < > < > ...)
 */
bool hayZigZag(const list<int>& L) {
    if (L.size() < 3) return false;
    
    auto prev = L.begin();
    auto next = prev;
    next++;

    int counter = *prev < *next ? -1 : 1;

    while (next != L.end()) {
        if ((*prev - *next) * counter <= 0)
            return false;

        counter *= -1;
        ++prev;
        ++next;
    }

    return true;
}

/****************************
 *         TESTS
 ****************************/
int main() {
    cout << "=== TEST hayZigZag con assert ===" << endl;

    int testNum = 1;

    cout << "Pasando el test " << testNum++ << endl;
    assert(hayZigZag({1,3,2,4,3}) == true);

    cout << "Pasando el test " << testNum++ << endl;
    assert(hayZigZag({5,2,6,1,7}) == true);

    cout << "Pasando el test " << testNum++ << endl;
    assert(hayZigZag({1,3,5}) == false);

    cout << "Pasando el test " << testNum++ << endl;
    assert(hayZigZag({5,3,1}) == false);

    cout << "Pasando el test " << testNum++ << endl;
    assert(hayZigZag({1,2,2,3}) == false);

    cout << "Pasando el test " << testNum++ << endl;
    assert(hayZigZag({1,4,2,3,1}) == true);

    cout << "Pasando el test " << testNum++ << endl;
    assert(hayZigZag({9,1,8,2,7,3}) == true);

    cout << "Pasando el test " << testNum++ << endl;
    assert(hayZigZag({1,0,1,0,1,0}) == true);

    cout << "Pasando el test " << testNum++ << endl;
    assert(hayZigZag({1,0,1,1,0}) == false);

    cout << "Pasando el test " << testNum++ << endl;
    assert(hayZigZag({1,2}) == false);

    cout << "Pasando el test " << testNum++ << endl;
    assert(hayZigZag({3,1,4,2,5,3,6}) == true);

    cout << "✅ Todos los tests pasaron correctamente." << endl;

    return 0;
}
