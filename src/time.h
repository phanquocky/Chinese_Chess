#pragma once 
#include"header.h"

class TIME{
private:
    int _minutes;
    int _seconds;
public:
    bool stop;
    TIME();
    TIME(int ,int );
public:
    void setTime(int m, int s) {_minutes = m ; _seconds = s;}
    string tostring() const;
public:
    // giảm phút giảm giờ 
    bool decreseMinute();
    bool decreaseSecond();
    
    //bắt đầu đếm giờ 
    void start();

    // kiểm tra thời gian hết chưa
    bool checkTimeOut();
};