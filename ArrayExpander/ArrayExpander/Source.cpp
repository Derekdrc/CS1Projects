//Derek D'Arcy
//I have neither given nor received unauthorized aid in completing this work, nor have I presented someone else’s work as my own.

#include <iostream>
using namespace std;

int* doubleSize(int [], const int);
void showArray(int *, const int);

int main() {
	const int SIZE = 3;

	int nums[SIZE] = { 1, 2, 3 };

	int *nums_doubled = doubleSize(nums, SIZE); 

	showArray(nums, SIZE);
	cout << endl;
	showArray(nums_doubled, (SIZE * 2));
	cout << endl;

	delete[] nums_doubled;
	nums_doubled = nullptr;

	system("pause");
	return 0;


}

int* doubleSize(int array[], const int SIZE) {
	const int NEW_SIZE = SIZE * 2;
	int *newArr = new int[NEW_SIZE];

	for (int i = 0; i < NEW_SIZE; i++) {
		if (i >= SIZE) {
			*(newArr + i) = 0;
		}
		else {
			*(newArr + i) = array[i];
		}
	}

	return newArr;


}

void showArray(int *array, const int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		cout << *(array + i) << " "; 
	}

	return;

}

