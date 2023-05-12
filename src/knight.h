#pragma once 

#include"piece.h"

class Knight : public Piece{
private:
public:
    Knight() : Piece() {}
    Knight(sf::Sprite s, int index, int cost) : Piece (s, index, cost){}
    ~Knight(){}
public:
    void getNextMove(int i , int j, int [8][8]);
};