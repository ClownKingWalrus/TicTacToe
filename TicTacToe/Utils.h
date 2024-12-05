#pragma once
#include <iostream>
#include <vector>
class Utils {
public:
	static char PlayRound(char* arr[3]) {
		int count = 0;
		std::vector<int> tempVect;
		//====================================Player Turn==========================================//
		//print the board with valid moves
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (arr[i][j] == 0) {
					std::cout << count << "|";
					tempVect.push_back(count);
				} else {
					std::cout << arr[i][j] << "|";
				}
				count++;
			}
			std::cout << "\n" << "------\n";
		}

		std::cout << "\n\ntype a numberd spot to place your move\n" << std::endl;
		int x;
		std::cin >> x;

		//make sure the input is valid and is in the board space
		while (!std::cin.good() || !CheckInput(tempVect, x)) {
			std::cout << "try again\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin >> x;
		}

		//now we take the number the play inputted and put it on the board
		count = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (count == x) {
					arr[i][j] = 'X';
					std::cout << arr[i][j] << "|";
				} else if (arr[i][j] == 0) {
					std::cout << count << "|";
				} else {
					std::cout << arr[i][j] << "|";
				}
				count++;
			}
			std::cout << "\n" << "------\n";
		}
		std::cout << "\n\n\n";
		if (WinCheck(arr) == 'X') {
			count = 0;
			std::cout << "Winner was X\n";
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						if (arr[i][j] == 0) {
							std::cout << count << "|";
						} else {
							std::cout << arr[i][j] << "|";
						}
						count++;
					}
					std::cout << "\n" << "------\n";
				}
			return 'X';
		}
	//====================================AI TURN==========================================//
		//print the board with valid moves and push valid moves into vector
		count = 0;
		tempVect.clear(); //clear the vector
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (arr[i][j] == 0) {
					std::cout << count << "|";
					tempVect.push_back(count);
				} else {
					std::cout << arr[i][j] << "|";
				}
				count++;
			}
			std::cout << "\n" << "------\n";
		}
		std::cout << "\n\n\n";

		//set valid moves for ai to choose from

		std::cout << "Ai is thinking..." << std::endl;

		//randomly choose a valid place on the board
		int aiChoice = rand() % tempVect.size();
		aiChoice = tempVect[aiChoice];
		count = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (count == aiChoice) {
					arr[i][j] = 'O';
					std::cout << arr[i][j] << "|";
				} else if (arr[i][j] == 0) {
					std::cout << count << "|";
				}
				else {
					std::cout << arr[i][j] << "|";
				}
				count++;
			}
			std::cout << "\n" << "------\n";
		}

		std::cout << "\n\n\n";
		if (WinCheck(arr) == 'O') {
			count = 0;
			std::cout << "Winner was O\n";
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (arr[i][j] == 0) {
						std::cout << count << "|";
					}
					else {
						std::cout << arr[i][j] << "|";
					}
					count++;
				}
				std::cout << "\n" << "------\n";
			}
			return 'O';
		}
		return 0;
	}


	static bool CheckInput(std::vector<int> tempVect, int x) {
		for (int i = 0; i < tempVect.size(); i++) {
			if (x == tempVect[i]) {
				return true;
			}
		}
		return false;
	}

	static char WinCheck(char* arr[3]) {
		int count = 0;
		char arrTestX[3] = { 'X', 'X', 'X' };
		char arrTestO[3] = { 'O', 'O', 'O' };
		for (int i = 0; i < 3; i++) {//check board horzontals
			if (arr[i] == arrTestX) {
				return 'X';
			}
			else if (arr[i] == arrTestO) {
				return 'O';
			}
		}

		for (int i = 0; i < 3; i++) {//check board verticals
			if (arr[i][0] == 'X' && arr[i][1] == 'X' && arr[i][2] == 'X') {
				return 'X';
			}
			else if (arr[i][0] == 'O' && arr[i][1] == 'O' && arr[i][2] == 'O') {
				return 'O';
			}
		}
		//check diagnoals
		if (arr[0][0] == 'X' && arr[1][1] == 'X' && arr[2][2] == 'X' || arr[0][2] == 'X' && arr[1][1] == 'X' && arr[2][0] == 'X') {
			return 'X';
		}
		else if (arr[0][0] == 'O' && arr[1][1] == 'O' && arr[2][2] == 'O' || arr[0][2] == 'O' && arr[1][1] == 'O' && arr[2][0] == 'O') {
			return 'O';
		}
		return 0;
	}
};