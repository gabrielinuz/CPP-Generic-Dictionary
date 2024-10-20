#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

#include <memory>    // Para usar shared_ptr
#include <functional>
#include <iostream>  // Para imprimir en consola
#include <vector>    // Usaremos un vector para almacenar los pares clave-valor

// Declaramos la clase Dictionary como un template que acepta dos tipos: Key y Value.
template<typename Key, typename Value>
class Dictionary {
    private:
        // Clase interna Pair para almacenar la clave y el valor.
        struct Pair {
            Key key;
            std::shared_ptr<Value> value;

            // Constructor para inicializar la clave y el valor.
            Pair(const Key& k, std::shared_ptr<Value> v) : key(k), value(v) {}
        };

        // Vector de pares clave-valor. Almacenamos Pairs usando un vector.
        std::vector<Pair> pairs;

    public:
        // Método para agregar un par clave-valor.
        void add(const Key& key, std::shared_ptr<Value> value) {
            // Recorremos la lista de pares para ver si la clave ya existe.
            for (auto& pair : pairs) {
                if (pair.key == key) {
                    // Si la clave ya existe, actualizamos su valor.
                    pair.value = value;
                    return;
                }
            }
            // Si la clave no existe, agregamos un nuevo par.
            pairs.emplace_back(key, value);
        }

        // Método para obtener el valor correspondiente a una clave.
        std::shared_ptr<Value> get(const Key& key) const {
            // Recorremos la lista de pares para buscar la clave.
            for (const auto& pair : pairs) {
                if (pair.key == key) {
                    // Si encontramos la clave, retornamos el valor.
                    return pair.value;
                }
            }
            // Si la clave no se encuentra, retornamos un nullptr.
            return nullptr;
        }

        // Método para eliminar un par clave-valor basado en la clave.
        void remove(const Key& key) {
            // Usamos un iterador para eliminar el par de la lista.
            for (auto it = pairs.begin(); it != pairs.end(); ++it) {
                if (it->key == key) {
                    pairs.erase(it);  // Borramos el par encontrado.
                    return;
                }
            }
        }

        // Método para recorrer todos los pares clave-valor.
        void forEach(const std::function<void(const Key&, const std::shared_ptr<Value>&)>& func) const {
            // Recorremos todos los pares clave-valor.
            for (const auto& pair : pairs) {
                // Aplicamos la función pasada a cada par.
                func(pair.key, pair.value);
            }
        }
};

#endif // DICTIONARY_HPP
