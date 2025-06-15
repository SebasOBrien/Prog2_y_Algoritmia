/* 
 * File:   Virtual.cpp
 * Author: AXEL
 * 
 * Created on 14 de junio de 2025, 08:01 PM
 */
#include "utils.h"
#include "Virtual.h"
#include "Alumno.h"
#include "funcionesAux.h"


void Virtual::SetTotal(double total) {
    this->total = total;
}

double Virtual::GetTotal() const {
    return total;
}

void Virtual::SetLicencia(char* licenciaNew) {
    setCadena(licencia,licenciaNew);
}

void Virtual::GetLicencia(char* aux) const {
    getCadena(licencia,aux);
}

void Virtual::leer(ifstream& arch) {
    char aux[15];
    Alumno::leer(arch);
    arch.getline(aux,15,'\n');
    SetLicencia(aux);
}

void Virtual::imprime(ofstream& arch) {
    Alumno::imprime(arch);
    arch<<setw(5)<<' '<<left<<setw(10)<<licencia<<right<<setw(10)<<Alumno::GetTotal()<<endl;
}

void Virtual::actualizatotal(double monto) {
    total = 100 + monto;
    Alumno::SetTotal(total);
}
