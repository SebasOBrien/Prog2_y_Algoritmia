/* 
 * File:   funcionesAux.h
 * Author: AXEL
 *
 * Created on 14 de junio de 2025, 07:31 PM
 */

#ifndef FUNCIONESAUX_H
#define FUNCIONESAUX_H
void setCadena(char *&cadenaClase,const char* cadenaNew);
void getCadena(const char *cadenaClase,char *&cadenaGuardar);
ifstream abrirArchivoLectura(const char*name);
ofstream abrirArchivoEscritura(const char*name);
void imprimerLinea(ofstream &,char );
#endif /* FUNCIONESAUX_H */
