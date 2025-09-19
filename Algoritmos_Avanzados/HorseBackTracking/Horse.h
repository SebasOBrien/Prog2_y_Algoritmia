//
// Created by AXEL on 29/08/2025.
//

#ifndef CABALLO_HORSE_BACKTRACK_HORSE_H
#define CABALLO_HORSE_BACKTRACK_HORSE_H
#include <vector>

#include "Tablero.h"


using namespace  std;
class Horse {
public:
    void solucion(int fil, int col, Tablero &tabla);

    int countPossibleMoves(Tablero &tabla, std::pair<int, int> size, std::pair<int, int> pos);

    bool validPosition(Tablero &tabla, pair<int, int> size, pair<int, int> position);

    Horse();


    void changePosition(int);

private:
    pair<int,int> position;
    vector<pair<int, int>> moves;
    void fillMoves();
    bool solucionRecursiva(Tablero &tabla, pair<int, int> size, int num);
};


#endif //CABALLO_HORSE_BACKTRACK_HORSE_H