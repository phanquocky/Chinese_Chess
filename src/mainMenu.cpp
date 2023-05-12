#include"mainMenu.h"

MainMenu::MainMenu(){
    if(!_font.loadFromFile(PATH_FONT))
        cout << "No font is here" << endl;
    
    // nút play
    _mainMenu[0].setFont(_font);
    _mainMenu[0].setFillColor(Color::Blue);
    _mainMenu[0].setString("PLAY");
    _mainMenu[0].setCharacterSize(MENU_CHARACTER_SIZE);
    _mainMenu[0].setPosition(POSITION_PLAY_BUTTON);

    // nút setting
    _mainMenu[1].setFont(_font);
    _mainMenu[1].setFillColor(Color::White);
    _mainMenu[1].setString("SETTING");
    _mainMenu[1].setCharacterSize(MENU_CHARACTER_SIZE);
    _mainMenu[1].setPosition(POSITION_SETTING_BUTTON);

    // nút about
    _mainMenu[2].setFont(_font);
    _mainMenu[2].setFillColor(Color::White);
    _mainMenu[2].setString("ABOUT");
    _mainMenu[2].setCharacterSize(MENU_CHARACTER_SIZE);
    _mainMenu[2].setPosition(POSITION_ABOUT_BUTTON);

    //exit
    _mainMenu[3].setFont(_font);
    _mainMenu[3].setFillColor(Color::White);
    _mainMenu[3].setString("EXIT");
    _mainMenu[3].setCharacterSize(MENU_CHARACTER_SIZE);
    _mainMenu[3].setPosition(POSITION_EXIT_BUTTON);

    // mặc định lựa chọn là 0
    _mainMenuSelected = 0;
}

// xử lý di chuyển lên
void MainMenu::moveUp(){
    _mainMenu[_mainMenuSelected].setFillColor(Color::White);    
    _mainMenuSelected  = (_mainMenuSelected - 1 + MAX_MAIN_MENU) % MAX_MAIN_MENU;
    _mainMenu[_mainMenuSelected].setFillColor(Color::Blue);

}

// xử lý di chuyển xuống
void MainMenu::moveDown(){
    _mainMenu[_mainMenuSelected].setFillColor(Color::White);
    _mainMenuSelected = (_mainMenuSelected + 1) % MAX_MAIN_MENU;
    _mainMenu[_mainMenuSelected].setFillColor(Color::Blue);
}

void MainMenu::Draw(){

    // render màn hình
    RenderWindow MENU(VideoMode(800,700) , "MENU");
    MENU.setPosition(sf::Vector2i(325, 25));
    MENU.setActive(true);
    MENU.setFramerateLimit(60);

    // load texture và tạo sprite cho menu backgroud 
    Texture textureBackground;
    textureBackground.loadFromFile(PATH_IMAGE_MENU_BACKGROUD);
    Sprite menu;
    menu.setTexture(textureBackground); 

    while(MENU.isOpen()){
        Event event;        
        while(MENU.pollEvent(event)){
            
            // xử lý nút tắt
            if(event.type == Event::Closed){
                MENU.close();
            }

            // xử lý khi bấm nút lên xuống
            if(event.type == Event::KeyPressed){
                if(event.key.code == Keyboard::Up){
                    this->moveUp();
                    break;
                }

                if(event.key.code == Keyboard::Down){
                    this->moveDown();
                    break;
                }

                // xử lý khi bấm nút enter
                if(event.key.code == Keyboard::Return){

                    int x = this->mainMenuPressed();
                    
                    // xử lý khi bấm nút Play
                    if(x == 0){
                        _gameManager.create();
                        _gameManager.play(MENU, _setting._username1, _setting._username2, _setting._minutes);
                    }

                    // xử lý khi bấm nút setting
                    else if(x == 1)
                        _setting.draw(MENU);
                    
                    // xử lý khi bấm nút about
                    else if(x == 2){

                    }

                    // xử lý khi bấm nút exit
                    else if(x == 3) MENU.close();
                    
                }
            }

            // vẽ
            MENU.clear();
            MENU.draw(menu);
            for(int i = 0 ; i < MAX_MAIN_MENU ; i ++)    MENU.draw(_mainMenu[i]);
            MENU.display();
        }
    }
}