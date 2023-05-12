#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include<SFML/Graphics.hpp>
using namespace sf;
using namespace std;


#define MAX_MAIN_MENU 4
#define SIZE 56
#define MENU_CHARACTER_SIZE 70
#define SETTING_CHARACTER_SIZE 18
#define SIGN_PROMOTE_WHITE_PAWN 100
#define SIGN_PROMOTE_BLACK_PAWN -100

#define OFFSET sf::Vector2f(28, 28)
#define DISPLACEMENT sf::Vector2f(148, 0)
#define OUTVECTOR sf::Vector2f(-100, -100)

#define POSITION_WIN sf::Vector2f(240, 150)
#define POSITION_CONTINUE sf::Vector2f(300, 500)
#define POSITION_PLAY_BUTTON sf::Vector2f(300, 200)
#define POSITION_SETTING_BUTTON sf::Vector2f(300, 300)
#define POSITION_ABOUT_BUTTON sf::Vector2f(300, 400)
#define POSITION_EXIT_BUTTON sf::Vector2f(300, 500)
#define POSITION_SETTING_NAME1 sf::Vector2f(255, 235)
#define POSITION_SETTING_NAME2 sf::Vector2f(255, 335)
#define POSITION_SETTING_TIME sf::Vector2f(255,435)

#define PATH_IMAGE_BOARD "image/board.png"
#define PATH_IMAGE_GAME_BACKGROUND "image/game_background.jpg"
#define PATH_IMAGE_PIECES "image/pieces.png"
#define PATH_IMAGE_MENU_BACKGROUD "image/menu_background.png"
#define PATH_IMAGE_WIN "image/win.png"
#define PATH_IMAGE_DEFEAT "image/defeat.png"
#define PATH_IMAGE_CONTINUE "image/continues.jpg"
#define PATH_IMAGE_SIGN "image/sign.png"
#define PATH_FONT "font/AlexandriaFLF.ttf"