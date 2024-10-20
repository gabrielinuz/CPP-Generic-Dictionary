#include <iostream>
#include <memory>
#include "Dictionary.hpp"
#include <string>

using namespace std;

int main() {
    // Crear un diccionario con claves de tipo string y valores de tipo int
    Dictionary<string, int> dict;

    // Agregar elementos al diccionario
    dict.add("Apple", 3);
    dict.add("Banana", 5);
    dict.add("Orange", 10);

    // Verificar si un elemento está en el diccionario
    if (dict.contains("Apple")) {
        cout << "Apple está en el diccionario." << endl;
    }

    // Obtener un valor por su clave
    try {
        int value = dict.get("Banana");
        cout << "El valor de 'Banana' es: " << value << endl;
    } catch (const std::out_of_range& e) {
        cout << e.what() << endl;
    }

    // Recorrer el diccionario e imprimir todos los elementos
    cout << "Recorriendo el diccionario:" << endl;
    dict.forEach([](const string& key, const int& value) {
        cout << key << ": " << value << endl;
    });

    // Eliminar un elemento
    dict.remove("Orange");

    // Intentar obtener el valor de una clave eliminada
    try {
        int value = dict.get("Orange");
        cout << "El valor de 'Orange' es: " << value << endl;
    } catch (const std::out_of_range& e) {
        cout << e.what() << endl;  // Debería mostrar "Key not found"
    }

    // Ver el tamaño actual del diccionario
    cout << "Tamaño actual del diccionario: " << dict.size() << endl;

    return 0;
}
