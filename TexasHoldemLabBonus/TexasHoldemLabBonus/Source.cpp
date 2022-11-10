//Derek D'Arcy
//I have neither given nor received unauthorized aid in completing this work, nor have I presented someone else’s work as my own.

#include <iostream>
#include <iomanip> 
#include <ctime>
#include <vector>
#include <Windows.h>
using namespace std;
char suit(int);
char picture(int);
void swap(int&, int&);
void swap(char&, char&);
bool IsItFlush(char[][7], int[][7], int[5], int); 
bool IsRoyalFlush(int[][7], int);
bool IsStraight(int[][7], int[5], int);

bool fourOfKind(int[][7], int[5], int);
bool fullHouse(int[][7], int[5], int);
bool threeOfKind(int[][7], int[5], int);
bool twoPair(int[][7], int[5], int);
bool isPair(int[][7], int[5], int);
int playerChips[5] = { 0 };

/*main handles the initating of the deck, shuffles the deck and then
* deals each player their 5 respective card, as well as handling the checking of
* each hands winning hand, and also handles the replaying of the game
* as well as the chip count for each player
*/
int main()
{
    int playerTwoCards[5][2], sharedCards[5] = { 0 }, playerCardsWithShared[5][7], Total[5] = { 0 };
    char playerTwoSuits[5][2], sharedCardSuits[5], playerSuitsWithShared[5][7], tempsuit;
    int wayToWin[5] = { 0 };
    vector<int> winnerVector;
    string winningString[10] = { "Royal Flush", "Straight Flush", "Four of a Kind", "Full House", "Flush", "Straight", "Three of a Kind", "Two Pair", "Pair", "High Card" };
    int deck[52], picked[52] = { 0 };
    int i, j, k, number, temp, start, index, minIndex, minValue, winnerIndex = 0;
    srand(time(NULL));

    system("color A"); // Colors the cards green like a poker table

    //shuffles the deck and makes it so the same card cannot be dealt twice
    for (i = 0; i < 52; i++)
    {
        do
        {
            number = rand() % 52;
        } while (picked[number] != 0);
        deck[i] = number;
        picked[number]++;
    }

    //gives 5 players 2 cards each in a 2d array from the shuffled deck array and corresponding suits 
    k = 0;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 2; j++)
        {
            playerTwoCards[i][j] = deck[k];
            playerTwoSuits[i][j] = suit(deck[k]);
            k++;
        }
    }

    //deals the shared 5 cards and corresponding suits
    for (int i = 0; i < 5; i++) {
        sharedCards[i] = deck[k];
        sharedCardSuits[i] = suit(deck[k]);
        k++;
    }

    //assigns the proper value of each players 2 cards
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 2; j++)
        {
            playerTwoCards[i][j] = playerTwoCards[i][j] % 13;
        }
    }

    //assigns the proper value of the 5 shared cards
    for (i = 0; i < 5; i++)
    {
        sharedCards[i] = sharedCards[i] % 13;
    }


    //sort the 5 shared cards and swap them
    for (start = 0; start < 4; start++)
    {
        minIndex = start;
        minValue = sharedCards[start];
        tempsuit = sharedCards[start];;
        for (index = start + 1; index < 5; index++)
        {
            if (sharedCards[index] < minValue)
            {
                minValue = sharedCards[index];
                tempsuit = sharedCardSuits[index];
                minIndex = index;
            }
        }
        swap(sharedCards[minIndex], sharedCards[start]);
        swap(sharedCardSuits[minIndex], sharedCardSuits[start]); 
    }

    //sort the players 2 cards and swap them
    for (int i = 0; i < 5; i++) {
        if (playerTwoCards[i][0] > playerTwoCards[i][1]) {
            swap(playerTwoCards[i][0], playerTwoCards[i][1]);
            swap(playerTwoSuits[i][0], playerTwoSuits[i][1]);
        }
    }

    //prints out the shared 5 cards and their suits SORTED
    for (int i = 0; i < 5; i++) {
        temp = sharedCards[i] % 13;
        if (temp > 9 || temp == 0) {
            cout << setw(3) << picture(temp);
        }
        else {
            cout << setw(3) << temp + 1;
        }
        cout << sharedCardSuits[i];
    }
    cout << endl;

    //prints out each players 2 cards and their suits SORTED
    cout << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 2; j++) {
            temp = playerTwoCards[i][j] % 13;
            if (temp > 9 || temp == 0) {
                cout << setw(3) << picture(temp);
            }
            else {
                cout << setw(3) << temp + 1;
            }
            cout << playerTwoSuits[i][j];
        }
        cout << endl;
    }

    //create a 2d array of combined cards for each player, of their 2 cards + shared 5
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 7; j++) {
            if (j < 2) {
                playerCardsWithShared[i][j] = playerTwoCards[i][j];
                playerSuitsWithShared[i][j] = playerTwoSuits[i][j];
            }
            else {
                playerCardsWithShared[i][j] = sharedCards[j - 2];
                playerSuitsWithShared[i][j] = sharedCardSuits[j - 2];
            }
        }
    }

    //Sort each players 2 cards + 5 additional cards
    for (int i = 0; i < 5; i++){
        for (start = 0; start < 6; start++)
        {
            minIndex = start;
            minValue = playerCardsWithShared[i][start];
            tempsuit = playerSuitsWithShared[i][start];;
            for (index = start + 1; index < 7; index++)
            {
                if (playerCardsWithShared[i][index] < minValue)
                {
                    minValue = playerCardsWithShared[i][index];
                    tempsuit = playerSuitsWithShared[i][index];
                    minIndex = index;
                }
            }
            swap(playerCardsWithShared[i][minIndex], playerCardsWithShared[i][start]);
            swap(playerSuitsWithShared[i][minIndex], playerSuitsWithShared[i][start]);
        }
    }

    //Loop through each player and check for each possible winning hand
    for (i = 0; i < 5; i++)  // for all five players
    {
        // check if it is a flush
        if (IsItFlush(playerSuitsWithShared, playerCardsWithShared, Total, i)) // 6,000,000 
        {
            // check if it is Royal Flush 10JQKA - A10JQK
            if (IsRoyalFlush(playerCardsWithShared, i)) { // 10,000,000
                Total[i] = 10, 000, 000;
                wayToWin[i] = 0;
            }
            // Check if it is a straight Flush 5 cards one is higher than previous
            else if (IsStraight(playerCardsWithShared, Total, i)) {
                Total[i] = 9000000 + playerCardsWithShared[i][4] * 10000;
                wayToWin[i] = 1;
            }
            else
            {
                //else it is just a normal flush
                wayToWin[i] = 4;
                Total[i] = 6000000;
                if (playerCardsWithShared[i][0] == 0)
                    Total[i] += 130, 000;
                else
                    Total[i] += playerCardsWithShared[i][0];
                Total[i] += playerCardsWithShared[i][4] * 10000;
                Total[i] += playerCardsWithShared[i][3] * 1000;
                Total[i] += playerCardsWithShared[i][2] * 100;
                Total[i] += playerCardsWithShared[i][1] * 10;
            }
        }
        //check if it is four of a kind
        else if (fourOfKind(playerCardsWithShared, Total, i)) {
            wayToWin[i] = 2;
            Total[i] += 8000000;

        }
        //check if it is a full house
        else if (fullHouse(playerCardsWithShared, Total, i)) {
            wayToWin[i] = 3;
            Total[i] += 7000000;
        }
        //check if it is a straight
        else if (IsStraight(playerCardsWithShared, Total, i)) {
            wayToWin[i] = 5;
            Total[i] += 5000000;
        }
        //check if it is a three of a kind
        else if (threeOfKind(playerCardsWithShared, Total, i)) {
            wayToWin[i] = 6;
            Total[i] += 4000000;
        }
        //check if it is two pair
        else if (twoPair(playerCardsWithShared, Total, i)) {
            wayToWin[i] = 7;
            Total[i] += 3000000;
        }
        //check if it is pair
        else if (isPair(playerCardsWithShared, Total, i)) {
            wayToWin[i] = 8;
            Total[i] += 2000000;
        }
        else {
            //else it is a high card and calculates total
            wayToWin[i] = 9;
            Total[i] = 1000000;
            Total[i] += playerCardsWithShared[i][2];
            Total[i] += playerCardsWithShared[i][6] * 10000;
            Total[i] += playerCardsWithShared[i][5] * 1000;
            Total[i] += playerCardsWithShared[i][4] * 100;
            Total[i] += playerCardsWithShared[i][3] * 10;
        }
    }
    cout << endl;
    //Prints out the hand score of each player
    for (int i = 0; i < 5; i++) {
        cout << "Player " << i + 1 << "'s hand score: " << Total[i] << endl;
    }
    cout << endl;
    
    //finds the maximum value out of total array
    for (int i = 0; i < 5; i++) {
        if (Total[i] >= Total[winnerIndex]) {
            winnerIndex = i;
        }
    }

    //loops through and adds the index of each winner
    for (int i = 0; i < 5; i++) {
        if (Total[i] == Total[winnerIndex]) {
            winnerVector.push_back(i);
        }
    }

    //prints out the winner(s) of the hand and how they won
    if (winnerVector.size() == 1) {
        cout << "Player " << winnerVector.at(0) + 1 << " won this hand via " << winningString[wayToWin[winnerIndex]] << endl << endl;
    }
    else {
        cout << "The following players won this hand: " << endl;
        for (int i = 0; i < winnerVector.size(); i++) {
            cout << "Player " << winnerVector.at(i) + 1 << endl;
        }
        cout << "via " << winningString[wayToWin[winnerIndex]] << endl << endl;
    }
    
    //updates the chip count correctly based on if a player won or lost the hand
    for (int i = 0; i < winnerVector.size(); i++) {
        playerChips[winnerVector.at(i)] += 2;
    }
    for (int i = 0; i < 5; i++) {
        playerChips[i]--;
    }

    //prints out the updated chip counts
    for (int i = 0; i < 5; i++) {
        cout << "Player " << i + 1 << "'s chip count is " << playerChips[i] << endl;
    }
    cout << endl << endl;

    //Handles asking the player if he would like to keep playing after each game. 
    char playAgain;
    cout << "Would You like to play again? ('y' or 'n')";
    cin >> playAgain;
    while (playAgain != 'y' && playAgain != 'n') {
        cout << "Please enter valid response. Would You like to play again? ('y' or 'n')";
        cin >> playAgain;
    }
    if (playAgain == 'y') {
        Beep(523, 250); // produce beep sound when player elects to play again
        system("cls");
        main();
    }
    else if (playAgain == 'n') {
        system("pause");
        return 0;
    }
 }

