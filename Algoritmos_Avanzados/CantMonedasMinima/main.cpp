#include <algorithm>
#include <iostream>
using namespace std;
#define CANT_MONEDAS 4
int main() {

    int monedas[CANT_MONEDAS] = {5,10,6,1};
    int valor_devolver;
    int cant_monedas_usadas = 0;
    cout<<"Ïngresa el precio a devolver: " <<endl;
    cin>>valor_devolver;
    int ultuma_moneda_usada;
    //ordenar arreglo para ser voraz
    sort(begin(monedas),end(monedas),[](const int &a,const int &b) {
        return a>b;
    });
    int monedas_usadas[CANT_MONEDAS]{};
    for (int i=0;i<CANT_MONEDAS;i++) {

        if (valor_devolver >= monedas[i]) {
            int cantidad_usada = valor_devolver/monedas[i];
            monedas_usadas[i] = cantidad_usada;
            valor_devolver = valor_devolver - (cantidad_usada*monedas[i]);
        }
        if (valor_devolver<= 0) {
            ultuma_moneda_usada = i;
            break;
        }
    }
    cout<<"Monedas usada: ";
    for (int i=0;i<CANT_MONEDAS;i++) {
        cant_monedas_usadas += monedas_usadas[i];
        if (monedas_usadas[i] > 0) {
            cout<<monedas[i]<<" X "<<monedas_usadas[i];
            if (i != ultuma_moneda_usada) cout<<" ,";
        }
        if (i == ultuma_moneda_usada) {
            cout<<endl;
        }
    }
    cout<<"Cantidad de usadas: "<<cant_monedas_usadas<<endl;
    return 0;
}