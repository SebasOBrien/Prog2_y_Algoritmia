
/* 
 * File:   main.cpp
 * Author: Sebastián O'Brien
 *
 * Created on 22 de mayo de 2025, 11:37 AM
 */

#include <iostream>

#include "Elemento.h"
#include "Cola.h"
#include "funcionesCola.h"
#include "funcionesLista.h"

using namespace std;

void poblarCola(struct Cola &cola) {
    struct Elemento elemento;
    elemento.numero = 3;
    encolar(cola, elemento);
    elemento.numero = 1;
    encolar(cola, elemento);
    elemento.numero = 6;
    encolar(cola, elemento);
    elemento.numero = 2;
    encolar(cola, elemento);
    elemento.numero = 5;
    encolar(cola, elemento);
    elemento.numero = 7;
    encolar(cola, elemento);
    elemento.numero = 4;
    encolar(cola, elemento);
}

void ordenarCola(struct Cola &cola, int n){
    struct Elemento elemento;
    //Condición de salida
    if(esColaVacia(cola)) return;
    
    //Hallamos el mayor
    int mayor = desencolar(cola).numero;
    for(int i=0; i<n-1; i++){
        int aux = desencolar(cola).numero;
        if(mayor > aux){
            elemento.numero = aux;
            encolar(cola, elemento);
        }
        else{
            elemento.numero = mayor;
            encolar(cola, elemento);
            mayor = aux;
        }
    }
    
    //Llamamos a la función de nuevo para que obtenga los mayores de los n-1 elementos
    ordenarCola(cola, longitud(cola.lista));
    
    //En el regreso de la recursividad encolamos los mayores
    elemento.numero = mayor;
    encolar(cola, elemento);
}

int main(int argc, char** argv) {
    struct Cola cola;
    construir(cola);
    poblarCola(cola);

    cout << "Cola sin ordenar: ";
    imprimir(cola);
    ordenarCola(cola, longitud(cola.lista));
    cout << "Cola ordenada: ";
    imprimir(cola);
    return 0;
}

