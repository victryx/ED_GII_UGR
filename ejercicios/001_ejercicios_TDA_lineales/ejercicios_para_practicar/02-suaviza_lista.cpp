/**
 * 
 * 
 */

#include <list>
#include <iostream>

using namespace std;


int max_dev(list<int> &l) {

    list<int>::iterator it = l.begin();

    auto max = it;
    auto min = it;
    it++;
    while (it != l.end()) {
        if (*it > *max) {
            max = it;
        }
        if (*it < *min) {

        }

        it++;
    }
}

int suaviza_lista(list<int> &l, int m, int maxdif) {
    auto left = l.begin();
    auto right = left;

    int cmin, cmax;

    while (right != l.end()) {
        while (distance(right, left) < m - 1) {

            right++;
        }
    }
}


int suaviza_lista_brute(list<int> &l, int m, int maxdif) {
    auto it = l.begin();
    auto last = l.end();
    advance(last, -m);
    while (it != last) {
        auto right = it;
        for (int i = 0; i < m - 1; i++) {
            /* code */
        }
        
        ++it;
    }
}