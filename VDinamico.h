//
// Created by Dalton Gabriel Abambari on 25/9/23.
//
#ifndef VECTORDINAMICO_H
#define VECTORDINAMICO_H
#include <iostream>
#include <climits>
#include <new>
#include <algorithm>
#include <cmath>
#include <stdexcept>

using namespace std;

template<class T>
class VectorDinamico {
public:
    VectorDinamico();
    explicit VectorDinamico(unsigned int n);
    VectorDinamico(const VectorDinamico<T>& orig);
    VectorDinamico(const VectorDinamico<T>& orig, unsigned int posicionInicial, unsigned int numElementos);
    virtual ~VectorDinamico();

    void insertar(const T& dato, unsigned pos = UINT_MAX);
    T borrar(unsigned pos = UINT_MAX);
    void ordenar();
    void ordenarRev();
    int busquedaBin(T& dato);
    unsigned tamLogico();
    void print( int tam );
    VectorDinamico<T>& operator=(const VectorDinamico<T>& orig);
    T& operator[](int pos);

private:
    unsigned int tamf; //fijo hasta que sea necesario aumentar
    unsigned int taml; //es el que va cambiando cuando metemos y sacamos datos
    T *vector;
};

#include "VDinamico.h"
#include <cmath> // Para funciones matemáticas como pow y ceil
#include <algorithm> // Para la función sort
#include <stdexcept> // Para excepciones

template<class T>
VectorDinamico<T>::VectorDinamico() : tamf(1), taml(0) {
    this->vector = new T[1];
}

/**
 * @brief Constructor que inicializa el vector con un tamaño dado
 * @param n Tamaño inicial del vector
 */
template<class T>
VectorDinamico<T>::VectorDinamico(unsigned int n) : taml(n) {
    vector = new T[this->tamf];
    if (n != 0) {
        unsigned int a = (int) pow(2, ceil(log(taml) / log(2)));
        this->tamf = a;
    } else {
        this->tamf = 1;
    }
}

/**
 * @brief Constructor de copia
 * @param orig VectorDinamico original a copiar
 */
template<class T>
VectorDinamico<T>::VectorDinamico(const VectorDinamico<T>& orig) {
    this->tamf = orig.tamf;
    this->taml = orig.taml;
    this->vector = new T[tamf];
    for (int i = 0; i < this->taml; i++) {
        this->vector[i] = orig.vector[i];
    }
}

/**
 * @brief Constructor de copia con posición inicial y número de elementos
 * @param orig VectorDinamico original a copiar desde
 * @param posicionInicial Posición inicial de copia
 * @param numElementos Número de elementos a copiar
 */

template<class T>
VectorDinamico<T>::VectorDinamico(const VectorDinamico<T>& orig, unsigned int posicionInicial, unsigned int numElementos) {
    if (posicionInicial > taml || numElementos > taml) {
        throw std::out_of_range("El posicionInicial o numero es mayor que el vector");
    }
    tamf = orig.tamf;
    taml = orig.taml;
    unsigned aux = taml;
    do {
        tamf / 2;
    } while (tamf < (3 * aux));
    aux = 0;
    try {
        vector = new T[tamf];
    } catch (std::out_of_range &e) {
        throw "No hay memoria";
    }
    for (unsigned i = posicionInicial; i < numElementos; i++) {
        vector[aux] = orig.vector[numElementos];
        aux++;
    }
}

/**
 * @brief Inserta un elemento en la posición dada
 * @param dato Elemento a insertar
 * @param pos Posición en la que se insertará el elemento
 */
template<class T>
void VectorDinamico<T>::insertar(const T& dato, unsigned pos) {
    if (pos > tamf && pos != UINT_MAX) {//puede ser tamaño fisico
        throw std::out_of_range("La posicion es mayor al tamaño del vector");
    }
    if (taml == tamf) {
        T* vaux;
        try {
            tamf = tamf * 2;
            vaux = new T[tamf];
        } catch (std::out_of_range &e) {
            throw "No hay memoria";
        }
        for (unsigned i = 0; i < taml; i++) {
            vaux[i] = vector[i];
        }
        delete[] vector;
        vector = vaux;
    }
    if (pos < taml) {
        for (unsigned i = taml - 1; i >= pos; i--) {
            vector[i + 1] = vector[i];
        }
        vector[pos] = dato;
    }
    if (pos == UINT_MAX) { //SE INSERTA AL FINAL
        pos = taml;
        vector[pos] = dato;
    }
    taml++;
}

