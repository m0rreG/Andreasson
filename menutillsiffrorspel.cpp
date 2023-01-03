#include <iostream>
#include <fstream>
#include <windows.h>
#include <ctime>
#include <iomanip>
#include <string>
using namespace std;

void game(); //spel funktionen - Game function
void randgenerator(); //random nummer generatorn till spelet - random number generator to the game
int login(); //funktionen för login - function for login
void create_user(); //funktionen som skapar användare - function creates user
void top_players(); //funktion som visar dem bästa spelarna - function displays best players (not done)
void credits(); //fuunktion som visar vem som kodat allt - Credits screen
void exit_game(); //funktion som stänger hela spelet. - Terminates the program

string login_status = "SIGNED OUT";
string allnum;
int startgame = 0, level = 1;

int main()
{
	char choice;
	do
	{
		system("color 97");
		system("cls");
		cout << "\n\n\n\tNumber Memory Game" << "\t\t\t\t\t\t\t\tSTATUS: " << login_status;
		cout << "\n\n\t01. Play Game";
		cout << "\n\n\t02. Login";
		cout << "\n\n\t03. Create User";
		cout << "\n\n\t04. Top Players";
		cout << "\n\n\t05. Credits";
		cout << "\n\n\t06. Exit Game";
		cout << "\n\n\tSelect your option (1-6) ";
		cin >> choice;
		system("cls");
		switch(choice)
		{
		case '1':
			if(startgame == 1)
				game();
			else
				cout << "\n\n\tYou need to login or create an account before playing the game!";
			break;
		case '2':
			login();
			break;
		case '3':
			create_user();
			break;
		case '4':
			top_players();
			break;
		case '5':
			credits();
			break;
		case '6':
			cout << "\n\n\tThanks for playing the Number Memory Game!";
			break;
			default: cout << "\a"; // om man gör något annat en 1 - 6 - if you do something else then 1 - 6
		}
		cin.ignore();
		cin.get();
	}while(choice != '6');
	return 0;
}

void game()
{
	string Clear = "                                                  ";
	string stringanswer;
	int cd_delay = 50, loose = 0;
	level = 1;
	cin.ignore(); //HERE
	while(1)// lopen som kör HELA spelet - the loop that runs the entire game
	{
		if(level == 1 && loose == 0) //körs om man spelar för första gången - if it is the first time you play the game
		{
			cout << "\n\n\r\tThe game will start in: 3.";
			Sleep(1000);
			cout << Clear;
			cout << "\r\tThe game will start in: 2.";
			Sleep(1000);
			cout << Clear;
			cout << "\r\tThe game will start in: 1.";
			Sleep(1000);
			cout << Clear;
		}
		else if(level > 1 && loose == 0) //körs om du klarade förra nivån - runs if you completed the privous level
		{
			system("cls");
			cout << "\n\n\tCorrect!";
			cout << "\n\r\tLevel " << level << " starts in: 3.";
			Sleep(1000);
			cout << Clear;
			cout << "\r\tLevel " << level << " starts in: 2.";
			Sleep(1000);
			cout << Clear;
			cout << "\r\tLevel " << level << " starts in: 1.";
			Sleep(1000);
		}
		else //körs om du förlorade. - runs if you lost
		{
			// en meny precis som om du skrev fel inlog. - the game over screen
			system("cls");
			cout << "\n\n\tGAME OVER!";
			cout << "\n\tCorrect answer: " << allnum;
			cout << "\n\tYour answer: " << stringanswer;
			break;
		}
		system("cls");
		cout << "\n\n\tThe Number Memory Game";
		randgenerator();

		string countdown = "********************";
		cout << "\n\t" << countdown;
		cd_delay = cd_delay + 50;
		int j = 1;
		while(j <= 20)//countdown loop
		{
			if(!countdown.empty())
				countdown.pop_back();
			cout << "\r" << Clear << "\r\t" << countdown;
			j++;
			Sleep(cd_delay);
		}
		system("cls");

		cout << "\n\n\tThe Number Memory Game";
		cout << "\n\n\n\tWhat was the number?: ";
		getline(cin, stringanswer); //för att detta ska funka finns cin.ignore högst upp i funktionen - to make it work cin.ignore is in the top of the function^

		if(allnum == stringanswer)
			level++;
		else
			loose++;
	}
}

void randgenerator()
{
	int guessnum, i = 0;
	string num1;
	allnum = "";
	srand(time(NULL));
	while(i < level)
	{
		guessnum = rand() % 10;
		num1 = to_string(guessnum);
		allnum = allnum + num1;
		i++;
	}
	cout << "\n\n\t\t | " << allnum << " |";// varje lvl = -1 blank space
}

int login()
{
	string pass;
	string login_name;
	string login_pass;

	ifstream playerdata;
	playerdata.open("playerdata");
	while(1) //inloggnings loopen - inlogg loop
	{
		system("cls");
		cout << "\n\n\tEnter your Username: ";
		cin >> login_name;

		cout << "\tEnter your password: ";
		cin >> login_pass;

		pass = login_name + login_pass;
		string testword;
		int next = 0;
		while(playerdata >> testword) // kollar om inloggningen stämmer - checks if inlog is correct
		{
			if(pass == testword)
				next++;
		}

		if(next == 1) //om inloggningen är rätt - if inlog is correct
		{
			system("cls");
			cout << "\n\tLogging in to " << login_name << "...";
			login_status = "SIGNED IN";
			startgame++; //ger dig tillgång till att spela spelet (eftersom du är inloggad) - makes you viable to play the game
			Sleep(500);
			break;
		}
		else //om inloggningen är fel - if inlog is wrong
		{
			system("cls");
			cout << "\n\tError, Wrong Username or Password";
			cout << "\n\n\t01. Main Menu";
			cout << "\n\n\t02. Try Again";
			cout << "\n\n\tSelect your option (1-2) ";
			char answer;
			cin >> answer;
			if(answer == '1') //om du går tillbaka till main menu annars börjar loopen om igen - if you go back to main menu otherwise the loop starts over
			{
				system("cls");
				cout << "\n\n\tReturning to Main Menu...";
				break;
			}
		}
	}
	playerdata.close();
	return main();
}

void create_user()
{
	int highscore;
	char user_name[30];
	char password[30];
	string file_name = "playerdata";
	//string file_name2 = "playerstats";

	ofstream Players(file_name, ios_base::app);

	cout << "\n\n\tWhat is your Username?: ";
	cin >> user_name;
	
	cout << "\n\tEnter a password to your account: ";
	cin >> password;

	Players << user_name << password << endl;

	cout << "\n\tCreating player " << user_name << "...";
	login_status = "SIGNED IN";
	startgame++; //ger dig tillgång till att spela spelet (eftersom du är inloggad) - gives you access to play the game

	//************************************************
	/* till highscore och top players sidan - for higescore and top players page
	ofstream PlayerStats(file_name2, ios_base::app)
	PlayerStats << user_name << ", " << highscore << endl;*/

}

void top_players()
{
	cout << "\n\n\twork in progress!";
}

void credits()
{
	cout << "\n\n\t======================";
	cout << "\n\t  Number Memory Game";
	cout << "\n\t======================";
	cout << "\n\n\tMade by : M\x86rten Andreasson"; 
	cout << "\n\n\tWritten with C++";
}

// ** Thanks for checking out my code **