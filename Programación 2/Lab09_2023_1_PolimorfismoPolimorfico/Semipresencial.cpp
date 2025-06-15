/* 
 * File:   Semipresencial.cpp
 * Author: AXEL
 * 
 * Created on 14 de junio de 2025, 07:56 PM
 */
#include "utils.h"
#include "Semipresencial.h"


void Semipresencial::SetTotal(double total) {
    this->total = total;
}

double Semipresencial::GetTotal() const {
    return total;
}

void Semipresencial::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Semipresencial::GetDescuento() const {
    return descuento;
}

void Semipresencial::leer(ifstream& arch) {
    Alumno::leer(arch);
    arch>>descuento;
    arch.get();
}

void Semipresencial::imprime(ofstream& arch) {
    Alumno::imprime(arch);
    arch<<fixed<<setprecision(2)<<setw(25)<<Alumno::GetTotal()<<endl;
}

void Semipresencial::actualizatotal(double monto) {
    total = monto * (1 - 20/100);
    Alumno::SetTotal(total);
}
