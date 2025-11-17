/**
 * @file 01-separa.cpp
 *
 *
 */

#include <list>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

void separa(const map<string, int>& M, list<string>& L, queue<string>& Q, stack< pair<string, int>>& S) {
    for (pair<string, int> p : M) {
        if (p.second < 0) {
            L.push_back(p.first);
        }
        if (p.second == 0) {
            Q.push(p.first);
        }
        if (p.second > 0) {
            S.push(p);
        }
    }
}

void printList(const list<string>& L) {
    for (string num : L) {
        cout << num << " ";
    }
    cout << endl;
}
void printStack(stack<pair<string, int>> P) {
    while (!P.empty()) {
        cout << P.top().first << " "; cout << P.top().second << " ";
        P.pop();
    }cout << endl;
}
void printQueue(queue<string> C) {
    while (!C.empty()) {
        cout << C.front() << " ";
        C.pop();
    }
    cout << endl;
}
int main() {
    map<string, int> M = {
        {"A", -2}, {"B", -1}, {"C", 0}, {"D", 0}, {"E", 1}, {"F", 2}, {"G", 3}
    };
    list<string> L;
    queue<string> Q;
    stack<pair<string, int>> S;
    separa(M, L, Q, S);
    cout << "Lista: ";
    cout << endl;
    printList(L);
    cout << endl;
    cout << "Pila: ";
    cout << endl;
    printStack(S);
    cout << endl;
    cout << "Cola: ";
    cout << endl;
    printQueue(Q);
    cout << endl;
    return 0;
}