
/* 
 * File:   main.cpp
 * Author: Sebastián O'Brien
 *
 * Created on 10 de julio de 2025, 05:22 PM
 */

#include <iostream>
#include <iomanip>

#include "ArbolB.h"
#include "funcionesAB.h"
#include "Elemento.h"
#include "Cola.h"
#include "funcionesCola.h"

using namespace std;

void plantarArbolBinarioModificado(struct ArbolBinario & arbol, struct NodoArbol * izquierda, 
                          const struct Elemento & elemento, struct NodoArbol * derecha) {
    
    struct NodoArbol * nuevoNodo = crearNuevoNodo(izquierda, elemento, derecha);
    arbol.raiz = nuevoNodo;
    arbol.tamano = 1;
}

void plantarArbolBinarioModificado(struct ArbolBinario & arbol, struct ArbolBinario & arbolIzquierda, 
                         const struct Elemento & elemento, struct ArbolBinario & arbolDerecha) {
    struct NodoArbol * nuevoNodo = crearNuevoNodo(arbolIzquierda.raiz, elemento,
            arbolDerecha.raiz);
    arbol.raiz = nuevoNodo;
    arbol.tamano = 1 + arbolIzquierda.tamano + arbolDerecha.tamano;
}

void construirLibro(struct ArbolBinario & libro) {
    ArbolBinario arbol_1, arbol_2, arbol_3, arbol_4, 
            arbol_5, arbol_6, arbol_7, arbol_8;
    construir(arbol_1);
    construir(arbol_2);
    construir(arbol_3);
    construir(arbol_4);
    construir(arbol_5);
    construir(arbol_6);
    construir(arbol_7);
    construir(arbol_8);
    
    struct Elemento elemento;
    
    elemento.seccion = "Seccion1.1.1";
    elemento.nivel = 4;
    plantarArbolBinarioModificado(arbol_1, nullptr, elemento, nullptr);
    elemento.seccion = "Seccion1.1.2";
    elemento.nivel = 2;
    plantarArbolBinarioModificado(arbol_2, nullptr, elemento, nullptr);
    
    elemento.seccion = "Seccion1.1";
    elemento.nivel = 6;
    plantarArbolBinarioModificado(arbol_3, arbol_1, elemento, arbol_2);
    elemento.seccion = "Principal";
    elemento.nivel = 10;
    plantarArbolBinarioModificado(arbol_4, nullptr, elemento, nullptr);
    elemento.seccion = "Seccion2.1";
    elemento.nivel = 3;
    plantarArbolBinarioModificado(arbol_5, nullptr, elemento, nullptr);
    elemento.seccion = "Seccion2.2";
    elemento.nivel = 4;
    plantarArbolBinarioModificado(arbol_6, nullptr, elemento, nullptr);
    
    elemento.seccion = "Capitulo1";
    elemento.nivel = 8;
    plantarArbolBinarioModificado(arbol_7, arbol_3, elemento, arbol_4);
    elemento.seccion = "Capitulo2";
    elemento.nivel = 5;
    plantarArbolBinarioModificado(arbol_8, arbol_5, elemento, arbol_6);
    
    elemento.seccion = "Titulo";
    elemento.nivel = 7;
    plantarArbolBinarioModificado(libro, arbol_7, elemento, arbol_8);
}

void imprimirNodoModificado(struct NodoArbol * actual) {
    cout<<setw(5)<<actual->elemento.seccion<<" - "<<actual->elemento.nivel<<", ";
}

bool esColaVaciaModificado(const struct Cola & colaAux) {
    return colaAux.lista.longitud == 0;
}

void encontrarPrincipal(struct ArbolBinario & libro, int &nivel) {
    struct Cola colaAux;
    construir(colaAux);
    int i = 0;
    encolar(colaAux, libro.raiz);
    encolar(colaAux, nullptr);
    
    while(not esColaVaciaModificado(colaAux)) {
        struct NodoArbol * actual = desencolar(colaAux);
        if(actual != nullptr){
            if(actual->elemento.seccion == "Principal") nivel = i;
            imprimirNodoModificado(actual);
            if(actual->izquierda != nullptr)
                encolar(colaAux, actual->izquierda);
            if(actual->derecha != nullptr)
                encolar(colaAux, actual->derecha);
        }
        else {
            nivel++;
            cout << endl;
            if(not esColaVaciaModificado(colaAux))
                encolar(colaAux, nullptr);
        }
    }
}

void borrarMitadArbol(struct ArbolBinario & libro, char mitad) {
    struct Cola colaAux;
    construir(colaAux);
    struct NodoArbol * actual;
    
    if(mitad == 'D') {   
        encolar(colaAux, libro.raiz->derecha);
        libro.raiz->derecha = nullptr;
    }
    else if(mitad == 'I') {
        encolar(colaAux, libro.raiz->izquierda);
        libro.raiz->izquierda = nullptr;
    }
    else return;
    while(not esColaVacia(colaAux)) {
        actual = desencolar(colaAux);
        if(actual->izquierda != nullptr) {
            encolar(colaAux, actual->izquierda);
            actual->izquierda = nullptr;
        }
        if(actual->derecha != nullptr) {
            encolar(colaAux, actual->derecha);
            actual->derecha = nullptr;
        }

        delete actual;
        libro.tamano--;
    }
}

int main(int argc, char** argv) {
    
    ArbolBinario libro;
    construir(libro);
    construirLibro(libro);
    int nivel;
    encontrarPrincipal(libro, nivel);
    cout << "El nivel es " << nivel << endl;
    cout << "El tamano del arbol es " << libro.tamano << endl;
    
    cout << endl;
    borrarMitadArbol(libro, 'D');
    encontrarPrincipal(libro, nivel);
    cout << "El tamano del arbol es " << libro.tamano << endl;

    return 0;
}

