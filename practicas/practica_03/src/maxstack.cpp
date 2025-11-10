/**
 * @file maxstack.cpp
 * @brief  Archivo de implementación del TDA MaxStack
 * @author []
 * @author []
 */


#include "maxstack.h"
#include <stack>

// Método de intercambio auxiliar

using namespace std;

// Método empty: Comprueba si la pila está vacía
bool MaxStack::empty() const{
    return elementos.empty();
}

// Método max: Devuelve el valor máximo actual en la pila
int MaxStack::max() const{
    if(!empty()){
        return nMaximos.back();
    }
}

// Metódo top: Devuelve el elemento en la cima de la pila
element MaxStack::top() const{
    if(!empty()){
        return elementos.back();
    }
}

// Método push: Inserta un elemento en la pila
void MaxStack::push(int value){

    if(!nMaximos.empty()){
        if(nMaximos.back() < value){
            nMaximos.push(value);
        }
    }else{
        nMaximos.push(value);
    }

    elementos.push({value,nMaximos.back()});
}

// Método pop: Elimina el elemento en la cima de la pila
void MaxStack::pop(){
    if (elementos.empty()) {
        return;
    }

    queue<element> aux_elementos;
    int num_elementos = elementos.size();

    // Mueve todos menos el último
    for (int i = 0; i < num_elementos - 1; ++i) {
        aux_elementos.push(elementos.front());
        elementos.pop();
    }
    
    if (elementos.front().value == elementos.front().maximum) {
        if (elementos.front().value == nMaximos.back()) {
            queue<int> aux_nMaximos;
            int num_maximos = nMaximos.size();
            
            // Mueve todos menos el último
            for (int i = 0; i < num_maximos - 1; ++i) {
                aux_nMaximos.push(nMaximos.front());
                nMaximos.pop();
            }

            // Elimina el máximo actual (que queda en nMaximos.front())
            nMaximos.pop();
            
            // Devuelve los N-1 máximos
            nMaximos = aux_nMaximos;
        }

    }

    elementos.pop();

    elementos = aux_elementos;
}

ostream& operator<<(ostream & os, const element & e){
    return (os << e.value << "," << e.maximum);
}


