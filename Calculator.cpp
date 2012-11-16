#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	while(true)
	{
		double num1, num2, add, sub, multi, div, root1, root2, power;
		cout << "Please enter a number: ";
		cin >> num1;
		cout << "Please enter another number: ";
		cin >> num2;
		add = num1 + num2;										// Add first and second number
		cout << num1 << " + " << num2 << " = " << add << endl;
		sub = num1 - num2;										// Subtract first and second number
		cout << num1 << " - " << num2 << " = " << sub << endl;
		multi = num1 * num2;									// Multiply first and second number
		cout << num1 << " * " << num2 << " = " << multi << endl;
		div = num1 / num2;										// Divide first and second number
		if ( num2 == 0 )
			cout << "Error cannot divide by 0" << endl;			// Make sure not to divide by zero, prevents crashing
		else
			cout << num1 << " / " << num2 << " = " << div << endl;
		root1 = sqrt(num1);										// Square root of first number
		cout << "The square root of " << num1 << " is " << root1 << endl;
		root2 = sqrt(num2);										// Square root of second number
		cout << "The square root of " << num2 << " is " << root2 << endl;
		power = pow(num1, num2);								// First number to the power of the second number
		cout << num1 << " to the power of " << num2 << " is " << power << endl;
	}
}