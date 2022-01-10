#pragma once
#include <string>
#include <vector>
class CSnakeSegment
{
private:
    /* data */
    int size = 0;
    std::vector<std::pair<int,int>> body = {};
    int _colour = 0;
    int direction = 2;
public:
    CSnakeSegment(int size);
    ~CSnakeSegment();
    std::vector<std::pair<int,int>> get_body();

public:
    void change_colour();
    void move();
    void change_direction(int dir);
    std::pair<int,int> get_head();
    void reset(int snake_size);
    void grow();
    bool hit();
};


