/* 
 * File:   Escala.h
 * Author: AXEL
 *
 * Created on 14 de junio de 2025, 07:45 PM
 */

#ifndef ESCALA_H
#define ESCALA_H

class Escala {
public:
    Escala();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
private:
    int codigo;
    double precio;
};

#endif /* ESCALA_H */

