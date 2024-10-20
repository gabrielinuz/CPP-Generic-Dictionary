#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

#include "Vector.hpp"  // Incluir nuestro Vector.hpp
#include <memory>      // Para usar shared_ptr
#include <iostream>
#include <functional>
#include <string>

// Definición de la clase template Dictionary (clave, valor)
template<typename Key, typename Value>
class Dictionary 
{
    private:
        // Clase interna para representar pares clave-valor
        struct KeyValuePair {
            Key key;
            Value value;

            // Constructor del KeyValuePair
            KeyValuePair(const Key& k, const Value& v) : key(k), value(v) {}
        };

        Vector<std::shared_ptr<KeyValuePair>> items; // Vector personalizado para almacenar pares clave-valor

    public:
        // Constructor por defecto
        Dictionary() = default;

        // Método para agregar o actualizar un valor asociado a una clave
        void add(const Key& key, const Value& value) {
            // Verificar si la clave ya existe
            bool found = false;

            items.forEach([&](const std::shared_ptr<KeyValuePair>& kvp) {
                if (kvp->key == key) {
                    kvp->value = value; // Si ya existe la clave, actualizamos el valor
                    found = true;
                }
            });

            if (!found) {
                // Si la clave no existe, la añadimos
                items.push_back(std::make_shared<KeyValuePair>(key, value));
            }
        }

        // Método para obtener un valor basado en la clave
        Value get(const Key& key) const {
            for (size_t i = 0; i < items.getSize(); ++i) {
                if (items[i]->key == key) {
                    return items[i]->value;
                }
            }
            throw std::out_of_range("Key not found");
        }

        // Método para eliminar una clave-valor del diccionario
        void remove(const Key& key) {
            for (size_t i = 0; i < items.getSize(); ++i) {
                if (items[i]->key == key) {
                    items.pop_back();  // En este ejemplo, eliminamos el último
                    return;
                }
            }
            throw std::out_of_range("Key not found");
        }

        // Método para recorrer todos los elementos del diccionario
        void forEach(const std::function<void(const Key&, const Value&)>& func) const {
            items.forEach([&](const std::shared_ptr<KeyValuePair>& kvp) {
                func(kvp->key, kvp->value);
            });
        }

        // Verificar si existe una clave en el diccionario
        bool contains(const Key& key) const {
            bool found = false;
            items.forEach([&](const std::shared_ptr<KeyValuePair>& kvp) {
                if (kvp->key == key) {
                    found = true;
                }
            });
            return found;
        }

        // Obtener el tamaño actual del diccionario
        size_t size() const {
            return items.getSize();
        }
};

#endif // DICTIONARY_HPP
