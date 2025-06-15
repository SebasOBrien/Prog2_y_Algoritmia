/* 
 * File:   Boleta.h
 * Author: AXEL
 *
 * Created on 14 de junio de 2025, 08:02 PM
 */

#ifndef BOLETA_H
#define BOLETA_H
#include "Alumno.h"
class Boleta {
public:
    Boleta();
    virtual ~Boleta();
    void lee(ifstream &);
    void imprime(ofstream &);
    void asignaPresencial();
    void asignaSemipresencial();
    void asignaVirtual();
    bool ultimo();
    int getEscala();
    double getCreditos();
    void actualiza(double);
private:
    class Alumno *pboleta;
};

#endif /* BOLETA_H */