/**
 * @brief Borra un elemento en la posición dada
 * @param pos Posición del elemento a borrar
 * @return El elemento borrado
 */
template<class T>
T VectorDinamico<T>::borrar(unsigned pos) {
    if (pos > taml && pos != UINT_MAX) {
        throw std::out_of_range("La posicion es mayor al tamaño del vector");
    }
    if (taml * 3 < tamf) {
        T* vaux;
        vaux = new T[tamf = tamf / 2];
        for (unsigned i = 0; i < taml; i++) {
            vaux[i] = vector[i];
        }
        delete[] vector;
        vector = vaux;
    }
    if (pos < taml) {
        for (unsigned i = pos; i < taml; i++) {
            vector[i] = vector[i + 1];
        }
    }
    return vector[taml--];
}

/**
 * @brief Ordena el vector en orden ascendente
 */

template<class T>
void VectorDinamico<T>::ordenar() {
    sort(vector, vector + taml);
}

/**
 * @brief Ordena el vector en orden descendente
 */
template<class T>
void VectorDinamico<T>::ordenarRev() {
    for(int i = 0; i < taml - 1; i++){ //ESTO LO ORDENA DE MAYOR A MENOR
        for(int j = 0; j < taml - 1; j++){
            if (vector[j] < vector[j + 1]){
                int tmp = vector[j+1];
                vector[j+1] = vector[j];
                vector[j] = tmp;
            }
        }
    }
}

/**
 * @brief Realiza una búsqueda binaria en el vector
 * @param dato Elemento a buscar
 * @return La posición del elemento encontrado o -1 si no se encuentra
 */
template<class T>
int VectorDinamico<T>::busquedaBin(T& dato) {

    int izq = 0;
    int drcha = this->taml;
    int centro = this->taml / 2;
    bool encontro = false;

    while (!encontro && izq <= drcha) {
        centro = (drcha + izq) / 2;
        if (vector[centro] == dato) {
            encontro = true;
            return centro;
        } else {
            if (dato < vector[centro]) {
                drcha = centro - 1;
            } else {
                izq = centro + 1;
            }
        }
    }
    return -1;

}

/**
 * @brief Obtiene el tamaño lógico del vector
 * @return El tamaño lógico del vector
 */
template<class T>
unsigned VectorDinamico<T>::tamLogico() {
    return this->taml;
}

/**
 * @brief Destructor de la clase, libera la memoria asignada al vector
 */
template<class T>
VectorDinamico<T>::~VectorDinamico() {
    delete[] vector;
}

/**
 * @brief Imprime los primeros 'tam' elementos del vector en la consola
 * @param tam Cantidad de elementos a imprimir
 */
template<class T>
void VectorDinamico<T>::print( int tam ) {
    for (uint i = 0; i < tam; i++) {
        cout << vector[i] << endl;
    }
}

/**
 * @brief Operador de asignación de copia
 * @param orig VectorDinamico original a copiar
 * @return Una referencia al objeto VectorDinamico actual después de la copia
 */
template<class T>
VectorDinamico<T>& VectorDinamico<T>::operator=(const VectorDinamico<T>& orig) {
    if (this != &orig) {
        delete[] vector;
        this->tamf = orig.tamf;
        this->taml = orig.taml;
        this->vector = new T[orig.tamf];
        for (int i = 0; i < orig.taml; i++) {
            this->vector[i] = orig.vector[i];
        }
    }
    return *this;
}


/**
 * @brief Operador de acceso al índice
 * @param pos Posición del elemento a acceder
 * @return Una referencia al elemento en la posición 'pos'
 * @throws std::out_of_range Si 'pos' está fuera del rango válido
 */
template<class T>
T& VectorDinamico<T>::operator[](int pos) {
    if (pos < 0 || pos >= 10000000000000) {
        throw std::out_of_range("La posicion es mayor que el vector");
    }
    return vector[pos];
}

;
#endif /* VECTORDINAMICO_H */