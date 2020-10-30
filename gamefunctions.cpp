#include "gamefunctions.h"

int sero;
int garo;

std::vector< std::vector <char> > board;

void Draw() { //흑일때 백일떄 없을때로 나눠서 출력

    system("cls");
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            std::cout << board[i][j] <<" ";
        }
        std::cout << std::endl;
    }
}

bool Check(char& p) {
    for (int y = 0; y < sero; y++) { //가로
        for (int x = 0; x < garo - 4; x++) {
            if (board[y][x + 0] == p && board[y][x + 1] == p && board[y][x + 2] == p && board[y][x + 3] == p && board[y][x + 4] == p)
                return true;

        }
    }
    for (int x = 0; x < garo; x++) { //세로
        for (int y = 0; y < sero - 4; y++) {
            if (board[y + 0][x] == p && board[y + 1][x] == p && board[y + 2][x] == p && board[y + 3][x] == p && board[y + 4][x] == p)
                return true;
        }
    }
    for (int y = 0; y < garo - 4; y++) { //북동
        for (int x = 4; x < sero; x++) {
            if (board[x][y] == p && board[x - 1][y + 1] == p && board[x - 2][y + 2] == p && board[x - 3][y + 3] == p && board[x - 4][y + 4] == p)
                return true;
        }
    }
    for (int y = 0; y < garo - 4; y++) { //북서
        for (int x = 0; x < sero - 4; x++) {
            if (board[x][y] == p && board[x + 1][y + 1] == p && board[x + 2][y + 2] == p && board[x + 3][y + 3] == p && board[x + 4][y + 4] == p)
                return true;
        }
    }

    return false;
}

void Chaksu(char& p) {
    int r, c;
    while (1) {
        std::cout << "It's " << p << " turn, " << "Where? " << " ";
        std::cin >> r >> c;
        if (r > board.size() || c > board[0].size()) {
            std::cout << "ERROR: TRY AGAIN" << std::endl;
        }
        else if (board[r - 1][c - 1] == 'O' || board[r - 1][c - 1] == 'X') {
            std::cout << "Already taken!! TRY AGAIN" << std::endl;
        }
        else if (r == board.size() && c == board[0].size()) {
            exit(0);
        }
        else if (r < board.size() && c < board[0].size()) {
            board[r - 1][c - 1] = p;
            break;
        }
    }
}

void TogglePlayer(char& p) {
    p == 'O' ? p = 'X' : p = 'O';
}

void Fill(int r, int c) { 
    garo = c;
    sero = r;
    board.assign(r, std::vector <char>(c, '-'));
} //굳이 채워놀을필요x