
/* 
 * File:   main.cpp
 * Author: AXEL
 *
 * Created on 27 de octubre de 2024, 02:09
 */

#include <iostream>

using namespace std;

/*
 * 
 */

int busquedaBinaria(int *array,int n,int ini,int fin){
    if(ini>fin)return -1;
    int medio=(ini+fin)/2;
    if(array[medio]<=n and (medio==fin or array[medio+1]>0)){
        return medio+1;
    }else if(array[medio]>n){
        return busquedaBinaria(array,n,ini,medio);
    }else{
        return busquedaBinaria(array,n,medio+1,fin);
    }
}
void alizarHiroshima(int *explosion,int n,int &radiacion,int &megatonesMax){
    radiacion=busquedaBinaria(explosion,0,0,n-1);
    if(explosion[radiacion-1]==explosion[radiacion])radiacion--;
    megatonesMax=(n-1-radiacion)/2 + radiacion;
}

int main(int argc, char** argv) {
    int explosion[14]={0,-1,0,-1,0,1,1,2,2,3,2,2,1,1};
    int radiacion,megatonesMax;
    alizarHiroshima(explosion,14,radiacion,megatonesMax);
    cout<<" La radiación empieza a "<<radiacion<<" km. Potencia máxima "<<
            explosion[megatonesMax]<<" megatones. "<<endl;
    
    int explosion2[17]={0,-1,0,-1,1,1,2,2,3,3,4,3,3,2,2,1,1};
    alizarHiroshima(explosion2,17,radiacion,megatonesMax);
    cout<<" La radiación empieza a "<<radiacion<<" km. Potencia máxima "<<
            explosion2[megatonesMax]<<" megatones. "<<endl;
    
    return 0;
}

