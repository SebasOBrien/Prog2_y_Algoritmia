/* 
 * File:   Presencial.cpp
 * Author: AXEL
 * 
 * Created on 14 de junio de 2025, 07:46 PM
 */
#include "utils.h"
#include "Presencial.h"


void Presencial::SetTotal(double total) {
    this->total = total;
}

double Presencial::GetTotal() const {
    return total;
}

void Presencial::SetRecargo(double recargo) {
    this->recargo = recargo;
}

double Presencial::GetRecargo() const {
    return recargo;
}

void Presencial::leer(ifstream& arch) {
    Alumno::leer(arch);
    arch>>recargo;
    arch.get();
}

void Presencial::imprime(ofstream& arch) {
    Alumno::imprime(arch);
    arch<<fixed<<setprecision(2)<<setw(25)<<Alumno::GetTotal()<<endl;
}

void Presencial::actualizatotal(double monto) {
    total = monto * (1 + recargo/100);
    Alumno::SetTotal(total);
}
