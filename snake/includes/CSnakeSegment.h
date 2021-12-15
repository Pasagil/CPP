#pragma once

class CSnakeSegment
{
private:
    /* data */
    int _x = 0;
    int _y = 0;
    int _colour = 0;

public:
    CSnakeSegment(/* args */);
    ~CSnakeSegment();

public:
    void change_colour();
};


