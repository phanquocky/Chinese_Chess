
#include"PieceSet.h"
sf::Texture texturePieces;
sf::Texture t2;

// những vị trí mà quân trắng chết 
sf::Vector2f posDeadWhite[16] = {
sf::Vector2f(0,0),sf::Vector2f(56,0),sf::Vector2f(0,56),sf::Vector2f(56,56),
sf::Vector2f(0,56*2),sf::Vector2f(56,56*2),sf::Vector2f(0,56*3),sf::Vector2f(56,56*3),
sf::Vector2f(0,56*4),sf::Vector2f(56,56*4),sf::Vector2f(0,56*5),sf::Vector2f(56,56*5),
sf::Vector2f(0,56*6),sf::Vector2f(56,56*6),sf::Vector2f(0,56*7),sf::Vector2f(56,56*7)};

// những vị trí mà quân đen chết
sf::Vector2f posDeadBlack[16] = {
sf::Vector2f(688,0),sf::Vector2f(744,0),sf::Vector2f(688,56),sf::Vector2f(744,56),
sf::Vector2f(688,56*2),sf::Vector2f(744,56*2),sf::Vector2f(688,56*3),sf::Vector2f(744,56*3),
sf::Vector2f(688,56*4),sf::Vector2f(744,56*4),sf::Vector2f(688,56*5),sf::Vector2f(744,56*5),
sf::Vector2f(688,56*6),sf::Vector2f(744,56*6),sf::Vector2f(688,56*7),sf::Vector2f(744,56*7)
};

// để đánh dấu nước quay lui có ăn hay ko
int flag = 0;

PieceSet::PieceSet(){
}

// khởi tạo các giá trị
void PieceSet::create(int board[8][8]){
    
    // làm mới 2 giá trị
    previousMove.clear();
    firstMove = 1;

    texturePieces.loadFromFile(PATH_IMAGE_PIECES);
    int count = 0 ;     // đếm số quân cờ được tạo
    for(int i = 0 ; i < 8 ; i ++){
        for (int j = 0 ; j < 8 ; j ++){

            // xác định index của quân cờ(n) và vị trí mà quân cờ nên đặt vào (xCoor, yCoor) lúc đầu game
            int n = board[i][j];
            if(n == 0) continue;
            int xCoor = abs(n)-1;
            int yCoor = n>0?1:0;
            
            // để lưu ảnh của quân cờ vào sprite
            sf::Sprite sprite;
            sprite.setTextureRect(sf::IntRect(SIZE*xCoor, SIZE*yCoor + 1, SIZE, SIZE));
            sprite.setPosition(SIZE*j + OFFSET.x + DISPLACEMENT.x, SIZE*i + OFFSET.y + DISPLACEMENT.y);
            sprite.setTexture(texturePieces);

            // khởi tạo quân cờ tùy thuộc vào n , tức là các vị trí trên bàn cờ ban đầu
            if(abs(n) == 1) _piece[count] = new Rook(sprite,board[i][j],0);
            else if(abs(n) == 2) _piece[count] = new Knight(sprite, board[i][j], 0);
            else if(abs(n) == 3) _piece[count] = new Bishoop(sprite, board[i][j], 0);
            else if(abs(n) == 4) _piece[count] = new Queen(sprite, board[i][j], 0);
            else if(abs(n) == 5) _piece[count] = new King(sprite, board[i][j], 0);
            else _piece[count] = new Pawn(sprite, board[i][j], 0);
                      
            count++;
        }
    }
}


