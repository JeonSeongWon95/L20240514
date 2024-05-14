#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

class Actor
{
public:
	int ActorX;
	int ActorY;
	char ActorShape;	
};

Actor* Player = new Actor;
Actor* Monster = new Actor;
Actor* Goal = new Actor;

char Key = 0;
char WallShape = '*';
char FloorShape = ' ';
bool IsRunning = true;
int MonsterLocation = 0;

int World[10][10] =
{
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}

};

void Input() 
{
	Key = _getch();
}

void Tick() 
{
	if (Player->ActorX == Goal->ActorX && Player->ActorY == Goal->ActorY)
	{
		cout << "You are Win" << endl;
		IsRunning = false;
	}
	if(Player->ActorX == Monster->ActorX && Player->ActorY == Monster->ActorY)
	{
		cout << "You are Dead" << endl;
		IsRunning = false;
	}
	if (Key == 'w')
	{
		if (Player->ActorY == 1 ) 
		{

		}
		else
		{ 
			Player->ActorY--; 
		}
	}
	else if (Key == 's')
	{
		if(Player->ActorY == 8)
		{

		}
		else
		{
			Player->ActorY++;
		}
	}
	else if (Key == 'a')
	{
		if (Player->ActorX == 1)
		{

		}
		else
		{
			Player->ActorX--;
		}
	}
	else if (Key == 'd')
	{
		if (Player->ActorX == 8)
		{

		}
		else
		{
			Player->ActorX++;
		}
	}
	else if (Key == 27)
	{
		IsRunning = false;
	}

	int Number = rand() % 4;

	if (Number == 0)
	{
		if (Monster->ActorX == 1)
		{

		}
		else
		{
			Monster->ActorX--;
		}
	}
	else if (Number == 1)
	{
		if (Monster->ActorX == 8)
		{

		}
		else
		{
			Monster->ActorX++;
		}
	}
	else if (Number == 2)
	{
		if (Monster->ActorY == 1)
		{

		}
		else
		{
			Monster->ActorY--;
		}
	}
	else if (Number == 3)
	{
		if (Monster->ActorY == 8)
		{

		}
		else
		{
			Monster->ActorY++;
		}
	}
}

void Render() 
{
	system("cls");

	for(int Line = 0; Line < 10; ++Line)
	{
		for(int Count = 0; Count < 10; ++Count)
		{
			if(Player->ActorY == Line && Player->ActorX == Count )
			{
				cout << Player->ActorShape;
			}
			else if(Monster->ActorY == Line && Monster->ActorX == Count)
			{
				cout << Monster->ActorShape;

			}
			else if (Goal->ActorY == Line && Goal->ActorX == Count)
			{
				cout << Goal->ActorShape;
			}
			else if (World[Line][Count] == 1)
			{
				cout << WallShape;
			}
			else if (World[Line][Count] == 0)
			{
				cout << FloorShape;
			}
		}

		cout << endl;
	}
};


int main ()
{
	srand(static_cast<unsigned int>(time(0)));

	Player->ActorX = 1;
	Player->ActorY = 1;
	Player->ActorShape = 'P';

	Monster->ActorX = 5;
	Monster->ActorY = 5;
	Monster->ActorShape = 'M';

	Goal->ActorX = 8;
	Goal->ActorY = 8;
	Goal->ActorShape = 'G';

	while (IsRunning)
	{
		Input();
		Tick();
		Render();
	}


	delete Player;
	delete Monster;
	delete Goal;

	return 0;
}