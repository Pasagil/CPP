#include <iostream>
#include <thread>
#include <chrono>

#include "snake.h"
#include "screen.h"
#include "board.h"
#include "keyboard.h"
#include "CSnakeSegment.h"

#define UP_ARROW    65
#define LEFT_ARROW  68
#define DOWN_ARROW  66
#define RIGHT_ARROW 67

// Variables de contexte du board
std::map<std::pair<int,int>,bool> snake_board;

// Variables de contexte du snake
int snake_size = 5;
std::vector<snake_segment_st> snake_segments;

int main(int, char**) {
    std::cout << "Snake starting...\n";
    CSnakeSegment snake = CSnakeSegment(snake_size);
    keyboard_init();
    int board_size = 15;

    std::chrono::steady_clock::time_point last_move = std::chrono::steady_clock::now();

    while (true)
    {

        // Affichage de la scène

        screen_clear();
        board_clear(snake_board);
        board_set_pixel(snake_board, snake.get_body(), board_size);
        screen_draw_board(snake_board);

        long ellapsedms = 0;
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

        ellapsedms = (long)std::chrono::duration_cast<std::chrono::milliseconds>(end - last_move).count();
        if (ellapsedms > 500)
        {
            // Simulation d'un déplacement automatique/calculé
            snake.move();
            // Fin simulation

            last_move = std::chrono::steady_clock::now();
        }


        // Lecture clavier et actions
        int key_scan = keyboard_scan();
        if (key_scan == UP_ARROW)
        {
            snake.change_direction(8);
            snake.move();
            
        }
        else if (key_scan == DOWN_ARROW)
        {
            snake.change_direction(2);
            snake.move();
        }
        else if (key_scan == LEFT_ARROW)
        {
            snake.change_direction(4);
            snake.move();
        }
        else if (key_scan == RIGHT_ARROW)
        {
            snake.change_direction(6);
            snake.move();
        }
        // Contrôle  des limites
        std::pair<int,int> coords = snake.get_head();
        if (coords.first > board_size or coords.first < 0 or coords.second > board_size or coords.second < 0) 
        {
            std::cout << "YOU LOSE AHAH LOOOOOOSER";
            snake.reset(snake_size);
        }



        // Exemple d'attente si besoin était (attention, suspend entièrement l'application)
        //std::this_thread::sleep_for (std::chrono::milliseconds(100));
    }

    keyboard_end();

}
