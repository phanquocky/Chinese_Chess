#pragma once
#include"header.h"
#include"time.h"

class Setting{
public:
    Font _font;
    Text _username2Display;
    Text _time;
    Text _username1Display;

    string _minutes;
    string _username1;
    string _username2;
    
public:
    Setting();
    void draw(RenderWindow &window);
};