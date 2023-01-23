#include <SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include <iostream> 
#include "Header.h"


bool check_the_winner(char board_model[]) {
    if ((board_model[0] == board_model[1] && board_model[1] == board_model[2]) || (board_model[3] == board_model[4] && board_model[4] == board_model[5]) ||
        (board_model[6] == board_model[7] && board_model[7] == board_model[8]) || (board_model[0] == board_model[4] && board_model[4] == board_model[8]) ||
        (board_model[2] == board_model[4] && board_model[4] == board_model[6]) || (board_model[0] == board_model[3] && board_model[3] == board_model[6]) ||
        (board_model[1] == board_model[4] && board_model[4] == board_model[7]) || (board_model[2] == board_model[5] && board_model[5] == board_model[8])) {
 
        return true;

    }
    return false;
}
void mouse_click(char board_model[], char& currnet_mark, int& coordinates_on_the_board) {
    if (board_model[coordinates_on_the_board] == '1' || board_model[coordinates_on_the_board] == '2' ||
        board_model[coordinates_on_the_board] == '3' || board_model[coordinates_on_the_board] == '4' ||
        board_model[coordinates_on_the_board] == '5' || board_model[coordinates_on_the_board] == '6' ||
        board_model[coordinates_on_the_board] == '7' || board_model[coordinates_on_the_board] == '8' ||
        board_model[coordinates_on_the_board] == '9')
    {
        board_model[coordinates_on_the_board] = currnet_mark;

        if (currnet_mark == 'x')
            currnet_mark = 'o';
        else
            currnet_mark = 'x';
    }
}

bool draw(char board_model[]) {
    if (!check_the_winner(board_model) && board_model[0] != '1' && board_model[1] != '2' &&
        board_model[2] != '3' && board_model[3] != '4' &&
        board_model[4] != '5' && board_model[5] != '6' &&
        board_model[6] != '7' && board_model[7] != '8' &&
        board_model[8] != '9') {
        return true;
    }
    return false;
}

