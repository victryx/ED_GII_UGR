/**
 * Construir una función 
 * 
 * void compacta(list<int> &l, stack<int> &s);
 * 
 * que va tomando un elemento entero n de s. Si n es positivo, saca n elementos
 * de la lista l, y los reemplaza por su suma. Hasta que stack s esté vacío o 
 * lista l esté vacia.
 */

#include <list>
#include <stack>
#include <iostream>

using namespace std;


void compacta(list<int> &l, stack<int> &s) {
    list<int> result_list;
    while (!s.empty() && !l.empty()) {
        int n = s.top();
        int sum = 0;
        s.pop();
        for (int i = 0; i < n && !l.empty(); i++) {
            sum += l.back();
            l.pop_back();
        }
        if (n > 0) {
            result_list.push_front(sum);
        }
    }
    l.splice(l.end(),result_list);
}

int main(int argc, char const *argv[]) {
    list<int> l = {1,3,2,1,4,5,3,2,4,1};
    list<int> stack_ini = {3,2,-1,0,2,5,2,-3};
    stack<int> s;
    while (!stack_ini.empty()) {
        s.push(stack_ini.back());
        stack_ini.pop_back();
    }
    
    compacta(l, s);

    for(int i : l) {
        cout << " " << i;
    }
    cout << endl;

    return 0;
}
