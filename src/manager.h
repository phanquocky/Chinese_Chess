#pragma once
#include"header.h"
#include"PieceSet.h"
#include"board.h"
#include"statusWin.h"
#include"player.h"
class GameManager {
private:
    Board _board;
    PieceSet _pieceSet;
    Player _player1;
    Player _player2;

    StatusWin _status;
public:
    ~GameManager(){}
    void create();
    void play(sf::RenderWindow &, string ,string ,string);
};