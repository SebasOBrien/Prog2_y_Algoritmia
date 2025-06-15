/* 
 * File:   Alumno.h
 * Author: AXEL
 *
 * Created on 14 de junio de 2025, 07:37 PM
 */

#ifndef ALUMNO_H
#define ALUMNO_H

class Alumno {
public:
    Alumno();
    Alumno(const Alumno& orig);
    virtual ~Alumno();
    void SetTotal(double total);
    double GetTotal() const;
    void SetCreditos(double creditos);
    double GetCreditos() const;
    void SetEscala(int escala);
    int GetEscala() const;
    void SetNombre(char* nombre);
    void GetNombre(char*) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    virtual void leer(ifstream &);
    virtual void imprime(ofstream &);
    virtual void actualizatotal(double)=0;
    void inicialisa();
private:
    int codigo;
    char* nombre;
    int escala;
    double creditos;
    double total;
};

#endif /* ALUMNO_H */

