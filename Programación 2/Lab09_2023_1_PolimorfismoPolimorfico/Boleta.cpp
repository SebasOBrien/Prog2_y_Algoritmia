/* 
 * File:   Boleta.cpp
 * Author: AXEL
 * 
 * Created on 14 de junio de 2025, 08:02 PM
 */
#include "utils.h"
#include "Boleta.h"
#include "Alumno.h"
#include "Presencial.h"
#include "Semipresencial.h"
#include "Virtual.h"

Boleta::Boleta() {
    pboleta=nullptr;
    
}



Boleta::~Boleta() {
    if(pboleta!=nullptr)delete pboleta;
}

void Boleta::asignaPresencial() {
    pboleta = new Presencial;
}

void Boleta::asignaSemipresencial() {
    pboleta = new Semipresencial;
}

void Boleta::asignaVirtual() {
    pboleta = new Virtual;
}

void Boleta::lee(ifstream& arch) {
    pboleta->leer(arch);
}

void Boleta::imprime(ofstream& arch) {
    pboleta->imprime(arch);
}

bool Boleta::ultimo() {
    return pboleta==nullptr;
}

int Boleta::getEscala() {
    return pboleta->GetEscala();
}

double Boleta::getCreditos() {
    return pboleta->GetCreditos();
}

void Boleta::actualiza(double monto) {
    pboleta->actualizatotal(monto);
}

