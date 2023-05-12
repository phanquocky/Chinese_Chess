#include"player.h"

Player::Player(){
    // khởi tạo mặc định cho tên
    _name = "username";
    _font.loadFromFile(PATH_FONT);
    _nameDisplay.setFont(_font);
    _nameDisplay.setFillColor(Color::Black);
    _nameDisplay.setString(_name);
    _nameDisplay.setCharacterSize(25);
    
    // khởi tạo mặc định cho thời gain
    _time.setTime(0,10);
    _timeDisplay.setFont(_font);
    _timeDisplay.setFillColor(Color::Black);
    _timeDisplay.setString(_time.tostring());
    _timeDisplay.setCharacterSize(25);
}

void Player::draw(sf::RenderWindow &window){
    // vẽ tên và thời gian lên màn hình window
    window.draw(_nameDisplay);
    _timeDisplay.setString(_time.tostring());
    window.draw(_timeDisplay);
}

