#include <iostream>
using namespace std;

char star = '*';
int rows, numberofstars, numberofspace;
char space = ' ';

void print_quest(); // initicierar funktionen
int calq(); // initicierar funktionen

int main()
{
	print_quest();

	return 0;
}

void print_quest()
{
	cout << "How many rows of stars do you want to print?: ";
	cin >> rows;
	rows++;
	calq();
}

int calq() // Räknar ut och skriver ut mönstret
{
	for(int i = 0; i < rows; i++) // gör en ny rad
		{
			numberofspace = rows - i; // räknar ut antal mellanrum
			numberofstars = i + i - 1; // räknar ut antal stjärnor
			cout << "\n"; // ny rad

			for(int j = 0; j != numberofspace; j++) // skriver ut mellanrum
				cout << space;

			for(int k = 0; k < numberofstars; k++ ) // skriver ut alla stjärnor
					cout << star;
		}
	return 0;
}