//
// Created by AXEL on 29/08/2025.
//

#include "Tablero.h"

#include <iostream>
#include <iomanip>
Tablero::Tablero(int num) {
    table.resize(num, vector<int>(num, 0));
}
void Tablero::showTable() {
    for (int i = 0; i < table.size(); i++) {
        for (int j = 0; j < table[i].size(); j++) {
            cout <<left<<setw(4)<< table[i][j];
        }
        cout << endl;
    }
}

pair<int,int> Tablero::getSize() {
    pair<int,int> size = {table.size(), table[0].size()};
    return size;
}

void Tablero::changeValue(int num,int fil,int col) {
    this->table[fil][col]= num;
}

int Tablero::getValue(int fil, int col) {
    return this->table[fil][col];
}