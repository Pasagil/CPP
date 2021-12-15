#pragma once
#include <map>
#include <vector>

void board_clear(std::map<std::pair<int,int>,bool> &board);
void board_set_pixel(std::map<std::pair<int,int>,bool> &board, std::vector<std::pair<int,int>>, int board_size);



