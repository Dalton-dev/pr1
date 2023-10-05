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
    VectorDinamico(unsigned int n);
    VectorDinamico(const VectorDinamico<T>& orig);
    VectorDinamico(const VectorDinamico<T>& orig, unsigned int posicionInicial, unsigned int numElementos);
    virtual ~VectorDinamico();

    void insertar(const T& dato, unsigned pos = UINT_MAX);

    [[maybe_unused]] T borrar(unsigned pos = UINT_MAX);
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
#endif /* VECTORDINAMICO_H */