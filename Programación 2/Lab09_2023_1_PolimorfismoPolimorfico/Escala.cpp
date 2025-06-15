/* 
 * File:   Escala.cpp
 * Author: AXEL
 * 
 * Created on 14 de junio de 2025, 07:45 PM
 */
#include "utils.h"
#include "Escala.h"

Escala::Escala() {
    codigo=0;
    precio=0.0;
}


void Escala::SetPrecio(double precio) {
    this->precio = precio;
}

double Escala::GetPrecio() const {
    return precio;
}

void Escala::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Escala::GetCodigo() const {
    return codigo;
}


