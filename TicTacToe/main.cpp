/*
Project Tic Tac Toe
Creator: Trunks Thomas
*/
#include "Utils.h"
#include <ctime>

char ln1[3] = { 0,0,0 };
char ln2[3] = { 0,0,0 };
char ln3[3] = { 0,0,0 };
char* board[3] = { ln1, ln2, ln3 };

int main() {
	srand(time(0));
	char winner = 0;
	while (winner != 'X' && winner != 'O') {
	winner = Utils::PlayRound(board);
	}
}

