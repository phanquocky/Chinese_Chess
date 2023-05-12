#pragma once
#include"header.h"
#include"piece.h"
#include"rook.h"
#include"bishoop.h"
#include"queen.h"
#include"pawn.h"
#include"knight.h"
#include"king.h"

#include<stack>

class PieceSet{

public:
    // lưu lại bước đi gần nhất để vẽ lại 
    vector<sf::Vector2f> previousMove;
private:

    Piece* _piece[32];               // 32 quân cờ 
    stack<sf::Vector2f> _positions;          // lưu lại những vị trí đã đi qua, để quay lui
    stack<int> _path;                    // lưu lại những quân nào đã đi trước đó để quay lui
    vector<Piece*> _deadPieceBlack;      // lưu lại quân chết đen
    vector<Piece*> _deadPieceWhite;      // lưu lại quân chết trắng




public:
    int firstMove;      // lượt đi của bên nào
public:
    PieceSet();
    ~PieceSet();

    void create(int board[8][8]);       // khởi tạo quân cờ và giá trị
    void move(sf::Vector2f oldPos, sf::Vector2f newPos, int board[8][8]); // di chuyển từ oldPos tới newPos và thay đổi trong board
    void moveBack(int board[8][8]);     // quay lui
    void drawSetPiece(sf::RenderWindow &window);  // vẽ các quân cờ 

    bool checkOnPiece(sf::Vector2f pos); // kiểm tra xem vị trí pos có chứa quân cờ nào không

};