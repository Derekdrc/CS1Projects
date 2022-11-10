//Derek D'Arcy
//I have neither given nor received unauthorized aid in completing this work, nor have I presented someone else’s work as my own
#include <iostream>
#include <iomanip>
using namespace std;

//prototype
int multi(int, int);

//main function handles the user input and calling of recursive function
int main() {
	int x, y;
	cout << "Enter 2 numbers to multiply" << endl;
	cout << "Please enter the first number to multiply: ";
	cin >> x;
	cout << "Please enter the second number to multiply: ";
	cin >> y;

	cout << x << " multiplied by " << y << " is: " << multi(x, y) << endl;
	
	system("pause");
	return 0;
}

//multi works by adding y x times, and calling itself recursively until it has added y x times
int multi(int x, int y) {
	if (x > 1) {
		x--;
		return y + multi(x, y);
	}
	else {
		return y;
	}
}