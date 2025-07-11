
/* 
 * File:   main.cpp
 * Author: Sebastián O'Brien
 *
 * Created on 8 de julio de 2025, 01:39 PM
 */

#include <iostream>

#include "ArbolBB.h"
#include "funcionesABB.h"
#include "funcionesAB.h"

using namespace std;

void preOrden(struct ArbolBinarioBusqueda & arbol) {
    recorrerPreOrden(arbol.arbolBinario);
}

bool noTieneHijos(struct NodoArbol * nodo) {
    return nodo->izquierda == nullptr and nodo->derecha == nullptr;
}

struct Elemento extraerNodoSinPadresRecursivo(struct NodoArbol *& nodo) {
    struct Elemento e;
    if(not esNodoVacio(nodo)) {
        if(noTieneHijos(nodo)) {
            e = nodo->elemento;
            delete nodo;
            nodo = nullptr;
            return e;
        }
        if(not esNodoVacio(nodo->izquierda)) {
            e = extraerNodoSinPadresRecursivo(nodo->izquierda);
            if(e.numLote != 0) return e;
        }
        if(not esNodoVacio(nodo->derecha)) {
            e = extraerNodoSinPadresRecursivo(nodo->derecha);
            if(e.numLote != 0) return e;
        }
    }
    return e; // devolver algo vacío si no encontró nada
}

struct Elemento extraerNodoSinPadres(struct ArbolBinarioBusqueda & emisor) {
    return extraerNodoSinPadresRecursivo(emisor.arbolBinario.raiz);
}

void insertarModificadoRecursivo(struct NodoArbol *& raiz, const struct Elemento & elemento){
    if(esNodoVacio(raiz))
        plantarArbolBinario(raiz, nullptr, elemento, nullptr);
    else
        if(raiz->elemento.numLote > elemento.numLote)
            insertarModificadoRecursivo(raiz->izquierda, elemento);
        else
            if(raiz->elemento.numLote < elemento.numLote)
                insertarModificadoRecursivo(raiz->derecha, elemento);
            else raiz->elemento.cantidad += elemento.cantidad;
}

void insertarModificado(struct ArbolBinarioBusqueda & arbol, const struct Elemento & elemento){
    insertarModificadoRecursivo(arbol.arbolBinario.raiz, elemento);
}

void fusionarAlmacenes(struct ArbolBinarioBusqueda & destino, 
        struct ArbolBinarioBusqueda & emisor) {
    while(not esArbolVacio(emisor.arbolBinario)) {
        struct Elemento elementoAInsertar = extraerNodoSinPadres(emisor);
        insertarModificado(destino, elementoAInsertar);
    }
}

void crearAlmacenes(struct ArbolBinarioBusqueda & destino, 
        struct ArbolBinarioBusqueda & emisor) {
    Elemento elemento;
    
    construir(destino);
    elemento.numLote = 20170620;
    elemento.cantidad = 20;
    insertar(destino, elemento);
    elemento.numLote = 20170810;
    elemento.cantidad = 20;
    insertar(destino, elemento);
    elemento.numLote = 20180211;
    elemento.cantidad = 20;
    insertar(destino, elemento);
    elemento.numLote = 20180409;
    elemento.cantidad = 10;
    insertar(destino, elemento);
    
    construir(emisor);
    elemento.numLote = 20170811;
    elemento.cantidad = 5;
    insertar(emisor, elemento);
    elemento.numLote = 20180211;
    elemento.cantidad = 10;
    insertar(emisor, elemento);
    elemento.numLote = 20180410;
    elemento.cantidad = 15;
    insertar(emisor, elemento);

}


int main(int argc, char** argv) {
    
    ArbolBinarioBusqueda destino, emisor;
    crearAlmacenes(destino, emisor);
    
    cout << "ANTES DE LA FUSION: " << endl;
    cout << "------------------------------- " << endl;
    cout << "En orden: " << endl;
    cout << "Destino: ";
    enOrden(destino);
    cout << endl;
    cout << "Emisor: ";
    enOrden(emisor);
    
    cout << endl;

    cout << "Pre orden: " << endl;
    cout << "Destino: ";
    preOrden(destino);
    cout << endl;
    cout << "Emisor: ";
    preOrden(emisor);
    
    fusionarAlmacenes(destino, emisor);
    
    cout << endl;
    cout << "DESPUES DE LA FUSION: " << endl;
    cout << "------------------------------- " << endl;
    cout << "En orden: " << endl;
    cout << "Destino: ";
    enOrden(destino);
    cout << endl;
    cout << "Emisor: ";
    enOrden(emisor);
    
    cout << endl;

    cout << "Pre orden: " << endl;
    cout << "Destino: ";
    preOrden(destino);
    cout << endl;
    cout << "Emisor: ";
    preOrden(emisor);
    
    return 0;
}

