/* 
 * File:   Semipresencial.h
 * Author: AXEL
 *
 * Created on 14 de junio de 2025, 07:56 PM
 */

#ifndef SEMIPRESENCIAL_H
#define SEMIPRESENCIAL_H
#include "Alumno.h"
class Semipresencial:public Alumno {
public:
    void SetTotal(double total);
    double GetTotal() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void leer(ifstream&) override;
    void imprime(ofstream&) override;
    void actualizatotal(double) override;


private:
    double descuento;
    double total;
};

#endif /* SEMIPRESENCIAL_H */

