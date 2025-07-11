/* 
 * File:   main.cpp
 * Author: AXEL
 *
 * Created on 22 de noviembre de 2024, 19:04
 */

#include <iostream>

using namespace std;
#include "ArbolB.h"
#include "ArbolBB.h"
#include "funcionesABB.h"
#include "funcionesAB.h"
/*
 * 
 */

void aplicarArbolRec(struct NodoArbol *paquetes,struct NodoArbol *sistema,
        struct NodoArbol *&arbol){
    if(not esNodoVacio(paquetes)){
        int suma=paquetes->elemento+numeroNodosRecursivo(sistema)-numeroHojasRecursivo(sistema);
        insertarRecursivo(arbol,suma);
    }else
        return;
    
    aplicarArbolRec(paquetes->izquierda,sistema->izquierda,arbol);
    aplicarArbolRec(paquetes->derecha,sistema->derecha,arbol);
    
    
}
struct ArbolBinario aplicarArbol(struct ArbolBinarioBusqueda &paquetes,
        struct ArbolBinario &sistema){
    struct ArbolBinario arbol;
    construir(arbol);
    aplicarArbolRec(paquetes.arbolBinario.raiz,sistema.raiz,arbol.raiz);
    return arbol;
    
}
int sumemosLosNodos(struct NodoArbol *raiz){
    if(esNodoVacio(raiz))
        return 0;
    int suma=raiz->elemento;
    suma+=sumemosLosNodos(raiz->izquierda);
    suma+=sumemosLosNodos(raiz->derecha);
    return suma;
}

bool determinarAbb(struct NodoArbol *resultado){
    
    if(not esNodoVacio(resultado)){
        if(resultado->elemento>resultado->izquierda->elemento and
                resultado->elemento<resultado->derecha->elemento){
            return true;
        }else
            return false;
        
        determinarAbb(resultado->izquierda);
        determinarAbb(resultado->derecha);
        
    }
    
}

bool determinar_anomalia(struct ArbolBinario &resultado){
    int sumaNodos=sumemosLosNodos(resultado.raiz);
    
    
    return (sumaNodos%2==0) and determinarAbb(resultado.raiz);
}


int main(int argc, char** argv) {
    struct ArbolBinarioBusqueda paquetes;
    struct ArbolBinario sistema,arbol1,arbol2,arbol3,arbol4;
    construir(paquetes);
    construir(sistema);
    
    insertar(paquetes,6);
    insertar(paquetes,3);
    insertar(paquetes,9);
    
    plantarArbolBinario(arbol1,nullptr,2,nullptr);
    plantarArbolBinario(arbol2,nullptr,3,nullptr);
    plantarArbolBinario(arbol3,arbol1,7,arbol2);
    plantarArbolBinario(arbol4,nullptr,8,nullptr);
    plantarArbolBinario(sistema,arbol3,1,arbol4);
    
    struct ArbolBinario resultado=aplicarArbol(paquetes,sistema);
    recorrerEnOrden(resultado);
    cout<<endl;
    if(determinar_anomalia(resultado)){
        cout<<"No hay anomalia"<<endl;
    }else
        cout<<"Hay anomalia";
    
    return 0;
}

