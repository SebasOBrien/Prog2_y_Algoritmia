
/* 
 * File:   main.cpp
 * Author: Sebastián O'Brien
 *
 * Created on 21 de mayo de 2025, 04:43 PM
 */

#include <iostream>

#include "Cola.h"
#include "funcionesCola.h"

using namespace std;

creaClave(struct Cola &clave){
    struct Elemento elemento;
    elemento.numero = 3;
    encolar(clave, elemento);
    elemento.numero = 1;
    encolar(clave, elemento);
    elemento.numero = 7;
    encolar(clave, elemento);
    elemento.numero = 4;
    encolar(clave, elemento);
}


void cifraConClave(char *textoACifrar){
    struct Cola clave;
    construir(clave);
    creaClave(clave);
    
    struct Elemento elemento;
    for(int i=0; textoACifrar[i]; i++){
        int cifra = desencolar(clave).numero;
        textoACifrar[i] += cifra;
        elemento.numero = cifra;
        encolar(clave, elemento);
    }
}

void descifraConClave(char *textoACifrar){
    struct Cola clave;
    construir(clave);
    creaClave(clave);
    
    struct Elemento elemento;
    for(int i=0; textoACifrar[i]; i++){
        int cifra = desencolar(clave).numero;
        textoACifrar[i] -= cifra;
        elemento.numero = cifra;
        encolar(clave, elemento);
    }
}


int main(int argc, char** argv) {
    
    
    
    char textoACifrar[30] = {"Gente Con Stickmans"};
    cout << "Texto a cifrar: "<<textoACifrar<<endl;
    cifraConClave(textoACifrar);
    cout << "Texto cifrado: "<<textoACifrar<<endl;
    descifraConClave(textoACifrar);
    cout << "Texto descifrado: "<<textoACifrar<<endl;
    
    return 0;
}

