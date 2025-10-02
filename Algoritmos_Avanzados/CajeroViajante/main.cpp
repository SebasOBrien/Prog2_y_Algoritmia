#include <algorithm>
#include <iostream>
#include <vector>
#include <limits>
using namespace std;


int escogerCiudadProx(int pos_actual,vector<vector<int>> matris,vector<int> por_visitar) {
    int menor = numeric_limits<int>::max();
    int prox;
    for (int i = 0; i < por_visitar.size(); i++) {
        if (matris[pos_actual][por_visitar[i]] < menor) {
            menor = matris[pos_actual][por_visitar[i]];
            prox = por_visitar[i];
        }
    }
    return prox;
}

void NearestNeighborAlgorithm(vector<vector<int>> matris,int ciudadOrigen) {
    //iniciailizamos las ciudades por visitar
    vector<int> ruta;
    vector<int> distancia;
    ruta.push_back(ciudadOrigen);
    vector<int> por_visitar;
    int distancia_recorrida = 0;
    //inicialisamos
    int ciudad_actual = ciudadOrigen,prox_ciudad;
    for (int i = 0; i < matris[0].size(); i++) {
        if (i != ciudadOrigen) {
            por_visitar.push_back(i);
        }
    }
    while (por_visitar.size() != 0) {
        prox_ciudad = escogerCiudadProx(ciudad_actual,matris,por_visitar);
        ruta.push_back(prox_ciudad);
        distancia.push_back(matris[ciudad_actual][prox_ciudad]);
        auto nuevo_fin = remove(por_visitar.begin(),por_visitar.end(),prox_ciudad);
        por_visitar.erase(nuevo_fin,por_visitar.end());
        ciudad_actual = prox_ciudad;
    }
    ruta.push_back(ciudadOrigen);
    distancia.push_back(matris[prox_ciudad][ciudadOrigen]);
    for (int i = 0;i < ruta.size(); i++) {
        cout<<ruta[i];
        if (i < ruta.size() - 1) {
            cout<<" -> ";
        }else {
            cout<<endl;
        }
    }
    for (int i = 0; i < distancia.size(); i++) {
        distancia_recorrida += distancia[i];
        if (i < distancia.size() - 1) {
            cout<<distancia[i]<<" + ";
        }else {
            cout <<distancia[i]<<" = "<<distancia_recorrida<<endl;
        }

    }

}



int main() {
    vector<vector<int> > matris = {
        {0, 2, 9, 10, 7},
        {2, 0, 6, 4, 3},
        {9, 6, 0, 8, 5},
        {10, 4, 8, 0, 6},
        {7, 3, 5, 6, 0}
    };

    NearestNeighborAlgorithm(matris,0);
    return 0;
}