//returns the suit of the card
char suit(int card)
{
    return card / 13 + 3;
}
//returns the face card of a given card
char picture(int num)
{
    if (num == 0)
        return 'A';
    else if (num == 10)
        return 'J';
    else if (num == 11)
        return 'Q';

    return 'K';
}
//swaps two card values
void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
//swaps two card characters for the suit
void swap(char& a, char& b)
{
    char temp = a;
    a = b;
    b = temp;
}
//checks if a players hand is a Flush
bool IsItFlush(char suits[][7], int cards[][7], int Total[5], int i)
{
    for (int j = 0; j < 7; j++) {
        int counter = 0; 
        int index = 0;
        while (index < 7) {
            if (suits[i][j] == suits[i][index] && index!= i) { 
                counter++;
                index++;
            }
            else {
                index++;
            }

            if (counter >= 5) {
                return true;
            }
        }
    }

    return false;
}
//checks if a players hand is a Royal Flush
bool IsRoyalFlush(int cards[][7], int i)
{
    if (cards[i][0] == 0 && cards[i][3] == 9 && cards[i][4] == 10 && cards[i][5] ==
        11 && cards[i][6] == 12)
        return true;
    return false;
}
//checks if a players hand is a Straight
bool IsStraight(int cards[][7], int Total[5], int i)
{
    int j;
    int counter = 0;
    for (j = 0; j < 6; j++)
    {
        if (cards[i][j] + 1 == cards[i][j + 1]) {
            counter++;
        }
        else {
            counter = 0;
        }
        if (counter >= 5) {
            Total[i] += cards[i][j + 1] * 10000;
            Total[i] += cards[i][j] * 1000;
            Total[i] += cards[i][j - 1] * 100;
            Total[i] += cards[i][j-2] * 10;
            Total[i] += cards[i][j - 3];
            return true;
        }
    }
    return false;
}
//checks if a players hand is a four of a kind and adds the proper hand score for that player
bool fourOfKind(int cards[][7], int Total[5], int player) {
    if (cards[player][0] == cards[player][1] && cards[player][1] == cards[player][2] && cards[player][2] == cards[player][3]) {
        if (cards[player][0] == 0) { //checks if four of a kind is aces
            Total[player] += cards[player][4];
            Total[player] += 13 * 10000;
            Total[player] += 13 * 1000;
            Total[player] += 13 * 100;
            Total[player] += 13 * 10;
            return true;
        }
        else {
            Total[player] += cards[player][4];
            Total[player] += cards[player][3] * 10000;
            Total[player] += cards[player][2] * 1000;
            Total[player] += cards[player][1] * 100;
            Total[player] += cards[player][0] * 10;
            return true;
        }
    }
    else if (cards[player][1] == cards[player][2] && cards[player][2] == cards[player][3] && cards[player][3] == cards[player][4]) {
        Total[player] += cards[player][6];
        Total[player] += cards[player][4] * 10000;
        Total[player] += cards[player][3] * 1000;
        Total[player] += cards[player][2] * 100;
        Total[player] += cards[player][1] * 10;
        return true;
    }
    else if (cards[player][2] == cards[player][3] && cards[player][3] == cards[player][4] && cards[player][4] == cards[player][5]) {
        Total[player] += cards[player][6];
        Total[player] += cards[player][5] * 10000;
        Total[player] += cards[player][4] * 1000;
        Total[player] += cards[player][3] * 100;
        Total[player] += cards[player][2] * 10;
        return true;
    }
    else if (cards[player][3] == cards[player][4] && cards[player][4] == cards[player][5] && cards[player][5] == cards[player][6]) {
        Total[player] += cards[player][2];
        Total[player] += cards[player][6] * 10000;
        Total[player] += cards[player][5] * 1000;
        Total[player] += cards[player][4] * 100;
        Total[player] += cards[player][3] * 10;
        return true;
    }
    else {
        return false;
    }
}
//checks if a players hand is a full house and adds the proper hand score for that player
bool fullHouse(int cards[][7], int Total[5], int player) {
    //checks if full house, starting with two pair coming before three pair
    if (cards[player][0] == cards[player][1] && cards[player][2] == cards[player][3] && cards[player][3] == cards[player][4]) {
        if (cards[player][2] == 0) { //checks if full house has 3 aces
            Total[player] += cards[player][3];
            Total[player] += 13 * 10000;
            Total[player] += 13 * 1000;
            Total[player] += cards[player][5] * 100;
            Total[player] += cards[player][4] * 10;
            return true;
        }
        else {
            Total[player] += cards[player][0];
            Total[player] += cards[player][4] * 10000;
            Total[player] += cards[player][3] * 1000;
            Total[player] += cards[player][2] * 100;
            Total[player] += cards[player][1] * 10;
            return true;
        }
    }
    else if (cards[player][0] == cards[player][1] && cards[player][3] == cards[player][4] && cards[player][4] == cards[player][5]) {
        if (cards[player][2] == 0) { //checks if full house has 3 aces
            Total[player] += cards[player][3];
            Total[player] += 13 * 10000;
            Total[player] += 13 * 1000;
            Total[player] += cards[player][5] * 100;
            Total[player] += cards[player][4] * 10;
            return true;
        }
        else {
            Total[player] += cards[player][0];
            Total[player] += cards[player][5] * 10000;
            Total[player] += cards[player][4] * 1000;
            Total[player] += cards[player][3] * 100;
            Total[player] += cards[player][1] * 10;
            return true;
        }
    }
    else if (cards[player][0] == cards[player][1] && cards[player][4] == cards[player][5] && cards[player][5] == cards[player][6]) {
        if (cards[player][1] == 0) { //checks if full house has 2 aces
            Total[player] += cards[player][4];
            Total[player] += 13 * 10000;
            Total[player] += 13 * 1000;
            Total[player] += cards[player][6] * 100;
            Total[player] += cards[player][5] * 10;
            return true;
        }
        else {
            Total[player] += cards[player][0];
            Total[player] += cards[player][6] * 10000;
            Total[player] += cards[player][5] * 1000;
            Total[player] += cards[player][4] * 100;
            Total[player] += cards[player][1] * 10;
            return true;
        }
    }
    else if (cards[player][1] == cards[player][2] && cards[player][3] == cards[player][4] && cards[player][4] == cards[player][5]) {
        Total[player] += cards[player][1];
        Total[player] += cards[player][5] * 10000;
        Total[player] += cards[player][4] * 1000;
        Total[player] += cards[player][3] * 100;
        Total[player] += cards[player][2] * 10;
        return true;
    }
    else if (cards[player][1] == cards[player][2] && cards[player][4] == cards[player][5] && cards[player][5] == cards[player][6]) {
        Total[player] += cards[player][1];
        Total[player] += cards[player][6] * 10000;
        Total[player] += cards[player][5] * 1000;
        Total[player] += cards[player][4] * 100;
        Total[player] += cards[player][2] * 10;
        return true;
    }
    else if (cards[player][2] == cards[player][3] && cards[player][4] == cards[player][5] && cards[player][5] == cards[player][6]) {
        Total[player] += cards[player][2];
        Total[player] += cards[player][6] * 10000;
        Total[player] += cards[player][5] * 1000;
        Total[player] += cards[player][4] * 100;
        Total[player] += cards[player][3] * 10;
        return true;
    }
    //starts checks of three pair being before 2 pair
    else if (cards[player][0] == cards[player][1] && cards[player][1] == cards[player][2] && cards[player][3] == cards[player][4]) {
        if (cards[player][1] == 0) { //checks if full house has 3 aces
            Total[player] += cards[player][3];
            Total[player] += 13 * 10000;
            Total[player] += 13 * 1000;
            Total[player] += 13 * 100;
            Total[player] += cards[player][4] * 10;
            return true;
        }
        else {
            Total[player] += cards[player][0];
            Total[player] += cards[player][4] * 10000;
            Total[player] += cards[player][3] * 1000;
            Total[player] += cards[player][2] * 100;
            Total[player] += cards[player][1] * 10;
            return true;
        }
    }
    else if (cards[player][0] == cards[player][1] && cards[player][1] == cards[player][2] && cards[player][4] == cards[player][5]) {
        if (cards[player][1] == 0) { //checks if full house has 3 aces
            Total[player] += cards[player][4];
            Total[player] += 13 * 10000;
            Total[player] += 13 * 1000;
            Total[player] += 13 * 100;
            Total[player] += cards[player][5] * 10;
            return true;
        }
        else {
            Total[player] += cards[player][0];
            Total[player] += cards[player][5] * 10000;
            Total[player] += cards[player][4] * 1000;
            Total[player] += cards[player][2] * 100;
            Total[player] += cards[player][1] * 10;
            return true;
        }
    }
    else if (cards[player][0] == cards[player][1] && cards[player][1] == cards[player][2] && cards[player][5] == cards[player][6]) {
        if (cards[player][1] == 0) { //checks if full house has 3 aces
            Total[player] += cards[player][5];
            Total[player] += 13 * 10000;
            Total[player] += 13 * 1000;
            Total[player] += 13 * 100;
            Total[player] += cards[player][6] * 10;
            return true;
        }
        else {
            Total[player] += cards[player][0];
            Total[player] += cards[player][6] * 10000;
            Total[player] += cards[player][5] * 1000;
            Total[player] += cards[player][2] * 100;
            Total[player] += cards[player][1] * 10;
            return true;
        }
    }
    else if(cards[player][1] == cards[player][2] && cards[player][2] == cards[player][3] && cards[player][4] == cards[player][5]) {
        Total[player] += cards[player][1];
        Total[player] += cards[player][5] * 10000;
        Total[player] += cards[player][4] * 1000;
        Total[player] += cards[player][3] * 100;
        Total[player] += cards[player][2] * 10;
        return true;
    }
    else if (cards[player][1] == cards[player][2] && cards[player][2] == cards[player][3] && cards[player][5] == cards[player][6]) {
        Total[player] += cards[player][1];
        Total[player] += cards[player][6] * 10000;
        Total[player] += cards[player][5] * 1000;
        Total[player] += cards[player][3] * 100;
        Total[player] += cards[player][2] * 10;
        return true;
    }
    else if (cards[player][2] == cards[player][3] && cards[player][3] == cards[player][4] && cards[player][5] == cards[player][6]) {
        Total[player] += cards[player][2];
        Total[player] += cards[player][6] * 10000;
        Total[player] += cards[player][5] * 1000;
        Total[player] += cards[player][4] * 100;
        Total[player] += cards[player][3] * 10;
        return true;
    }
    else {
        return false;
    }
}
//checks if a players hand is a three of a kind and adds the proper hand score for that player
bool threeOfKind(int cards[][7], int Total[5], int player) {
    if (cards[player][0] == cards[player][1] && cards[player][1] == cards[player][2]) {
        if (cards[player][0] == 0) { //checks if aces are involved in 3 of a kind
            Total[player] += cards[player][5];
            Total[player] += 13 * 10000;
            Total[player] += 13 * 1000;
            Total[player] += 13 * 100;
            Total[player] += cards[player][6] * 10;
            return true;
        }
        else {
            Total[player] += cards[player][6];
            Total[player] += cards[player][2] * 10000;
            Total[player] += cards[player][1] * 1000;
            Total[player] += cards[player][0] * 100;
            Total[player] += cards[player][5] * 10;
            return true;
        }
    }
    else if (cards[player][1] == cards[player][2] && cards[player][2] == cards[player][3]) {
        Total[player] += cards[player][5];
        Total[player] += cards[player][3] * 10000;
        Total[player] += cards[player][2] * 1000;
        Total[player] += cards[player][1] * 100;
        Total[player] += cards[player][6] * 10;
        return true;
    }
    else if (cards[player][2] == cards[player][3] && cards[player][3] == cards[player][4]) {
        Total[player] += cards[player][5];
        Total[player] += cards[player][4] * 10000;
        Total[player] += cards[player][3] * 1000;
        Total[player] += cards[player][2] * 100;
        Total[player] += cards[player][6] * 10;
        return true;
    }
    else if (cards[player][3] == cards[player][4] && cards[player][4] == cards[player][5]) {
        Total[player] += cards[player][5];
        Total[player] += cards[player][5] * 10000;
        Total[player] += cards[player][4] * 1000;
        Total[player] += cards[player][3] * 100;
        Total[player] += cards[player][6] * 10;
        return true;
    }
    else if (cards[player][4] == cards[player][5] && cards[player][5] == cards[player][6]) {
        Total[player] += cards[player][2];
        Total[player] += cards[player][6] * 10000;
        Total[player] += cards[player][5] * 1000;
        Total[player] += cards[player][4] * 100;
        Total[player] += cards[player][3] * 10;
        return true;
    }
    else {
        return false;
    }
}
//checks if a players hand is a two pair and adds the proper hand score for that player
bool twoPair(int cards[][7], int Total[5], int player) {
    if (cards[player][0] == cards[player][1]) { //checks if first two cards are pair, then if true checks if there is another pair
        if (cards[player][2] == cards[player][3]) {
            if (cards[player][0] == 0) { //checks if aces are a pair
                Total[player] += cards[player][6];
                Total[player] += 13 * 10000;
                Total[player] += 13 * 1000;
                Total[player] += cards[player][3] * 100;
                Total[player] += cards[player][2] * 10;
                return true;
            }
            else {
                Total[player] += cards[player][6];
                Total[player] += cards[player][3] * 10000;
                Total[player] += cards[player][2] * 1000;
                Total[player] += cards[player][1] * 100;
                Total[player] += cards[player][0] * 10;
                return true;
            }
        }
        else if (cards[player][3] == cards[player][4]) {
            if (cards[player][0] == 0) { //checks if aces are a pair
                Total[player] += cards[player][6];
                Total[player] += 13 * 10000;
                Total[player] += 13 * 1000;
                Total[player] += cards[player][4] * 100;
                Total[player] += cards[player][3] * 10;
                return true;
            }
            else {
                Total[player] += cards[player][6];
                Total[player] += cards[player][4] * 10000;
                Total[player] += cards[player][3] * 1000;
                Total[player] += cards[player][1] * 100;
                Total[player] += cards[player][0] * 10;
                return true;
            }
        }
        else if (cards[player][4] == cards[player][5]) {
            if (cards[player][0] == 0) { //checks if aces are a pair
                Total[player] += cards[player][6];
                Total[player] += 13 * 10000;
                Total[player] += 13 * 1000;
                Total[player] += cards[player][5] * 100;
                Total[player] += cards[player][4] * 10;
                return true;
            }
            else {
                Total[player] += cards[player][6];
                Total[player] += cards[player][5] * 10000;
                Total[player] += cards[player][4] * 1000;
                Total[player] += cards[player][1] * 100;
                Total[player] += cards[player][0] * 10;
                return true;
            }
        }
        else if (cards[player][5] == cards[player][6]) {
            if (cards[player][0] == 0) { //checks if aces are a pair
                Total[player] += cards[player][4];
                Total[player] += 13 * 10000;
                Total[player] += 13 * 1000;
                Total[player] += cards[player][6] * 100;
                Total[player] += cards[player][5] * 10;
                return true;
            }
            else {
                Total[player] += cards[player][4];
                Total[player] += cards[player][6] * 10000;
                Total[player] += cards[player][5] * 1000;
                Total[player] += cards[player][1] * 100;
                Total[player] += cards[player][0] * 10;
                return true;
            }
        }
    }
    else if (cards[player][1] == cards[player][2]) { //checks if cards 1 and 2 are a pair then the subsequent cards for a second pair
        if (cards[player][3] == cards[player][4]) {
            Total[player] += cards[player][6];
            Total[player] += cards[player][4] * 10000;
            Total[player] += cards[player][3] * 1000;
            Total[player] += cards[player][2] * 100;
            Total[player] += cards[player][1] * 10;
            return true;
        }
        else if (cards[player][4] == cards[player][5]) {
            Total[player] += cards[player][6];
            Total[player] += cards[player][5] * 10000;
            Total[player] += cards[player][4] * 1000;
            Total[player] += cards[player][2] * 100;
            Total[player] += cards[player][1] * 10;
            return true;
        }
        else if (cards[player][5] == cards[player][6]) {
            Total[player] += cards[player][4];
            Total[player] += cards[player][6] * 10000;
            Total[player] += cards[player][5] * 1000;
            Total[player] += cards[player][2] * 100;
            Total[player] += cards[player][1] * 10;
            return true;
        }
    }
    else if (cards[player][2] == cards[player][3]) {
        if (cards[player][4] == cards[player][5]) {
            Total[player] += cards[player][6];
            Total[player] += cards[player][5] * 10000;
            Total[player] += cards[player][4] * 1000;
            Total[player] += cards[player][3] * 100;
            Total[player] += cards[player][2] * 10;
            return true;
        }
        else if (cards[player][5] == cards[player][6]) {
            Total[player] += cards[player][4];
            Total[player] += cards[player][6] * 10000;
            Total[player] += cards[player][5] * 1000;
            Total[player] += cards[player][3] * 100;
            Total[player] += cards[player][2] * 10;
            return true;
        }
    }
    else if (cards[player][3] == cards[player][4]) {
        if (cards[player][5] == cards[player][6]) {
            Total[player] += cards[player][2];
            Total[player] += cards[player][6] * 10000;
            Total[player] += cards[player][5] * 1000;
            Total[player] += cards[player][4] * 100;
            Total[player] += cards[player][3] * 10;
            return true;
        }
    }
    return false;
}
//checks if a players hand is a pair and adds the proper hand score for that player
bool isPair(int cards[][7], int Total[5], int player) {
    if (cards[player][0] == cards[player][1]) {
        //if the pair is a pair of aces then aces wins else calc as normal
        if (cards[player][0] == 0) {
            Total[player] += cards[player][4];
            Total[player] += 13 * 10000;
            Total[player] += 13 * 1000;
            Total[player] += cards[player][6] * 100;
            Total[player] += cards[player][5] * 10;
            return true;
        }
        else {
            Total[player] += cards[player][4];
            Total[player] += cards[player][1] * 10000;
            Total[player] += cards[player][0] * 1000;
            Total[player] += cards[player][6] * 100;
            Total[player] += cards[player][5] * 10;
            return true;
        }
    }
    else if (cards[player][1] == cards[player][2]) {
        Total[player] += cards[player][0];
        Total[player] += cards[player][2] * 10000;
        Total[player] += cards[player][1] * 1000;
        Total[player] += cards[player][4] * 100;
        Total[player] += cards[player][3] * 10;
        return true;
    }
    else if (cards[player][2] == cards[player][3]) {
        Total[player] += cards[player][0];
        Total[player] += cards[player][3] * 10000;
        Total[player] += cards[player][2] * 1000;
        Total[player] += cards[player][4] * 100;
        Total[player] += cards[player][1] * 10;
        return true;
    }
    else if (cards[player][3] == cards[player][4]) {
        Total[player] += cards[player][0];
        Total[player] += cards[player][4] * 10000;
        Total[player] += cards[player][3] * 1000;
        Total[player] += cards[player][2] * 100;
        Total[player] += cards[player][1] * 10;
        return true;
    }
    else if (cards[player][4] == cards[player][5]) {
        Total[player] += cards[player][2];
        Total[player] += cards[player][5] * 10000;
        Total[player] += cards[player][4] * 1000;
        Total[player] += cards[player][6] * 100;
        Total[player] += cards[player][3] * 10;
        return true;
    }
    else if (cards[player][5] == cards[player][6]) {
        Total[player] += cards[player][2];
        Total[player] += cards[player][6] * 10000;
        Total[player] += cards[player][5] * 1000;
        Total[player] += cards[player][4] * 100;
        Total[player] += cards[player][3] * 10;
        return true;
    }
    else {
        return false;
    }
}