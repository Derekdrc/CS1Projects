//Derek D'Arcy
//I have neither given nor received unauthorized aid in completing this work, nor have I presented someone else’s work as my own.

#include <iostream>
#include <ctime>
#include <iomanip>
#include <windows.h>

using namespace std;
void goToXY(int, int);
char suit(int);
int value(int);
char faceCard(int);
void updateTotal(int[], int[][8]);
void dealTwoCards(int[], int[][8]);
void dealCard(int[], int[][8], int, int, int);
void finishDealer(int[], int[][8], int[], int, bool);
void determineWinner(int[]);
void updateScreen(int[], int[][8], int[], bool);

/*main is the main function that handles the creation 
of the arrays, the creation of the card deck array 
and calls all the functions neccessary for when a player hits or stands, 
to finish the dealer and assign win/loss/ties */
int main() {
	int playerCurrentCards[11][8] = { -1 };//2d array that has 8 players with 11 cards, maximimum a player hand can have before busting (A,A,A,A,2,2,2,2,3,3,3) 
	int cards[52], picked[52] = { 0 }, cardIndex, totals[8] = { 0 };
	char hitStand = ' ';
	bool playersDone = false;
	srand(time(NULL));
	for (cardIndex = 0; cardIndex < 52; cardIndex++) {
		do {
			cards[cardIndex] = rand() % 52;
		} while (picked[cards[cardIndex]] != 0);
		picked[cards[cardIndex]] = 1;
		cout << cards[cardIndex] << endl;
	}
	//populates 2d array of current player cards with -1, so unused cards can easily be ignored
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 8; j++) {
			playerCurrentCards[i][j] = -1;
		}
	}
	//deals the first two cards to all players, and then sets var to 15, the number of cards dealt
	dealTwoCards(cards, playerCurrentCards);
	int totalCardsDealt = 15;
	updateScreen(cards, playerCurrentCards, totals, playersDone);
	// loops with a call to a function to deal cards to a player
	for (int j = 1; j < 8; j++) {
		for (int i = 2; i < 11; i++) {
			goToXY(0, 19);
			cout << "Would Player " << j << " like another card? (Please enter 'y' or 'n')";
			cin >> hitStand;
			while (hitStand != 'y' && hitStand != 'n') {
				cout << "That is not a valid choice. Please enter 'y' or 'n'). ";
				cin >> hitStand;
			}
			if (hitStand == 'y') {
				Beep(523, 250); // produce beep sound when player takes card
				dealCard(cards, playerCurrentCards, i, j, totalCardsDealt); //deal card to player
				totalCardsDealt++;
				updateScreen(cards, playerCurrentCards, totals, playersDone); //updates the playing table
				if (totals[j] >= 21) {
					break; //goes to next player if plaayer busts
				}
			}
			if (hitStand == 'n') {
				system("cls");
				updateScreen(cards, playerCurrentCards, totals, playersDone);
				break; //goes to next plaayer if player stands
			}
		}
	}

	playersDone = true;
	// call a function to finish the dealer
	finishDealer(cards, playerCurrentCards, totals, totalCardsDealt, playersDone);
	// call a function to determine win/lose/tie
	determineWinner(totals);

	goToXY(0, 20);

	//Handles asking the player if he would like to keep playing after each game. 
	char playAgain;
	cout << "Would You like to play again? ('y' or 'n')";
	cin >> playAgain;
	while (playAgain != 'y' && playAgain != 'n') {
		cout << "Please enter valid response. Would You like to play again? ('y' or 'n')";
		cin >> playAgain;
	}
	if (playAgain == 'y') {
		main();
	}
	else if (playAgain == 'n') {
		system("pause");
		return 0;
	}

}

/*goToXY handles positioning the cursor 
wherever necessary to ensure printing in 
the correct place*/
void goToXY(int column, int row) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		COORD pos = { column, row };
		SetConsoleCursorPosition(hConsole, pos);
	}
	return;
}

/*suit takes in the index of a card and assigns
it the correct suit*/
char suit(int i) {
	if (i == -1) {
		return ' ';
	}
	char c;
	c = char(i / 13 + 3);
	return c;
}

/*value takes in the index of a card and assigns 
it the correct value (1-10)*/
int value(int i) {
	if (i == -1) {
		return 0;
	}
	int r;
	if (i % 13 == 0)
		r = 1;
	else if (i % 13 > 9)
		r = 10;
	else
		r = i % 13 + 1;
	return r;
}

/*faceCard takes in the index of a card and assigns 
it A, J, Q, K if its a face card*/
char faceCard(int i) {

	char c = ' ';
	if (i % 13 == 0)
		c = 'A';
	else if (i % 13 == 10)
		c = 'J';
	else if (i % 13 == 11)
		c = 'Q';
	else if (i % 13 == 12)
		c = 'K';

	return c;
}

