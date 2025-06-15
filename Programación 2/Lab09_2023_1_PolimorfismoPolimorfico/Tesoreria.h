/* 
 * File:   Tesoreria.h
 * Author: AXEL
 *
 * Created on 14 de junio de 2025, 08:04 PM
 */

#ifndef TESORERIA_H
#define TESORERIA_H
#include "Boleta.h"
#include "Escala.h"

class Tesoreria {
public:
    Tesoreria();
    virtual ~Tesoreria();
    void cargaalumnos(const char*);
    void cargaescalas(const char*);
    void imprimeboleta(const char*);
    void actualizaboleta();
private:
    class Boleta lboleta[200];
    class Escala lescala[10];
};

#endif /* TESORERIA_H */

