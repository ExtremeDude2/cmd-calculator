#include <iostream> 
 
using namespace std; 
 
int main() 
{   
          double num1, num2, add, sub, multi, div; 
          cout << "Please enter a number: "; 
          cin >> num1; 
          cout << "Please enter another number: "; 
          cin >> num2; 
          add = num1 + num2; 
          sub = num1 - num2; 
          multi = num1 * num2; 
          div = num1 / num2; 
          cout << num1 << " + " << num2 << " = " << add << endl; 
          cout << num1 << " - " << num2 << " = " << sub << endl; 
          cout << num1 << " * " << num2 << " = " << multi << endl;
          cout << num1 << " / " << num2 << " = " << div << endl;
}