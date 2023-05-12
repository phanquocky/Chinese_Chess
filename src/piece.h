#pragma once

#include"header.h"

class Piece{
private:
    sf::Sprite _sprite;
    int _indext;
    int _cost;
    vector<sf::Vector2f> _movable;

public:
    Piece();
    Piece(sf::Sprite, int, int);

public:
    int getIndex() {return this->_indext; }
    void setPosition(sf::Vector2f pos) {this->_sprite.setPosition(pos); }
    sf::Sprite getSprite() {return this->_sprite; }
    bool containPosition(int x, int y) {return this->_sprite.getGlobalBounds().contains(x,y);}
    
public:
    void IncreasePositive(int , int); // thêm vào những bước đi có thể đi ( thêm vào movable 2 vị trí (i,j))
    virtual void getNextMove(int ,int ,int[8][8]) = 0;
public:
    void clearMovable() {_movable.clear();};
    bool isMove(sf::Vector2f);
public:
    virtual ~Piece();
};