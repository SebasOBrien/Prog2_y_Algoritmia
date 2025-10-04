//
// Created by AXEL on 27/09/2025.
//

#include "Grafo.h"

#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#define ZONA_NULA 'Z'

Grafo::Grafo(int numero_vertices) {
    this->num_vertices = numero_vertices;
    this->lista_vecinos.resize(num_vertices);
}

void Grafo::agregar_arista(char u, char v, int peso) {
    int posicion = u - 'A';
    this->lista_vecinos[posicion].emplace_back(v, peso);
    sort((this->lista_vecinos[posicion].begin()),(this->lista_vecinos[posicion].end()),
        [](const pair<char,int>&a,const pair<char,int>&b) {
            return a.second > b.second;
        });
}

void Grafo::imprimirSolucion(vector<int> costo,int posDestino,int posOrigen,char origen) {
    vector<char> aux;
    if (costo[posDestino] != 0) {
        cout<<"Ruta tomada: ";
        int posActual = posDestino;
        while (posActual != posOrigen) {
            char auxNodo  = posActual + 'A';
            aux.push_back(auxNodo);
            posActual = this->ruta[posActual];
        }
        cout<<origen<<" -> ";
        for (int i = aux.size()-1 ; i >=0; i--) {
            cout<<aux[i];
            if (i > 0) cout<<" -> ";
        }
        cout<<endl;
        cout<<"Se tardara en llegar un total de : "<<costo[posDestino]<<" minutos"<<endl;
    }else {
        cout<<"Es imposible llegar D:"<<endl;
    }
}
void Grafo::apilarVecinos(char posicionChar,stack<pair<char,char>>&pila) {
    int posicion = posicionChar - 'A';
    for (int i = 0; i < lista_vecinos[posicion].size(); i++) {
        char posAux = lista_vecinos[posicion][i].first;
        pair<char,char> aux = {posicionChar,posAux};
        pila.push(aux);
    }
}

int Grafo::devolverPeso(char origen, char destino) {
    int posOrigen = origen - 'A';
    for (int i = 0 ; i<lista_vecinos[posOrigen].size();i++) {
        if (lista_vecinos[posOrigen][i].first == destino) {
            return lista_vecinos[posOrigen][i].second;
        }
    }
    return 0;
}

void Grafo::diksjtra(char origen, char destino) {
    int posOrigen = origen - 'A';
    int posDestino = destino - 'A';
    this->ruta.resize(this->num_vertices,-1);
    vector<int> costo(this->num_vertices, 0);
    stack<pair<char,char>> pila;
    //inicializamos la pila
    apilarVecinos(origen, pila);
    while (pila.empty() == false){
        char origenAux = pila.top().first;
        char destinoAux = pila.top().second;
        int posOrigenAux = origenAux - 'A';
        int posDestinoAux = destinoAux - 'A';
        pila.pop();
        int pesoAux = devolverPeso(origenAux, destinoAux);
        costo[posDestinoAux] = pesoAux + costo[posOrigenAux];
        this->ruta[posDestinoAux] = posOrigenAux;
        apilarVecinos(destinoAux,pila);
        if (destino == destinoAux) {
            break;
        }
    }
    imprimirSolucion(costo,posDestino,posOrigen,origen);
}









