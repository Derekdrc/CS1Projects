//Derek D'Arcy
//I have neither given nor received unauthorized aid in completing this work, nor have I presented someone else’s work as my own.
#include <iostream>
#include <iomanip>
using namespace std;

//Original ship class
class Ship {
private:
	string shipName;
	int shipYear;

public:
	//default constructor
	Ship() {
		shipName = "Ship";
		shipYear = 2022;
	}

	//constructor with both name and year
	Ship(string name, int year) {
		shipName = name;
		shipYear = year;
	}
	//constructor with name
	Ship(string name) {
		shipName = name;
	}
	//constructor with year
	Ship(int year) {
		shipYear = year;
	}

	//get shipname method
	string getShipName() {
		return shipName;
	}

	//get year method
	int getYear() {
		return shipYear;
	}

	//set name method
	void setShipName(string name) {
		shipName = name;
		return;
	}

	//set year method
	void setYear(int year) {
		shipYear = year;
		return;
	}

	//print method
	virtual void printShip() {
		cout << "Ship name is: " << getShipName() << endl;
		cout << "Year ship was built: " << getYear() << endl << endl; 
	}

};

//class for cruise ships that extends Ship class
class CruiseShip : public Ship {
private:
	int maxPassengers;

public:
	//default constructor
	CruiseShip() {
		maxPassengers = 0;
	}

	//parameter constructor
	CruiseShip(string name, int year, int max): Ship (name, year) {
		maxPassengers = max;
	}

	//gettor
	int getMaxPassengers() {
		return maxPassengers;
	}

	//setter
	void setMaxPassengers(int max) {
		maxPassengers = max;
		return;
	}

	//print function overiding base
	virtual void printShip() {
		cout << "Ship name is: " << getShipName() << endl;
		cout << "Maximum number of passengers: " << getMaxPassengers() << endl << endl;
		return;
	}

};

//class for cargo ship that extends ship class
class CargoShip : public Ship {
private:
	int cargoCapacity;

public:
	//default constructor
	CargoShip() {
		cargoCapacity = 0;
	}

	//parameter constructor
	CargoShip(string name, int year, int capacity) : Ship(name, year) {
		cargoCapacity = capacity;
	}

	//getter
	int getMaxCapacity() {
		return cargoCapacity;
	}

	//setter
	void setMaxCapacity(int capacity) {
		cargoCapacity = capacity;
		return;
	}

	//print function overiding base
	virtual void printShip() {
		cout << "Ship name is: " << getShipName() << endl;
		cout << "Maximum capacity of ship: " << getMaxCapacity() << endl;
		return;
	}

};

//main function to demonstrate ship classes using arrays of Ship pointers
int main() {
	const int numShips = 3;
	//pointer array of ships
	Ship* ships[numShips] =
	{ new Ship("SwanShip", 2021),
		new CruiseShip("Cruiser", 2020, 1000),
		new CargoShip("Hauler", 2011, 250000)
	};

	for (int i = 0; i < numShips; i++) {
		ships[i]->printShip();
	}

	system("pause");
	return 0;
}