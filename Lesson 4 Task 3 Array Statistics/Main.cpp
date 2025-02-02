#include <iostream>
#include <array>
using std::endl;
using std::cout;
using std::cin;
/*
Practice Task 3: Array Statistics
Objective: Work with arrays to store data and calculate statistics.

Instructions:

Write a program that:
Asks the user to input 10 integer values.
Stores these values in an array.
Uses a loop to print the array contents.
Calculates and prints the following statistics:
The sum of all values.
The average of the values.
The largest and smallest values.
The number of even and odd values.
Bonus Task:

Modify the program to handle an array of 20 values.
Reuse the same functions to calculate the statistics for this larger array.
*/

int sumOfArray(int array[], int length) {
	int sum = 0;
	for (int i = 0; i < length; i++) {
		sum += array[i];
	}
	return sum;
}

int averageOfArray(int array[], int length) {
	int sum = 0;
	for (int i = 0; i < length; i++) {
		sum += array[i];
	}
	return sum / length;
}

int getSmallestNumber(int array[], int length) {
	int number = array[0];
	for (int i = 0; i < length; i++) {
		if (array[i] == number)
			continue;

		if (array[i] < number) {
			number = array[i];
		}
	}
	return number;
}

int getLargestNumber(int array[], int length) {
	int number = array[0];
	for (int i = 0; i < length; i++) {
		if (array[i] == number)
			continue;

		if (array[i] > number) {
			number = array[i];
		}
	}
	return number;
}

int getOddOrEvenNumbers(int array[], int length, bool lookingForOdd) {
	int counter = 0;
	for (int i = 0; i < length; i++) {
		if (array[i] % 2 == 0) {
			if (!lookingForOdd) {
				counter++;
			}
		}
		else {
			if (lookingForOdd) {
				counter++;
			}
		}
	}

	return counter;
}

int main() {
	const int arrayLength = 20;
	int arrayOfNumbers[arrayLength];

	for (int i = 0; i < arrayLength; i++) {
		arrayOfNumbers[i] = 0;
	}

	int counter = 0;
	int enteredNumber = 0;
	
	cout << "Please enter " << arrayLength << " numeric values." << endl;
	
	for (; counter < arrayLength; counter++) {
		cout << (counter + 1) << ") ";
		cin >> enteredNumber;
		// -- cin check
		arrayOfNumbers[counter] = enteredNumber;
	}

	counter = 0;
	for (; counter < arrayLength; counter++) {
		cout << arrayOfNumbers[counter];
		if (counter == arrayLength - 1) {
			cout << "." << endl << endl;
		}
		else {
			cout << + ", ";
		}
	}

	int sum = sumOfArray(arrayOfNumbers, arrayLength);
	cout << "Sum: " << sum << endl;

	int average = averageOfArray(arrayOfNumbers, arrayLength);
	cout << "Average: " << average << endl;

	int smallestNumber = getSmallestNumber(arrayOfNumbers, arrayLength);
	int largestNumber = getLargestNumber(arrayOfNumbers, arrayLength);

	cout << "Smallest Number: " << smallestNumber << endl;
	cout << "Largest Number: " << largestNumber << endl;

	int amountOfOddNumbers = getOddOrEvenNumbers(arrayOfNumbers, arrayLength, true);
	int amountOfEvenNumbers = getOddOrEvenNumbers(arrayOfNumbers, arrayLength, false);

	cout << "Amount of Odd Numbers: " << amountOfOddNumbers << endl;
	cout << "Amount of Even Numbers: " << amountOfEvenNumbers << endl;

	return 0;
}