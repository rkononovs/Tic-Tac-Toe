// My Tic-Tac-Toe game
//TODO Valdate user input
//TODO Add menu
//TODO Add win and lose condition
//TODO Add AI to fight with
//TODO Add game loop
//TODO Add menu loop
//TODO Fix Bug - If input number that is more then int can store it overflows

#include <iostream>
#include <string>
#include <cctype>
using std::cout;
using std::cin;
using std::endl;
using std::string;

const int g_kiSize = 3; // Define board size
char g_acBoard[g_kiSize][g_kiSize] = { { '1', '2', '3' },{ '4', '5', '6' },{ '7', '8', '9' } }; // Define boards fields
char cPlayer = 'X';

void printWelcomeScreen(){
	cout << "\n"; // ASCII art for tic-tac-toe game name
	cout << "  	      _______   _____    _____    _______           _____    _______   ____    ______ " << endl;
	cout << "  	     |__   __| |_   _|  / ____|  |__   __|  /\\     / ____|  |__   __| / __ \\  |  ____|" << endl;
	cout << "  	 	| |      | |   | |   ______ | |    / _\\   | |   ______ | |   | |  | | | |__   " << endl;
	cout << " 	 	| |      | |   | |  |______|| |   / /_\\\\  | |  |______|| |   | |  | | |  __|  " << endl;
	cout << " 		| |     _| |_  | |____      | |  / ____ \\ | |____      | |   | |__| | | |____ " << endl;
	cout << " 		|_|    |_____|  \\_____|     |_| /_/    \\_\\ \\_____|     |_|    \\____/  |______|" << endl;
	cout << "\n\n";

	cout << "Options: " << endl;
	cout <<"To play - Player vs. Player - type 'PvP'" << endl; 
	cout <<"To play - Player vs. AI - type 'PvE'" << endl;
};

void printOptions() {

};

void resetBoard() { // Reset boards fields
	int iPosition = 0;
	for (int i = 0; i < g_kiSize; i++) {
		for (int j = 0; j < g_kiSize; j++) {
			iPosition++;
			char cPosition = '0' + iPosition; // Make integer a character
			g_acBoard[i][j] = cPosition;
		}
	}
};

void printBoard() {
	cout << "+---+---+---+" << endl;
	for (int i = 0; i < g_kiSize; i++) {
		for (int j = 0; j < g_kiSize; j++) {
			cout << "| " << g_acBoard[i][j] << " ";
		} 
		cout << "| " << endl;
		cout << "+---+---+---+" << endl;
	} 
};
void changePlayer() {
	if (cPlayer == 'X') {
		cPlayer = 'O';
	}
	else {
		cPlayer = 'X';
	}
}

bool setBoard(int iX, int iY, char cCharValue) { // Give option to change boards fields
	if (isdigit(g_acBoard[iX][iY])) {   // Check whether field is digit 
		g_acBoard[iX][iY] = cCharValue;
		return true; 
	} 
	else { 
		return false; 
	} 
}

void getUserInput() {
	int iInput;
	cout << "Enter number that indicates position" << endl;
	cin >> iInput;
	switch (iInput)
	{
	case 1:
		setBoard(0, 0, cPlayer);
		break;
	case 2:
		setBoard(0, 1, cPlayer);
		break;
	case 3:
		setBoard(0, 2, cPlayer);
		break;
	case 4:
		setBoard(1, 0, cPlayer);
		break;
	case 5:
		setBoard(1, 1, cPlayer);
		break;
	case 6:
		setBoard(1, 2, cPlayer);
		break;
	case 7:
		setBoard(2, 0, cPlayer);
		break;
	case 8:
		setBoard(2, 1, cPlayer);
		break;
	case 9:
		setBoard(2, 2, cPlayer);
		break;
	default:
		cout << "Your input is not an option!" << endl;
		break;
	}

	changePlayer();
};

bool checkIfPlayerHasWon() {
	return true;
};


int main() {
	string uInput;
	bool bPlayerHasWon = false;
	while (1) {
		printBoard();
		getUserInput();
	}

	return 0;
}