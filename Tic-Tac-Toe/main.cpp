// My Tic-Tac-Toe game
//TODO Add user input
//TODO Add menu
//TODO Add win and lose condition
//TODO Add AI to fight with

#include <iostream>
using std::cout;
using std::endl;

const int g_kiSize = 3; // Define board size
char g_acBoard[g_kiSize][g_kiSize] = { { ' ', ' ', ' ' },{ ' ', ' ', ' ' },{ ' ', ' ', ' ' } }; // Define boards fields

void printWelcomeScreen(){
	cout << "\n"; // ASCII art for tic-tac-toe game name
	cout << "  	      _______   _____    _____    _______           _____    _______   ____    ______ " << endl;
	cout << "  	     |__   __| |_   _|  / ____|  |__   __|  /\\     / ____|  |__   __| / __ \\  |  ____|" << endl;
	cout << "  	 	| |      | |   | |   ______ | |    / _\\   | |   ______ | |   | |  | | | |__   " << endl;
	cout << " 	 	| |      | |   | |  |______|| |   / /_\\\\  | |  |______|| |   | |  | | |  __|  " << endl;
	cout << " 		| |     _| |_  | |____      | |  / ____ \\ | |____      | |   | |__| | | |____ " << endl;
	cout << " 		|_|    |_____|  \\_____|     |_| /_/    \\_\\ \\_____|     |_|    \\____/  |______|" << endl;
	cout << "\n\n";

};

void resetBoard() { // Reset boards fields
	for (int i = 0; i < g_kiSize; i++) {
		for (int j = 0; j < g_kiSize; j++) {
			g_acBoard[i][j] = ' ';
		}
	}
};

void printBoard() {
	cout << "+---+---+---+" << endl;
	for (int j = 0; j < g_kiSize; j++) {
		for (int i = 0; i < g_kiSize; i++) {
			cout << "| " << g_acBoard[i][j] << " ";
		} 
		cout << "| " << endl;
		cout << "+---+---+---+" << endl;
	} 
};

bool setBoard(int iX, int iY, char cCharValue) { // Give option to change boards fields
	if (g_acBoard[iX][iY] == ' ') { 
		g_acBoard[iX][iY] = cCharValue;
		return true; 
	} 
	else { 
		return false; 
	} 
}

int main() {
	resetBoard();
	printWelcomeScreen();

	printBoard();
	cout << endl;
	setBoard(2, 2, 'X');
	printBoard();
	cout << endl;

	return 0;
}