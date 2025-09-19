#include <iostream>

#include "Horse.h"
#include "Tablero.h"
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    Tablero tabla(8);
    tabla.showTable();
    Horse horse;
    horse.solucion(0,0,tabla);
    cout<<endl<<endl;
    tabla.showTable();

    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}