
#include "pila_doble_pi.h"
#include <cassert>

template <typename T>
pila_doble<T>::pila_doble() {
    data = vector<T>(INITIAL_SIZE);
    even_stack_top = 0;
    odd_stack_top = 1;
}

template <typename T>
bool pila_doble<T>::empty(int numpila) {
    assert(numpila == 0 || numpila == 1);
    if (numpila == 0)
        return even_stack_top == 0;
    return odd_stack_top == 1;
}

template <typename T>
void pila_doble<T>::push_even_stack(const T& elem) {
    data[even_stack_top] = elem;
    even_stack_top += 2;
    if (even_stack_top <= data.)
}

template <typename T>
void pila_doble<T>::push(int numpila, const T& elem) {
    assert(numpila == 0 || numpila == 1);
    if (numpila == 0) {
        push_even_stack(elem);
    } else {
        push_odd_stack(elem);
    }
}

template <typename T>
void pila_doble<T>::pop(int numpila) {
    assert(numpila == 0 || numpila == 1);
    if (numpila == 0) {
        pop_even_stack();
    } else {
        pop_odd_stack();
    }
}