// di chuyen tu oldPos toi new Pos
void PieceSet::move(sf::Vector2f oldPos, sf::Vector2f newPos, int board[8][8]){

    // hai biến để lưu index
    int newPath =  -1;
    int oldPath = -1;

    // các index ở trong mảng 2 chiều
    int xOld = oldPos.y / SIZE;
    int yOld = oldPos.x / SIZE;
    int xNew = newPos.y / SIZE;
    int yNew = newPos.x / SIZE;

    // tìm quân cờ bị click lần 2
    for(int i = 0 ; i < 32 ; i ++){
        if(_piece[i]->containPosition(newPos.x + OFFSET.x + DISPLACEMENT.x, newPos.y + OFFSET.y + DISPLACEMENT.y)){
            newPath = i;
            break;
        }
    }

    // tìm quân cờ bị click lần thứ 1
    for(int i = 0 ; i < 32 ; i ++){
        if(_piece[i]->containPosition(oldPos.x + OFFSET.x + DISPLACEMENT.x, oldPos.y + OFFSET.y + DISPLACEMENT.y)){
            oldPath = i;
            break;
        }
    }

    // nếu click đầu không trúng quân cờ
    if(oldPath == -1) return;

    // nếu hai click khác chỗ thì mới xử lý
    if(oldPath != newPath && _piece[oldPath]->getIndex() * firstMove > 0){

        // di chuyển con bị click đầu tiên
        _piece[oldPath]->getNextMove(xOld , yOld , board);

        // kiểm tra thử có đi được không
        if(_piece[oldPath]->isMove(newPos)){

            // lưu lại các vị trí
            _positions.push(oldPos);
            _positions.push(newPos);
            previousMove.clear();
            previousMove.push_back(oldPos);
            previousMove.push_back(newPos);
            _path.push(oldPath);
            
            // kiểm tra phong tốt
            // phong tốt cho quân trắng
            if(xNew == 0 && _piece[oldPath]->getIndex() == 6){
                _path.push(SIGN_PROMOTE_WHITE_PAWN);
                sf::Sprite spriteQueen;
                spriteQueen.setTextureRect(sf::IntRect(SIZE*3, SIZE, SIZE, SIZE));
                spriteQueen.setPosition(SIZE*xOld + OFFSET.x + DISPLACEMENT.x, SIZE*yOld + OFFSET.y + DISPLACEMENT.y);
                spriteQueen.setTexture(texturePieces);
                delete _piece[oldPath];
                _piece[oldPath] = new Queen(spriteQueen, 4, 0);

            }

            // phong tốt cho quân đen
            if(xNew == 7 && _piece[oldPath]->getIndex() == -6){
                _path.push(SIGN_PROMOTE_BLACK_PAWN);
                sf::Sprite spriteQueen;
                spriteQueen.setTextureRect(sf::IntRect(SIZE*3, 0, SIZE, SIZE));
                spriteQueen.setPosition(SIZE*xOld + OFFSET.x + DISPLACEMENT.x, SIZE*yOld + OFFSET.y + DISPLACEMENT.y);
                spriteQueen.setTexture(texturePieces);
                delete _piece[oldPath];
                _piece[oldPath] = new Queen(spriteQueen, -4, 0);
            }

            // di chuyển quân bị click đầu tiên
            _piece[oldPath]->setPosition(sf::Vector2f(newPos) + OFFSET + DISPLACEMENT);
            board[xNew][yNew] = _piece[oldPath]->getIndex();
            board[xOld][yOld] = 0;
            _piece[oldPath]->clearMovable();

            // chuyển lượt di cho bên kia ;
            firstMove = firstMove - 2 * firstMove;
        }
        else {
            // xóa đi các nước có thể di chuyển được
            _piece[oldPath]->clearMovable();
            return;
        }

        // xử lý trường hợp có quân bị ăn
        if (newPath != -1){
            _path.push (newPath);

            // xóa đi quân bị ăn
            if(_piece[newPath]->getIndex() < 0){
                _piece[newPath]->setPosition(posDeadBlack[_deadPieceBlack.size()]);
                _deadPieceBlack.push_back(_piece[newPath]);
            }
            else {
                _piece[newPath]->setPosition(posDeadWhite[_deadPieceWhite.size()]);
                _deadPieceWhite.push_back(_piece[newPath]);
            }

            // lưu lại dấu vết
            _positions.push(newPos);
            _positions.push(sf::Vector2f(OUTVECTOR));
        }
    }
    else return;
}

