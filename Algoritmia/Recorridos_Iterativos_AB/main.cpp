
/* 
 * File:   main.cpp
 * Author: Sebastián O'Brien
 *
 * Created on 11 de julio de 2025, 02:13 PM
 */

#include <iostream>

#include "ArbolB.h"
#include "funcionesAB.h"
#include "Pila.h"
#include "funcionesPila.h"
#include "Cola.h"
#include "funcionesCola.h"

using namespace std;

void poblarArbol(struct ArbolBinario & arbol) {
    ArbolBinario arbol_1, arbol_2, arbol_3, arbol_4, arbol_5, arbol_6;
    construir(arbol_1);
    construir(arbol_2);
    construir(arbol_3);
    construir(arbol_4);
    construir(arbol_5);
    construir(arbol_6);
    
    struct Elemento elemento;
    
    elemento.numero = 2;
    plantarArbolBinario(arbol_1, nullptr, elemento, nullptr);
    elemento.numero = 7;
    plantarArbolBinario(arbol_2, nullptr, elemento, nullptr);
    elemento.numero = 11;
    plantarArbolBinario(arbol_3, nullptr, elemento, nullptr);
    elemento.numero = 15;
    plantarArbolBinario(arbol_4, nullptr, elemento, nullptr);
    
    elemento.numero = 5;
    plantarArbolBinario(arbol_5, arbol_1, elemento, arbol_2);
    elemento.numero = 13;
    plantarArbolBinario(arbol_6, arbol_3, elemento, arbol_4);
    
    elemento.numero = 10;
    plantarArbolBinario(arbol, arbol_5, elemento, arbol_6);
}

void recorrerPreOrdenIterativo(struct ArbolBinario & arbol) {
    struct Pila pilaAux;
    construir(pilaAux);
    
    struct NodoArbol * actual = arbol.raiz;
    while(not esPilaVacia(pilaAux) or not esNodoVacio(actual)) {
        while(not esNodoVacio(actual)) {
            apilar(pilaAux, actual);
            cout << actual->elemento.numero << " ";
            actual = actual->izquierda;
        }
        actual = desapilar(pilaAux);
        if(not esNodoVacio(actual))
            actual = actual->derecha;
    } 
}

void recorrerEnOrdenIterativo(struct ArbolBinario & arbol) {
    struct Pila pilaAux;
    construir(pilaAux);
    
    struct NodoArbol * actual = arbol.raiz;
    while(not esPilaVacia(pilaAux) or not esNodoVacio(actual)) {
        while(not esNodoVacio(actual)) {
            apilar(pilaAux, actual);
            actual = actual->izquierda;
        }
        actual = desapilar(pilaAux);
        cout << actual->elemento.numero << " ";
        if(not esNodoVacio(actual))
            actual = actual->derecha;
    } 
}

void recorrerPostOrdenIterativo(struct ArbolBinario & arbol) {
    struct Pila pilaAux;
    construir(pilaAux);
    
    int ultimoProcesado = 0;
    
    struct NodoArbol * actual = arbol.raiz;
    while(not esPilaVacia(pilaAux) or not esNodoVacio(actual)) {
        while(not esNodoVacio(actual)) {
            apilar(pilaAux, actual);
            actual = actual->izquierda;
        }
        actual = cima(pilaAux);
        if(not esNodoVacio(actual->derecha) and actual->derecha->elemento.numero != ultimoProcesado)
            actual = actual->derecha;
        else {
            ultimoProcesado = desapilar(pilaAux)->elemento.numero;
            cout << ultimoProcesado << " ";
            actual = nullptr;
        }
    } 
}

void recorrerPorAmplitud(struct ArbolBinario & arbol) {
    struct Cola colaAux;
    construir(colaAux);
    
    encolar(colaAux, arbol.raiz);
    encolar(colaAux, nullptr);
    
    while(colaAux.lista.longitud != 0) {
        struct NodoArbol * actual = desencolar(colaAux);
        if(not esNodoVacio(actual)) {
            cout << actual->elemento.numero << " ";
            if(not esNodoVacio(actual->izquierda))
                encolar(colaAux, actual->izquierda);
            if(not esNodoVacio(actual->derecha))
                encolar(colaAux, actual->derecha);
        }
        else {
            cout << endl;
            if(colaAux.lista.longitud != 0)
                encolar(colaAux, nullptr);
        }
    }
}

int main(int argc, char** argv) {

    ArbolBinario arbol;
    construir(arbol);
    poblarArbol(arbol);
    
    cout << "En pre-orden: ";
    recorrerPreOrdenIterativo(arbol);
    cout << endl;
    cout << "En orden: ";
    recorrerEnOrdenIterativo(arbol);
    cout << endl;
    cout << "En post-orden: ";
    recorrerPostOrdenIterativo(arbol);
    cout << endl;
    cout << "Por amplitud: " << endl;
    recorrerPorAmplitud(arbol);
    
    return 0;
}

