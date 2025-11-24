# Árboles

Un árbol se compone de _nodos_:
- **Raíz**, no tiene nodo padre, está en la parte superior de la jerarquía.
- **Hoja**, no tienen nodos hijo, están en la parte inferior de la jerarquía.
- **Interior**, el resto de nodos.

```mermaid
graph TD
    A((A))
    B((B))
    C((C))
    D((D))
    E((E))
    F((F))
    G((G))
    H((H))
	I((I))
	class A l1
	class B,C l2
	class D,E,F,G l3
	class H,I l4
    A --> B
    A --> C
    B --> D
    B --> E
    C --> F
    C --> G
    D --> H
    D --> I
    
	classDef l1 fill: #ffffff, stroke: #000000
	classDef l2 fill: #fa9de1
	classDef l3 fill: #a9e9f5 
	classDef l4 fill: #ffffff
```

- Nodo raíz: `A`
- Nodos hoja: `H` `I` `E` `F` `G`
- Nivel 0: `A`
- Nivel 1: `B` `C`
- Nivel 2: `D` `E` `F` `G`
- Nivel 3: `H` `I`