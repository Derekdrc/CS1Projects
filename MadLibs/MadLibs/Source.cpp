//Derek D'Arcy
//I have neither given nor received unauthorized aid in completing this work, nor have I presented someone else’s work as my own.

#include <iostream>
#include <string>
using namespace std;

int main() {
	//declare variables here
	string name;
	int age;
	string city;
	string college;
	string profession;
	string animalType;
	string petName;

	//get user input here
	cout << "Enter your name: ";
	getline(cin, name);

	cout << "Enter your age: ";
	cin >> age;
	cin.ignore();

	cout << "Enter a city: ";
	getline(cin, city);

	cout << "Enter a college: ";
	getline(cin, college);

	cout << "Enter a profession: ";
	getline(cin, profession);

	cout << "Enter a type of animal: ";
	getline(cin, animalType);

	cout << "Enter a pet's name: ";
	getline(cin, petName);

	//Print out MadLib with user input
	cout << "There once was a person named " << name << " who lived in " << city << ". " << endl;
	cout << "At the age of " << age << ", " << name << " went to college at "<< college << ". " << endl;
	cout << name << " graduated and went to work as a "<< profession << ". " << endl;
	cout << "Then, "<< name << " adopted a " << animalType << " named "<< petName << ". " << endl;
	cout << "They both lived happily ever after!" << endl;

	//end program
	system("pause");
	return 0;

}