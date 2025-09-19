//
// Created by AXEL on 29/08/2025.
//

#include "Horse.h"

#include <algorithm>
#include <iostream>
#define NO_ASSIGN 0


void Horse::fillMoves() {
    this->moves = {
        {2, 1},
        {1, 2},
        {-1, 2},
        {2, -1},

        {-2, -1},
        {-2, 1},
        {-1, -2},
        {1, -2}


    };
}

void Horse::changePosition(int num) {
    this->position.first += this->moves[num].first;
    this->position.second += this->moves[num].second;
}

Horse::Horse() {
    this->position.first = 0;
    this->position.second = 0;
    this->fillMoves();
}

void Horse::solucion(int fil, int col, Tablero &tabla) {
    pair<int, int> sizeTable = tabla.getSize();
    this->position.first = fil;
    this->position.second = col;
    tabla.changeValue(1,this->position.first,this->position.second);
    if (this->solucionRecursiva(tabla, sizeTable, 2))cout << "Se encontro solucion \n";
    else cout << "No se encontro solu :( \n";
}

int Horse::countPossibleMoves(Tablero &tabla, std::pair<int, int> size, std::pair<int, int> pos) {
    int count = 0;
    for (const auto& move : this->moves) {
        if (this->validPosition(tabla, size, {pos.first + move.first, pos.second + move.second})) {
            count++;
        }
    }
    return count;
}




bool Horse::validPosition(Tablero &tabla, pair<int, int> size, pair<int, int> position) {
    return (position.first >=0 && position.second >= 0 && position.first < size.first && position.second < size.second
        && tabla.getValue(position.first, position.second) == NO_ASSIGN );
}

bool Horse::solucionRecursiva(Tablero &tabla, pair<int, int> size, int num) {

    //caso base
    if (num > size.first * size.second ) {
        return true;
    }
    std::vector<std::pair<int, int>> possibleMoves = this->moves;
    std::sort(possibleMoves.begin(), possibleMoves.end(), [this, &tabla, size](const auto& a, const auto& b) {
        std::pair<int, int> posA = {this->position.first + a.first, this->position.second + a.second};
        std::pair<int, int> posB = {this->position.first + b.first, this->position.second + b.second};
        return this->countPossibleMoves(tabla, size, posA) < this->countPossibleMoves(tabla, size, posB);
    });
    pair<int, int> oldPosition = this->position;
    //validation of the new position
    for (const auto& move : possibleMoves) {
        std::pair<int, int> newPosition = {
            this->position.first + move.first,
            this->position.second + move.second
        };

        if (this->validPosition(tabla, size, newPosition)) {
            std::pair<int, int> oldPosition = this->position;
            this->position = newPosition;
            tabla.changeValue(num, this->position.first, this->position.second);

            if (this->solucionRecursiva(tabla, size, num + 1)) {
                return true;
            }

            // Backtracking: si la llamada recursiva falla, deshacemos el movimiento
            this->position = oldPosition;
            tabla.changeValue(NO_ASSIGN, newPosition.first, newPosition.second);
        }
    }
    return false;
}
