#include <iostream>
using namespace std;
int main(){
	double num1, num2, result;
	char Operator;
	cout << "Enter first number: " << endl;
	cin >> num1;
	cout << "Enter operator: ";
	cin >> Operator;
	cout << "Enter second number: " << endl;
	cin >> num2;
	if(Operator == '+'){result = num1 + num2;} 
	else if(Operator == '-'){result = num1 - num2;}
	else if(Operator == '*'){result = num1 * num2;}
	else if(Operator == '/'){result = num1 / num2;}
	else{cout << "ERROR";}
	cout << "Your answer is: " << result << endl;
	return 0;
};