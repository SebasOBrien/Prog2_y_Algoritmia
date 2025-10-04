//
// Created by AXEL on 27/09/2025.
//

#ifndef LAB3_2024_1_PEDIDOSYAP_GRAFO_H
#define LAB3_2024_1_PEDIDOSYAP_GRAFO_H
#include <stack>
#include <vector>
using namespace std;

class Grafo {
public:
    Grafo(int numero_vertices);
    void agregar_arista(char u,char v,int peso);
    void imprimirSolucion(vector<int> costo, int posDestino, int posOrigen, char origen);

    void apilarVecinos(char posicionChar, stack<pair<char, char>> &pila);

    int devolverPeso(char origen, char destino);

    void diksjtra(char origen,char destino);

private:
    int num_vertices;
    vector<vector<pair<char, int>>> lista_vecinos; //(vertice, peso);
    vector<int> ruta;




};


#endif //LAB3_2024_1_PEDIDOSYAP_GRAFO_H