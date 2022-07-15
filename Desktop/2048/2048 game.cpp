
#include<iostream>
#include<conio.h>
#include<ctime>
#include<fstream>
#include<stdlib.h>
#include<string>
using namespace std;
int arr[4][4], score = 0, maxscore, totalmoved = 0;
bool lost = 0;
//prototypes
void moveup();
void up();
void movedown();
void down();
void moveleft();
void left();
void moveright();
void right();
void board();
void genrnd();
bool winner(int choice);
void initialization();
void display();
bool up_down_check();
bool left_right_check();
int main()
{
	int n, j;

	int choice1;
	int b = 0, a = 0;
	cout << "                           WELCOME TO THE 2048 or 4096 GAME     ";
	cout << "\n";
	cout << "\n";
	bool flag = 1;
	while (flag == 1)
	{
		string choice; char input; int control;
		cout << "               -------------------Main menu and rules-----------------------" << endl;
		cout << "Please Enter the choice 1 for 2048 game" << endl << endl;

		cout << "press 2 for 4096 game" << endl << endl;
		cout << "press c for continue(if paused already) " << endl << endl;
		cout << "if you press c without pausing any previus game it will start new game of 2048" << endl << endl;
		cout << "press 0 for quiting=" << endl << endl;
		cout << "the game will operate on arrow keys." << endl << endl;
		cout << "enter your choice from menu" << endl;

		getline(cin, choice);
		if (choice.length() > 1)
		{
			cout << "enter string character of length one" << endl;
			system("pause");
			system("cls");
			continue;
		}
		else

		{
			if (choice != "1" && choice != "2"&&choice != "0"&&choice != "c"&&choice != "C")
			{
				cout << "enter valid choice" << endl;
				system("pause");
				system("cls");
				continue;
			}
			else
			{
				if (choice == "0")
					break;
				else
				{

					choice1 = choice[0];
					if ((choice == "1" || choice == "2"))
					{
						initialization();
						score = 0;
						totalmoved = 0;
						for (int a = 0; a <= 1; a++)
						{
							n = rand() % 4;
							j = rand() % 4;
							arr[n][j] = 2;
						}
						board();
					}
					else
						if ((choice == "c" || choice == "C") && (b == 1 || a == 1))
						{

							initialization();
							score = 0;
							totalmoved = 0;
							for (int a = 0; a <= 1; a++)
							{
								n = rand() % 4;
								j = rand() % 4;
								arr[n][j] = 2;
							}
							board();
						}
						else
							if ((choice == "c" || choice == "C") && (b == 0 && a == 0))
								board();
					if (choice1 == 50 || choice1 == 49 || choice1 == 67 || choice1 == 99)
					{
						while (lost != 1)
						{



							input = _getch();
							control = input;
							if ((control == 72 || control == 77 || control == 80 || control == 75 || control == -32 || control == 115 || control == 83))
							{
								switch (control)
								{
								case 72:

									up();
									break;
								case 80:
									down();
									break;
								case 75:
									left();
									break;
								case 77:
									right();
									break;
								case 115:
									cout << "you have paused game" << endl;
									
									break;
								case 83:
									cout << "you have paused game" << endl;
									
									break;
								default:
								{
									board();
									break;
								}

								}
								if (control == 115 || control == 83)
									break;
								a = winner(choice1);
								b = up_down_check();
								if (a == 1)
								{
									lost = a;
								}
								else if (b == 1)
								{
									lost = b;
								}
							}
							else
							{
								cout << "play with arrow keys" << endl;
								system("pause");
								continue;
							}
						}

					}
				}

			}
		}

		ofstream out;
		if (a == 1)
		{
			if (choice1 == "49")
			{
				cout << "You Win the 2048 Game:";
				cout << "\n";
			}
			else if (choice1 == "50")
			{
				cout << "You Win the 4096 Game:";
				cout << "\n";
			}
		}
		if (choice1 == 49 || choice1 == 50)
		{
			if (score > maxscore)
			{
				out.open("maxscore.txt");
				maxscore = score;
				out << maxscore;
				out.close();
			}
		}
		if (b == 1)
		{
			cout << "You Lose the Game Try Again:";
			cout << "\n";
			cout << "Your Score is " << score;
			cout << "\n";

		}
		if (totalmoved >= 131038)
		{
			cout << "You lose the Game as the possible moves limit reached:";
			cout << "\n";
		}
		if (score > maxscore)
		{
			out.open("maxscore.txt");
			maxscore = score;
			out << maxscore;
			out.close();
		}

		lost = 0;
		cout << "press enter to continue...." << endl;
		cin.get();
		system("cls");


	}
	system("pause");
	return 0;
}
void initialization()
{
	for (int i = 0; i <= 3; i++)
	{
		for (int j = 0; j <= 3; j++)
		{
			arr[i][j] = 0;
		}
	}
}
void moveup()
{
	for (int col = 0; col <= 3; col++)
	{
		for (int count = 0; count <= 3; count++)
		{
			if (arr[0][col] == 0)
			{
				arr[0][col] = arr[1][col];
				arr[1][col] = 0;
			}
			if (arr[1][col] == 0)
			{
				arr[1][col] = arr[2][col];
				arr[2][col] = 0;
			}
			if (arr[2][col] == 0)
			{
				arr[2][col] = arr[3][col];
				arr[3][col] = 0;
			}
		}
	}

}
void up()
{
	moveup();

	for (int col = 0; col <= 3; col++)
	{
		if (arr[0][col] == arr[1][col])
		{
			arr[0][col] = arr[1][col] + arr[0][col];
			arr[1][col] = 0;
			score += arr[0][col];
		}
		if (arr[1][col] == arr[2][col])
		{
			arr[1][col] = arr[1][col] + arr[2][col];
			arr[2][col] = 0;
			score += arr[1][col];
		}
		if (arr[2][col] == arr[3][col])
		{
			arr[2][col] = arr[3][col] + arr[2][col];
			arr[3][col] = 0;
			score += arr[2][col];
		}
	}

	moveup();
	totalmoved++;
	genrnd();
	board();
}
void movedown()
{

	for (int col = 0; col <= 3; col++)
	{
		for (int count = 0; count <= 3; count++)
		{
			if (arr[3][col] == 0)
			{
				arr[3][col] = arr[2][col];
				arr[2][col] = 0;
			}
			if (arr[2][col] == 0)
			{
				arr[2][col] = arr[1][col];
				arr[1][col] = 0;
			}
			if (arr[1][col] == 0)
			{
				arr[1][col] = arr[0][col];
				arr[0][col] = 0;
			}
		}
	}

}
void down()
{
	movedown();

	for (int col = 0; col <= 3; col++)
	{
		if (arr[3][col] == arr[2][col])
		{
			arr[3][col] = arr[2][col] + arr[3][col];
			arr[2][col] = 0;
			score += arr[3][col];
		}
		if (arr[2][col] == arr[1][col])
		{
			arr[2][col] = arr[2][col] + arr[1][col];
			arr[1][col] = 0;
			score += arr[2][col];
		}
		if (arr[1][col] == arr[0][col])
		{
			arr[1][col] = arr[0][col] + arr[1][col];
			arr[0][col] = 0;
			score += arr[1][col];
		}
	}

	movedown();
	totalmoved++;
	genrnd();
	board();
}
void moveleft()
{

	for (int row = 0; row <= 3; row++)
	{
		for (int count = 0; count <= 3; count++)
		{
			if (arr[row][0] == 0)
			{
				arr[row][0] = arr[row][1];
				arr[row][1] = 0;
			}
			if (arr[row][1] == 0)
			{
				arr[row][1] = arr[row][2];
				arr[row][2] = 0;
			}
			if (arr[row][2] == 0)
			{
				arr[row][2] = arr[row][3];
				arr[row][3] = 0;
			}
		}
	}

}
void left()
{
	moveleft();
	for (int row = 0; row <= 3; row++)
	{

		if (arr[row][0] == arr[row][1])
		{
			arr[row][0] += arr[row][1];
			arr[row][1] = 0;
			score = score + arr[row][0];
		}
		if (arr[row][1] == arr[row][2])
		{
			arr[row][1] += arr[row][2];
			arr[row][2] = 0;
			score += arr[row][1];
		}
		if (arr[row][2] == arr[row][3])
		{
			arr[row][2] += arr[row][3];
			arr[row][3] = 0;
			score = score + arr[row][2];
		}
	}

	moveleft();
	totalmoved++;
	genrnd();
	board();
}
void moveright()
{
	for (int row = 0; row <= 3; row++)
	{

		for (int count = 0; count <= 3; count++)
		{
			if (arr[row][3] == 0)
			{
				arr[row][3] = arr[row][2];
				arr[row][2] = 0;
			}
			if (arr[row][2] == 0)
			{
				arr[row][2] = arr[row][1];
				arr[row][1] = 0;
			}
			if (arr[row][1] == 0)
			{
				arr[row][1] = arr[row][0];
				arr[row][0] = 0;
			}
		}
	}

}
void right()
{
	moveright();
	for (int col = 3; col >= 3; col--)
	{
		for (int row = 0; row <= 3; row++)
		{
			if (arr[row][3] == arr[row][2])
			{
				arr[row][3] += arr[row][2];
				arr[row][2] = 0;
				score = score + arr[row][3];
			}
			if (arr[row][2] == arr[row][1])
			{
				arr[row][2] += arr[row][1];
				arr[row][1] = 0;
				score += arr[row][2];
			}
			if (arr[row][1] == arr[row][0])
			{
				arr[row][1] += arr[row][0];
				arr[row][0] = 0;
				score = score + arr[row][1];
			}
		}
	}
	moveright();
	totalmoved++;
	genrnd();
	board();
}
void genrnd()
{
	int p, y, twofour;
	if (totalmoved<131038)
	{
		for (int i = 0; i < 16; i++)
		{
			p = rand() % 4;
			y = rand() % 4;
			twofour = rand() % 4;
			if (twofour >= 2)
			{
				if (arr[p][y] == 0)
				{
					arr[p][y] = 2;
					i = 16;
				}
			}
			else
			{
				if (arr[p][y] == 0)
				{
					arr[p][y] = 4;
					i = 16;
				}
			}
		}
	}
	else
	{
		lost = 1;
	}
}
void board()
{

	system("cls");
	display();
	for (int row = 0; row <= 3; row++)
	{
		for (int col = 0; col <= 3; col++)
		{
			if (arr[row][col] == 0)
			{
				cout << "|       |";
			}
			else
			{
				if (arr[row][col]<10)
				{
					cout << "|   " << arr[row][col] << "   |";
				}
				else if (arr[row][col]<100)
				{
					cout << "|  " << arr[row][col] << "   |";
				}
				else if (arr[row][col]<1000)
				{
					cout << "|  " << arr[row][col] << "  |";
				}
				else if (arr[row][col]<10000)
				{
					cout << "| " << arr[row][col] << "  |";
				}
				else
				{
					cout << "| " << arr[row][col] << " |";
				}
			}
		}
		cout << endl;
	}
}
bool winner(int choice)
{
	bool win;
	for (int row = 0; row <= 3; row++)
	{
		for (int col = 0; col <= 3; col++)
		{
			if (choice == 1)
			{
				if (arr[row][col] == 2048)
				{
					win = 1;
					return win;
				}
			}
			else if (choice == 2)
			{
				if (arr[row][col] == 4096)
				{
					win = 1;
					return win;
				}
			}
			else
			{
				win = 0;
				return win;
			}
		}
	}
}
void display()
{
	ifstream in;
	cout << "         WELCOME TO THE 2048/4096 GAME          " << endl << endl;

	cout << "\n" << "Player Score is ::" << score;
	cout << "\t  The Max score is :" << maxscore;
	cout << "\n";
	cout << "You did   " << totalmoved << "    moves"; cout << "\t"; cout << " Your Possible moves are " << (131038 - totalmoved);
	cout << "\n";
	cout << "\n";
	cout << "\n";
	in.open("maxscore.txt");
	in >> maxscore;
	cout << "press s/S to stop or pause the game" << endl;
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	
}
bool up_down_check()
{
	int a = 0, b = 0, c = 0;
	bool ans;
	for (int row = 0; row <= 3; row++)
	{
		for (int col = 0; col <= 3; col++)
		{
			if (arr[row][col] != 0)
			{
				a++;
			}
		}
	}
	if (a == 16)
	{

		for (int col = 0; col <= 3; col++)
		{
			if (arr[0][col] != arr[1][col])
			{
				b++;
			}
			if (arr[1][col] != arr[2][col])
			{
				b++;
			}
			if (arr[2][col] != arr[3][col])
			{
				b++;
			}
		}

	}
	if (b == 12)
	{

		for (int col = 0; col <= 3; col++)
		{
			if (arr[3][col] != arr[2][col])
			{
				c++;
			}
			if (arr[2][col] != arr[1][col])
			{
				c++;
			}
			if (arr[1][col] != arr[0][col])
			{
				c++;
			}
		}
	}

	if (c == 12)
	{
		bool ans2;
		ans2 = left_right_check();
		ans = ans2;
		return ans;
	}
	else
	{
		ans = 0;
		return ans;
	}
}
bool left_right_check()
{
	int a = 0, b = 0;
	bool ans3;

	for (int row = 0; row <= 3; row++)
	{
		if (arr[row][3] != arr[row][2])
		{
			a++;
		}
		if (arr[row][2] != arr[row][1])
		{
			a++;
		}
		if (arr[row][1] != arr[row][0])
		{
			a++;
		}
	}

	if (a == 12)
	{
		for (int row = 0; row <= 3; row++)
		{

			if (arr[row][0] != arr[row][1])
			{
				b++;
			}
			if (arr[row][1] != arr[row][2])
			{
				b++;
			}
			if (arr[row][2] != arr[row][3])
			{
				b++;
			}
		}

	}
	if (b == 12)
	{
		ans3 = 1;
		return ans3;
	}
	else
	{
		ans3 = 0;
		return ans3;
	}
}

