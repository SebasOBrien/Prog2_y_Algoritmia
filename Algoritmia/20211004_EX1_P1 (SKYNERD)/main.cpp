
/* 
 * File:   main.cpp
 * Author: Sebastián O'Brien
 *
 * Created on 22 de mayo de 2025, 02:44 PM
 */

#include <iostream>

#include "Elemento.h"
#include "Pila.h"
#include "funcionesPila.h"

using namespace std;

//Verificamos que sea SKYNERD revisando que no reciba paquetes de ningún servidor

bool verificarSkynerd(int paquetes[][7], int posibleSkynerd, int n) {
    for (int i = 0; i < n; i++) {
        if (paquetes[i][posibleSkynerd] != 0) return false;
    }
    return true;
}

void encontrarSkynerd(int paquetes[][7], int cantServidores) {
    struct Pila servidores;
    construir(servidores);
    struct Elemento elemento;
    //Llenamos una pila con la cantidad de servidores
    for (int i = 0; i < cantServidores; i++) {
        elemento.numero = i;
        apilar(servidores, elemento);
    }
    while (true) {
        int servidor_1 = desapilar(servidores).numero;
        if (not esPilaVacia(servidores)) {
            int servidor_2 = desapilar(servidores).numero;
            //Desapilamos los dos primeros elementos y evaluamos
            if (paquetes[servidor_1][servidor_2] != 0) {
                /*Si servidor_2 ha recibido paquetes, no puede ser SKYNERD 
                 * así que apilamos servidor_1*/
                elemento.numero = servidor_1;
            } else {
                /*Si servidor_2 no ha recibido paquetes, puede ser SKYNERD 
                 * así que lo apilamos*/
                elemento.numero = servidor_2;
            }
            apilar(servidores, elemento);
        } else {
            //Ingresa aquí cuando solo queda 1 elemento en la pila, que es el posible Skynerd
            elemento.numero = servidor_1;
            apilar(servidores, elemento);
            break;
        }
    }
    int posibleSkynerd = desapilar(servidores).numero;
    //Verificamos que sea SKYNERD
    if (verificarSkynerd(paquetes, posibleSkynerd, cantServidores)) {
        cout << "Skynerd ha sido encontrado en el servidor " << posibleSkynerd + 1;
    } else cout << "Skynerd no ha sido encontrado";
}

int main(int argc, char** argv) {

    int paquetes[7][7] = {
        {   0,  0,  0,  0,  0,  0,  0},
        {  10,  0, 20, 30,  0, 20, 40},
        {   0,  0,  0,  0,  0,100,  0},
        {   0,  0,  0,  0,  0, 80,  0},
        {  50, 10,  5, 10,  0,100,  4},
        { 100,  0,  0,  0,  0,  0,  0},
        {   0,  0,  0,  0,  0,  0,  0},
    };

    int cantServidores = 7;
    encontrarSkynerd(paquetes, cantServidores);

    return 0;
}

