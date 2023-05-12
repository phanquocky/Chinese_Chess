#pragma once 

#include"piece.h"

class Rook : public Piece{
private:
public:
    Rook() : Piece() {}
    Rook(sf::Sprite s, int index, int cost) : Piece (s, index, cost){}
    ~Rook(){}
public:
    void getNextMove(int i , int j, int [8][8]);
};