/* 
My Tic-Tac-Toe that was part of Intruduction to C++ coursework
Completed in 08/12/2019
This program can take input from user and change fields in array.
This program checks win conditions and ensures that input is correct.
This program implements basic functions and passing by reference as well as arrays and I/O.
*/

#include <iostream>
#include <cctype>

using std::cout;
using std::cin;
using std::endl;

const int g_kiSize = 3; // Define board size
char g_acBoard[g_kiSize][g_kiSize] = { { '1', '2', '3' },{ '4', '5', '6' },{ '7', '8', '9' } }; // Define boards fields
char g_cPlayer = 'X'; // Define current player
void getUserPositionInput();

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
	int iPosition = 0;
	for (int i = 0; i < g_kiSize; i++) {
		for (int j = 0; j < g_kiSize; j++) {
			iPosition++; // Move to the next position
			char cPosition = '0' + iPosition; // Make integer a character
			g_acBoard[i][j] = cPosition; // Asign a number to a related field
		}
	}
};

void printBoard() { 
	cout << "+---+---+---+" << endl; // Print upper side of the board
	for (int i = 0; i < g_kiSize; i++) {
		for (int j = 0; j < g_kiSize; j++) {
			cout << "| " << g_acBoard[i][j] << " "; // Print Sides and spaces in between
		} 
		cout << "| " << endl; // Print ending sides
		cout << "+---+---+---+" << endl; // Print lines
	} 
};

void changePlayer() {
	if (g_cPlayer == 'X') { // Change X to O
		g_cPlayer = 'O';
	}
	else { // Change O to X
		g_cPlayer = 'X';
	}
}

bool setBoard(int iX, int iY, char cCharValue) { // Give option to change boards fields
	if (isdigit(g_acBoard[iX][iY])) {   // Check whether field is digit i.e. if field is not taken
		g_acBoard[iX][iY] = cCharValue; // Add assigned character( X or O ) to choosen field position
		return true; 
	} 
	else { // Else indicate that field is taken and request input again!
		cout << "This field is already occupied." << endl;
		cout << "Try other position.\n" << endl;
		getUserPositionInput();
	}
}

void getUserPositionInput() {
	char cInput;

	cout << "It is " << g_cPlayer << " turn." << endl;
	cout << "Enter number that indicates position: ";
	cin >> cInput;
	cout << endl;
	switch (cInput) // Set user input to field 
	{
	case '1':
		setBoard(0, 0, g_cPlayer);
		break;
	case '2':
		setBoard(0, 1, g_cPlayer);
		break;
	case '3':
		setBoard(0, 2, g_cPlayer);
		break;
	case '4':
		setBoard(1, 0, g_cPlayer);
		break;
	case '5':
		setBoard(1, 1, g_cPlayer);
		break;
	case '6':
		setBoard(1, 2, g_cPlayer);
		break;
	case '7':
		setBoard(2, 0, g_cPlayer);
		break;
	case '8':
		setBoard(2, 1, g_cPlayer);
		break;
	case '9':
		setBoard(2, 2, g_cPlayer);
		break;
	default: // if input is above 9 ask again for input
		cout << "Your input is not an option!" << endl;
		cout << "Try another input!\n" << endl;
		getUserPositionInput();
		break;
	}
};

void getUserExitInput(bool& exit) {
	char cInput; // define input
	while (true) {
		cin >> cInput; // input a character
		if ((cInput == 'y') || (cInput == 'Y')) { // if input is either y or Y then reset board and start new game
			resetBoard();
			exit = true;
			break;
		}
		else if ((cInput == 'n') || (cInput == 'N')) {  // if input is either y or Y then exit the game
			exit = false;
			break;
		}
		else { // if input is not y,Y or n,N then ask again for input.
			cout << "Wrong input! Try again." << endl;
		}
	}
}

