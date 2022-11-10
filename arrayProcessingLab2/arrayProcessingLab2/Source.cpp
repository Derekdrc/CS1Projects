//Derek D'Arcy
//I have neither given nor received unauthorized aid in completing this work, nor have I presented someone else’s work as my own.

//This program reads data from a file into an array.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int process_employee(string[], float[], int[], ifstream&);
int maxWage(const float[], int);
int minWage(const float[], int);
float avrgWage(const float[], int);
void process_payroll(string, int, float, ofstream&);
void print_summary(int, string, float, string, float, float, ofstream&); 


/*main handles the calling of all other functions
properly*/
int main()
{
	const int SIZE = 15;
	string Name[SIZE];
	float Wage[SIZE];
	int Hours[SIZE];
	float Gross[SIZE];
	char Bonus[SIZE];
	float AdjGross[SIZE]; 

	int count = 0, high = 0, low = 0;
	float avrg = 0;
	
	ifstream Input;
	Input.open("C:/Users/derek/source/repos/CS1/arrayProcessingLab2/lab2Input.txt");
	ofstream Output;
	Output.open("C:/Users/derek/source/repos/CS1/arrayProcessingLab2/lab2Output.txt");

	if (Input.fail())
	{
		cout << "Input file failed to open\n" << endl;
		system("pause");
		exit(0);
	}
	count = process_employee(Name, Wage, Hours, Input);
	if (count > 10) 
	{
		cout << "Error: More than 10 names are being processed." << endl;
	}

	high = maxWage(Wage, count);
	low = minWage(Wage, count);
	avrg = avrgWage(Wage, count);

	print_summary(count, Name[high], Wage[high], Name[low], Wage[low], avrg, Output);

	//loops through each employee file and process payroll for each indexed employee
	for (int i = 0; i < count; i++) 
	{
		process_payroll(Name[i], Hours[i], Wage[i], Output);
	}
		
	Input.close();
	Output.close();

	system("pause");
	return 0;
}

/*process_payroll takes in the currrent name hours
and wage and performs the calculations for gross
adj gross and bonus then outputs*/
void process_payroll(string name, int hours, float wage, ofstream& out) 
{
	const float PENALTY = 0.25;
	const int BONUS = 50;
	float gross = 0;
	char bonus = ' ';
	float adjGross = 0;
	

	if (hours > 45) 
	{
		gross = (wage*hours);
		bonus = 'Y';
		adjGross = gross + BONUS; 
	}
	else if(hours < 30)
	{
		gross = (wage * hours);
		bonus = 'N';
		adjGross = (wage - PENALTY) * hours;
	}
	else
	{
		gross = (wage * hours);
		bonus = 'N';
		adjGross = gross;
	}

	out << left << setw(10) << name;
	out << right << setw(10) << hours;
	out << right << setw(10) << wage;
	out << right << setw(10) << gross;
	out << right << setw(10) << bonus;
	out << right << setw(20) << adjGross << "\n";


	return;
}

/*Counts the number of employees
on the input file and returns number as well
as populating the arrays*/
int process_employee(string Name[], float Wage[], int Hours[], ifstream& Input)
{
	int count = 0;
	while (Input >> Name[count] >> Wage[count] >> Hours[count] && count < 15)
		count++;
	return count;
}

/*finds the maximum wage 
of the emplyees in input file
and returns index of highest employee*/
int maxWage(const float Rate[], int count)
{
	int i, high, highest = -999999;
	for (i = 0; i < count; i++)
	{
		if (Rate[i] > highest)
		{
			high = i;
			highest = Rate[i];
		}
	}
	return high;
}

/*finds the minimum wage
of the emplyees in input file
and returns index of lowest employee*/
int minWage(const float Rate[], int count)
{
	int i, low, lowest = 999999;
	for (i = 0; i < count; i++)
	{
		if (Rate[i] < lowest)
		{
			low = i;
			lowest = Rate[i];
		}
	}
	return low;
}

/*finds the average wage
of the emplyees in input file
and returns average*/
float avrgWage(const float Rate[], int count)
{
	float totalRate = 0;
	float avgWage = 0; 
	for (int i = 0; i < count; i++)
	{
		totalRate += Rate[i];
	}
	avgWage = (totalRate / count);
	return avgWage;
}

/*print_summary takes in all data from top half of output
file, and formats and outputs correctly the payroll sheet*/
void print_summary(int numEmpl, string maxRateName, float maxRate, string minRateName, float minRate, float avrg, ofstream& out) 
{
	const string date = "February 2022";

	if (numEmpl > 10)
	{
		out << "Error: There are more than 10 employees" << "\n";
	}

	out << "Number of Employees: " << numEmpl << "\n" << "\n";
	out << "Maximum Payrate: " << maxRateName << " @ " << fixed << setprecision(2) << maxRate << "\n" << "\n";
	out << "Minimum Payrate: " << minRateName << " @ " << fixed << setprecision(2) << minRate << "\n" << "\n";
	out << "Average Pay: $" << fixed << setprecision(2) << avrg << "\n" << "\n";
	out << date << " Payroll" << "\n" << "\n";

	//Prints the labels for each column
	out << left << setw(10) << "Name";
	out << right << setw(10) << "Hours";
	out << right << setw(10) << "Rate";
	out << right << setw(10) << "Gross";
	out << right << setw(10) << "Bonus";
	out << right << setw(20) << "Adjusted Gross" << "\n" << "\n";

	return;
}