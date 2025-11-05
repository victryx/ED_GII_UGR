/**
 * Construir una función que agrupe en la primera parte de la lista
 * los elementos menores que k y en la segunda los mayores o iguales
 * 
 * Ejemplo
 * si L = {1,3,4,14,11,9,7,16,25,19,7,8,9}, K = 8
 * debe quedar L = {1,3,4,7,7,9,11,16,25,19,14,8,9}
 * 
 */

#include <list>
#include <iostream>

using namespace std;

void dividir_lista(list<int> &l, int k) {
    list<int>::iterator left = l.begin();
    list<int>::iterator right = l.end();
    right--;

    while (left != right) {
        while (*left < k && left != right)
            left++;

        while (*right >= k && left != right)
            right--;
        
        swap(*left, *right);

    }
}

int main() {
    list<int> l = {1,3,4,14,11,9,7,16,25,19,7,8,9};
    dividir_lista(l, 8);

    for (int i : l) {
        cout << i << endl;
    }
    

}
