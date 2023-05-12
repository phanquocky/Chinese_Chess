#pragma once 

#include"piece.h"

class Pawn : public Piece{
private:
public:
    Pawn() : Piece() {}
    Pawn(sf::Sprite s, int index, int cost) : Piece (s, index, cost){}
    ~Pawn(){}
public:
    void getNextMove(int i , int j, int [8][8]);
};