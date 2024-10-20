#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>  // Para usar shared_ptr
#include <functional>

// Definición de la clase template Vector
template<typename T>
class Vector 
{
    private:
        std::shared_ptr<T[]> data; // Arreglo dinámico usando shared_ptr
        size_t capacity;           // Capacidad máxima del vector
        size_t size;               // Número actual de elementos

        // Método privado para redimensionar el arreglo dinámico
        void resize(size_t newCapacity) {
            // Crear nuevo arreglo dinámico con la nueva capacidad
            std::shared_ptr<T[]> newData(new T[newCapacity]);

            // Copiar los elementos del arreglo viejo al nuevo usando while
            size_t i = 0;
            while (i < size) {
                newData[i] = data[i];
                ++i;
            }

            // Actualizar el shared_ptr a apuntar al nuevo arreglo
            data = newData;
            capacity = newCapacity;
        }

    public:
        // Constructor por defecto, inicializa con una capacidad de 4
        Vector() : capacity(4), size(0) {
            data = std::shared_ptr<T[]>(new T[capacity]);
        }

        // Añadir un nuevo elemento al vector
        void push_back(const T& value) {
            if (size == capacity) {
                resize(capacity * 2); // Doblar la capacidad si está lleno
            }
            data[size++] = value; // Insertar nuevo valor y aumentar el tamaño
        }

        // Obtener el tamaño del vector (número de elementos)
        size_t getSize() const {
            return size;
        }

        // Añadir en la clase Vector
        T& operator[](size_t index) {
            return data[index];
        }

        // Obtener el elemento en una posición dada
        // Añadir la versión const del operador []:
        const T& operator[](size_t index) const {
            if (index >= size) {
                throw std::out_of_range("Index out of range");
            }
            return data[index];
        }

        // Método para eliminar el último elemento
        void pop_back() {
            if (size > 0) {
                --size;
            }
        }

        // Método para limpiar el vector (eliminar todos los elementos)
        void clear() {
            size = 0;
        }

        // Recorrer los elementos del vector aplicando una función
        void forEach(const std::function<void(const T&)>& func) const {
            size_t i = 0;
            while (i < size) {
                func(data[i]);
                ++i;
            }
        }
};

#endif // VECTOR_HPP
