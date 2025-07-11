
/* 
 * File:   main.cpp
 * Author: Sebastián O'Brien
 *
 * Created on 11 de julio de 2025, 10:19 AM
 */

#include <iostream>

#include "ArbolBB.h"
#include "funcionesABB.h"
#include "funcionesAB.h"
#include "Pila.h"
#include "funcionesPila.h"

using namespace std;

void ingresa_lote_recursivo(struct NodoArbol *& raiz, const struct Elemento & elemento){
    if(esNodoVacio(raiz))
        plantarArbolBinario(raiz, nullptr, elemento, nullptr);
    else
        if(raiz->elemento.anho > elemento.anho)
            insertarRecursivo(raiz->izquierda, elemento);
        else
            if(raiz->elemento.anho < elemento.anho)
                insertarRecursivo(raiz->derecha, elemento);
            else
                raiz->elemento.cantidad += elemento.cantidad;
}

void ingresa_lote(struct ArbolBinarioBusqueda & arbol, const struct Elemento & elemento){
    ingresa_lote_recursivo(arbol.arbolBinario.raiz, elemento);
}

void construirArbol(struct ArbolBinarioBusqueda & vinos) {
    struct Elemento elemento;
    
    elemento.anho = 2018;
    elemento.cantidad = 100;
    ingresa_lote(vinos, elemento);
    
    elemento.anho = 2011;
    elemento.cantidad = 150;
    ingresa_lote(vinos, elemento);
    elemento.anho = 2022;
    elemento.cantidad = 50;
    ingresa_lote(vinos, elemento);
    
    elemento.anho = 2010;
    elemento.cantidad = 175;
    ingresa_lote(vinos, elemento);
    elemento.anho = 2017;
    elemento.cantidad = 25;
    ingresa_lote(vinos, elemento);
    elemento.anho = 2019;
    elemento.cantidad = 125;
    ingresa_lote(vinos, elemento);
    elemento.anho = 2023;
    elemento.cantidad = 200;
    ingresa_lote(vinos, elemento);
    
    elemento.anho = 2020;
    elemento.cantidad = 75;
    ingresa_lote(vinos, elemento);
}

struct NodoArbol * buscarNodo(struct NodoArbol * nodo, const struct Elemento & elemento) {
    if (esNodoVacio(nodo)) return nullptr;
    if (nodo->elemento.anho < elemento.anho)
        return buscarNodo(nodo->derecha, elemento);
    else if (nodo->elemento.anho > elemento.anho)
        return buscarNodo(nodo->derecha, elemento);
    else return nodo;
}

void reporteStock(struct ArbolBinarioBusqueda & vinos) {
    struct Pila pilaVinos;
    construir(pilaVinos);
    struct NodoArbol * actual = vinos.arbolBinario.raiz;
    while (not esPilaVacia(pilaVinos) or not esNodoVacio(actual)) {
        //Nos vamos todo a la derecha y vamos apilando los elementos
        while (not esNodoVacio(actual)) {
            apilar(pilaVinos, actual->elemento);
            actual = actual->derecha;
        }
        //Cuando llegamos al tope desapilamos, imprimimos y buscamos el nodo
        struct Elemento elemento = desapilar(pilaVinos);
        cout << elemento.anho << "-" << elemento.cantidad << " ";
        actual = buscarNodo(vinos.arbolBinario.raiz, elemento);
        //Nos vamos a la izquierda si estamos en el árbol
        if (not esNodoVacio(actual)) {
            actual = actual->izquierda;
        }
    }
}

int main(int argc, char** argv) {
    
    ArbolBinarioBusqueda vinos;
    construir(vinos);
    construirArbol(vinos);
    reporteStock(vinos);
    
    return 0;
}

