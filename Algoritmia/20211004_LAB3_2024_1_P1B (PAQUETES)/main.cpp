
/* 
 * File:   main.cpp
 * Author: Sebastián O'Brien
 *
 * Created on 10 de julio de 2025, 07:18 PM
 */

#include <iostream>

using namespace std;

int evaluarMinimo(int minIzq, int minDer, int minTotal) {
    if(minIzq < minDer and minIzq < minTotal) {
        return minIzq;
    }else if(minDer < minIzq and minDer < minTotal) {
        return minDer;
    }else return minTotal;
}

int buscarMayorAcumulacionCentro(int *arreglo, int inicio, int medio, int fin) {
    bool esPrimero = true;
    int suma = 0, minIzq, minDer, minTotal;
    for (int i = medio; i >= inicio; i--) {
        suma += arreglo[i];
        if (esPrimero or suma < minIzq) {
            minIzq = suma;
        }
        esPrimero = false;
    }
    esPrimero = true;
    suma = 0;
    for (int i = medio + 1; i <= fin; i++) {
        suma += arreglo[i];
        if (esPrimero or suma < minDer) {
            minDer = suma;
        }
        esPrimero = false;
    }
    minTotal = minIzq + minDer;
    return evaluarMinimo(minIzq, minDer, minTotal);
}

int encontrarMayorAcumulacion(int *paquete, int inicio, int fin) {
    if (inicio == fin) {
        return paquete[inicio];
    }
    int medio = (inicio + fin) / 2;
    int minIzq = encontrarMayorAcumulacion(paquete, inicio, medio);
    int minDer = encontrarMayorAcumulacion(paquete, medio + 1, fin);
    int minCentro = buscarMayorAcumulacionCentro(paquete, inicio, medio, fin);
    return evaluarMinimo(minIzq, minDer, minCentro);
}

int main(int argc, char** argv) {
    
    int paquete_1[8] = {2, 5, -6, 2, 3, -1, -5, 6};
    int paquete_2[5] = {2, -3, 4, -5, -7};
    int paquete_3[8] = {-4, 5, 6, -4, 3, -1, -5, 6};
    
    cout << encontrarMayorAcumulacion(paquete_1, 0, 7) << endl;
    cout << encontrarMayorAcumulacion(paquete_2, 0, 4) << endl;
    cout << encontrarMayorAcumulacion(paquete_3, 0, 7) << endl;

    return 0;
}

