
/* 
 * File:   main.cpp
 * Author: Sebastián O'Brien
 *
 * Created on 22 de mayo de 2025, 07:05 PM
 */

#include <iostream>

#include "Lista.h"
#include "funcionesLista.h"

using namespace std;

void ingresoDeDatos(struct Lista &guerreros, int &n, int &cantGuerreros){
    cout << "Ingrese el valor de n: ";
    cin >> n;
    cout << "Ingrese la cantidad total de guerreros: ";
    cin >> cantGuerreros;
    struct Elemento guerrero;
    for(int i=0; i<cantGuerreros; i++){
        cin >> guerrero.numero;
        insertarAlFinal(guerreros, guerrero);
    }
}

void asignarGuerreros(struct Lista &guerreros, struct Lista &ejercito_Bowser, 
        struct Lista &ejercito_Peach, struct Lista &ejercito_DK){
    struct Elemento guerrero;
    while(not esListaVacia(guerreros)){
        int datosGuerrero = obtenerUltimoNodo(guerreros)->elemento.numero;
        eliminaCola(guerreros);
        
        int nEjercito = datosGuerrero%10;
        int ataque = datosGuerrero/10;
        guerrero.numero = ataque;
        if(nEjercito == 1){
            insertarEnOrden(ejercito_Bowser, guerrero);
            ejercito_Bowser.sumaAtaques += guerrero.numero;
        }else if(nEjercito == 2){
            insertarEnOrden(ejercito_Peach, guerrero);
            ejercito_Peach.sumaAtaques += guerrero.numero;
        }else{
            insertarEnOrden(ejercito_DK, guerrero);
            ejercito_DK.sumaAtaques += guerrero.numero;
        }
    }
    destruir(guerreros);
}

struct Nodo * extraerUltimoNodo(struct Lista &ej_refuerzo){
    struct Nodo * penultimo = nullptr;
    struct Nodo * ultimo = nullptr;
    struct Nodo* recorrido = ej_refuerzo.cabeza;

    while (recorrido != nullptr) {
        penultimo = ultimo;
        ultimo = recorrido;
        recorrido = recorrido->siguiente;
    }
    if(penultimo == nullptr){
        ej_refuerzo.cabeza = nullptr;
    } else penultimo->siguiente = nullptr;
    return ultimo;
}

void insertarNodoEnOrden(struct Lista &ej_principal, struct Nodo *&nodoGuerrero){
    struct Nodo * nodoAnterior = nullptr;
    struct Nodo * nodoActual = ej_principal.cabeza;
    //Buscamos en que posición debe ingresar el guerrero
    while(nodoActual != nullptr and (nodoActual->elemento.numero < nodoGuerrero->elemento.numero)){
        nodoAnterior = nodoActual;
        nodoActual = nodoActual->siguiente;
    }
    if(nodoAnterior == nullptr) { //Si la lista está vacía
        nodoGuerrero->siguiente = ej_principal.cabeza;
        ej_principal.cabeza = nodoGuerrero;
    }else{
        nodoAnterior->siguiente = nodoGuerrero;
        nodoGuerrero->siguiente = nodoActual;
    }
    ej_principal.longitud++;
}

void integrarEjercito(struct Lista &ej_principal, struct Lista &ej_refuerzo){
    while(not esListaVacia(ej_refuerzo)){
        struct Nodo *nodoGuerrero = extraerUltimoNodo(ej_refuerzo);
        
        insertarNodoEnOrden(ej_principal, nodoGuerrero);
        ej_principal.sumaAtaques += nodoGuerrero->elemento.numero;
    }
    destruir(ej_refuerzo);
}

