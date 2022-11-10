//Derek D'Arcy
//I have neither given nor received unauthorized aid in completing this work, nor have I presented someone else’s work as my own.

#include <iostream>
#include <string>
using namespace std;

int main() {
	//declare variables here
	string userInput;

	//Start program here
	cout << "Reboot the computer and try to connect." << endl;
	cout << "Did that fix the problem? (Please answer 'yes' or 'no') ";
	getline(cin, userInput);
	if (userInput == "yes") {
		//end program
		cout << "Problem solved, troubleshooting over!" << endl;
		system("pause");
		return 0;
	}
	else if(userInput == "no"){
		cout << "Reboot the router and try to connect." << endl;
		cout << "Did that fix the problem? (Please answer 'yes' or 'no') ";
	}
	else {
		cout << "Invalid input, please try again." << endl;
		cout << "Reboot the computer and try to connect." << endl;
		cout << "Did that fix the problem? (Please answer 'yes' or 'no') ";
		getline(cin, userInput);
		if (userInput == "yes") {
				//end program
				cout << "Problem solved, troubleshooting over!" << endl;
				system("pause");
				return 0;
		}
		else if(userInput == "no") {
			cout << "Reboot the router and try to connect." << endl;
			cout << "Did that fix the problem? (Please answer 'yes' or 'no') ";
		}
		else {
			cout << "Invalid input." << endl;
			cout << "Troubleshooting over" << endl;
			system("pause");
			return 0;
		}
	}
	
	getline(cin, userInput);
	if (userInput == "yes") {
		cout << "Problem solved, troubleshooting over!" << endl;
		system("pause");
		return 0;
	}
	else if(userInput == "no") {
		cout << "Make sure the cables between the router and modem are plugged in firmly." << endl;
		cout << "Did that fix the problem? (Please answer 'yes' or 'no') ";
	}
	else {
		cout << "Invalid input, please try again." << endl;
		cout << "Reboot the router and try to connect." << endl;
		cout << "Did that fix the problem? (Please answer 'yes' or 'no') ";
		getline(cin, userInput);
		if (userInput == "yes") {
			//end program
			cout << "Problem solved, troubleshooting over!" << endl;
			system("pause");
			return 0;
		}
		else if (userInput == "no") {
			cout << "Make sure the cables between the router and modem are plugged in firmly." << endl;
			cout << "Did that fix the problem? (Please answer 'yes' or 'no') ";
		}
		else {
			cout << "Invalid input." << endl;
			cout << "Troubleshooting over" << endl;
			system("pause");
			return 0;
		}
	}

	getline(cin, userInput);
	if (userInput == "yes") {
		cout << "Problem solved, troubleshooting over!" << endl;
		system("pause");
		return 0;
	}
	else if(userInput == "no") {
		cout << "Move the router to a new location." << endl;
		cout << "Did that fix the problem? (Please answer 'yes' or 'no') ";
	}
	else {
		cout << "Invalid input, please try again." << endl;
		cout << "Make sure the cables between the router and modem are plugged in firmly." << endl;
		cout << "Did that fix the problem? (Please answer 'yes' or 'no') ";
		getline(cin, userInput);
		if (userInput == "yes") {
			//end program
			cout << "Problem solved, troubleshooting over!" << endl;
			system("pause");
			return 0;
		}
		else if (userInput == "no") {
			cout << "Move the router to a new location." << endl;
			cout << "Did that fix the problem? (Please answer 'yes' or 'no') ";
		}
		else {
			cout << "Invalid input." << endl;
			cout << "Troubleshooting over" << endl;
			system("pause");
			return 0;
		}
	}

	getline(cin, userInput);
	if (userInput == "yes") {
		cout << "Problem solved, troubleshooting over!" << endl;
		system("pause");
		return 0;
	}
	else if(userInput == "no") {
		cout << "Get a new router." << endl;
		system("pause");
		return 0;
	}
	else {
		cout << "Invalid input, please try again." << endl;
		cout << "Move the router to a new location" << endl;
		cout << "Did that fix the problem? (Please answer 'yes' or 'no') " << endl;
		getline(cin, userInput);
		if (userInput == "yes") {
			cout << "Problem solved, troubleshooting over!" << endl;
			system("pause");
			return 0;
		}
		else if(userInput == "no") {
			cout << "Get a new router." << endl;
			system("pause");
			return 0;
		}
		else {
			cout << "Invalid input." << endl;
			cout << "Troubleshooting over" << endl;
			system("pause");
			return 0;
		}
	}

}