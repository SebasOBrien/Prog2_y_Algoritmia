/* 
 * File:   Alumno.cpp
 * Author: AXEL
 * 
 * Created on 14 de junio de 2025, 07:37 PM
 */
#include "utils.h"
#include "funcionesAux.h"
#include "Alumno.h"

Alumno::Alumno() {
    inicialisa();
}

Alumno::Alumno(const Alumno& orig) {
}

Alumno::~Alumno() {
    if(nombre!=nullptr)delete nombre;
}

void Alumno::SetTotal(double total) {
    this->total = total;
}

double Alumno::GetTotal() const {
    return total;
}

void Alumno::SetCreditos(double creditos) {
    this->creditos = creditos;
}

double Alumno::GetCreditos() const {
    return creditos;
}

void Alumno::SetEscala(int escala) {
    this->escala = escala;
}

int Alumno::GetEscala() const {
    return escala;
}

void Alumno::SetNombre(char* newName) {
    setCadena(nombre,newName);
}

void Alumno::GetNombre(char*aux) const {
    getCadena(nombre,aux);
}

void Alumno::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Alumno::GetCodigo() const {
    return codigo;
}

void Alumno::inicialisa() {
    codigo=0;
    creditos=0.0;
    escala=0;
    nombre=nullptr;
    total=0.0;
}

void Alumno::leer(ifstream& arch) {
    char aux[100],c;
    arch>>codigo>>c;
    arch.getline(aux,100,',');
    SetNombre(aux);
    arch>>escala>>c>>creditos>>c;
}

void Alumno::imprime(ofstream& arch) {
    arch<<codigo<<setw(10)<<' '<<left<<setw(60)<<nombre<<right<<setw(3)<<escala<<
            fixed<<setprecision(2)<<setw(14)<<creditos;
}


