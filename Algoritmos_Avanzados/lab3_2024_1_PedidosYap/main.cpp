#include <iostream>

#include "Grafo.h"
using namespace std;


int main() {
    int num_vertices = 8; //cantidad de nodos del grafo :0, un poco obvio diria yo pero uno nunca sabe
    Grafo grafo(num_vertices);
    grafo.agregar_arista('A','B',4);
    grafo.agregar_arista('A','C',5);
    grafo.agregar_arista('A','D',6);
    grafo.agregar_arista('B','E',2);
    grafo.agregar_arista('C','H',3);
    grafo.agregar_arista('D','F',3);
    grafo.agregar_arista('E','G',10);
    grafo.agregar_arista('F','G',2);
    char origen,destino;
    cout<<"Ingresa el punto de partida: "<<endl;
    cin>>origen;
    cout<<"Ingresa el punto de destino: "<<endl;
    cin>>destino;

    grafo.diksjtra(origen,destino);

    return 0;
}