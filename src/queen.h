#pragma once 

#include"piece.h"

class Queen : public Piece{
private:
public:
    Queen() : Piece() {}
    Queen(sf::Sprite s, int index, int cost) : Piece (s, index, cost){}
    
    ~Queen(){}
public:
    void getNextMove(int i , int j, int [8][8]);
};