/* 
 * File:   funcionesAux.cpp
 * Author: AXEL
 * 
 * Created on 14 de junio de 2025, 07:31 PM
 */
#include "utils.h"
#include "funcionesAux.h"
#define LINEA 123
void setCadena(char *&cadenaClase,const char* cadenaNew){
    if(cadenaClase!=nullptr)delete cadenaClase;
    cadenaClase =new char[strlen(cadenaNew)+1];
    strcpy(cadenaClase,cadenaNew);
}

void getCadena(const char *cadenaClase,char *&cadenaGuardar){
    if(cadenaClase==nullptr)cadenaGuardar[0]=0;
    else
        strcpy(cadenaGuardar,cadenaClase);
}

ifstream abrirArchivoLectura(const char*name){
    ifstream arch(name,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR en la apertura del archivo "<<name;
        exit(1);
    }
    return arch;
}

ofstream abrirArchivoEscritura(const char*name){
    ofstream arch(name,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR en la apertura del archivo "<<name;
        exit(1);
    }
    return arch;
}

void imprimerLinea(ofstream &arch,char caracter){
    for(int i=0;i<LINEA;i++)
        arch.put(caracter);
    arch<<endl;
}