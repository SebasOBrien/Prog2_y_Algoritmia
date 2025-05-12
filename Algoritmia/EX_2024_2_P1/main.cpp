
/* 
 * File:   main.cpp
 * Author: Sebastián O'Brien
 *
 * Created on 12 de mayo de 2025, 02:35 PM
 */

#include <iostream>

#include "funcionesPila.h"
#include "Pila.h"
#include "funcionesLista.h"

using namespace std;

void encuentraPilas(int *productosApilados, int n){
    struct Pila pilaAux;
    construir(pilaAux);
    struct Elemento elemento;
    int numeroMax = 0, sumaPilas = 0, sumaPilasMax = 0, posMax = 0;
    //Encuentra el numero máx
    for(int i=0; i<n; i++){
        if(productosApilados[i] > numeroMax){
            numeroMax = productosApilados[i];
        }
    }
    //Encuentra las posiciones del numero máx y las apila
    for(int i=0; i<n; i++){
        if(productosApilados[i]==numeroMax){
            elemento.numero = i;
            apilar(pilaAux, elemento);
        }
    }
    //Calculamos las pilas inferiores entre las posiciones de los numeros máx
    int lim_der = n-1, lim_izq;
    int izq, der;
    while(not esPilaVacia(pilaAux)){
        elemento = desapilar(pilaAux);
        int num = elemento.numero;
        der = lim_der - num;
        if(not esPilaVacia(pilaAux)){
            elemento = cima(pilaAux);
            lim_izq = elemento.numero;
            izq = num -1 - lim_izq;
            
        }else izq = num;
        sumaPilas = izq + der;
        if(sumaPilas>sumaPilasMax){
            sumaPilasMax = sumaPilas;
            posMax = num;
        }
        lim_der = num-1;
    }
    
    cout<<"Posicion = "<<posMax<<", "<<sumaPilasMax
            <<" pilas inferiores alrededor"<<endl;
    
}

int main(int argc, char** argv) {
    
    int productosApilados[20] = {1, 7, 2, 7, 3, 4, 3, 2, 1, 7, 2, 1, 7, 3};
    encuentraPilas(productosApilados, 14);

    return 0;
}

