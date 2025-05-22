
/* 
 * File:   main.cpp
 * Author: Sebastián O'Brien
 *
 * Created on 21 de mayo de 2025, 08:23 PM
 */

#include <iostream>

#include "Cola.h"
#include "funcionesCola.h"

#define TIEMPO_ENTRE_CLIENTES 15
#define TIEMPO_PROCESAMIENTO 120

using namespace std;

void simularDespachoEntradas(int numCajeros, int numClientes){
    struct Cola colaClientes;
    construir(colaClientes);
    
    int cajeros[numCajeros]{};
    bool cajeroOcupado[numCajeros]{};
    
    int horaActual = 0, posCliente = 1, clientesAtendidos = 0;
    struct Elemento cliente;
    while(clientesAtendidos < numClientes){
        //Ingresa el cliente
        if(posCliente <= numClientes){
            cliente.numero = posCliente;
            cliente.horaLlegada = horaActual;
            encolar(colaClientes, cliente);
        }
        for(int i=0; i<numCajeros; i++){
            if((cajeros[i] == 0 and cajeroOcupado[i] != true) or (horaActual - cajeros[i]>=TIEMPO_PROCESAMIENTO)){
                desencolar(colaClientes);
                clientesAtendidos++;
                cout << "Atendiendo al cliente " << clientesAtendidos << " en la caja " << 
                        i+1 << " luego de " << horaActual << "s" << endl;
                cajeros[i] = horaActual;
                cajeroOcupado[i] = true;
                break;
            }
        }
        horaActual += TIEMPO_ENTRE_CLIENTES;
        posCliente++;
    }
}

int main(int argc, char** argv) {

    int nCajeros = 2, nClientes = 10;
    simularDespachoEntradas(nCajeros, nClientes);
    
    return 0;
}

