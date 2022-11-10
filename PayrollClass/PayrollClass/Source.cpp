//Derek D'Arcy
//I have neither given nor received unauthorized aid in completing this work, nor have I presented someone else’s work as my own.

#include <iostream>
#include <iomanip>
using namespace std;

//Payroll Class
class PayRoll {
private:
	double hoursWorked;
	double payRate;
	
	void initializeValues() {
		hoursWorked = 0;
		payRate = 9.87;
		return;
	}

public:
	//constructor
	PayRoll() {
		initializeValues();
	}

	//mutator for hours
	void setHours(double d) {
		hoursWorked = d;
		return;
	}

	//mutator for pay rate
	void setPayRate(double r) {
		payRate = r;
		return;
	}

	//accesor for hours
	double getHours() const {
		return hoursWorked;
	}

	//accesor for pay rate
	double getPayRate() const {
		return payRate;
	}

	//accesor for total pay
	double getTotalPay() const {
		return hoursWorked * payRate;
	}
};

/*the Main function is where the array of PayRoll
* objects is first created and populated, 
* and also handles input validation as well
* as looping through to get all employees total pay 
*/
int main() {
	double hours;
	double rate;
	const int employeeNum = 7;
	//array of employee payroll objects
	PayRoll employees[employeeNum];
	
	//loop through each employee top get info
	for (int i = 0; i < employeeNum; i++) {
		//get employee hours for each iteration
		cout << "Enter the hours worked for employee number " << i + 1 << ": ";
		cin >> hours;
		//verify hours worked is under 60
		while (hours > 60) {
			cout << "This is too many hours for employee number " << i + 1 << "." << endl;
			cout << "Please enter an acceptable number of hours for employee number " << i+1 << ": ";
			cin >> hours;
		}
		cout << endl;
		employees[i].setHours(hours);
	}
	//loop through each employee to display total
	//the final output should be lined up with the following information(employee number, hours worked, hourly wage, and their gross pay).
	for (int i = 0; i < employeeNum; i++) {
		cout << "Employee # " << i + 1;
		cout << ": Hours worked: " << employees[i].getHours();
		cout << ", Hourly wage: " << employees[i].getPayRate();
		cout << ", and the gross pay: $" << fixed << setprecision(2) <<  employees[i].getTotalPay() << endl;
	}

	system("pause");
	return 0;
}