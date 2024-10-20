#include "Dictionary.hpp"
#include <memory>
#include <string>
#include <iostream>

int main() 
{
    // Creamos un diccionario de string (clave) y entero (valor).
    Dictionary<std::string, int> dict;

    // Agregamos algunos pares clave-valor.
    dict.add("Apple", std::make_shared<int>(50));
    dict.add("Banana", std::make_shared<int>(30));

    // Obtenemos el valor asociado a una clave.
    auto appleValue = dict.get("Apple");
    if (appleValue) {
        std::cout << "Apple: " << *appleValue << std::endl;
    }

    // Eliminamos un par clave-valor.
    dict.remove("Banana");

    // Usamos forEach para recorrer todos los pares y mostrarlos.
    dict.forEach([](const std::string& key, const std::shared_ptr<int>& value) {
        std::cout << key << ": " << *value << std::endl;
    });

    return 0;
}
