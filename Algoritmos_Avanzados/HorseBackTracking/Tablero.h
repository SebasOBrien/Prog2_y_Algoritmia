//
// Created by AXEL on 29/08/2025.
//

#ifndef CABALLO_HORSE_BACKTRACK_TABLERO_H
#define CABALLO_HORSE_BACKTRACK_TABLERO_H

#include <vector>
using namespace std;


class Tablero {
    public:
    Tablero(int num);
    pair<int,int> getSize();
    void changeValue(int num,int fil,int col);
    int getValue(int fil,int col);
    void showTable();
    private:
    vector<vector<int>> table;

};


#endif //CABALLO_HORSE_BACKTRACK_TABLERO_H