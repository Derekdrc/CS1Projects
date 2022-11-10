//Derek D'Arcy
//I have neither given nor received unauthorized aid in completing this work, nor have I presented someone else’s work as my own.

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	//declare variables here
	float mealCost = 88.67;
	const float tax = 0.0675;
	float taxAmount;
	const float tip = 0.2;
	float tipAmount;
	float totalBill;

	//perform calculations here
	taxAmount = mealCost * tax;
	tipAmount = (mealCost + taxAmount) * tip;
	totalBill = mealCost + taxAmount + tipAmount;

	//Display totals here rounded to two decimal points
	cout << "The initial cost of the meal was " << fixed << setprecision(2) << mealCost << endl;
	cout << "The Tax amount is " << fixed << setprecision(2) << taxAmount << endl;
	cout << "The tip amount is " << fixed << setprecision(2) << tipAmount << endl;
	cout << "The total bill is " << fixed << setprecision(2) << totalBill << endl;

	//end program
	system("pause");
	return 0;
}