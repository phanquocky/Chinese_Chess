#pragma once 

#include"piece.h"

class King : public Piece{
private:
public:
    King() : Piece() {}
    King(sf::Sprite s, int index, int cost) : Piece (s, index, cost){}
    ~King(){}
public:
    void getNextMove(int i , int j, int [8][8]);
};