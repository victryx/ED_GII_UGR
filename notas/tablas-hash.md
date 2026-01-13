# Hashing

## Introducción

- Usando estructuras que trabajan por **comparación**, podemos lograr una 
eficiencia de $O(log_2(n))$ para la operación de **búsqueda**
- Las **tablas hash** mejoran la eficiencia de la operación de **búsqueda** hasta $O(1)$

## Funcionamiento

- Una **tabla Hash** es un contenedor asociativo (clave-valor)
- El hashing consiste con una **función** $h(k)$, que dada la _clave_ `k`, devuelve
    la localización del _valor_ en la estructura. $h(k)$ se denomina **función hash**
    - Calcular esta función es $O(1)$, luego la operación de búsqueda es $O(1)$
- Se asigna a cada elemento del conjunto una posición **única** dentro de la **tabla**
- Se producen **colisiones** cuando a una sola _posición_ en la tabla se le asigna 
    más de un elemento, esto ocurre porque la función hash puede asignar el mismo valor
    para claves diferentes. Veremos mecanismos para resolver estas colisiones

## Tipos de funciones hash

$$
h : C \rightarrow Z
$$

- $C$ El conjunto de las posibles claves
- $Z$ El conjunto de los enteros positivos (índices sobre la tabla hash)

La función $h$ se debe definir de forma que cumpla varios requisitos:

- Debe ser rápida de calcular
- Debe tomar todos los posibles valores
- Debe distribuir de forma lo más aleatoria posible las claves
- Debe minimizar el número de colisiones

Existen varios métodos para definir funciones hash

### Truncamiento

Consiste en eliminar dígitos de la clave (la tabla debe tener tamaño potencia de 10):

$$
h(123456879) = 123\\
h(121567034) = 121
$$

También se puede realizar truncamiento a nivel de bits (la tabla debe tener tamaño potencia de 2)

### Plegado

Consiste en dividir una clave en dos o más partes y sumarlas

Ejemplo: 2 funciones hash que usan plegado.

$$
h_1(123456) = 123 + 456 = 579\\
h_2(123456789) = 123 + 456 + 789 = 1368
$$

### Multiplicación

Consiste en dividir una clave en dos o más partes y multiplicarlas

Ejemplo: Tabla de tamaño 10000 y claves de 9 dígitos, usa multiplicación y truncamiento.

$$
h(\underline{123}456\underline{789}) = 123 \times 789 = \underline{9}7047 \Rightarrow 7047
$$

Este método tiende a esparcir las claves, generando menos colisiones

Variantes:

#### Cuadrado del centro

Se seleccionan varias cifras del centro de la clave y se calcula su cuadrado, opcionalmente se usa truncamiento.

$$
h(123\underline{456}789) = 456^2 = \underline{20}7936 \Rightarrow 7936
$$

#### Centro del cuadrado

Se calcula el cuadrado de la clave y se seleccionan varias cifras del centro

$$
h(1234) = 1234^2 = 15\underline{2275}6 \Rightarrow 2275
$$

### Resto de la división

Llamamos $M$ al **tamaño** de la tabla

Consiste en tomar el resto de la división de la clave entre $M$ ($h(k)=k\%M$).
Este método no requiere truncamiento.

La mejor elección es tomar un $M$ número primo mayor que el número de claves

Ejemplo, tabla hash con $M = 11$

$$
h(k) = k \% 11\\
\\
h(12) = 1\\
h(21) = 10\\
h(68) = 2\\
h(38) = 5\\
h(52) = 8\\
h(70) = 4\\
h(44) = 0\\
h(18) = 7\\
$$

## Resolución de colisiones

Una colisión ocurre cuando dos claves diferentes tienen el mismo valor hash

Dadas dos claves $k_i$ y $k_j$, ocurre una colisión si $h(k_i) = h(k_j)$ siendo $k_i \neq k_j$

Una tabla muy grande evita colisiones, pero desperdicia mucho espacio.
Una tabla muy pequeña aprovecha el espacio pero genera muchas colisiones

### Hashing abierto

Consiste en construir una **lista de claves sinónimas** para cada índice de la tabla.

El tamaño de la tabla es **fijo**, suele implementarse cono un vector estático de punteros a listas dinámicas

Para la operación de **búsqueda** calculamos el valor hash de la clave y buscamos en la 
correspondiente lista enlazada. 

### Hashing cerrado

Se usa un vector para representar la tabla hash, cuando se produce una colisión, 
asignamos otro valor hash a la clave hasta encontrar un hueco (**rehashing**)

- **búsquedas:** Se sigue misma secuencia de la función hash usada para inserción
- **borrados:** La casilla se marca como _borrada_
    - Para la **inserción**, borrada y libre son equivalentes (hay hueco)
    - Para la **búsqueda**, borrada y ocupada son equivalentes (hay que seguir buscando)

- **redimensionamiento**: Cuando la tabla hash se desborda, se vuelve a construir con
  un nuevo tamaño (`M`) y una nueva función hash.

#### Rehashing lineal

$$
h_i(k) = [h(k) + (i - 1)] \% M, i = 2, 3, \cdots
$$

- Si hay colisión para una clave $k$ con $h(k)$
- Generamos los valores $h_2(k)$, $h_3(k)$, ... hasta que no haya colisión
- Cuando para un $t$, $h_t(k)$ no se produzca colisión, termina el rehashing

El rehashing lineal tiende a crear sucesiones de casillas ocupadas contiguas,
esto reduce la eficiencia de inserciones y borrados.

**Búsqueda**

```
buscar(k) {
    int i = 0;
    pos = h(k,i); // h_i(k)
    while (!vacia(pos) && (clave(pos) != k || borrada(pos))) {
        i++;
        pos = h(k,i); // siguiente función hash
    }

    if (clave(pos) == k) {
        return pos;
    } 
    return -1; // no existe
}
```

### Sondeo aleatorio

$$\begin{align}
h_i(k) = (h(k) + (i-1) * C) \bmod M,\  i = 2, 3, \cdots \\
h_i(k) = [h_{i-1}(k) + C] \bmod M,\  i = 2, 3,   \cdots
\end{align}$$

- $h(k)$ valor de la función hash
- $M$ tamaño de la tabla
- $C > 1$  y primo relativo con $M$

Crea agrupaciones secundarias de orden C

#### Rehashing doble

$$\begin{align}
h_i(k) = (h_{i-1}(k) + h_0(k)) \bmod M,\ i=2,3,\cdots \\
\\
h_0(k) = 1 + (k \bmod (M-2)) \\
h_1(k) = h(k)
\end{align}$$

- Puede haber otras elecciones de $h_0(k)$, siempre que:
    - h_0(k) no sea constante
    - h_0(k) sea distinta de 0
- Buena función cuando $M$ y $M - 2$ son primos relativos

Ejemplo 

$$\begin{align}
h_1(72) = 7 \\
\text{casilla 7 ya está ocupada:} \\
h_2(72) = (h_1(72) + h_0(72)) \bmod 13 = (7+7) \bmod 13 = 1
\end{align}$$