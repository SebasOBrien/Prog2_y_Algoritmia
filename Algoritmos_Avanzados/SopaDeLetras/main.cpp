#include <iostream>

#include "SopaLetras.h"

using namespace std;// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    SopaDeLetras sopaDeLetras;
    string palabra1,palabra2,palabra3;
    palabra1 = "ABCCED";
    palabra2 = "SEE";
    palabra3 = "ABCB";

    cout<<"Palabra: "<<palabra1<<" => ";
    if (sopaDeLetras.encontrarSolucion(palabra1))cout<<"true"<<endl;
    else cout<<"false"<<endl;
    cout<<"Palabra: "<<palabra2<<" => ";
    if (sopaDeLetras.encontrarSolucion(palabra2))cout<<"true"<<endl;
    else cout<<"false"<<endl;
    cout<<"Palabra: "<<palabra3<<" => ";
    if (sopaDeLetras.encontrarSolucion(palabra3))cout<<"true"<<endl;
    else cout<<"false"<<endl;


    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}