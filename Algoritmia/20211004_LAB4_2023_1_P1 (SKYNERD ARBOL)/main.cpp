
/* 
 * File:   main.cpp
 * Author: Sebastián O'Brien
 *
 * Created on 8 de julio de 2025, 05:28 PM
 */

#include <iostream>

#define NO_ENCONTRADO -1

#include "ArbolB.h"
#include "funcionesAB.h"
#include "Cola.h"
#include "funcionesCola.h"

using namespace std;

//Izquierda arbol y derecha nullptr
void plantarArbolBinario(struct ArbolBinario & arbol, struct ArbolBinario & arbolIzquierda, 
                         const struct Elemento & elemento, struct NodoArbol * derecha) {
    struct NodoArbol * nuevoNodo = crearNuevoNodo(arbolIzquierda.raiz, elemento,
            derecha);
    arbol.raiz = nuevoNodo;
}

void poblarArbol(struct ArbolBinario & arbol) {
    ArbolBinario arbol_1, arbol_2, arbol_3, arbol_4, arbol_5, arbol_6,
                arbol_7, arbol_8, arbol_9, arbol_10, arbol_11, arbol_12;
    
    construir(arbol_1);
    construir(arbol_2);
    construir(arbol_3);
    construir(arbol_4);
    construir(arbol_5);
    construir(arbol_6);
    construir(arbol_7);
    construir(arbol_8);
    construir(arbol_9);
    construir(arbol_10);
    construir(arbol_11);
    construir(arbol_12);
    
    struct Elemento elemento;
    
    //Nivel 5
    elemento.numero = 50;
    elemento.letra = 'E';
    plantarArbolBinario(arbol_1, nullptr, elemento, nullptr);
    elemento.numero = 100;
    elemento.letra = 'E';
    plantarArbolBinario(arbol_2, nullptr, elemento, nullptr);
    
    //Nivel 4
    elemento.numero = 50;   
    elemento.letra = 'S';
    plantarArbolBinario(arbol_3, arbol_1, elemento, nullptr);
    elemento.numero = 200;
    elemento.letra = 'Z';
    plantarArbolBinario(arbol_4, arbol_2, elemento, nullptr);
    elemento.numero = 100;
    elemento.letra = 'S';
    plantarArbolBinario(arbol_5, nullptr, elemento, nullptr);
    elemento.numero = 200;
    elemento.letra = 'E';
    plantarArbolBinario(arbol_6, nullptr, elemento, nullptr);
    
    //Nivel 3
    elemento.numero = 100;   
    elemento.letra = 'E';
    plantarArbolBinario(arbol_7, arbol_3, elemento, arbol_4);
    elemento.numero = 50;
    elemento.letra = 'S';
    plantarArbolBinario(arbol_8, nullptr, elemento, nullptr);
    elemento.numero = 200;
    elemento.letra = 'S';
    plantarArbolBinario(arbol_9, arbol_5, elemento, arbol_6);
    elemento.numero = 150;
    elemento.letra = 'S';
    plantarArbolBinario(arbol_10, nullptr, elemento, nullptr);
    
    //Nivel 2
    elemento.numero = 50;   
    elemento.letra = 'Z';
    plantarArbolBinario(arbol_11, arbol_7, elemento, arbol_8);
    elemento.numero = 200;
    elemento.letra = 'E';
    plantarArbolBinario(arbol_12, arbol_9, elemento, arbol_10);
    
    //Nivel 1
    elemento.numero = 100;   
    elemento.letra = 'Z';
    plantarArbolBinario(arbol, arbol_11, elemento, arbol_12);
}

int buscarSkyNerd(struct ArbolBinario & arbol) {
    struct Cola colaAux;
    construir(colaAux);
    encolar(colaAux, arbol.raiz, 1);
    
    while(not esColaVacia(colaAux)) {
        struct NodoArbol * nodoArbolActual;
        int nivel;
        desencolar(colaAux, nodoArbolActual, nivel);
        
        if(nodoArbolActual->elemento.numero == 200) {
            if(not esNodoVacio(nodoArbolActual->izquierda)) {
                if(nodoArbolActual->izquierda->elemento.numero == 200 and 
                        nodoArbolActual->izquierda->elemento.letra == 'S') {
                    return nivel + 1;
                }
                else encolar(colaAux, nodoArbolActual->izquierda, nivel + 1);
            }
            if(not esNodoVacio(nodoArbolActual->derecha)) {
                if(nodoArbolActual->derecha->elemento.numero == 200 and 
                        nodoArbolActual->derecha->elemento.letra == 'S') {
                    return nivel + 1;
                }
                else encolar(colaAux, nodoArbolActual->derecha, nivel + 1);
            }
        }
        else {
            if(not esNodoVacio(nodoArbolActual->izquierda))
                encolar(colaAux, nodoArbolActual->izquierda, nivel + 1);
            if(not esNodoVacio(nodoArbolActual->derecha))
                encolar(colaAux, nodoArbolActual->derecha, nivel + 1);
        }
    }
    return NO_ENCONTRADO;
}

int main(int argc, char** argv) {
    
    ArbolBinario arbol;
    construir(arbol);
    poblarArbol(arbol);
    
    int nivel = buscarSkyNerd(arbol);
    if(nivel == NO_ENCONTRADO)
        cout << "SkyNerd no se encuentra en la red";
    else cout << "SkyNerd fue encontrado en el nivel " << nivel;

    return 0;
}

