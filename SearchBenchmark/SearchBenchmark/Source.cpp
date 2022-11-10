//Derek D'Arcy
//I have neither given nor received unauthorized aid in completing this work, nor have I presented someone else’s work as my own.

#include <iostream>
using namespace std;

int linear(int arr[], int size, int value);
int binary(int arr[], int size, int value);


int main() {
    const int SIZE = 20;
    int arr[SIZE] = { 101, 142, 147, 189, 199, 207, 222,
                    234, 289, 296, 310, 319, 388, 394,
                    417, 429, 447, 521, 536, 600 };
    
    cout << "Linear: " << linear(arr, SIZE, 521) << endl;
    cout << "Binary: " << binary(arr, SIZE, 521) << endl;

    system("pause");
    return 0;
}



//function for binary search
int binary(int arr[], int size, int value) {
    int first = 0;
    int last = size - 1;
    int mid;
    int pos = -1;
    bool found = false;
    int loops = 0;

    while (!found && first <= last) {
        loops++;
        mid = (first + last) / 2;
        if (arr[mid] == value) {
            found = true;
            pos = mid;
        }
        else if (arr[mid] > value) {
            last = mid - 1;
        }
        else {
            first = mid + 1;
        }
    }
    return loops;
}


//function for linear search
int linear(int arr[], int size, int value) {
    int ind = 0;
    int pos = -1; 
    bool found = false;

    while (ind < size && !found) {
        if (arr[ind] == value) {
            found = true;
            pos = ind +1; 
        }
        ind++;
    }
    return pos;
}