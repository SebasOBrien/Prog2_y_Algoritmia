/* 
 * File:   main.cpp
 * Author: AXEL
 *
 * Created on 10 de julio de 2025, 01:10 AM
 */

#include <iostream>
#include <cstring>

using namespace std;
#include "funcionesAB.h"
#include "ArbolB.h"
#include "Lista.h"
#include "funcionesLista.h"
#include "Elemento.h"
/*
 * 
 */

bool listaCompletamenteRecorrida(struct Lista &lista){
    //verificamos si cada letra de la palabra al terminar de recorrer el arbol fue encontrada
    Nodo *recorrido = lista.cabeza;
    while(recorrido!=nullptr){
        if(recorrido->elemento.visto==false)return false;
        recorrido = recorrido->siguiente;
    }
    return true;
}

bool seEncuentraEnLista(struct NodoArbol *nodo,struct Lista &lista){
    //se verifica si la letra del nodo del arbol se encuentra en la lista
    //en caso sea cierto se marcara como letra ya vista
    Nodo *recorrido = lista.cabeza;
    while(recorrido != nullptr){
        if(recorrido->elemento.letra == nodo->elemento.letra
                and recorrido->elemento.visto == false){
            recorrido->elemento.visto=true;
            return true;
        }
        recorrido = recorrido->siguiente;
    }
    return false;
}

int buscarRecursivamentePalabra(struct Lista &lista,struct NodoArbol *nodo){
   if(not esNodoVacio(nodo)){
       if(seEncuentraEnLista(nodo,lista)){ //se hace la suma para tener el contador de nodos recorridos hasta llegar a la hoja
           return 1 + maximo(buscarRecursivamentePalabra(lista,nodo->izquierda), 
                   buscarRecursivamentePalabra(lista,nodo->derecha));
       }
       
       
   }
   return 0;
}

bool existeLaPalabra(char *palabra,struct ArbolBinario &arbol){
    int tam=0;
    Lista lista;
    construir(lista);
    Elemento elemento;
    //insertamos las palabras a una lista para poder verificarla con el arbol
    // EJ: CICLO --> C -> I -> C -> L -> O -> null
    for (int i = 0;palabra[i]!='\0'; i++) {
        elemento.letra=palabra[i];
        elemento.visto=false;
        insertarAlFinal(lista,elemento);
    }
    tam = buscarRecursivamentePalabra(lista,arbol.raiz);
    // se verifica que el recorrido de nodos tenga la misma longitud que la palabra a buscar
    
    if(tam == lista.longitud and listaCompletamenteRecorrida(lista)){
        destruir(lista);
        return true;
    }
    else{
        destruir(lista);
        return false;
    }
    
}




int main(int argc, char** argv) {
    ArbolBinario hoja1,hoja2,hoja3,hoja4,arbol,arbol2,arbol3,arbol4,arbol5,
            arbol6,arbol7,arbol8,arbol9,arbol10,arbol11;
    Elemento elemento;
    //construir
    construir(arbol);
    construir(arbol2);
    construir(arbol3);
    construir(arbol4);
    construir(arbol5);
    construir(arbol6);
    construir(arbol7);
    construir(arbol8);
    construir(arbol9);
    construir(arbol10);
    construir(arbol11);
    construir(hoja1);
    construir(hoja2);
    construir(hoja3);
    construir(hoja4);
    
    //plantar Hojas
    elemento.letra = 'T';
    plantarArbolBinario(hoja1,nullptr,elemento,nullptr);
    elemento.letra = 'O';
    plantarArbolBinario(hoja2,nullptr,elemento,nullptr);
    elemento.letra = 'F';
    plantarArbolBinario(hoja3,nullptr,elemento,nullptr);
    elemento.letra = 'T';
    plantarArbolBinario(hoja4,nullptr,elemento,nullptr);
    
    //plantar nivel siguiente
    elemento.letra = 'R';
    plantarArbolBinario(arbol8,nullptr,elemento,nullptr);
    elemento.letra = 'G';
    plantarArbolBinario(arbol9,hoja1,elemento,nullptr);
    elemento.letra = 'C';
    plantarArbolBinario(arbol10,hoja2,elemento,nullptr);
    elemento.letra = 'A';
    plantarArbolBinario(arbol11,hoja3,elemento,hoja4);
    
    //plantar nivel siguiente
    elemento.letra = 'E';
    plantarArbolBinario(arbol4,nullptr,elemento,nullptr);
    elemento.letra = 'E';
    plantarArbolBinario(arbol5,arbol8,elemento,arbol9);
    elemento.letra = 'C';
    plantarArbolBinario(arbol6,arbol10,elemento,nullptr);
    elemento.letra = 'N';
    plantarArbolBinario(arbol7,arbol11,elemento,nullptr);
    
    //plantar nivel siguiente
    elemento.letra = 'D';
    plantarArbolBinario(arbol2,arbol4,elemento,arbol5);
    elemento.letra = 'I';
    plantarArbolBinario(arbol3,arbol6,elemento,arbol7);
    
    //raiz
    elemento.letra = 'L';
    plantarArbolBinario(arbol,arbol2,elemento,arbol3);
    
    //palabras
    char palabra1[6]="FINAL";
    char palabra2[6]="MUNDO";
    char palabra3[4]="DEL";
    char palabra4[4]="DIA";
    char palabra5[6]="CICLO";
    
    //probamos las palabras
    if(existeLaPalabra(palabra1,arbol)){
        cout<<palabra1<<" ";
        
    }

    if(existeLaPalabra(palabra2,arbol)){
        cout<<palabra2<<" ";
        
    }
    
    
    if(existeLaPalabra(palabra3,arbol)){
        cout<<palabra3<<" ";
        
    }
    
    
    if(existeLaPalabra(palabra4,arbol)){
        cout<<palabra4<<" ";
        
    }
    
    if(existeLaPalabra(palabra5,arbol)){
        cout<<palabra5<<" ";
        
    }
    
    destruirArbolBinario(arbol);
    
    
    
    return 0;
}

