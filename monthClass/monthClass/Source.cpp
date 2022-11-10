//Derek D'Arcy
//I have neither given nor received unauthorized aid in completing this work, nor have I presented someone else’s work as my own.

#include <iostream>
#include <iomanip>
#include "Header.h"
#include "Header.cpp"
using namespace std;

ostream& operator<<(ostream& str, const Month& obj) {
	str << " Month Details: \nName: "
		<< obj.monthName << "\nNumber: " << obj.monthNumber << endl;
	return str;
}

istream& operator >> (istream& str, Month& obj)  //cin operator overload
{
	cout << "Enter month number: ";
	str >> obj.monthNumber;
	cout << "Enter month name: ";
	str >> obj.monthName;
	return str;
}


int main() {
	Month m1;
	Month m2, m3, m4;
	cout << m1.getMonthName() << endl;
	cout << m1.getMonthNumber() << endl;
	cout << endl;
	cout << m1;
	cout << endl;
	m2 = ++m1;
	cout << m1;
	cout << m2;
	cout << endl;
	m3 = ++m1;
	cout << m1;
	cout << m3;
	cout << endl;
	cout << "Enter the name of a month: ";
	cin >> m4;
	cout << m4;

	system("pause");
	return 0;
}
