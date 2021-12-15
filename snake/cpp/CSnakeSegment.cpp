#include "CSnakeSegment.h"

CSnakeSegment::CSnakeSegment(int size)
{
    for (int i=0 ; i<size ; i++) {body.push_back(std::make_pair(size-i-1,0));}
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
    direction = dir;
}

std::pair<int,int> CSnakeSegment::get_head(){
    return body.front();
}

void CSnakeSegment::reset(int snake_size)
{
    size = snake_size;
    body = {};
    for (int i=0 ; i<size ; i++) {body.push_back(std::make_pair(size-i-1,0));}
}

void CSnakeSegment::grow()
{
    size ++;
}