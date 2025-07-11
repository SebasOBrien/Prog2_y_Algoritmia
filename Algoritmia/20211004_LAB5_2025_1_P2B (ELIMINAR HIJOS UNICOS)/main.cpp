
/* 
 * File:   main.cpp
 * Author: Sebastián O'Brien
 *
 * Created on 9 de julio de 2025, 01:02 PM
 */

#include <iostream>

#include "ArbolBB.h"
#include "funcionesABB.h"
#include "Pila.h"
#include "funcionesPila.h"
#include "funcionesAB.h"

using namespace std;

void eliminarSubArbol(struct NodoArbol * nodoArbol) {
    struct Pila pilaAux;
    construir(pilaAux);
    apilar(pilaAux, nodoArbol);
    
    while(not esPilaVacia(pilaAux)) {
        struct NodoArbol * actual = desapilar(pilaAux);
        
        if(actual->izquierda != nullptr)
            apilar(pilaAux, actual->izquierda);
        if(actual->derecha != nullptr)
            apilar(pilaAux, actual->derecha);
        
        delete actual;
    }
}

void eliminarHijosUnicos(struct ArbolBinarioBusqueda & almacenes) {
    struct Pila pilaAux;
    construir(pilaAux);
    apilar(pilaAux, almacenes.arbolBinario.raiz);
    while(not esPilaVacia(pilaAux)) {
        struct NodoArbol * actual = desapilar(pilaAux);
        
        if(actual->izquierda == nullptr or actual->derecha == nullptr) {
            if (actual->izquierda != nullptr) {
                eliminarSubArbol(actual->izquierda);
                actual->izquierda = nullptr;
            }
            if (actual->derecha != nullptr) {
                eliminarSubArbol(actual->derecha);
                actual->derecha = nullptr;
            }
                
        }
        else {
            apilar(pilaAux, actual->derecha);
            apilar(pilaAux, actual->izquierda);
        }
    }
}

int main(int argc, char** argv) {
    
    ArbolBinarioBusqueda almacenes;
    construir(almacenes);
    
    Elemento elemento;
    
    elemento.numero = 100;
    insertar(almacenes, elemento);
    elemento.numero = 50;
    insertar(almacenes, elemento);
    elemento.numero = 150;
    insertar(almacenes, elemento);
    elemento.numero = 25;
    insertar(almacenes, elemento);
    elemento.numero = 75;
    insertar(almacenes, elemento);
    elemento.numero = 125;
    insertar(almacenes, elemento);
    elemento.numero = 175;
    insertar(almacenes, elemento);
    elemento.numero = 30;
    insertar(almacenes, elemento);
    elemento.numero = 200;
    insertar(almacenes, elemento);
    elemento.numero = 28;
    insertar(almacenes, elemento);
    
    cout << "Antes de la eliminacion: " << endl;
    enOrden(almacenes);
    eliminarHijosUnicos(almacenes);
    cout << endl << "Despues de la eliminacion: " << endl;
    enOrden(almacenes);
    
    return 0;
}

