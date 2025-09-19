//
// Created by AXEL on 21/08/2025.
//

#ifndef SOPADELETRAS_SOPALETRAS_H
#define SOPADELETRAS_SOPALETRAS_H

#include <string>
#include <vector>
using namespace std;

class SopaDeLetras {
public:
    SopaDeLetras();



    bool encontrarSolucion(string palabra);

private:
    int filas;
    int columnas;
    vector<vector<char> > tabla;

    void inicializarTabla();
    bool encontrarSolucionRecursiva(int i, string palabra, int fil, int col, vector<vector<bool>> visitado);
};
#endif //SOPADELETRAS_SOPALETRAS_H
