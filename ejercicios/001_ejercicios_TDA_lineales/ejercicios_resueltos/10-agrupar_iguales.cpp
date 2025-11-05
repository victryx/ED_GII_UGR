/**
 * Dada una lista de enteros  L con elementos repetidos implementar una función
 * que construya a partir de ella una lista ordenada de listas, de forma
 * que en la lista resultado los elementos iguales se agrupen en la
 * misma sublista. No puede usarse ningún algorítmo de
 * ordenación, ni la libreria algorithm y como estructura auxiliar solo
 * se permite usar el tipo list.
 *
 * Ejemplo:
 *
 * l1 = {1, 3, 4, 5, 6, 3, 2, 1, 4, 5, 5, 1, 1}
 *   => {{1,1,1}, {2}, {3,3}, {4,4}, {5,5,5}, {6} }
 */

#include <list>
#include <iostream>

using namespace std;

/**
 * Solución propia
 */
list<list<int>> agrupariguales(const list<int> &l) {
    list<list<int>> output;
    auto it1 = l.begin();

    while (it1 != l.end()) {
        int val = *it1;
        auto insert_list = output.begin();
        while (insert_list != output.end() && insert_list->front() < val) {
            insert_list++;
        }

        if (insert_list == output.end() || insert_list->front() > val) {
            output.insert(insert_list, {val});
        } else {
            insert_list->push_back(val);
        }
        ++it1;
    }
    return output;
}

template <typename T>
void Imprimir(T comienzo, T fin)
{
    for (auto it = comienzo; it != fin; ++it)
    {
        cout << *it << " ";
    }
}


/**
 * Solución del pdf
 */
list<list<int>> agrupariguales_sol(const list<int> & L){
    list<list<int>> out;
    for (auto it=L.begin(); it!=L.end(); ++it){
        bool enc=false; 
        bool salir=false;
        auto it_out=out.begin();

        while(!enc && !salir && it_out!=out.end()){
            if ( it_out->front() == *it ){
                enc=true;
                it_out->push_back(*it);
            } else if ( it_out->front() > *it){
                salir=true;
            } else {
                ++it_out;
            }
        }

        if (!enc){
            list<int> aux(1,*it);
            out.insert(it_out,aux);
        }
    
    }
    return out;
}

int main()
{
    list<int> L = {1, 3, 4, 5, 6, 3, 2, 1, 4, 5, 5, 1, 1};
    cout << "Lista original ";
    Imprimir(L.begin(), L.end());
    cout << endl;
    list<list<int>> salida = agrupariguales(L);
    for (auto it = salida.begin(); it != salida.end(); ++it)
    {
        Imprimir(it->begin(), it->end());
        cout << endl;
    }
}