bool playerXHasWon() { // Check if win condition is met
	int iHorizontalX = 0; // How many X are in one row
	int iVerticalX = 0; // How many X are in one column
	int iDiagonalX = 0; // How many X are in the diagonal
	int iRDiagonalX = 0; // How many X are in the reverse diagonal
	int iRDiagonalXCordinate = 2; // Starting cordinate for reverse diagonal win condition check 

	while (true) {
		// Check if Horizontal win condition is met
		for (int i = 0; i < g_kiSize; i++) {
			for (int j = 0; j < g_kiSize; j++) {
				if (g_acBoard[i][j] == 'X') { // if horizontaly one of the fields has X
					iHorizontalX++; // Add 1 to iHorizontalX
				}
			}
			if (iHorizontalX == 3) { // if in one horizontal row ( 0 row ) there are 3 X then 
				return true; // X HAS WON
			}
			else {
				iHorizontalX = 0;  // Reset iHorizontalX and check next row
			}
		}

		// Check if Vertical win condition is met
		for (int i = 0; i < g_kiSize; i++) {
			for (int j = 0; j < g_kiSize; j++) {
				if (g_acBoard[j][i] == 'X') { // if vertically one of the fields has X
					iVerticalX++; // Add 1 to iVerticalX
				}
			}
			if (iVerticalX == 3) { // if in one vertical column ( 0 column ) there are 3 X then 
				return true; // X HAS WON
			}
			else {
				iVerticalX = 0;  // Reset iVerticalX and check next column
			}
		}

		// Check if diagonal win condition is met
		for (int i = 0; i < g_kiSize; i++) {
			if (g_acBoard[i][i] == 'X') { // if in diagonal one of the fields has X
				iDiagonalX++; // Add 1 to iDiagonalX
			}
		}
		if (iDiagonalX == 3) { // if in diagonal there are 3 X then 
			return true; // X HAS WON
		}
		else {
			iDiagonalX = 0;  // Reset iDiagonalX
		}

		// Check if reverse diagonal win condition is met
		for (int i = 0; i < g_kiSize; i++) {
			if (g_acBoard[i][iRDiagonalXCordinate] == 'X') { // if in reverse diagonal one of the fields has X
				iRDiagonalX++; // Add 1 to iDiagonalX
			}
			iRDiagonalXCordinate--;
		}
		if (iRDiagonalX == 3) { // if in reverse diagonal there are 3 X then 
			return true; // X HAS WON
		}
		else {
			iRDiagonalX = 0;  // Reset iDiagonalX
		}

		return false;
	}
};

bool playerOHasWon() { // Check if win condition is met
	int iHorizontalO = 0; // How many O are in one row
	int iVerticalO = 0; // How many O are in one column
	int iDiagonalO = 0; // How many O are in the diagonal
	int iRDiagonalO = 0; // How many O are in the reverse diagonal
	int iRDiagonalOCordinate = 2; // Starting cordinate for reverse diagonal win condition check 

	while (true) {
		// Check if Horizontal win condition is met
		for (int i = 0; i < g_kiSize; i++) {
			for (int j = 0; j < g_kiSize; j++) {
				if (g_acBoard[i][j] == 'O') { // if horizontaly one of the fields has O
					iHorizontalO++; // Add 1 to iHorizontalO
				}
			}
			if (iHorizontalO == 3) { // if in one horizontal row ( 0 row ) there are 3 O then 
				return true; // O HAS WON
			}
			else {
				iHorizontalO = 0;  // Reset iHorizontalO and check next row
			}
		}

		// Check if Vertical win condition is met
		for (int i = 0; i < g_kiSize; i++) {
			for (int j = 0; j < g_kiSize; j++) {
				if (g_acBoard[j][i] == 'O') { // if vertically one of the fields has O
					iVerticalO++; // Add 1 to iVerticalO
				}
			}
			if (iVerticalO == 3) { // if in one vertical column ( 0 column ) there are 3 O then 
				return true; // O HAS WON
			}
			else {
				iVerticalO = 0;  // Reset iVerticalO and check next column
			}
		}

		// Check if diagonal win condition is met
		for (int i = 0; i < g_kiSize; i++) {
			if (g_acBoard[i][i] == 'O') { // if in diagonal one of the fields has O
				iDiagonalO++; // Add 1 to iDiagonalO
			}
		}
		if (iDiagonalO == 3) { // if in diagonal there are 3 O then 
			return true; // O HAS WON
		}
		else {
			iDiagonalO = 0;  // Reset iDiagonalO
		}

		// Check if reverse diagonal win condition is met
		for (int i = 0; i < g_kiSize; i++) {
			if (g_acBoard[i][iRDiagonalOCordinate] == 'O') { // if in reverse diagonal one of the fields has O
				iRDiagonalO++; // Add 1 to iRDiagonalO
			}
			iRDiagonalOCordinate--;
		}
		if (iRDiagonalO == 3) { // if in reverse diagonal there are 3 O then 
			return true; // O HAS WON
		}
		else {
			iRDiagonalO = 0;  // Reset iRDiagonalO
		}

		return false;
	}
};

int main() {
	int iTurn = 0; // Turns taken
	bool bPlayAgain = true;

	printWelcomeScreen();
	while (bPlayAgain) {
		printBoard();
		getUserPositionInput();
		iTurn++; // Increment how many turns were played
		changePlayer();

		if (playerXHasWon() == true) {
			printBoard();
			cout << "Player 'X' has won!\n" << endl;
			cout << "Do you want to start new game? Type y/n" << endl;
			getUserExitInput(bPlayAgain); // When game won check if player wants to play again
			iTurn = 0; // Reset turns
		}
		else if (playerOHasWon() == true) {
			printBoard();
			cout << "Player 'O' has won!\n" << endl;
			cout << "Do you want to start new game? Type y/n" << endl;
			getUserExitInput(bPlayAgain);
			iTurn = 0; // Reset turns
		}
		else if (iTurn == 9) { // If no one won and there were 9 turns it is a draw.
			printBoard();
			cout << "It's a draw!\n" << endl;
			cout << "Do you want to start new game? Type y/n" << endl;
			getUserExitInput(bPlayAgain); // When game won check if player wants to play again
			iTurn = 0; // Reset turns
		}
	}

	return 0;
}