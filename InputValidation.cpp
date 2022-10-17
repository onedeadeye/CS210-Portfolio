#include <iostream>
using namespace std;

/*
* Collects and validates user input for a double value
* 
* @return double user input
*/
double getValidDoubleInput() {
	double input;
	while (!(cin >> input)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input. Please try again: ";
	}
	return input;
}

/*
* Collects and validates user input for an int value
* 
* @return int user input
*/
int getValidIntInput() {
	int input;
	while (!(cin >> input)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input. Please try again: ";
	}
	return input;
}

/*
* Collects and validates user input for an int value within a specified range
* 
* @param min Minimum value for input, inclusive.
* @param max Maximum value for input, inclusive.
*/
int getValidIntInput(int min, int max) {
	int input;
	while (!(cin >> input) || input < min || input > max) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input. Please try again: ";
	}
	return input;
}