/* 
 * File:   Presencial.h
 * Author: AXEL
 *
 * Created on 14 de junio de 2025, 07:46 PM
 */

#ifndef PRESENCIAL_H
#define PRESENCIAL_H
#include "Alumno.h"
class Presencial:public Alumno {
public:
    void SetTotal(double total);
    double GetTotal() const;
    void SetRecargo(double recargo);
    double GetRecargo() const;
    void leer(ifstream&) override;
    void imprime(ofstream&) override;
    void actualizatotal(double) override;


private:
    double recargo;
    double total;
};

#endif /* PRESENCIAL_H */

