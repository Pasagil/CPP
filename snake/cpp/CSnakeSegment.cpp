#include "CSnakeSegment.h"

CSnakeSegment::CSnakeSegment(/* args */)
{
    _x = 1;
}

CSnakeSegment::~CSnakeSegment()
{
}

void CSnakeSegment::change_colour()
{
    _colour++;
}
