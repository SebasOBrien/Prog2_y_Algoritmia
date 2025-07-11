
/* 
 * File:   main.cpp
 * Author: Sebastián O'Brien
 *
 * Created on 8 de julio de 2025, 12:24 PM
 */

#define N 5

#include <iostream>

#include "NodoArbol.h"
#include "funcionesAB.h"
#include "ArbolB.h"

using namespace std;

bool noTieneHijos(struct NodoArbol * nodo) {
    return nodo->izquierda == nullptr and nodo->derecha == nullptr;
}

int calcularCombinacionesRecursivo(struct NodoArbol * nodo, int peso, int pesoActual){
    if(not esNodoVacio(nodo)){
        if (nodo->elemento.valor == 1) pesoActual += nodo->elemento.numero;
        if(noTieneHijos(nodo)) {
            if(peso == pesoActual) return 1;
        }
        return calcularCombinacionesRecursivo(nodo->izquierda, peso, pesoActual) +
                calcularCombinacionesRecursivo(nodo->derecha, peso, pesoActual);
    }
    else return 0;
}

int calcularCombinaciones(const struct ArbolBinario & arbol, int peso){
    int pesoActual = 0;
    return calcularCombinacionesRecursivo(arbol.raiz, peso, pesoActual);
}

void plantarArbolBinarioCromosoma(struct NodoArbol *& nodo, 
        struct NodoArbol * izq, Elemento elemento, struct NodoArbol * der) {
    struct NodoArbol * nuevoNodo = crearNuevoNodo(izq, elemento, der);
    nodo = nuevoNodo;
}

void insertaValorArbol(struct NodoArbol *& nodo, Elemento elemento){
    if (esNodoVacio(nodo)) {
        plantarArbolBinarioCromosoma(nodo, nullptr, elemento, nullptr);
        return;
    }
    elemento.valor = 0;
    insertaValorArbol(nodo->izquierda, elemento);
    elemento.valor = 1;
    insertaValorArbol(nodo->derecha, elemento);
}

crearArbolBinario(struct ArbolBinario & arbol, int *arreglo, int n) {
    Elemento elemento;
    
    elemento.numero = 0;
    elemento.valor = 0;
    plantarArbolBinarioCromosoma(arbol.raiz, nullptr, elemento, nullptr);
    
    for(int i = 0; i < n; i++) {
        elemento.numero = arreglo[i];
        insertaValorArbol(arbol.raiz, elemento);
    }
}

int main(int argc, char** argv) {
    
    int arreglo[N] = {10, 50, 20, 30, 40};
    int n = 5;  
    
    ArbolBinario arbol;
    construir(arbol);
    
    crearArbolBinario(arbol, arreglo, n);
    int peso = 70;
    cout << "Existen " << calcularCombinaciones(arbol, peso) << " combinaciones posibles.";

    return 0;
}

