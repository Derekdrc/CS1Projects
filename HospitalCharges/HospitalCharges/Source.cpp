//Derek D'Arcy
//I have neither given nor received unauthorized aid in completing this work, nor have I presented someone else’s work as my own.

#include <iostream>
using namespace std;
	
double totalCharges(double, double);
double totalCharges(double, double, double, double);

int main() {
	
	char patientType;
	char admitted;

	double daysSpent;
	double dailyRate;
	double medCharges;
	double serviceCharges;
	
	
	cout << "Was your patient admitted as an inpatient, outpatient, or into the ER? " << endl;
	cout << "Input '1' for inpatient, '2' for outpatient or '3' for ER: ";
	cin >> patientType;
	while (patientType != '1' && patientType != '2' && patientType != '3') {
		cout << "Please answer '1', '2' or '3'." << endl <<  "Was your patient admitted as an inpatient, outpatient, or ER? ";
		cin >> patientType;
	}

	if (patientType == '1') {
		//get inpatient data
		
		cout << "How many days were spent at the hospital? ";
		cin >> daysSpent;
		while (daysSpent <= 0) {
			cout << "Patient must have stayed at least one day as an inpatient" << endl << "How many days were spent at the hospital? ";
			cin >> daysSpent;
		}
		
		cout << "What is the daily rate of the Hospital? ";
		cin >> dailyRate;
		while (dailyRate <= 0) {
			cout << "Hospital must charge positive number for rate. " << endl << "What is the daily rate of the hospital? ";
			cin >> dailyRate;
		}

		cout << "How much medication charges did patient incur? ";
		cin >> medCharges;
		while (medCharges <= 0) {
			cout << "Patient can not incur a negative number for medication charges" << endl << "How much medication charges did patient incur? ";
			cin >> medCharges; 
		}

		cout << "How much service charges does patient owe? ";
		cin >> serviceCharges;
		while (serviceCharges <= 0) {
			cout << "Patient can not incur a negative number for service charges" << endl << "How much in service charges did patient incur? ";
			cin >> serviceCharges;
		}

		cout << "The patients total bill is: $ " << totalCharges(daysSpent, dailyRate, medCharges, serviceCharges) << endl;

	}
	if (patientType == '2') {
		//get outpatient data

		cout << "How much medication charges did patient incur? ";
		cin >> medCharges;
		while (medCharges <= 0) {
			cout << "Patient can not incur a negative number for medication charges" << endl << "How much medication charges did patient incur? ";
			cin >> medCharges;
		}

		cout << "How much service charges does patient owe? ";
		cin >> serviceCharges;
		while (serviceCharges <= 0) {
			cout << "Patient can not incur a negative number for service charges" << endl << "How much in service charges did patient incur? ";
			cin >> serviceCharges; 
		}

		cout << "The patients total bill is: $ " << totalCharges(medCharges, serviceCharges) << endl;

	}
	if (patientType == '3') {
		//get ER data 

		//Ask for med and service charges first for ER patient
		cout << "How much medication charges did patient incur? ";
		cin >> medCharges;
		while (medCharges <= 0) {
			cout << "Patient can not incur a negative number for medication charges" << endl << "How much medication charges did patient incur? ";
			cin >> medCharges;
		}

		cout << "How much service charges does patient owe? ";
		cin >> serviceCharges;
		while (serviceCharges <= 0) {
			cout << "Patient can not incur a negative number for service charges" << endl << "How much in service charges did patient incur? ";
			cin >> serviceCharges;
		}

		cout << "The patients total bill before being admitted as an inpatient is: $" << totalCharges(medCharges, serviceCharges) << endl;

		cout << "Was patient admitted to hospital after ER visit?" << endl << "Please answer with 'y' for yes and 'n' for no. ";
		cin >> admitted;
		while (admitted != 'y' && admitted != 'n') {
			cout << "Please answer with 'y' for yes and 'n' for no." << endl << "Was patient admitted to hospital after ER visit? ";
			cin >> admitted;
		}
		if (admitted == 'y') {
			//process patient as inpatient
			//If inpatient get daily rate and days spent and process
			cout << "How many days were spent at the hospital? ";
			cin >> daysSpent;
			while (daysSpent <= 0) {
				cout << "Patient must have stayed at least one day as an inpatient" << endl << "How many days were spent at the hospital? ";
				cin >> daysSpent;
			}

			cout << "What is the daily rate of the Hospital? ";
			cin >> dailyRate;
			while (dailyRate <= 0) {
				cout << "Hospital must charge positive number as daily rate. " << endl << "What is the daily rate of the hospital? ";
				cin >> dailyRate; 
			}

			cout << "The patients total bill is: $ " << totalCharges(daysSpent, dailyRate, medCharges, serviceCharges) << endl;

		}
		if (admitted == 'n') {
			//process patient as outpatient
			//if outpatient just used already gathered med and service charges
			cout << "The patients total bill is: $ " << totalCharges(medCharges, serviceCharges) << endl;

		}

	}

	system("pause");
	return 0;

}

//calculating inpatient charges 
double totalCharges(double daysSpent, double dailyRate, double medCharges, double serviceCharges) {
	//calculate and return all charges added up
	return ( (daysSpent * dailyRate) + medCharges + serviceCharges);
}

//calculating outpatient charges
double totalCharges(double serviceCharges, double medCharges) {
	//calculate and return all charges added up
	return (serviceCharges + medCharges);
}