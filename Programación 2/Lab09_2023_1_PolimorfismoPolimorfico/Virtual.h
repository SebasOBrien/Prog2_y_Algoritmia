/* 
 * File:   Virtual.h
 * Author: AXEL
 *
 * Created on 14 de junio de 2025, 08:01 PM
 */

#ifndef VIRTUAL_H
#define VIRTUAL_H

#include "Alumno.h"


class Virtual:public Alumno {
public:
    void leer(ifstream&) override;
    void SetTotal(double total);
    double GetTotal() const;
    void SetLicencia(char* licencia);
    void GetLicencia(char*) const;
    void imprime(ofstream&) override;
    void actualizatotal(double) override;


private:
    char* licencia;
    double total;
};

#endif /* VIRTUAL_H */

