//Derek D'Arcy
//I have neither given nor received unauthorized aid in completing this work, nor have I presented someone else’s work as my own.

#include <iostream>
using namespace std;

void displayBoard(char[][3]);
void playerInput(char array[][3], char letter);
bool winAcross(char array[][3], char letter, string &);
bool winVert(char array[][3], char letter, string &);
bool diagonalWinLeft(char array[][3], char letter, string &);
bool diagonalWinRight(char array[][3], char letter, string &);
bool noSpacesLeft(char array[][3], char letter, string &);
bool checkWin(char array[][3], char letter, string &);


int main() {
	char gameBoard[3][3] = { {'*', '*', '*'},
								{'*', '*', '*'},
								{'*', '*', '*'} };

	bool playAgain = true;
	string playerWinner;
	char response;
	displayBoard(gameBoard);
	while (playAgain) {
		playerInput(gameBoard, 'X');
		displayBoard(gameBoard);
		if (checkWin(gameBoard, 'X', playerWinner)) {
			cout << playerWinner << " has won the game!" << endl;
			break;
		}

		playerInput(gameBoard, 'O');
		displayBoard(gameBoard);
		if (checkWin(gameBoard, 'O', playerWinner)) {
			cout << playerWinner << " has won the game!" << endl;
			break;
		}
	}
		cout << "Would you like to play again? (Please answer 'y' or 'n'). ";
		cin >> response;
		while (response != 'y' && response != 'n') {
			cout << "Please enter a valid response of 'y' or 'n'. Would you like to play again?";
			cin >> response;
		}
		if (response == 'n') {
			playAgain = false;
			system("pause");
			return 0;
		}
		else {
			system("cls");
			playAgain = true;
			char gameBoard[3][3] = { {'*', '*', '*'},
										{'*', '*', '*'},
										{'*', '*', '*'} };
			main();
		}

}

//display board
void displayBoard(char array[][3]) {
	cout << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << array[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

//get user input for space
void playerInput(char array[][3], char letter) {
	cout << "Please select where to place a(n) " << letter << ": " << endl;
	int row;
	int col;

	bool turnTaken = false;
	while (turnTaken == false) {
		cout << "Which row? (Please pick a number 1-3) ";
		cin >> row;
		while (row > 3 || row < 1) {
			cout << "Invalid number. Please pick your row again (1-3). ";
			cin >> row;
		}
		cout << "Which column? (Please pick a number 1-3) ";
		cin >> col;
		while (col > 3 || col < 1) {
			cout << "Invalid number. Please pick your column again (1-3). ";
			cin >> col;
		}
		if (array[(row - 1)][(col - 1)] == '*') {
			array[(row - 1)][(col - 1)] = letter;
			turnTaken = true;
		}
		else {
			cout << "Sorry that spot is already taken. " << endl;
		}
	}

}

//conbine all separate checks to win game into one function
bool checkWin(char array[][3], char letter, string &playerWinner) {
	bool winner = false;
	if (winAcross(array, letter, playerWinner)) {
		winner = true;
	}
	else if (winVert(array, letter, playerWinner)) {
		winner = true;
	}
	else if (diagonalWinLeft(array, letter, playerWinner)) {
		winner = true;
	}
	else if (diagonalWinRight(array, letter, playerWinner)) {
		winner = true;
	}
	else if(noSpacesLeft(array, letter, playerWinner)) {
		playerWinner = "tie game";
		winner = true;
	}
	return winner;
}

//check horizontally for a winner
bool winAcross(char array[][3], char letter, string &playerWinner) {
	int counter = 0;
	bool win = false;
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			if (array[row][col] == letter) {
				counter++;
			}
		}

		if (counter == 3) {
			if (letter == 'X') {
				playerWinner = "Player 1";
				win = true;
			}
			else if (letter == 'O') {
				playerWinner = "Player 2";
				win = true;
			}
			win = true;
		}
		else {
			win = false;
			counter = 0;
		}
	}
		return win;
}

//check vertically for a winner
bool winVert(char array[][3], char letter, string &playerWinner) {
	int counter = 0;
	bool win = false;

	for (int column = 0; column < 3; column++) {
		for (int row = 0; row < 3; row++) {
			if (array[row][column] == letter) {
				counter++;
			}
		}

		if (counter == 3) {
			if (letter == 'X') {
				playerWinner = "Player 1";
			}
			else if (letter == 'O') {
				playerWinner = "Player 2";
			}
			win = true;
		}
		else {
			win = false;
			counter = 0;
		}
	}
	return win;
}

//check diagonally top left to bottom right for winner
bool diagonalWinLeft(char array[][3], char letter, string &playerWinner) {
	int counter = 0;
	bool win = false;

	for (int i = 0; i < 3; i++) {
		if (array[i][i] == letter) {
			counter++;
		}
	}
	if (counter == 3) {
		if (letter == 'X') {
			playerWinner = "Player 1";
			win = true;
		}else if (letter == 'O') {
			playerWinner = "Player 2";
			win = true;
		}
		else {
			win = false;
		}
	}
	return win;
}

//check diagonally top right to bottom left for a winner
bool diagonalWinRight(char array[][3], char letter, string &playerWinner) {
	int counter = 0;
	bool win = false;

	for (int row = 0, column = (3 - 1); row < 3; row++, column--) {
		if (array[row][column] == letter) {
			counter++;
		}
	}
	if (counter == 3) {
		if (letter == 'X') {
			playerWinner = "Player 1";
			win = true;
		}
		else if (letter == 'O') {
			playerWinner = "Player 2";
			win = true;
		}
		else {
			counter = 0;
			win = false;
		}
	}
	return win;
}

//check if the game is over via no spaces being left on the board
bool noSpacesLeft(char array[][3], char letter, string &playerWinner) {
	bool over = false;
	int counter = 0;
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			if (array[row][col] == 'X' || array[row][col] == 'O') {
				counter++;
			}
		}
	}
	if (counter == 9) {
		over = true;
		playerWinner = "Nobody";
	}
	return over;
}



