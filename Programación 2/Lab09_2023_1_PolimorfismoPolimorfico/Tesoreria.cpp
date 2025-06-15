/* 
 * File:   Tesoreria.cpp
 * Author: AXEL
 * 
 * Created on 14 de junio de 2025, 08:04 PM
 */
#include "utils.h"
#include "Escala.h"
#include "Boleta.h"
#include "Tesoreria.h"
#include "funcionesAux.h"
#include "Alumno.h"

Tesoreria::Tesoreria() {
}

Tesoreria::~Tesoreria() {
}

void Tesoreria::cargaalumnos(const char* name) {
    ifstream arch=abrirArchivoLectura(name);
    int numBoletas=0;
    char tipo,c;
    while(true){
        arch>>tipo>>c;
        if(arch.eof())break;
        switch(tipo){
            case 'S':
                lboleta[numBoletas].asignaSemipresencial();
                break;
            case 'P':
                lboleta[numBoletas].asignaPresencial();
                break;
            case 'V':
                lboleta[numBoletas].asignaVirtual();
                break;
        }
        lboleta[numBoletas].lee(arch);
        numBoletas++;
    }
}

void Tesoreria::cargaescalas(const char* name) {
    ifstream arch=abrirArchivoLectura(name);
    int cod;
    double price;
    while(true){
        arch>>cod;
        if(arch.eof())break;
        arch.get();
        arch>>price;
        lescala[cod-1].SetCodigo(cod);
        lescala[cod-1].SetPrecio(price);
    }
    
}

void Tesoreria::imprimeboleta(const char* name) {
    ofstream arch = abrirArchivoEscritura(name);
    arch<<left<<setw(19)<<"Codigo"<<setw(60)<<"Nombre"<<setw(12)<<"Escala"<<
            setw(10)<<"Cred."<<setw(15)<<"Licencia"<<"Total"<<endl;
    imprimerLinea(arch,'=');
    for(int i=0;not lboleta[i].ultimo();i++){
        lboleta[i].imprime(arch);
    }
}

void Tesoreria::actualizaboleta(){
    int esc;
    double creditos,monto,price;
    
    for(int i=0;not lboleta[i].ultimo();i++){
        esc = lboleta[i].getEscala();
        creditos = lboleta[i].getCreditos();
        price = lescala[esc-1].GetPrecio();
        lboleta[i].actualiza(price * creditos);
    }
}
