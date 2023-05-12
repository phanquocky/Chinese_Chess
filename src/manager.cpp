#include"manager.h"


//khởi tạo những giá trị cần thiết để in ra bàn cờ
void GameManager::create(){
    
    // reset lại bàn cờ số , và tạo lại những quân cờ
    _board.reset();
    _pieceSet.create(_board._board);

    // đặt vị trí cho tên và thời gian của 2 người chơi
    _player1.setPosText(sf::Vector2f(550,570));
    _player1.setPosTime(sf::Vector2f(305,570));

    _player2.setPosText(sf::Vector2f(50,570));
    _player2.setPosTime(sf::Vector2f(425,570));
}


// hàm này sẽ xử lý khi chơi game với tham số name1, name2, minutes là tên 2 người chơi và thời gian
void GameManager::play(sf::RenderWindow &window, string name1, string name2, string minutes){

    // cài lại thời gian như tham số truyền vào
    _player1.setName(name1);
    _player1.setNameDisplay();
    _player2.setName(name2);
    _player2.setNameDisplay();
    _player1.setTime(minutes);
    _player2.setTime(minutes);

    // tạo 2 thread thời gian để chạy trong quá trình chơi 
    sf::Thread threadPlayer1(&TIME::start, &_player1._time);
    sf::Thread threadPlayer2(&TIME::start, &_player2._time);

    // chạy thời gian cho 2 người chơi
    threadPlayer1.launch();
    threadPlayer2.launch();
    
    // đọc cái file ảnh vào các texture
    sf::Texture textureBackground,textureBoard,textureSign;
    textureBoard.loadFromFile(PATH_IMAGE_BOARD);
    textureSign.loadFromFile(PATH_IMAGE_SIGN);
    textureBackground.loadFromFile(PATH_IMAGE_GAME_BACKGROUND);

    // tạo sprite cho bàn cờ
    sf::Sprite sBoard(textureBoard);
    sBoard.setPosition(DISPLACEMENT);
    
    // tạo sprite để đánh dấu
    sf::Sprite sign(textureSign);
    sign.setPosition(OUTVECTOR);

    // tạo sprite cho background game
    sf::Sprite background(textureBackground);


    // khởi tạo giá trị
    int click = 0;
    int x_new = 0 ;
    int y_new = 0;
    sf::Vector2i pos;
    sf::Vector2f oldPositon;
    sf::Vector2f newPosition;

    // mọi xử lý game tại đây
    while (window.isOpen())
    {
        // xử lý khi trắng thắng
        if(_board.checkWin() == 1 || _player2._time.checkTimeOut()) {
            _status.draw(window,-1);
            threadPlayer1.terminate();
            threadPlayer2.terminate();
            return;
        }

        // xử lý khi trắng thua
        if(_board.checkWin() == -1 || _player1._time.checkTimeOut()){
            _status.draw(window,1);
            threadPlayer1.terminate();
            threadPlayer2.terminate();
            return;
        }

        
        sf::Event event;
        while (window.pollEvent(event))
        {
            // dùng để tắt game
            if (event.type == sf::Event::Closed){
                window.close();
                threadPlayer1.terminate();
                threadPlayer2.terminate();
            }

            // xử lý nút quay lui
            if (event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Space)
                    _pieceSet.moveBack(_board._board);
            }

            // xử lý di chuyển quân cờ
            if (event.type == sf::Event::MouseButtonPressed){
                if(event.mouseButton.button == sf::Mouse::Left){
                    
                    // lấy vị trí chuột tại lúc click
                    pos = sf::Mouse::getPosition(window);
                    
                    // trừ cho phần cạnh của bàn cờ 
                    if(pos.x >= OFFSET.x + DISPLACEMENT.x && pos.y >= OFFSET.y + DISPLACEMENT.y
                        && pos.x <= SIZE*8+OFFSET.x + DISPLACEMENT.x  && pos.y <= SIZE*8 + OFFSET.y + DISPLACEMENT.y){
                        pos -= sf::Vector2i(OFFSET);
                        pos -= sf::Vector2i(DISPLACEMENT);
                        click++;
                    }
                }

                // xử lý ở click đầu tiên và lấy vị trí tại đó
                if(click == 1){
                    oldPositon = sf::Vector2f(int(pos.x / SIZE) * SIZE, int(pos.y / SIZE) * SIZE);
                    sign.setPosition(oldPositon + OFFSET + DISPLACEMENT);
                    if(_pieceSet.checkOnPiece(oldPositon) == false) click = 0; // nếu click 1 mà không có quân cờ nào thì click = 0
                }

                // xử lý ở click đầu tiên và lấy vị trí tại đó
                if(click == 1){
                    oldPositon = sf::Vector2f(int(pos.x / SIZE) * SIZE, int(pos.y / SIZE) * SIZE);
                    sign.setPosition(oldPositon + OFFSET + DISPLACEMENT);
                }

                // xử lý ở click thứ 2 
                if(click == 2){

                    // vị trí tại click thứ 2
                    newPosition = sf::Vector2f(int(pos.x / SIZE) * SIZE, int(pos.y / SIZE) * SIZE);
                    
                    // 2 biến này để kiểm tra những click có còn trong bàn cờ không
                    x_new = int(pos.x / float(SIZE));
                    y_new = int(pos.y / float(SIZE));
                    if(x_new < 8 && y_new < 8){

                        // nếu còn trong bàn cờ thì di chuyển
                        _pieceSet.move(oldPositon, newPosition, _board._board);
     
                    }
                    click =0 ; 
                }
                if(click > 2) click = 0;
            }
        }

        // xử lý từng lượt đi
        if(_pieceSet.firstMove == -1) {
            _player1._time.stop = false;
            _player2._time.stop = true;
        }
        if(_pieceSet.firstMove == 1){
            _player1._time.stop = true;
            _player2._time.stop = false;
        }

        // vẽ 
        window.clear();
        window.draw(background);
        window.draw(sBoard);
        window.draw(sign);
        _pieceSet.drawSetPiece(window);
        _player1.draw(window);
        _player2.draw(window);

        window.display();
    }
}

