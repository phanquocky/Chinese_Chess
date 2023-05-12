#include"piece.h"

Piece::Piece(){
    this->_cost = 0 ; 
    this->_indext = 0;
}

Piece::Piece(sf::Sprite sprite, int index, int cost){
    this->_sprite = sprite;
    this->_indext = index;
    this->_cost = cost;
}

Piece::~Piece(){

}

void Piece::IncreasePositive(int i, int j){
    _movable.push_back(sf::Vector2f(j * SIZE , i * SIZE));
}

bool Piece::isMove(sf::Vector2f pos){
    for(int i = 0 ; i < _movable.size() ; i++){
        if(_movable[i] == pos ) return true;
    }
    return false;
}
