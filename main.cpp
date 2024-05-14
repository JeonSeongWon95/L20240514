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
	int MonsterX = 8;
	int MonsterY = 8;
	
	for (int Line = 0; Line < 10; ++Line)
	{
		for (int Count = 0; Count < 10; ++Count)
		{
			if(PlayerX == Count && PlayerY == Line)
			{
				cout << "P";
			}
			else if(MonsterX == Count && MonsterY == Line)
			{
				cout << "G";
			}
			else if(Screen[Line][Count] == 0)
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

}