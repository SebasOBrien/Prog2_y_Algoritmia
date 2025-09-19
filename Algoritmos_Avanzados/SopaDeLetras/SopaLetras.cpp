//
// Created by AXEL on 21/08/2025.
//

#include "SopaLetras.h"


SopaDeLetras::SopaDeLetras() {
    this->filas = 3;
    this->columnas = 4;
    this->inicializarTabla();
}

void SopaDeLetras::inicializarTabla() {
    this->tabla = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
}

bool SopaDeLetras::encontrarSolucion(string palabra) {
    for (int i = 0; i < this->filas; i++) {
        for (int j = 0; j < this->columnas; j++) {
            if (this->tabla[i][j] == palabra[0]) {

                vector<vector<bool> > visitado(this->filas, vector<bool>(this->columnas, false));
                if (encontrarSolucionRecursiva(0, palabra, i, j, visitado)) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool SopaDeLetras::encontrarSolucionRecursiva(int i, string palabra, int fil, int col, vector<vector<bool> > visitado) {
    if (i == palabra.length()) {
        return true;
    }
    if (fil < 0 || fil >= this->filas || col < 0 || col >= this->columnas ||
        visitado[fil][col] || this->tabla[fil][col] != palabra[i]) {
        return false;
    }
    visitado[fil][col] = true;

    bool encontrado = encontrarSolucionRecursiva(i + 1, palabra, fil + 1, col, visitado) ||
                      encontrarSolucionRecursiva(i + 1, palabra, fil, col + 1, visitado) ||
                      encontrarSolucionRecursiva(i + 1, palabra, fil - 1, col, visitado) ||
                      encontrarSolucionRecursiva(i + 1, palabra, fil, col - 1, visitado);
    visitado[fil][col] = false;
    return encontrado;
}
