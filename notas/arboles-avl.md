# Árboles AVL (Adelson-Velsky Landis)

> - Búsqueda, inserción y borrado: $O(log_2(n))$ 

Variación balanceada del Árbol de Búsqueda Binaria para mejorar la eficiencia de las búsquedas.

Cumple las siguientes propiedades:

1. Dado un nodo `x` se cumple que:
    - Todos los elementos en el subárbol izquierdo de `x` son **menores** que el elemento en `x`
    - Todos los elementos en el subárbol derecho de `x` son **mayores** que el elemento en `x`
2. Está equilibrado: Para un nodo `n`, la altura del subárbol `n->left` y la altura del subárbol `n->right` NO pueden variar en más de 1

En el peor de los casos, la busqueda se realiza en $O(log_2(n))$ (en cada iteración se descartan aproximadamente la mitad de los elementos).


El siguiente árbol no cumple las propiedades:

```mermaid
graph TD
    A((8))
    B((4))
    C((12))
    D((x))
    E((6))
    F((10))
    G((15))
    H((5))
	I((x))

    A --> B
    A --> C
    B --x D
    B --> E
    C --> F
    C --> G
    E --> H
    E --x I
```

1. La altura de un nodo `n` es la longitud del camino más largo desde `n` hasta una hoja.
1. Los nodos que no existen tienen altura `h = -1`
1. Las hojas tienen altura `h = 0`

- En el árbol anterior, existe un **desequilibrio en el nodo 4**: 
    - `altura(n4->left) = -1` 
    - `altura(n4->right) = 1`
    - Diferencia de altura de más de 1 (`-1 - 1 = -2 > -1`)

NO es un AVLsdfsdf

Ejemplo equilibrado:

```mermaid
graph TD
    A((8))
    B((4))
    C((12))
    D((3))
    E((6))
    F((10))
    G((15))
    H((5))
	I((x))

    A --> B
    A --> C
    B --> D
    B --> E
    C --> F
    C --> G
    E --> H
    E --x I
```

Este árbol SÍ es un AVL

## Operaciones sobre un AVL

Tendremos que implementar funciones auxiliares para **mantener equilibrado** el
árbol tras realizar inserciones y borrados.

### Búsqueda 

La búsqueda en un AVL es igual que en un ABB

### Inserción 

1. Buscar posición de inserción
2. Insertar elemento
3. Equilibrar el árbol (si es necesario)

### Borrado

1. Buscar posición del elemento borrado
2. Borrar el elemento (igual que en ABB)
3. Equilibrar el árbol (si es necesario)

### Equilibrio en inserciones y borrados

Para equilibrar un árbol desequilibrado, se aplican **rotaciones simples** o **rotaciones dobles**

- El nodo `n` está desequilibrado (`abs(altura(n->left) - altura(n->right)) > 1`)
- La inserción se ha hecho a **la izquierda de la izquierda** o a **la derecha de la derecha** (subárboles exteriores) => aplicamos rotación simple
- La inserción se ha hecho a **la derecha de la izquierda** o a **la izquierda de la derecha** (subárboles interiores) => aplicamos rotación doble

<!--
TODO: aquí faltan dibujitos
-->

- Caso A: desequilibrio en `n` al insertar a la _izquierda de la izquierda_ de `n`
    - **Rotación simple a la derecha**
- Caso D: desequilibrio en `n` al insertar a la _derecha de la derecha_ de `n`
    - **Rotación simple a la izquierda**
- Caso B: desequilibrio en `n` al insertar a la _derecha de la izquierda_ de `n`
    - **Rotación doble hacia la derecha:**
        - Rotación simple a la izquierda sobre `n->left`
        - Rotación simple a la derecha sobre `n`
- Caso C: desequilibrio en `n` al insertar a la _izquierda de la derecha_ de `n`
    - **Rotación doble hacia la izquierda:**
        - Rotación simple a la derecha sobre `n->right`
        - Rotación simple a la izquierda sobre `n`

### Ejemplo:

Construir AVL con el conjunto de datos:
`{1,2,3,4,5,6,7,15,14,13}`

1. Elementos `1`, `2` y `3`

```mermaid
graph TD
    A((1))
    D((x))
    B((2))
    E((x))
    C((3))

    A --x D
    A --> B
    B --x E
    B --> C
```

2. Nodo `1` desequilibrado: Rotación simple a la izquierda

```mermaid
graph TD
    B((2))
    A((1))
    C((3))

    B --> A
    B --> C
```

3. Nodos `4` y `5`

```mermaid
graph TD
    A((2))
    B((1))
    C((3))
    D((x))
    E((4))
    F((x))
    G((5))

    A --> B
    A --> C
    C --x D
    C --> E
    E --x F
    E --> G
```

4. Nodo `3` Desequilibrado: Rotación simple a la izquierda

```mermaid
graph TD
    A((2))
    B((1))
    C((4))
    D((3))
    E((5))

    A --> B
    A --> C
    C --> D
    C --> E
```

5. Nodo `6`

```mermaid
graph TD
    A((2))
    B((1))
    C((4))
    D((3))
    E((5))
    F((x))
    G((6))

    A --> B
    A --> C
    C --> D
    C --> E
    E --x F
    E --> G
```

6. Nodo `2` Desequilibrado: Rotación simple a la izquierda

```mermaid
graph TD
    A((4))
    B((2))
    C((5))
    D((1))
    E((3))
    F((x))
    G((6))

    A --> B
    A --> C
    B --> D
    B --> E
    C --x F
    C --> G
```

7. Insertar nodo `7`, desequilibrio en `5`: Rotación simple a la izquierda (2 pasos)

```mermaid
graph TD
    A((4))
    B((2))
    C((6))
    D((1))
    E((3))
    F((5))
    G((7))

    A --> B
    A --> C
    B --> D
    B --> E
    C --> F
    C --> G
```

8. Insertar nodos `15` y `14` 

```mermaid
graph TD
    A((4))
    B((2))
    C((6))
    D((1))
    E((3))
    F((5))
    G((7))
    H((x))
    I((15))
    J((14))
    K((x))

    A --> B
    A --> C
    B --> D
    B --> E
    C --> F
    C --> G
    G --> H
    G --> I
    I --> J
    I --> K
```

9. Desequilibrio en el nodo `7`: Rotación doble a la izquierda
    - Rotación simple a la derecha sobre `15`
    - Rotación simple a la izquierda sobre `7`

Primero, rotación simple a la derecha sobre `15`

```mermaid
graph TD
    A((4))
    B((2))
    C((6))
    D((1))
    E((3))
    F((5))
    G((7))
    H((x))
    I((14))
    J((x))
    K((15))

    A --> B
    A --> C
    B --> D
    B --> E
    C --> F
    C --> G
    G --> H
    G --> I
    I --> J
    I --> K
```

Segundo, rotación simple a la izquierda sobre `7`

```mermaid
graph TD
    A((4))
    B((2))
    C((6))
    D((1))
    E((3))
    F((5))
    G((14))
    H((7))
    I((15))

    A --> B
    A --> C
    B --> D
    B --> E
    C --> F
    C --> G
    G --> H
    G --> I
```