void simularBatalla(struct Lista &ejercito_Bowser, struct Lista &ejercito_Peach, 
        struct Lista &ejercito_DK, int n){
    bool reforzado = false;
    int ganador;
    while(not esListaVacia(ejercito_Bowser) and not esListaVacia(ejercito_Peach)){
        cout << endl << "Inicia la batalla: " << endl;
        cout << "Ejercito 1 - Bowser: ";
        imprime(ejercito_Bowser);
        cout << "Ejercito 2 - Peach: ";
        imprime(ejercito_Peach);
        struct Nodo *guerreroActual_Bowser = ejercito_Bowser.cabeza;
        struct Nodo *guerreroActual_Peach = ejercito_Peach.cabeza;
        for(int i=0; i<n; i++){
            struct Elemento guerrero_Bowser =  guerreroActual_Bowser->elemento;
            struct Elemento guerrero_Peach =  guerreroActual_Peach->elemento;
            if(guerrero_Bowser.numero > guerrero_Peach.numero){
                ganador = guerrero_Bowser.numero;
                ejercito_Peach.sumaAtaques -= guerrero_Peach.numero;
                eliminaNodo(ejercito_Peach, guerrero_Peach);
            }else if(guerrero_Peach.numero > guerrero_Bowser.numero){
                ganador = guerrero_Peach.numero; 
                ejercito_Bowser.sumaAtaques -= guerrero_Bowser.numero;
                eliminaNodo(ejercito_Bowser, guerrero_Bowser);
            }else{
                ganador = 0; 
                ejercito_Bowser.sumaAtaques -= guerrero_Bowser.numero;
                ejercito_Peach.sumaAtaques -= guerrero_Peach.numero;
                eliminaNodo(ejercito_Bowser, guerrero_Bowser);
                eliminaNodo(ejercito_Peach, guerrero_Peach);
            }
            cout << "Pelea " << i+1 << ": " << guerrero_Bowser.numero << " vs " <<
                    guerrero_Peach.numero << ", ";
            if(ganador == 0) cout << "nadie gana " << endl;
            else cout << "gana " << ganador << endl;
            if(guerreroActual_Bowser->siguiente == nullptr or 
                    guerreroActual_Peach->siguiente == nullptr) break;
            guerreroActual_Bowser = guerreroActual_Bowser->siguiente;
            guerreroActual_Peach = guerreroActual_Peach->siguiente;
        }
        cout << "Nivel de Ataque Total del ejercito 1: " << ejercito_Bowser.sumaAtaques << endl;
        cout << "Nivel de Ataque Total del ejercito 2: " << ejercito_Peach.sumaAtaques << endl;
        if(ejercito_Peach.sumaAtaques > ejercito_Bowser.sumaAtaques){
            cout << "El ejercito de Peach no necesita refuerzos." << endl;
        }
        else if(reforzado==false){
            integrarEjercito(ejercito_Peach, ejercito_DK);
            cout << "El ejercito de Donkey Kong se une al ejercito de Peach." << endl;
            reforzado = true;
        }else{
            cout << "Ya no se puede unir nadie al ejército de Peach." << endl;
        }
    }
    if(esListaVacia(ejercito_Peach) and esListaVacia(ejercito_Bowser))
        cout << "Ambos ejercitos perecieron en combate";
    else if(esListaVacia(ejercito_Peach)) cout << "Gana la batalla Bowser";
    else cout << "Gana la batalla Peach";
}

int main(int argc, char** argv) {
    
    struct Lista guerreros;
    construir(guerreros);
    
    int n, cantGuerreros;
    ingresoDeDatos(guerreros, n, cantGuerreros);
    cout << "Lista Guerreros: ";
    imprime(guerreros);
    
    struct Lista ejercito_Bowser, ejercito_Peach, ejercito_DK;
    construir(ejercito_Bowser);
    construir(ejercito_Peach);
    construir(ejercito_DK);
    
    asignarGuerreros(guerreros, ejercito_Bowser, ejercito_Peach, ejercito_DK);
    cout << endl << "Ejercito 1 - Bowser: ";
    imprime(ejercito_Bowser);
    cout << "Nivel de Ataque Total del Ejército 1: " << ejercito_Bowser.sumaAtaques << endl;
    cout << endl << "Ejercito 2 - Peach: ";
    imprime(ejercito_Peach);
    cout << "Nivel de Ataque Total del Ejército 2: " << ejercito_Peach.sumaAtaques << endl;
    cout << endl << "Ejercito 3 - Donkey Kong: ";
    imprime(ejercito_DK);
    cout << "Nivel de Ataque Total del Ejército 3: " << ejercito_DK.sumaAtaques << endl;
    
    simularBatalla(ejercito_Bowser, ejercito_Peach, ejercito_DK, n);
    
    return 0;
}

// Casos de prueba:
// 723 182 123 262 851 352 653 103 561 841 391 241 n=12
// 952 753 951 852 653 482 152 632 521 253 853 452 192 862 751 131 561 n=17
// 413 932 781 262 823 511 392 341 652 112 743 931 502 613 282 781 322 853 441 962 n=20

