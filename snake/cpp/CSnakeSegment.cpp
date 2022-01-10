#include "CSnakeSegment.h"
#include <iostream>

CSnakeSegment::CSnakeSegment(int size)
{
    for (int i=0 ; i<size ; i++) {body.push_back(std::make_pair(1,size-i));}
}

CSnakeSegment::~CSnakeSegment()
{
}

void CSnakeSegment::change_colour()
{
    _colour++;
}

std::vector<std::pair<int,int>> CSnakeSegment::get_body() {return body;}
void CSnakeSegment::move()
{
    switch(direction)
    {
        case 2: 
            {body.pop_back();
            std::pair<int,int> pos = body.front();
            body.insert(body.begin(), std::make_pair(pos.first+1, pos.second));
            break;}

        case 8: 
            {body.pop_back();
            std::pair<int,int> pos = body.front();
            body.insert(body.begin(), std::make_pair(pos.first-1, pos.second));
            break;}

        case 4: 
            {body.pop_back();
            std::pair<int,int> pos = body.front();
            body.insert(body.begin(), std::make_pair(pos.first, pos.second-1));
            break;}

        case 6: 
            {body.pop_back();
            std::pair<int,int> pos = body.front();
            body.insert(body.begin(), std::make_pair(pos.first, pos.second+1));
            break;}
    }
}

void CSnakeSegment::change_direction(int dir)
{
    if (dir + direction != 10) {direction = dir;}
}

std::pair<int,int> CSnakeSegment::get_head(){
    return body.front();
}

void CSnakeSegment::reset(int snake_size)
{
    size = snake_size;
    body = {};
    for (int i=0 ; i<size ; i++) {body.push_back(std::make_pair(1,size-i));}
}

void CSnakeSegment::grow()
{
    size ++;
}

bool CSnakeSegment::hit()
{

    std::vector<std::pair<int,int>> snake_body = get_body();
    snake_body = std::vector<std::pair<int,int>> (snake_body.begin()+1, snake_body.end());
    std::pair<int,int> snake_head = get_head();
    for (std::pair<int,int> pair : snake_body)
    {
        if (pair == snake_head)
        {
            return true;
        }
    }
    return false;
}