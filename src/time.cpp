#include"time.h"

TIME::TIME(){
    this->_minutes = 10;
    this->_seconds = 0;
    this->stop = true;
}

TIME::TIME(int m, int s){
    this->_minutes = m ; 
    this->_seconds = s;
    this->stop = true;
}

string TIME::tostring() const {
    stringstream ss;
    ss << this->_minutes << " : " << this->_seconds;
    return ss.str();
}

bool TIME::decreseMinute(){
    this->_minutes --;
    if(this->_minutes < 0 ) return false;
    return true;
}

bool TIME::decreaseSecond(){
    this->_seconds -- ;
    if(this->_seconds < 0) {
        if(!TIME::decreseMinute()) return false;
        else this->_seconds += 60;
    }
    return true;
}

void TIME::start() {

    sf::Clock clock;
    while (true)
    {
        // bật tắt đếm giờ tùy vào biến stop
        sf::sleep(sf::milliseconds(100));
        if(!stop){
            static sf::Time text_effect_time;
            text_effect_time += clock.restart();

            // bắt đầu giảm giờ sau 1. giây
            if (text_effect_time >= sf::seconds(1.0f) )
            {
                if(!this->decreaseSecond()) break;
                text_effect_time = sf::Time::Zero;
            }
        }
    }
}

bool TIME::checkTimeOut(){
    if(this->_seconds ==0 && this->_minutes == 0) return true;
    return false;
}


