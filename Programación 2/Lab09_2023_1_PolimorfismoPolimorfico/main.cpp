/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: AXEL
 *
 * Created on 14 de junio de 2025, 07:31 PM
 */

#include "utils.h"
#include "Tesoreria.h"

/*
 * 
 */
int main(int argc, char** argv) {
    Tesoreria tesoreriatesorerin;
    tesoreriatesorerin.cargaalumnos("Alumnos.csv");
    tesoreriatesorerin.cargaescalas("escalas.csv");
    tesoreriatesorerin.imprimeboleta("reporteReportinSinTotales.txt");
    tesoreriatesorerin.actualizaboleta();
    tesoreriatesorerin.imprimeboleta("reporteActualizadoOseaCompleto.txt");
    return 0;
}

