#include<iostream>
#include <string>
#include "Header.h"
using namespace std;

void Month::setMonthName(int num) {
	switch (num) {
	case 1:
		monthName = "January";
	case 2:
		monthName = "February";
	case 3:
		monthName = "March";
	case 4:
		monthName = "April";
	case 5:
		monthName = "May";
	case 6:
		monthName = "June";
	case 7:
		monthName = "July";
	case 8:
		monthName = "August";
	case 9:
		monthName = "September";
	case 10:
		monthName = "October";
	case 11:
		monthName = "November";
	case 12:
		monthName = "December";
	}
	return;
}

void Month::setMonthNumber(string name) {
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
	
	return;
}

Month& Month::operator++()
{
	monthNumber++;
	if (monthNumber == 13)
	{
		monthNumber = 1;
		monthName = "January";
	}
	setMonthName(monthNumber);
	return *this;
}



Month& Month::operator--()
{
	monthNumber--;
	if (monthNumber == 0)
	{
		monthNumber = 12;
		monthName = "December";

	}
	setMonthName(monthNumber);
	return *this;
}


