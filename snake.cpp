#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
bool GameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN};
Direction dir;


int Setup()

{
	GameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
	return 0;
}

int Draw()

{
		system("cls"); 
		for (int i = 0; i < width+2; i++){
			cout << "#";
			cout << “\n”; 
            }
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (j == 0)
					cout << "#";
				if (i == y && j == x)
					cout << "O";
				else if (i == fruitY && j == fruitX)
					cout << "F";
				else
				{
					bool print = false;
					for (int k = 0; k < nTail; k++)
					{
						if (tailX[k] == j && tailY[k] == i)
						{
							cout << "o";
							print = true;
						}
					}
					if (!print)
						cout << "\n";
				}


				if (j == width - 1)
					cout << "#";
			}
			cout << "\n";
		}

		for (int i = 0; i < width+2; i++)
			cout << "#";
		cout << "\n";
		cout << "Score:" << score << "\n";
		return 0;
}

int Input()

{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 'a':
				dir = LEFT;
				break;
			case ’d’:
				dir = RIGHT;
				break;
			case 'w':
				dir = UP;
				break;
			case ’s’:
				dir = DOWN;
				break;
			case 'x':
				GameOver = true;
				break;
			}
		}
	return 0;
}


int Logic()

{
		int prevX = tailX[0];
		int prevY = tailY[0];
		int prev2X, prev2Y;
		tailX[0] = x;
		tailY[0] = y;
		for (int i = 1; i < nTail; i++)
		{
			prev2X = tailX[i];
			prev2Y = tailY[i];
			tailX[i] = prevX;
			tailY[i] = prevY;
			prevX = prev2X;
			prevY = prev2Y;
		}
		switch (dir)
		{
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
		case UP:
			y--;
			break;
		case DOWN:
			y++;
			break;
		default:
			break;
		}
		
		if (x >= width)
		{	
			GameOver = true;
		}
		if (x <= 0) 
		{
			GameOver = true;
		}
		if (y >= height)
		{
			GameOver = true;
		}
      		if (y <= 0) 
		{
			GameOver = true;
		}

	for (int i = 0; i < nTail; i++)
		{
			if (tailX[i] == x && tailY[i] == y)
			{
				GameOver = true;
			}
		}

		if (x == fruitX && y == fruitY)
		{
			score += 10;
			fruitX = rand() % width;
			fruitY = rand() % height;
			nTail++;
		}
		return 0;
}

int main()

{
	Setup();
	while (!GameOver)
	{
		Draw();
		Input();
		Logic();
		Sleep(50);
	}
	return 0;
}


