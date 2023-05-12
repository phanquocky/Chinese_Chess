#pragma once

#include"header.h"
#include"manager.h"
#include"setting.h"

using namespace std;
using namespace sf;

class MainMenu{
private:
    int _mainMenuSelected;
    Font _font;
    Text _mainMenu[4];
    
    GameManager _gameManager;
    Setting _setting;
public:
    MainMenu();
public:
    void Draw();
    void moveUp();
    void moveDown();

    int mainMenuPressed(){ return _mainMenuSelected;}
};
