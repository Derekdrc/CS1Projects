//Derek D'Arcy
//I have neither given nor received unauthorized aid in completing this work, nor have I presented someone else’s work as my own.

#include <iostream>
using namespace std;

int main() {
	//declare variables here

	//constants for minimum rooms and floors
	const int minFloors = 1,
			  minRooms = 10;

	float hotelFloors = 0,
		  hotelRooms = 0,
		  totalRooms = 0,
	  	  roomsFilled = 0,
		  occupied = 0,
		  unoccupied = 0; 

	cout << "How many floors are in the hotel? ";
	cin >> hotelFloors;

	while (hotelFloors <= minFloors) {
		cout << "Your hotel should have at least 1 floor." << endl;
		cout << "How many floors are in the hotel? ";
		cin >> hotelFloors;
	}
	//loop through every floor
	for (int i = 1; i <= hotelFloors; i++) {
		if (i == 13) {
			hotelFloors++; 
			continue;
		}
		cout << "How many rooms are on floor " << i << "? ";
		cin >> hotelRooms;
		while (hotelRooms < minRooms) {
			cout << "Your hotel needs to have at least " << minRooms << " per floor" << endl;
			cout << "How many rooms are on floor " << i << "? ";
			cin >> hotelRooms;
		}
		totalRooms += hotelRooms;
		cout << "How many of those rooms are filled? ";
		cin >> roomsFilled;
		while (roomsFilled < 0  || roomsFilled > hotelRooms) { 
			cout << "Your number of rooms filled must be between 0 and " << hotelRooms << ". " << endl;
			cout << "How many of those rooms are filled? ";
			cin >> roomsFilled;
		}
		occupied += roomsFilled; 
		unoccupied += (hotelRooms - roomsFilled);
	}

	//perform calculations here
	cout << "The hotel has " << hotelFloors << " floors, " << totalRooms << " rooms, " << occupied << " occupied rooms, and " << unoccupied << " unoccupied rooms." << endl;
	cout << "The percentage of occupied rooms is ";
	printf("%.2f", (occupied / totalRooms) * 100);
	cout << "%. " << endl;

	system("pause");
	return 0;
}
	