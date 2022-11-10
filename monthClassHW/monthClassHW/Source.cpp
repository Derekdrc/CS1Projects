//Derek D'Arcy
//I have neither given nor received unauthorized aid in completing this work, nor have I presented someone else’s work as my own.
#include <iostream>
#include <iomanip>
using namespace std;

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
	//constructors 
	Month(string name) {
		monthName = name;
		setMonthNumber(name);
	}

	Month(int num) {
		setMonthName(num);
		monthNumber = num;
	}

	Month(string name, int num) {
		monthName = name;
		monthNumber = num;
	}

	//sets the monthName based on the given month number
	void setMonthName(int num) {
		if (num == 1)
			monthName = "January";
		else if (num == 2)
			monthName = "February";
		else if (num == 3)
			monthName = "March";
		else if (num == 4)
			monthName = "April";
		else if (num == 5)
			monthName = "May";
		else if (num == 6)
			monthName = "June";
		else if (num == 7)
			monthName = "July";
		else if (num == 8)
			monthName = "August";
		else if (num == 9)
			monthName = "September";
		else if (num == 10)
			monthName = "October";
		else if (num == 11)
			monthName = "November";
		else if (num == 12)
			monthName = "December";

	}
	//sets the monthNumber based on the given month name
	void setMonthNumber(string name) {
		if (name == "January")
			monthNumber = 1;
		else if (name == "February")
			monthNumber = 2;
		else if (name == "March")
			monthNumber = 3;
		else if (name == "April")
			monthNumber = 4;
		else if (name == "May")
			monthNumber = 5;
		else if (name == "June")
			monthNumber = 6;
		else if (name == "July")
			monthNumber = 7;
		else if (name == "August")
			monthNumber = 8;
		else if (name == "September")
			monthNumber = 9;
		else if (name == "October")
			monthNumber = 10;
		else if (name == "November")
			monthNumber = 11;
		else if (name == "December")
			monthNumber = 12;
	}

	//gets and returns name of month
	string getMonthName() {
		return monthName;
	}

	//gets and returns month number
	int getMonthNumber() {
		return monthNumber;
	}

	// Overloading the prefix ++ operator
	Month operator++() {
		Month temp;
		temp.monthNumber = ++monthNumber;
		if (temp.monthNumber == 13) {
			temp.monthNumber = 1;
		}
		temp.setMonthName(temp.monthNumber);
		return temp;
	}

	// Overloading the postfix ++ operator
	Month operator++(int) {
		Month temp;
		temp.monthNumber = monthNumber++;
		if (temp.monthNumber == 13) {
			temp.monthNumber = 1;
		}
		temp.setMonthName(temp.monthNumber);
		return temp;
	}

	// Overloading the prefix -- operator
	Month operator--() {
		Month temp;
		temp.monthNumber = --monthNumber;
		if (temp.monthNumber == 0) {
			temp.monthNumber = 12;
		}
		temp.setMonthName(temp.monthNumber);
		return temp;
	}

	// Overloading the postfix -- operator
	Month operator--(int) {
		Month temp;
		temp.monthNumber = monthNumber--;
		if (temp.monthNumber == 0) {
			temp.monthNumber = 12;
		}
		temp.setMonthName(temp.monthNumber);
		return temp;
	}

	//overloading <<>> operators 
	friend ostream& operator << (ostream& out, const Month& m);
	friend istream& operator >> (istream& in, Month& m);

};

//overloading the cout operator to print out a month object
ostream& operator << (ostream& out, const Month& m)
{
	out << m.monthName;
	out << " is month " << m.monthNumber << endl;
	return out;
}

//overloading the cin operator to take in a month object
istream& operator >> (istream& in, Month& m)
{
	cout << "Enter month name: ";
	in >> m.monthName;
	cout << "Enter number of month: ";
	in >> m.monthNumber;
	return in;
}

//main function utilizes the month class to perform various functions 
int main() {
	Month m1;
	cout << "m1 is: " << m1;
	cout << "m1 getters: " << m1.getMonthName() << " " << m1.getMonthNumber() << endl;
	Month m2 = ++m1;
	cout << "m2 is m1 pre incremented: " << m2;
	Month m3 = m1++;
	cout << "m3 is m1 post incremented: " << m3;
	cout << "m3 getters: " << m3.getMonthName() << " " << m3.getMonthNumber() << endl;
	Month m4(4);
	cout <<"m4 is a new month set by number to the 4th month" << m4;
	Month m5 = --m4;
	cout << "m5 is m4 pre decremented " << m5;
	Month m6 = m4--;
	cout <<"m6 is m4 post decremented " << m6;
	Month m7("October");
	cout << "m7 is a new month set by name to october: " << m7;
	Month m8;
	cin >> m8;
	cout << "m8 is a new month set by overloading the cin operator for user input: " << m8;
	system("pause");
	return 0;

}