void PieceSet::moveBack(int board[8][8]){
    // xóa các nước di chuyển trước đó
    previousMove.clear();

    // trường hợp chưa đi 
    if(_path.size() == 0) return;

    if(_positions.size() > 0){
        int n = _path.top(); // quân mà trước đó đi
        _path.pop();

        // quay lui quân tốt được phong cho bên trắng
        if(n == SIGN_PROMOTE_WHITE_PAWN){
            n = _path.top();
            _path.pop();
            sf::Sprite spritePawn;
            spritePawn.setTextureRect(sf::IntRect(SIZE*5, SIZE, SIZE, SIZE));
            spritePawn.setPosition(_piece[n]->getSprite().getPosition());
            spritePawn.setTexture(texturePieces);
            delete _piece[n];
            _piece[n] = new Pawn(spritePawn, 6, 0);
        }

        // quay lui quân tốt được phong cho bên đen
        if(n == SIGN_PROMOTE_BLACK_PAWN){
            n = _path.top();
            _path.pop();
            sf::Sprite spritePawn;
            spritePawn.setTextureRect(sf::IntRect(SIZE*5, 0, SIZE, SIZE));
            spritePawn.setPosition(_piece[n]->getSprite().getPosition());
            spritePawn.setTexture(texturePieces);
            delete _piece[n];
            _piece[n] = new Pawn(spritePawn, -6, 0);
        }

        sf::Vector2f p = _positions.top();  // để kiểm tra xem nước trước có quân bị ăn không
        int x1 = p.y / SIZE;                // lưu lại index trong bàn cờ 2 chiều 
        int y1 = p.x / SIZE;                // để quay lui trong bàn cờ

        // tương tự trên
        _positions.pop();
        int x2 = _positions.top().y / SIZE;
        int y2 = _positions.top().x / SIZE;

        // di chuyển quân cờ rồi update lại trong mảng 2 chiều
        _piece[n]->setPosition(sf::Vector2f(_positions.top()) + OFFSET + DISPLACEMENT);
        board[x2][y2] = _piece[n]->getIndex();

        // nước trước không có ăn
        if(flag != 1) board[x1][y1] = 0;

        _positions.pop();
        flag = 0;

        // nếu có con bị ăn thì di chuyển lần 2
        if(p == OUTVECTOR){ 
            flag = 1;
            firstMove = firstMove - 2 * firstMove;
            moveBack(board);
        }
    }

    // thay đổi lại lượt đi
    firstMove = firstMove - 2 * firstMove;
}


void PieceSet::drawSetPiece(sf::RenderWindow &window){
    
    // vẽ 2 dấu nước đi trước
    for(int i = 0 ; i < previousMove.size() ; i ++){
        t2.loadFromFile(PATH_IMAGE_SIGN);
        sf::Sprite spriteSign;
        spriteSign.setTextureRect(sf::IntRect(0, 0, SIZE, SIZE));
        spriteSign.setPosition(previousMove[i] + OFFSET + DISPLACEMENT);
        spriteSign.setTexture(t2);
        window.draw(spriteSign);
    }

    // vẽ 32 quân cờ
    for (int i = 0 ; i< 32; i ++ ) window.draw(_piece[i]->getSprite());

}

PieceSet::~PieceSet(){
    for(int i = 0 ; i < 32 ; i ++){
        if(this->_piece[i] != NULL)
            delete this->_piece[i];
    }
}

bool PieceSet::checkOnPiece(sf::Vector2f pos){
    bool check = false;
     for(int i = 0 ; i < 32 ; i ++){
        if(_piece[i]->containPosition(pos.x + OFFSET.x + DISPLACEMENT.x, pos.y + OFFSET.y + DISPLACEMENT.y)){         
            check = true;
        }
    }
    return check;
}
