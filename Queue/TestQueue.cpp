#include <iostream>
#include "Queue.h"
#include <string>
#include <stdlib.h>
#include <ctime>
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	srand((unsigned)time(0));
	const int CAP = 10;
	int a = 0;
#pragma region intkö
	Queue<int> T;
	Queue<int> T1;
	Queue<int> T2;
#pragma endregion

#pragma region isepmty
	/////////////////////////////////
	//
	//	isEmpty testar om kön är tom eller inte 
	//
	/////////////////////////////////
	if (T.isEmpty() == true)
	{
		std::cout << "The queue is empty" << std::endl;
	}
	else
	{
		std::cout << "The queue is full" << std::endl;
	}
	std::cout << std::endl;
#pragma endregion

#pragma region innan kön är fylld
	/////////////////////////////////
	//
	//	Testar att titta på det övrsta elementet i kön innan kö har blivit fylld med element 
	//	samt att testa att ta bort elemen överst i kön innan kö har blivit fylld med element 
	//	detta testar om funktionerna kastar exeptions
	//
	/////////////////////////////////
	try
	{
		std::cout << "T1 innan fylld kö: " << T1.front() << std::endl;
	}
	catch (const char* msg)
	{
		std::cerr << msg << std::endl;
	}
	std::cout << std::endl;
	try
	{
		std::cout << "T1 innan fylld kö: " << T1.dequeue() << std::endl;
	}
	catch (const char* msg)
	{
		std::cerr << msg << std::endl;
	}
	std::cout << std::endl;
#pragma endregion

#pragma region Ladda kö	
	/////////////////////////////////
	//
	//	Loopen innehåller två enqueue() funtioner 
	//	som med hjälp av rand() laddar kön med slumnpmässiga tal
	//
	/////////////////////////////////
	for (int i = 0; i < CAP; i++)
	{
		T1.enqueue(a = rand() % 100 + 1);
		T2.enqueue(a = rand() % 100 + 1);
	}
#pragma endregion

#pragma region isEmpty
	/////////////////////////////////
	//
	//	isEmpty testar om kön är tom eller inte 
	//
	/////////////////////////////////
	if (T1.isEmpty() == true)
	{
		std::cout << "The queue is empty" << std::endl;
	}
	else
	{
		std::cout << "The queue is full" << std::endl;
	}
	std::cout << std::endl;
#pragma endregion

#pragma region Front
	/////////////////////////////////
	//
	//	dessa två try-catch block har front() funtionen som,
	//	tittar på elementet med högst prioritet i köerna T1 samt T2
	//
	/////////////////////////////////
	try
	{
		std::cout << "Front T1: " << T1.front() << std::endl;
	}
	catch (const char* msg)
	{
		std::cerr << msg << std::endl;
	}
	std::cout << std::endl;
	try
	{
		std::cout << "Front T2: " << T2.front() << std::endl;
	}
	catch (const char* msg)
	{
		std::cerr << msg << std::endl;
	}
	std::cout << std::endl;
#pragma endregion

#pragma region Dequeue
	/////////////////////////////////
	//
	//	dessa två try-catch block har dequeue() funtionen som,
	//	tar bort elementet med högst prioritet i köerna T1 samt T2
	//
	/////////////////////////////////
	try
	{
		std::cout << "Dequeue T1: " << T1.dequeue() << std::endl;
	}
	catch (const char* msg)
	{
		std::cerr << msg << std::endl;
	}
	std::cout << std::endl;
	try
	{
		std::cout << "Dequeue T2: " << T2.dequeue() << std::endl;
	}
	catch (const char* msg)
	{
		std::cerr << msg << std::endl;
	}
	std::cout << std::endl;
#pragma endregion

#pragma region tilldelnings operatorn
	/////////////////////////////////
	//
	//	Här testas copy tilldelnings operatorn
	//	Med de redan fylda köerna T1 och T2 
	//	sedan tilldelar kö T1 till T2
	//
	/////////////////////////////////

	T2 = T1;
	try
	{
		std::cout << "T2 efter tilldelning av T1: " << T1.front() << std::endl;
	}
	catch (const char* msg)
	{
		std::cerr << msg << std::endl;
	}
	std::cout << std::endl;
#pragma endregion

#pragma region Copy constructor
	/////////////////////////////////
	//
	//	Här testas copy tilldelnings operatorn
	//	skapar kö T3 med värdet av kö T1
	//	
	/////////////////////////////////
	Queue<int> T3(T1);
	try
	{
		std::cout << "T3 efter copyconstrucktor av T1: " << T3.front() << std::endl;
	}
	catch (const char* msg)
	{
		std::cerr << msg << std::endl;
	}
	std::cout << std::endl;
#pragma endregion

#pragma region charkö
	Queue<char> ch1;
	Queue<char> ch2;
#pragma endregion

#pragma region Front char

	/////////////////////////////////
	//
	//	Lägger till bokstäver i kön ch1
	//	sedan tittar på elementet med högst prioritet i kön ch1
	//
	/////////////////////////////////
	ch1.enqueue('a');
	ch1.enqueue('h');
	ch1.enqueue('f');
	ch1.enqueue('k');
	try
	{
		std::cout << "Front ch1: " << ch1.front() << std::endl;
	}
	catch (const char* msg)
	{
		std::cerr << msg << std::endl;
	}
	std::cout << std::endl;
#pragma endregion

#pragma region Dequeue char
	/////////////////////////////////
	//
	//	Tar bort ett element från kön ch1
	//
	/////////////////////////////////
	try
	{
		std::cout << "Dequeue ch1: " << ch1.dequeue() << std::endl;
	}
	catch (const char* msg)
	{
		std::cerr << msg << std::endl;
	}
	std::cout << std::endl;
#pragma endregion

#pragma region tilldelnings operatorn
	/////////////////////////////////
	//
	//	Här testas copy tilldelnings operatorn
	//	tilldelar kö ch1 till ch2
	//
	/////////////////////////////////
	ch2 = ch1;
	try
	{
		std::cout << "ch2 efter tilldelningav ch1: " << ch1.front() << std::endl;
	}
	catch (const char* msg)
	{
		std::cerr << msg << std::endl;
	}
	std::cout << std::endl;
#pragma endregion

#pragma region Copy constructor
	/////////////////////////////////
	//
	//	Här testas copy tilldelnings operatorn
	//	skapar kö ch3 med värdet av kö ch1
	//	
	/////////////////////////////////
	Queue<char> ch3(ch1);
	try
	{
		std::cout << "ch3 efter copyconstrucktor ch1: " << ch3.front() << std::endl;
	}
	catch (const char* msg)
	{
		std::cerr << msg << std::endl;
	}
	std::cout << std::endl;
#pragma endregion

	system("PAUSE");
	return 0;
}