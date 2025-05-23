
/* 
 * File:   main.cpp
 * Author: Sebastián O'Brien
 *
 * Created on 23 de mayo de 2025, 04:23 PM
 */

#include <iostream>

#include "Elemento.h"
#include "Pila.h"
#include "funcionesPila.h"

using namespace std;

void nautilus(char *instrucciones){
    struct Pila profundidad;
    construir(profundidad);
    int nivel = 0;
    struct Elemento elemento;
    elemento.numero = nivel + 1; //Inicia al nivel del suelo
    apilar(profundidad, elemento);
    while(instrucciones[nivel]){
        //Si la instrucción es S desapilará hasta que la pila esté vacía mostrando los niveles     
        if(instrucciones[nivel] == 'S'){
            while(not esPilaVacia(profundidad)){
                cout << desapilar(profundidad).numero << " ";
            }
        }
        //Si es B solo apilará el siguiente nivel
        nivel++;
        elemento.numero = nivel + 1;
        apilar(profundidad, elemento);
    }
    //Desapilamos el último nivel que quedó en la pila
    cout << desapilar(profundidad).numero <<endl;
}

int main(int argc, char** argv) {

    char instrucciones[10] = {'S', 'B', 'S', 'B', 'B', 'S', 'S'};
    cout << "Dada las instrucciones: " << instrucciones << endl;
    cout << "Nautilus sigue el siguiente recorrido: ";
    nautilus(instrucciones);
    
    return 0;
}

