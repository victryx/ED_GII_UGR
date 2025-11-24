# STL: Tipos no lineales (Set, Map, Multiset y Multimap)

> Ver nota sobre [Functores](./functores.md)

## Conjunto (`set`)

Es un contenedor de **valores únicos** almacenados **en orden**.

### Métodos

Además de los aquí indicados, también contiene los métodos de iteradores (`begin`, `end`,
`cbegin`, `cend`, `rbegin`, `rend`, ...), constructor de copia y por defecto y operadores `==, !=, < , >, <=, >=, =`

- `set(iterator inicio, iterator final)` Constructor de rango
- `bool empty() const` Informa si el conjunto está vacío
- `void clear()` vacía el conjunto
- `size_type size()` Número de elementos
- `count(const T& clave)` Busca un elemento en el conjunto (devuelve `0` o `1`), eficiencia lineal
- `iterator find (const T& clave)` Busca un elemento en el conjunto, eficiencia logarítmica
- `pair<iterator, bool> insert(const T& clave)` Inserta un elemento si no estaba ya en el conjunto, eficiencia logarítmica
    - devuelve un iterador y un valor booleano
        - booleano: **`true`** Si el elemento NO estaba ya en el conjunto
        - iterador: señala al elemento insertado o al ya existente 
- `int erase(const T& clave)` Borra el elemento `clave` del conjunto
    - Devuelve `1` si el elemento estaba en el conjunto y ha sido eliminado
    - Devuelve `0` en caso contrario
- `void erase(iterator pos)` Borra el elemento en la posición `pos`
- `void erase(iterator primero, iterator ultimo)` Borra elementos en el rango `[primero, ultimo)`

Para `C++20` también tiene la función `erase_if`!!

### Ordenación

```c++
set<int> set_int; // Ordenación por defecto (creciente)
set<double, greater<double>> set_double; // Ordenación decreciente
set<long, less<long>> set_long; // Ordenación creciente

// Un functor puede ser class o struct, definimos comparación
// de strings tipo C
struct ltstr {
    bool operator()(const char* s1, const char* s2) const {
        strcmp(s1, s2) < 0;
    }
};

set<char*, ltstr> set_str;
```

### Ejemplos

```c++
set<int, greater<int>> st = {4, 3, 5, 1, 6, 2, 5};

pair<set<int, greater<int>>>::iterator status = st.insert(4);
if (status.second) {
    cout << "4 Insertado en pos." << distance(st.begin(), status.first) + 1 << endl;
} else {
    cout << "El 4 ya está en el set" << endl 
}

// Elimina los elementos desde el primero hasta el 3
st.erase(st.begin(), st.find(3))

// Eliminación de una clave
int n = st.erase(5);
cout << "Elementos eliminados: " << n << endl;
```

## "Bolsa" (`multiset`)

Como un `set`, pero permite elementos repetidos.
Mismas funciones que en `set` con algunas particularidades

- `count(const T& clave)` ahora puede devolver más de 1
- `erase(const T& clave)` ahora puede devolver más de 1
- `find(const T& clave)` apunta al **primer** elemento que coincide

Además de `find`, tenemos:
- `iterator lower_bound(const T& clave)` Devuelve un iterador al primer elemento _no menor_ que `clave`
- `iterator upper_bound(const T& clave)` Devuelve un iterador al primer elemento _mayor_ que `clave`
- `pair<iterator, iterator> equal_range(const T& clave)` Devuelve el rango de elementos iguales a `clave`

## Mapa o diccionario (`map`)

Contenedor que almacena **pares clave-valor**.

Contiene elementos que consisten en valores identificados por una clave. **No existen claves repetidas**. Los elementos del `map` están _ordenados_ según las claves.

### Métodos

Igual que en el set, tenemos constructor por defecto, constructor de copia y constructor de rango.

- `bool empty() const` `true` si el `map` está vacío
- `void clear()` Borra todos los elementos del `map`
- `void size()` Número de pares clave-valor en el `map`
- Los métodos `count`, `find`, `equal_range`, `erase` funcionan exáctamente igual que en el `set`, trabajan solo con las `claves`.
- `pair<iterator, bool> insert(const value_type& par)` Inserta un par clave-valor si NO existe en el `map`. Si la clave **ya existe** en el `map`, entonces **no hace nada**
    - El valor de retorno funciona igual que en `set`
- **`T& operator[](const key_type& k)`**
    - Si `k` no existe, **crea** un elemento con clave `k`
    - Devuelve una referencia al **valor** identificado por la clave `k`, podemos sustituirlo o modificarlo.


- [¿`insert`, `emplace` o `operator[]?`](https://stackoverflow.com/questions/17172080/insert-vs-emplace-vs-operator-in-c-map)

### Ordenación

La ordenación con functores funciona como en los `set`

```cpp
map<string, double> map_string_double;
map<double, int, less<double>> map_entero_real // Ordenado ascendentemente por la clave
map<char*, int, ltstr> set_str; // functor definido en el ejemplo de set
```

### Ejemplos

[Ejercicio corta_map](/ejercicios/002_ejercicios_TDA_no_lineales/ejercicios_resueltos/04-corta_map.cpp)
```c++
using namespace std;

void corta_map(map<int, list<int>>& m, int p, int q) {
    auto it_map = m.begin();
    // Elimina pares con clave incorrecta
    while (it_map != m.end()) {
        if (it_map->first < p || it_map->first >= q) {
            it_map = m.erase(it_map);
        } else {
            ++it_map;
        }
    }

    // Elimina pares con valor incorrecto
    it_map = m.begin();
    while (it_map != m.end()) {
        it_map->second.remove_if([p, q](int val) {
            return val < p || val >= q;
        });

        if (it_map->second.empty()) {
            it_map = m.erase(it_map);
        } else {
            ++it_map;
        }
    }
}
```

[Ejercicio contar](/ejercicios/002_ejercicios_TDA_no_lineales/ejercicios_resueltos/05-contar.cpp)
```c++
void contar(const vector<set<int>>& v, map<int, int>& veces) {
    for (int i = 0; i < v.size(); i++) {
        for (auto it = v[i].begin(); it != v[i].end(); ++it) {
            veces[*it]++;
        }
    }
}
```