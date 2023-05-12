#pragma once 

#include"piece.h"

class Bishoop : public Piece{
private:
public:
    Bishoop() : Piece() {}
    Bishoop(sf::Sprite s, int index, int cost) : Piece (s, index, cost){}
    ~Bishoop(){}
public:
    void getNextMove(int i , int j, int [8][8]);
};