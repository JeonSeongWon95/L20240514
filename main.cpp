#include <iostream>

using namespace std;

int main ()
{
	int Screen[10][10] =
	{
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};

	int PlayerX = 1;
	int PlayerY = 1;
	int GoalX = 8;
	int GoalY = 8;
	char Key = 0;

	for (;;)
	{
		for (int Line = 0; Line < 10; ++Line)
		{
			for (int Count = 0; Count < 10; ++Count)
			{
				if (PlayerX == Count && PlayerY == Line)
				{
					cout << "P";
				}
				else if (GoalX == Count && GoalY == Line)
				{
					cout << "G";
				}
				else if (Screen[Line][Count] == 0)
				{
					cout << " ";
				}
				else if (Screen[Line][Count] == 1)
				{
					cout << "*";
				}
				else {}
			}
			cout << endl;
		}
		cin >> Key;

		if (Key == 'w') 
		{ 
			PlayerY--; 
		}
		else if (Key == 's') 
		{ 
			PlayerY++; 
		}
		else if (Key == 'a') 
		{ 
			PlayerX--; 
		}
		else if (Key == 'd') 
		{ 
			PlayerX++; 
		}

		if(PlayerX == GoalX && PlayerY == GoalY)
		{
			cout << "Escape";
		}

	}

	return 0;
}