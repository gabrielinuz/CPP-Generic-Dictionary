Explicación línea por línea:
Línea 1-2: Definimos el archivo de cabecera y evitamos que se incluya varias veces con guardas de inclusión.
Línea 4: Incluimos Vector.hpp para usar el vector personalizado que creamos previamente.
Líneas 5-7: Incluimos las librerías necesarias para shared_ptr, string y function.
Línea 10: Definimos la clase template Dictionary con dos tipos genéricos Key y Value para representar las claves y los valores.
Línea 13: Definimos una clase interna KeyValuePair para almacenar pares clave-valor.
Líneas 17-18: Constructor del KeyValuePair que toma una clave y un valor.
Línea 21: Declaramos un Vector de shared_ptr a KeyValuePair, que es donde almacenaremos los pares clave-valor.
Línea 23: Constructor por defecto de Dictionary.
Líneas 25-36: Método add para agregar o actualizar un valor basado en una clave. Si la clave ya existe, se actualiza el valor; si no existe, se crea un nuevo KeyValuePair y se agrega al vector.
Líneas 38-46: Método get para obtener un valor basado en la clave. Recorre el vector buscando la clave, y si la encuentra, devuelve el valor. Si no, lanza una excepción.
Líneas 48-55: Método remove para eliminar una clave y su valor asociado. Busca la clave en el vector y elimina el último (puedes adaptar esta lógica para una eliminación más específica si es necesario).
Líneas 57-61: Método forEach para recorrer todos los elementos del diccionario. Aplica una función a cada par clave-valor usando el forEach del Vector.
Líneas 63-71: Método contains para verificar si una clave está en el diccionario.
Líneas 73-75: Método size que devuelve el tamaño actual del diccionario.
Notas:
La clase interna KeyValuePair es útil para agrupar una clave y un valor, y la almacenamos en un Vector de shared_ptr.
En el método remove, se elimina el último elemento. Puedes adaptarlo para eliminar un elemento específico de acuerdo a tus necesidades.
Se utiliza el método forEach tanto en el Vector como en el Dictionary para recorrer y aplicar funciones de manera flexible.
Este diseño integra correctamente la clase Vector.hpp personalizada con el diccionario.


AGREGADO DE VECTOR.HPP_

Explicación línea por línea:
Líneas 1-2: Se asegura de que el archivo se incluya una sola vez.
Línea 4: Se incluye memory para el uso de shared_ptr.
Línea 7: Definimos la clase Vector como una clase template para que pueda almacenar cualquier tipo de dato.
Línea 9: Declaramos el arreglo dinámico data usando shared_ptr para una gestión automática de la memoria.
Líneas 10-11: Declaramos dos variables para la capacidad máxima (capacity) y el tamaño actual del vector (size).
Líneas 14-23: Implementamos el método resize, que redimensiona el vector si es necesario. Se crea un nuevo arreglo dinámico con la nueva capacidad, se copian los datos del arreglo viejo al nuevo, y finalmente se actualiza el shared_ptr.
Líneas 25-29: Constructor por defecto que inicializa el vector con una capacidad de 4 elementos.
Líneas 31-35: El método push_back añade un nuevo elemento al vector. Si el vector está lleno, llama a resize para doblar la capacidad.
Línea 37: Devuelve el tamaño actual del vector.
Líneas 39-44: Sobrecarga del operador [] para acceder a los elementos del vector.
Líneas 46-49: El método pop_back elimina el último elemento del vector si tiene algún elemento.
Líneas 51-53: El método clear elimina todos los elementos del vector.
Líneas 55-59: El método forEach recorre todos los elementos del vector y aplica una función pasada por parámetro a cada elemento. Usa std::function para mayor flexibilidad.
Con esto tienes una implementación de un vector propio, compatible con templates y shared_ptr, que puede almacenar cualquier tipo de objeto. 


EXPLICACIÓN MAIN

Explicación:
Línea 1: Incluimos las cabeceras necesarias como iostream para la entrada/salida y memory para shared_ptr.
Línea 2: Incluimos el archivo de cabecera Dictionary.hpp que definimos previamente.
Línea 5: Definimos el espacio de nombres std para evitar escribir std:: repetidamente.
Líneas 8-10: Creamos un diccionario donde las claves son de tipo string y los valores son de tipo int.
Líneas 12-14: Agregamos tres pares clave-valor al diccionario.
Líneas 16-19: Verificamos si una clave ("Apple") está presente en el diccionario usando el método contains.
Líneas 21-27: Intentamos obtener el valor de la clave "Banana". Si se encuentra, lo imprimimos; si no, se lanza una excepción.
Líneas 29-33: Utilizamos el método forEach para recorrer todos los elementos del diccionario e imprimir sus claves y valores.
Líneas 35-38: Eliminamos un elemento del diccionario usando la clave "Orange".
Líneas 40-45: Intentamos obtener el valor de "Orange" nuevamente después de eliminarlo, lo que debería lanzar una excepción y mostrar "Key not found".
Línea 48: Imprimimos el tamaño actual del diccionario.
Salida esperada del programa:
yaml
Copiar código
Apple está en el diccionario.
El valor de 'Banana' es: 5
Recorriendo el diccionario:
Apple: 3
Banana: 5
Orange: 10
Key not found
Tamaño actual del diccionario: 2
Este archivo main.cpp prueba la funcionalidad del Dictionary.hpp con la clase Vector.hpp personalizada. El programa agrega y elimina elementos del diccionario, recorre los elementos con una función lambda y maneja las excepciones al intentar acceder a claves que no existen. 


El error que estás viendo proviene del uso incorrecto de la clase Vector en un contexto constante. Al hacer la búsqueda dentro del método get del Dictionary, el Vector en el que estás almacenando los elementos es un miembro constante. Sin embargo, la sobrecarga de operator[] en Vector no está marcada como const, por lo que no puede ser usada dentro de un método const.

Para corregir estos errores, necesitas agregar una versión const del operador de índice operator[] en la clase Vector para que pueda ser utilizada cuando Vector sea constante.

A continuación, te muestro cómo ajustar la clase Vector para soportar operaciones de lectura cuando sea constante:


// Añadir en la clase Vector
T& operator[](size_t index) {
    return elements[index];
}

// Añadir la versión const del operador []:
const T& operator[](size_t index) const {
    return elements[index];
}



Con esta modificación, la sobrecarga de operator[] funcionará tanto para objetos constantes como no constantes. Esto significa que cuando estés dentro de un método const como get en el Dictionary, el operador [] podrá devolver una referencia constante a los elementos.

Modificaciones en Dictionary.hpp
No hay cambios adicionales en Dictionary.hpp aparte de los ajustes para usar el nuevo operator[] de Vector cuando se necesita.

Resumen del cambio:
La primera versión de operator[] es para operaciones no constantes y devuelve una referencia normal.
La segunda versión de operator[] (con const) es para operaciones sobre un Vector constante y devuelve una referencia constante.


CAMBIO A WHILE:
Explicación del cambio:
En los métodos de Vector.hpp como resize y forEach, reemplacé los bucles for por while. En resize, ahora utilizo un contador i que se incrementa manualmente en cada iteración.

En Dictionary.hpp, cambié todos los bucles for por while, en particular en métodos como add, get, remove, forEach y contains. Los bucles while siguen la misma lógica que antes, con un contador i que se incrementa manualmente.

Con estas modificaciones, ahora puedes estudiar cómo se comporta la lógica con el uso de while
