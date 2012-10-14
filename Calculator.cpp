#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	while(true)
	{
		double num1, num2, add, sub, multi, div, root1, root2;
		cout << "Please enter a number: ";
		cin >> num1;
		cout << "Please enter another number: ";
		cin >> num2;
		add = num1 + num2;
		sub = num1 - num2;
		multi = num1 * num2;
		div = num1 / num2;
		root1 = sqrt(num1);
		root2 = sqrt(num2);
		cout << num1 << " + " << num2 << " = " << add << endl;
		cout << num1 << " - " << num2 << " = " << sub << endl;
		cout << num1 << " * " << num2 << " = " << multi << endl;
		if ( num2 == 0 )
			cout << "Error Cannot divide by 0" << endl;
		else
			cout << num1 << " / " << num2 << " = " << div << endl;
		cout << "The square root of " << num1 << " is " << root1 << endl;
		cout << "The square root of " << num2 << " is " << root2 << endl;
	}
}