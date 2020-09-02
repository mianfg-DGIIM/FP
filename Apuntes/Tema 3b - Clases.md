
# Tema 3b: Clases

***Paradigma de programación***

## Módulos de código fuente

Bloques con tareas relacionadas distribuidas en **unidades de compilación**:

- **Visión externa, cabecera:** en fichero `.h`
- **Visión interna, implementación:** en fichero `.cpp`

## Tipos estructurados de datos: `struct`

Tipos estructurados heterogéneos.

```c++
struct {
	int num;
	int den;
} num_racional;
```

Acceder a los campos:

```c++
num_racional.num = 6;
int x = num_racional.den + 3;

typedef struct {
	int num;
	int den;
} racional;
racional r;
```

Si queremos hacer una definición correcta de racional, el segundo número (denominador) no puede ser cero. Esto se hace a través del **ocultamiento de información**, controlando cómo se acceden y modifican los datos.

## Programación orientada a objetos

**Paradigma** basado en:

 - Tipos de datos abstractos: nuevos tipos de datos que se comportan como tipo de dato primitivo.
 - Encapsulamiento
 - Ocultamiento de información
 - Polimorfismo
 - Herencia
 - Acoplamiento
 - Cohesión

## Tipo de dato abstracto

- Definición de un nuevo tipo de dato con operaciones propias.
- Definición de nuevos tipos de datos de forma similar a los datos primitivos del lenguaje.
- Abstracciones:
  - Por parametrización
  - Por especificación

### Especificación, representación e implementación

- **Visión externa:** el programador tiene que tener acceso a la especificación, para saber cómo funciona el TDA. *Preocupa a todos los usuarios*.
  - **Especificación:** descripción del comportamiento del TDA a nivel alto (qué objetos representa y qué puedo hacer con ellos, sus operaciones asociadas). Decimos qué representa, pero no cómo los representa.
    - Ej. 1: racional representa concepto matemático racional y con él puedo sumar, representante canónico...
    - Ej. 2: tipo de dato fecha: representa una fecha del calendario gregoriano y está, por tanto, compuesto por tres elementos: días (1-31), meses (1-12) y años (negativos AC positivos DC).
- **Visión interna:** *preocupa a quienes los están implementando*.
  - **Representación:** forma concreta en que se representan los datos para poder manejarlos. No afecta a los usuarios, y no se deben preocuparse de esto.
      - Ej. 1: podemos manejar un racional con dos enteros.
      - Ej. 2: podemos representarlo con tres números enteros. Así es cómo declararé las fechas, y nunca diré cómo los representaré al usuario. En algún momento tengo que expresar cómo asociaré los datos, haciendo uso de la función de representación (pues el usuario debe saber qué hay en cada sitio).
  - **Implementación:** forma en que se expresan las operaciones, cómo se hace cada una de ellas.
      - Ej. 1: suma, canónica, producto...
      - Ej. 2: 

> **Importante:** definir declaración y asignación (si son tipos de datos básicos C++ los gestiona por sí mismo, pero para tipos de datos más complejos hay que implementarlos).

| Ejercicios |
| ------------- |
| Ejercicio 1: pensar en una especificación para el tipo de dato abstracto fecha. |
| Ejercicio 2: pensar en una especificación para el tipo de dato abstracto número complejo. |
| Ejercicio 3: ¿cómo podríamos representar una fecha con un único entero? |

## Ventajas de la separación

- Evitamos el mal uso del TDA.
  - Ej.: hacer que `f.m = 15` fuera posible haría que todas las operaciones serían inválidas.
- Podemos cambiar la representación de tipos de datos previamente definidos. NO la especificación.
  - Es mejor pensar en la especificación antes que en la representación.

## Objetos y clases

- **Objeto:** entidad que tiene estado, comportamiento e identidad.
  - **Identidad:** propiedad que permite distinguir un objeto de otros.
  - **Estado:** representado por atributos.
  - **Comportamiento:** para cambiar su estado o interacción entre objetos: métodos.
- **Clase:** conjunto de objetos del mismo tipo que comparten estado y comportamiento.
- Se crean objetos de una clase mediante su instanciación.

> *Ej.:* clase fecha: cada objeto es una fecha.

Las funciones en este caso no son independientes, están "pegadas" a los objetos.

* Objeto: instancia de una clase. Entidad provista de propiedades o atributos (datos) y de comportamiento o funcionalidad (métodos). Se corresponden con los objetos reales del mundo o con objetos internos del sistema.
  * Intentamos construir un modelo desde la realidad.
* Método: algoritmo asociado a una clase de objetos cuya ejecución se activa tras la recepción de un mensaje.

- Los atributos y los métodos asociados a una clase deben ir juntos formando un todo inseparable: encapsulamiento.
- Debe ocultarse la información privada tras una interfaz pública que sea la única forma de cambiar el estado de los objetos: ocultamiento de la información.
  - Ej.: sólo podré modificar los objetos de la clase fecha a través de las funciones definidas en dicha clase.

## Ocultamiento de información

- La interacción con el exterior se debe hacer a través de una interfaz definida.
- Si no hay control de acceso a la parte interna se puede alterar su estado de manera inesperada y provocar efectos secundarios e interacciones no esperadas.
- Permite garantizar un uso consistente de los datos y cambiar la representación el futuro.

Mientras use la misma especificación, cualquier representación es válida.

## Clases en C++

Se definen con la palabra reservada `class`, seguida entre llaves de la definición de sus miembros (atributos y métodos).

```c++
class racional {
...
	int numerador;
	int denominador;
	racional suma(const racional &) const;
...
};
```
***¿Por qué la función suma tiene un solo objeto dentro?***
```c++
racional r(1,2); // constructor de primitivos
racional s(3,4);
racional a;      // aquí realmente estamos usando un constructor por defecto
                 // realmente sería racional a();
a = r.suma(s);
```
Nótese que la función que estamos definiendo es un método de la clase racional. Si por ejemplo llamásemos esto:
```c++
a = r.suma(3);
```
A no ser que haya un conversor de un tipo de dato al TDA, esta operación no sería posible, pues el argumento no concuerda con el método definido en la clase.

### Público y privado

```c++
class racional {
    int den;
    int num;
    racional suma(const & racional s) construcción;
    void simplifica();
};
```

***¿Cuál sería público y privado?***

En general, serán privados los datos (queremos que no nos manipulen los datos, o sea, que no sea posible que el usuario haga `a.den = 0`).

```c++
class racional {
    private: // de aquí hasta el final de la clase u otro
        int den;
        int num;
    public:
        racional suma(const & racional s) construcción;
        void simplifica();
};
```

Por defecto, en las clases todo es privado. La capacidad de interacción del usuario se define mediante los métodos.

Podríamos definir la operación de asignación privada.

## Parámetro `this`

En la operación suma la he definido para un racional. Cuando voy a implementar la operación suma necesito conocer numerador y denominador del primer sumando y del segundo sumando.

***¿Cómo obtengo el numerador y el denominador de `r`?***

```c++
racional suma(const & racional s) construcción;
```

Se invoca asociado al objeto `r`. ***¿Cómo sabe a qué objeto está asociado?***

Realmente la operación se define así:

```c++
racional suma (racional * this; racional & s) construcción;
```

Podemos acceder al objeto de esta forma:

```c++
this -> num;
this -> den;
```

Para simplificarlo, el compilador nos deja quitar el `this`.

```c++
num;
den;
```
<!--stackedit_data:
eyJoaXN0b3J5IjpbLTI3NzA0Nzk0OF19
-->