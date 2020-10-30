#include "gamefunctions.h"


int main() {

    Fill(15, 15);
    char player = 'O';

    while (1) {
        Draw();
        Chaksu(player);
        if (Check(player)) {
            std::cout<<"½Â¸®!"<<std::endl;
            break;
        }
        TogglePlayer(player);
    }

}