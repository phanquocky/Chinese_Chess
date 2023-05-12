#pragma once
#include"time.h"
#include"header.h"
class Player{
public:
    TIME _time;
private:
    string _name;
    Font _font;
    Text _nameDisplay;
    Text _timeDisplay;
public:
    Player();

    void setNameDisplay() {_nameDisplay.setString(_name); }
    void setPosText(sf::Vector2f pos){ _nameDisplay.setPosition(pos); }
    void setPosTime(sf::Vector2f pos){ _timeDisplay.setPosition(pos); }
    void setName(string name) {_name = name; }
    void setTime(string minutes) { _time.setTime(stoi(minutes), 0); }
    void draw(sf::RenderWindow &window);
    
};