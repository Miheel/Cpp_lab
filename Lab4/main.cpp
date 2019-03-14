#include "Queue.hpp"
#include "Stack.hpp"
#include "DataContainer.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <chrono>
#include <queue>
#include <stack>
#include <fstream>

#undef new

#include "MemoryLeakChecker.hpp"

using namespace std;
using namespace chrono;
typedef duration<unsigned int, nano> DurationNano;
typedef time_point<steady_clock, DurationNano> SteadyClockTimePoint;

int main()
{
	{
		
		srand((unsigned)time(0));
		const int CAP = 16;
		int a = rand() % 100 + 1;

		Queue<int> T1;
		Datacontainer<int> *ptr_t1 = &T1;		
		std::queue<int> T2;

		Stack<int> S1;
		Datacontainer<int> *ptr_s1 = &S1;
		std::stack<int> S2;

		/*Queue<std::string> S1;
		Datacontainer<int> *ptr_s1 = &S1;
		std::queue<std::string> S2;

		std::ifstream in;
		in.open("Lab4_TestFile", std::ifstream::in);
		std::string str;
		std::string temp;
		std::getline(in, str, '\0');
		std::stringstream str_s1(str);
		std::stringstream str_s2(str);*/



		//#pragma region queue string
		//	SteadyClockTimePoint start1 = steady_clock::now();
		//	while (str_s1 >> temp)
		//	{
		//		S1.Push(temp);
		//	}
		//	
		//	SteadyClockTimePoint end1 = steady_clock::now();
		//	std::cout << duration_cast<microseconds>(end1 - start1).count() << ": microsec my queue on string" << std::endl;
		//
		//	SteadyClockTimePoint start2 = steady_clock::now();
		//	while (str_s2 >> temp)
		//	{
		//		S2.push(temp);
		//	}
		//
		//	SteadyClockTimePoint end2 = steady_clock::now();
		//	std::cout << duration_cast<microseconds>(end2 - start2).count() << ": microsec std queue on string" << std::endl;
		//#pragma endregion

#pragma region queue_int
		SteadyClockTimePoint start3 = steady_clock::now();
		for (int i = 0; i < CAP; i++)
		{
			ptr_t1->Push(i);
		}
		SteadyClockTimePoint end3 = steady_clock::now();

		std::cout << duration_cast<microseconds>(end3 - start3).count() << ": microsec my queue on int" << std::endl;

		SteadyClockTimePoint start4 = steady_clock::now();
		for (int i = 0; i < CAP; i++)
		{
			T2.push(a);
		}
		SteadyClockTimePoint end4 = steady_clock::now();

		std::cout << duration_cast<microseconds>(end4 - start4).count() << ": microsec std queue on int" << std::endl;
#pragma endregion
//
//		T1.Print();
//		std::cout << ptr_t1->Peek() << "\n";
//		ptr_t1->Pop();
//		T1.Print();
//		std::cout << ptr_t1->Peek();
//		std::cout << "\n";
//		
//		ptr_t1->Push(16);
//		T1.Print();
//		std::cout << ptr_t1->Peek();

#pragma region stack_int
		SteadyClockTimePoint start5 = steady_clock::now();
		for (int i = 0; i < CAP; i++)
		{
			ptr_s1->Push(i);
		}
		SteadyClockTimePoint end5 = steady_clock::now();

		std::cout << duration_cast<microseconds>(end5 - start5).count() << ": microsec my stack on int" << std::endl;

		SteadyClockTimePoint start6 = steady_clock::now();
		for (int i = 0; i < CAP; i++)
		{
			S2.push(a);
		}
		SteadyClockTimePoint end6 = steady_clock::now();

		std::cout << duration_cast<microseconds>(end6 - start6).count() << ": microsec std stack on int" << std::endl;
#pragma endregion

		/*S1.Print();
		std::cout << ptr_s1->Peek() << "\n";
		ptr_s1->Pop();
		S1.Print();
		std::cout << ptr_s1->Peek();
		std::cout << "\n";

		ptr_s1->Push(16);
		S1.Print();
		std::cout << ptr_s1->Peek();*/

	}MemoryLeakChecker::DumpInformation();
	getchar();
	return 0;
}