/*updateTotal handles the calculations 
of each players totals and stores it in an array*/
void updateTotal(int total[], int playerCurrentCards[][8]) {
	for (int i = 0; i < 8; i++) {
		total[i] = 0;
	}
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 8; j++) {
			total[j] += value(playerCurrentCards[i][j]);
		}
	}
	return;
}

/*dealTwoCards is what is called to deal every 
player besides the dealer their first 2 cards, 
and deals the dealer his one card*/
void dealTwoCards(int cards[], int playerCurrentCards[][8]) {
	int nextCard = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 8; j++) {
			if (i == 1 && j == 0) {
				continue;
			}
			playerCurrentCards[i][j] = cards[nextCard];
			nextCard++;
		}
	}
	return;
}

/*dealCard is called to give whichever player that asks
for another card the next card out of the shuffled deck*/
void dealCard(int cards[], int playerCurrentCards[][8], int numCardsDealtPerPlayer, int currPlayer, int totalCardsDealt) {
	playerCurrentCards[numCardsDealtPerPlayer][currPlayer] = cards[totalCardsDealt + 1];
	return;
}

/*finishDealer is called once all players finish, 
and gives the dealer his 2nd card, then 
continues hitting according to the rules
of blackjack*/
void finishDealer(int cards[], int playerCurrentCards[][8], int totals[], int totalCardsDealt, bool playersFinished) {
	playerCurrentCards[1][0] = cards[totalCardsDealt + 1];
	totalCardsDealt++;
	updateScreen(cards, playerCurrentCards, totals, playersFinished);
	int dealerCards = 2;

	while (totals[0] < 17) {
		playerCurrentCards[dealerCards][0] = cards[totalCardsDealt + 1];
		dealerCards++;
		totalCardsDealt++;
		updateScreen(cards, playerCurrentCards, totals, playersFinished);
	}
	return;
}

/*determine winner is the function that goes
through each player and calculates if they won, 
tied or lost to the dealer*/
void determineWinner(int totals[]) {
	int dealerTotal = totals[0];
	goToXY(0, 15);
	cout << setw(8) << "Dealer";
	for (int i = 1; i < 8; i++) {
		if (totals[i] > 21) {
			cout << setw(8) << "Lose";
		}
		else if (dealerTotal > 21 && totals[i] <= 21) {
			cout << setw(8) << "Win";
		}
		else if (dealerTotal <= 21 && totals[i] == dealerTotal) {
			cout << setw(8) << "Tie";
		}
		else if (dealerTotal <= 21 && totals[i] <= 21 && dealerTotal > totals[i]) {
			cout << setw(8) << "Lose";
		}
		else if (dealerTotal <= 21 && totals[i] <= 21 && dealerTotal < totals[i]) {
			cout << setw(8) << "Win";
		}
	}
	return;
}

/*updateScreen is the function that is called that
repeatedly prints out the entire blackjack table
as it currently stands with everyones cards. */
void updateScreen(int cards[], int playerCurrentCards[][8], int totals[], bool playersFinished) {
	int row = 0;
	system("cls");
	system("color A");
	goToXY(0, 0);
	cout << setw(8) << "Dealer" << setw(8) << "P1" << setw(8) << "P2" << setw(8) <<
		"P3" << setw(8) << "P4" << setw(8) << "P5" << setw(8) << "P6" << setw(8) << "P7" <<
		endl;
	row = 1;
	goToXY(0, row);
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 8; j++) {
			if (!playersFinished) {
				if (i == 1 && j == 0) {
					cout << setw(8) << "??";
					continue;
				}
			}
			if (playerCurrentCards[i][j] == -1) {
				cout << setw(8) << " ";
			}
			char cardsuit = suit(playerCurrentCards[i][j]); // diamond, heart, club, spade
			int cardvalue = value(playerCurrentCards[i][j]); // 1-10
			char face = faceCard(playerCurrentCards[i][j]); // a, j, q, k
			if (playerCurrentCards[i][j] >= 0) {
				if (face != ' ') {
					cout << setw(7) << face << cardsuit;
				}
				else {
					cout << setw(7) << cardvalue << cardsuit;
				}
			}
			if (j == 7) {
				cout << endl;
			}
		}
	}

	updateTotal(totals, playerCurrentCards);
	goToXY(0, 16);
	for (int i = 0; i < 8; i++) {
		if (totals[i] > 21) {
			cout << setw(8) << "Bust";
		}
		else {
			cout << setw(8) << " ";
		}
	}
	goToXY(0, 17);
	for (int i = 0; i < 8; i++) {
		cout << setw(8) << "Total";
	}
	cout << endl;
	for (int i = 0; i < 8; i++) {
		cout << setw(8) << totals[i];
	}
	cout << endl;
	return;
}