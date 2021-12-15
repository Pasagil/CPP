#include "board.h"


void board_clear(std::map<std::pair<int,int>,bool> &board)
{
    board.clear();
}

void board_set_pixel(std::map<std::pair<int,int>,bool> &board, std::vector<std::pair<int,int>> body, int board_size)
{

    for (int i = 0; i<board_size; i++)
    {
        for (int j = 0; j<board_size; j++)
        {
            board[{i,j}] = false;
        }
    }
    
    for (std::pair<int,int> p : body)
    {
        board[{p.first, p.second}] = true;
    }
    
    
}

