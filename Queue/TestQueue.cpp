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
#pragma region intk�
	Queue<int> T;
	Queue<int> T1;
	Queue<int> T2;
#pragma endregion

#pragma region isepmty
	/////////////////////////////////
	//
	//	isEmpty testar om k�n �r tom eller inte 
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

#pragma region innan k�n �r fylld
	/////////////////////////////////
	//
	//	Testar att titta p� det �vrsta elementet i k�n innan k� har blivit fylld med element 
	//	samt att testa att ta bort elemen �verst i k�n innan k� har blivit fylld med element 
	//	detta testar om funktionerna kastar exeptions
	//
	/////////////////////////////////
	try
	{
		std::cout << "T1 innan fylld k�: " << T1.front() << std::endl;
	}
	catch (const char* msg)
	{
		std::cerr << msg << std::endl;
	}
	std::cout << std::endl;
	try
	{
		std::cout << "T1 innan fylld k�: " << T1.dequeue() << std::endl;
	}
	catch (const char* msg)
	{
		std::cerr << msg << std::endl;
	}
	std::cout << std::endl;
#pragma endregion

#pragma region Ladda k�	
	/////////////////////////////////
	//
	//	Loopen inneh�ller tv� enqueue() funtioner 
	//	som med hj�lp av rand() laddar k�n med slumnpm�ssiga tal
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
	//	isEmpty testar om k�n �r tom eller inte 
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
	//	dessa tv� try-catch block har front() funtionen som,
	//	tittar p� elementet med h�gst prioritet i k�erna T1 samt T2
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
	//	dessa tv� try-catch block har dequeue() funtionen som,
	//	tar bort elementet med h�gst prioritet i k�erna T1 samt T2
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
	//	H�r testas copy tilldelnings operatorn
	//	Med de redan fylda k�erna T1 och T2 
	//	sedan tilldelar k� T1 till T2
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
	//	H�r testas copy tilldelnings operatorn
	//	skapar k� T3 med v�rdet av k� T1
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

#pragma region chark�
	Queue<char> ch1;
	Queue<char> ch2;
#pragma endregion

#pragma region Front char

	/////////////////////////////////
	//
	//	L�gger till bokst�ver i k�n ch1
	//	sedan tittar p� elementet med h�gst prioritet i k�n ch1
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
	//	Tar bort ett element fr�n k�n ch1
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
	//	H�r testas copy tilldelnings operatorn
	//	tilldelar k� ch1 till ch2
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
	//	H�r testas copy tilldelnings operatorn
	//	skapar k� ch3 med v�rdet av k� ch1
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