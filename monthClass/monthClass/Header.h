#ifndef MONTH_H
#define MONTH_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
//Month Class

class Month {
private:
	string monthName;
	int monthNumber;

public:
	//default constructor
	Month() {
		monthName = "January";
		monthNumber = 1;
	}

	Month(string name) {
		monthName = name;
		setMonthNumber(monthName);
	}

	Month(int num) {
		if (monthNumber >= 1 && monthNumber <= 12) {
			monthNumber = num;
		}
		setMonthName(monthNumber);
	}

	string getMonthName() {
		return monthName;
	}

	int getMonthNumber() {
		return monthNumber;
	}

	void setMonthName(int num);
	void setMonthNumber(string name);

	//overloaded prefix and postfix ++ and -- functions
	   // Declare prefix and postfix increment operators
	Month& operator++();       // Prefix increment operator
	//Month operator++(int);     // Postfix increment operator

	// Declare prefix and postfix decrement operators.
	Month& operator--();       // Prefix decrement operator
	//Month operator--(int);     // Postfix decrement operator

	friend ostream& operator <<(ostream&, const Month&);
	friend istream& operator >> (istream&, Month&);
};



#endif
