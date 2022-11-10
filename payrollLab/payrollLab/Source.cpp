//Derek D'Arcy
//I have neither given nor received unauthorized aid in completing this work, nor have I presented someone else’s work as my own.

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int Process_Payroll(bool&, int&, float&, int&, float&, float&, float&, float&, float&, ifstream&, ofstream&);
int Process_Employee(int&, float&, int&, ifstream&);
void Print_Summary(float, float, float, float, float, ofstream&); 


/*Main creats the files to be read and written to, 
as well as prints headers to file and calls the other functions*/
int main()
{

	int Id, hour;
	float rate;
	bool finished = false;
	
	float totalGrossPay = 0; 
	float totalNetPay = 0; 
	float totalFederalTax = 0; 
	float totalStateTax = 0;
	float totalSocSecurity = 0;

	ifstream Input; 
	Input.open("C:/Users/derek/source/repos/CS1/payrollLab/lab1Input.txt");

	ofstream Output;
	Output.open("C:/Users/derek/source/repos/CS1/payrollLab/lab1Output.txt");


	if (Input.fail())
	{
		cout << "Input file failed to open\n";
		system("pause");
		exit(1);
	}

	if (Output.fail())
	{
		cout << "Output file failed to be created\n";
		system("pause");
		exit(1);
	}
	
	

	//Print out headers and title to file
	Output << "Employee Payroll" << "\n" << "\n";
	Output << right << setw(15) << "Employee";
	Output << right << setw(15) << "Hours";
	Output << right << setw(15) << "Rate";
	Output << right << setw(15) << "Gross";
	Output << right << setw(15) << "Net";
	Output << right << setw(15) << "Fed";
	Output << right << setw(15) << "State";
	Output << right << setw(15) << "Soc Sec" << "\n" << "\n";

	while (!finished)
	{
		Process_Payroll(finished, Id, rate, hour, totalGrossPay, totalNetPay, totalFederalTax, totalStateTax, totalSocSecurity, Input, Output);
	}
	
	// call print summary to print the totals.
	Print_Summary(totalGrossPay, totalNetPay, totalFederalTax, totalStateTax, totalSocSecurity, Output);


	Input.close();
	Output.close();

	system("pause");
	return 0;
}

/*Process Employee is checking to make sure there 
is more employee information to read, and when 
the file has ended returns 0 to end the loop in main*/
int Process_Employee(int& id, float& wage, int& hours, ifstream& in) 
{
	//Reads the individual employee payroll information
	//Returns the value read using parameters
	//Function  returns  (one  1)  if  employee  information  is  read  successfully  or  (zero  0)  if employee information is not read successfully.

	if (in >> id >> wage >> hours) 
	{
		return 1;
	}
	else 
	{
		return 0;
	}

	

}

/*Process Payroll handles the calculations
of the employees payroll and taxes, as well as 
updates the totals for the summary*/
int Process_Payroll(bool& finished, int& id, float& rate, int& hours, float&totalGrossPay, float& totalNetPay, float& totalFederalTax, float& totalStateTax, float& totalSocSecurity, ifstream& in, ofstream& out) 
{
		//Print “Employee Payroll” header message
		//Print the headings for the columns (Employee, Hours, Rate, etc.)
		//Call process_employee() [from inside a loop] until 0 is returned
		//For each employee calculate and record: Gross pay, net pay, fed tax, state tax, soc security, Update the variables required to print summary, Print out one line for each employee as shown
		//returns 1 until there are no more employee files to read, then returns 0 and sets finished to false

		const float fedTaxRate = 0.16;
		const float stateTaxRate = 0.0542;
		const float socSecTaxRate = 0.07;

		float employeeGrossPay = 0;
		float employeeNetPay = 0;
		float employeeFederalTax = 0;
		float employeeStateTax = 0;
		float employeeSocSecurity = 0;

		while (Process_Employee(id, rate, hours, in)) 
		{
			// calculate gross pay
			if (hours <= 35)
			{
				employeeGrossPay = ((rate + 0.15) * hours);
			}
			else if (hours > 40)
			{
				int hoursOver = hours - 40;
				employeeGrossPay = ((rate * 1.5) * hoursOver) + ((rate) * 40);
			}
			else
			{
				employeeGrossPay = (rate * hours);
			}

			// calculate all taxes
			employeeFederalTax = employeeGrossPay * fedTaxRate;
			employeeStateTax = employeeGrossPay * stateTaxRate;
			employeeSocSecurity = employeeGrossPay * socSecTaxRate;
			// calculate net pay
			employeeNetPay = employeeGrossPay - (employeeFederalTax + employeeStateTax + employeeSocSecurity);
			// print employee information
			cout << id << "\t" << hours << "\t" << rate << "\t" << employeeGrossPay << "\t" << employeeNetPay << "\t" << employeeFederalTax << "\t" << employeeStateTax << "\t" << employeeSocSecurity << endl;
			//Print to file justified employee table
			out << right << setw(15) << id;
			if (hours <= 35)
			{
				out << right << setw(14) << hours << "*";
			}
			else if (hours > 40)
			{
				out << right << setw(14) << hours << "$";
			}
			else
			{
				out << right << setw(15) << hours;
			}

			out << right << setw(15) << rate;
			out << right << setw(15) << fixed << setprecision(2) << employeeGrossPay;
			out << right << setw(15) << fixed << setprecision(2) << employeeNetPay;
			out << right << setw(15) << fixed << setprecision(2) << employeeFederalTax;
			out << right << setw(15) << fixed << setprecision(2) << employeeStateTax;
			out << right << setw(15) << fixed << setprecision(2) << employeeSocSecurity << "\n" << "\n";
			// update totals for gross, net, and all taxes.
			totalGrossPay += employeeGrossPay;
			totalNetPay += employeeNetPay;
			totalFederalTax += employeeFederalTax;
			totalStateTax += employeeStateTax;
			totalSocSecurity += employeeSocSecurity;
			
			
			return 1;
		}
		
		finished = true;
		return 0;

		
}

/*Print summary prints out the Summary at the bottom of the output
file, as well as the columns and the accumalted totals for
each employee, and formats them correctly*/
void Print_Summary(float totalGross, float totalNet, float totalFed, float totalState, float totalSoc, ofstream& out) 
{
	//Print out the “Summary ...” message line
	//Prints out the column headings(Gross Pay, Net Pay, etc.)
	//Prints out the totals which have been accumulated (running total kept)
	out << "SUMMARY - TOTALS FOR ALL EMPLOYEES" << "\n";
	out << "----------------------------------" << "\n";
	
	//Prints the labels for each column
	out << right << setw(15) << "Gross Pay";
	out << right << setw(15) << "Net Pay";
	out << right << setw(15) << "Federal Tax";
	out << right << setw(15) << "State Tax";
	out << right << setw(15) << "Soc Security" << "\n";
	
	//Prints the correct totals for all employees in correct format
	out << right << setw(15) << fixed << setprecision(2) << totalGross;
	out << right << setw(15) << fixed << setprecision(2) << totalNet;
	out << right << setw(15) << fixed << setprecision(2) << totalFed;
	out << right << setw(15) << fixed << setprecision(2) << totalState;
	out << right << setw(15) << fixed << setprecision(2) << totalSoc << "\n";

	return;
}