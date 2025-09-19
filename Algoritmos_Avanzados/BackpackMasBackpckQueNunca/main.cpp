#include <iostream>
using namespace std;
#define PESOMAX 5
#define CANT_OBJ 4


void solucionarProblemon(int dp[][PESOMAX + 1],int objetos[][2],int pesoMochila) {
    int pesoRestante = 0;
//inicializamos la primera linea de la matriz dp
    for (int i = 0; i < PESOMAX + 1; i++) {
        pesoRestante = i - objetos[0][0];
        if (pesoRestante >= 0) {
            dp[0][i]=objetos[0][1];
        }
        cout<<dp[0][i]<<" ";
    }
    cout<<endl;

    int valor;
    for (int i = 1; i < CANT_OBJ; i++) {
        for (int j = 0; j < PESOMAX + 1; j++) {
            valor = 0;
            pesoRestante = j  - objetos[i][0];
            if (pesoRestante >= 0) {
                valor = objetos[i][1] + dp[i - 1][pesoRestante];
            }
            dp[i][j] = max(valor,dp[i-1][j]);
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}



int main() {
    int pesoMochila = 5;
    int objetos[CANT_OBJ][2] = {
        {2, 12},
        {1, 10},
        {3, 20},
        {2, 15}
    };;
    int dpBackpack[CANT_OBJ][PESOMAX + 1];
    //inicializar la matriz con 0
    for (int i = 0; i < CANT_OBJ; i++) {
        for (int j = 0; j < PESOMAX + 1; j++) {
            dpBackpack[i][j] = 0;
        }
    }
    solucionarProblemon(dpBackpack,objetos,pesoMochila);
    cout<<"EL valor maximo obtenible en esta mochila es "<<dpBackpack[CANT_OBJ - 1][PESOMAX]<<endl;
    return 0;
}
