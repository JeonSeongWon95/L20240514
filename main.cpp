#include <iostream>
#include <conio.h>

using namespace std;

class Actor
{
public:
	int ActorX;
	int ActorY;
	char ActorShape;	
};

Actor* Player = new Actor;
Actor* Moster = new Actor;
Actor* Goal = new Actor;

char Key = 0;
char WallShape = '*';
char FloorShape = ' ';
bool IsRunning = true;

int World[10][10] =
{
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 1, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 1, 1, 1, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}

};

void Input() 
{
	Key = _getch();
}

void Tick() 
{

	if (Key == 'w')
	{
		cout << Player->ActorY--;
	}
	else if (Key == 's')
	{
		cout << Player->ActorY++;
	}
	else if (Key == 'a')
	{
		cout << Player->ActorX--;
	}
	else if (Key == 'd')
	{
		cout << Player->ActorX++;
	}
	else if (Key == 27)
	{
		IsRunning = false;
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
			else if(Moster->ActorY == Line && Moster->ActorX == Count)
			{
				cout << Moster->ActorShape;

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
	Player->ActorX = 1;
	Player->ActorY = 1;
	Player->ActorShape = 'P';

	Moster->ActorX = 5;
	Moster->ActorY = 5;
	Moster->ActorShape = 'M';

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
	delete Moster;
	delete Goal;

	return 0;
}

// Pointer
//
// ������ �ᱹ �޸� �ּҰ��� ������ �ִµ� �� �ּҸ� ����Ű�� �ڷ����̴�.
// &������ : �ش� ������ �ּ� ���� �޶�� �ǹ̴�.
// �ᱹ �� �ּ� ���� ���ڱ� ������ ������ �� �ִ�.
// ������ �ʱ�ȭ�� 0�ۿ� �ȵȴ�.
// �ڷ���* ������ ���� �� �ش� �ڷ��� ����Ҹ� ����Ű�� Pointer�� �ȴ�.
// �߿��� ������ int�� int*�� ���� �ٸ��ٴ� ���̴�.
// *�����ͺ��� : �ش� �ּ��� ���� ��������� �ǹ�
// C++�� ��ǻ�Ͱ� �ش� �۾��� ���� �����ֱ� ������ ���̵��� ������, ������ ���ȴ�.
// C#, Java ���� ��ǻ�Ͱ� ���ֱ� ������ ���̵��� �������� ���ɵ� ��������.
// *(Number+1 * Sizeof(int)) == Number[1] == *(Number + 1)
// �Լ��� ���ڷ� �޾ƿö� �Ź� �����ϹǷ� ������ ��������. �׷��� ���� �����͸� �޴´�.
// �迭�� ������ ó���� size�� ��� ���� ������ size ���� ������ �� ����.
// ���� ���ϴ� �迭 ����� �������� �ٲٱ� ���ؼ� �Ƿ��ϴ�
// �ڷᱸ���� �迭���� ������ �� -> ��� ������ �������ΰ�.
// 
// int size = 10;
// int* PA = new int[size];
// 
// new�� ���� ��ġ�� �˷��ִ� ��.
// �ݵ�� delete�� ���� ��.
// delete[] PA;
// �迭�� �ƴϸ� delete PA;
// 
// Computer Memory Managemed Language
// 
// Unmanaged Language
//