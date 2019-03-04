#include "Queue.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	srand((unsigned)time(0));
	const int CAP = 10;
	int a = 0;
	Queue<int> T;
	Queue<int> T1;
	Queue<int> T2;

	for (int i = 0; i < CAP; i++)
	{
		T1.Push(a = rand() % 100 + 1);
		T2.Push(a = rand() % 100 + 1);
	}
	T1.Print();
	std::cout << T1.Peek() << "\n";
	T1.Pop();
	T1.Print();
	std::cout << T1.Peek();
	getchar();
	return 0;
}