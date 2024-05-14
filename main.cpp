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
// 변수는 결국 메모리 주소값을 가지고 있는데 그 주소를 가르키는 자료형이다.
// &변수명 : 해당 변수의 주소 값을 달라는 의미다.
// 결국 이 주소 값도 숫자기 때문에 저장할 수 있다.
// 포인터 초기화는 0밖에 안된다.
// 자료형* 변수명 선언 시 해당 자료형 저장소를 가르키는 Pointer가 된다.
// 중요한 전제는 int와 int*는 완전 다르다는 것이다.
// *포인터변수 : 해당 주소의 값을 가져오라는 의미
// C++은 컴퓨터가 해당 작업을 따로 안해주기 때문에 난이도가 높지만, 성능이 향상된다.
// C#, Java 등은 컴퓨터가 해주기 때문에 난이도가 떨어지고 성능도 떨어진다.
// *(Number+1 * Sizeof(int)) == Number[1] == *(Number + 1)
// 함수의 인자로 받아올때 매번 복사하므로 성능이 떨어진다. 그래서 거의 포인터를 받는다.
// 배열의 선언은 처음에 size를 잡고 가기 때문에 size 없이 선언할 수 없다.
// 내가 원하는 배열 사이즈를 동적으로 바꾸기 위해서 피료하다
// 자료구조가 배열부터 나오는 것 -> 어떻게 저장해 놓을것인가.
// 
// int size = 10;
// int* PA = new int[size];
// 
// new가 시작 위치를 알려주는 것.
// 반드시 delete로 지울 것.
// delete[] PA;
// 배열이 아니면 delete PA;
// 
// Computer Memory Managemed Language
// 
// Unmanaged Language
//