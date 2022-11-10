//Derek D'Arcy
//I have neither given nor received unauthorized aid in completing this work, nor have I presented someone else’s work as my own.

#include <iostream>
#include <string>
using namespace std;

int sum(char array[]);
char high(char array[]);
char low(char array[]);

int main() {
	const int SIZE = 100;
	char digits[SIZE];

	cout << "Please enter a string of single digit numbers with nothing seperating them. ";
	cin.getline(digits, SIZE);
	int total = sum(digits);
	char max = high(digits); 
	char min = low(digits); 

	cout << "The sum of the digits is " << total << "." << endl;
	cout << "The highest number is " << max << "." << endl;
	cout << "The lowest number is " << min << "." << endl;

	system("pause");
	return 0;

}

int sum(char array[]) {
	int count = 0;
	int length = strlen(array);

	for (int i = 0; i < length; i++) {
		count = count + (array[i] - '0');
	}

	return count;

}

char high(char array[]) { 
	int length = strlen(array);
	char highest = array[0];

	for (int i = 0; i < length; i++) {
		if (array[i] > highest) {
			highest = array[i];
		}
	}

	return highest;

}

char low(char array[]) {
	int length = strlen(array);
	char lowest = array[0];

	for (int i = 0; i < length; i++) {
		if (array[i] < lowest) {
			lowest = array[i];
		}
	}

	return lowest;

}
