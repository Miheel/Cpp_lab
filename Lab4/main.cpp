#include "Queue.hpp"
#include "Stack.hpp"

#include <iostream>
#include <string>
#include <sstream>
#include <chrono>
#include <queue>
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
		const int CAP = 10000;
		int a = rand() % 100 + 1;
		Queue<int> T1;
		std::queue<int> T2;

		Queue<std::string> S1;
		std::queue<std::string> S2;

		std::ifstream in;
		in.open("Lab4_TestFile", std::ifstream::in);
		std::string str;
		std::string temp;
		std::getline(in, str, '\0');
		std::stringstream str_s1(str);
		std::stringstream str_s2(str);

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
			T1.Push(a);
			//std::cout << i << std::endl;
		}
		SteadyClockTimePoint end3 = steady_clock::now();

		std::cout << duration_cast<microseconds>(end3 - start3).count() << ": microsec my queue on int" << std::endl;

		SteadyClockTimePoint start4 = steady_clock::now();
		for (int i = 0; i < CAP; i++)
		{
			T2.push(a);
			//std::cout << i << std::endl;
		}
		SteadyClockTimePoint end4 = steady_clock::now();

		std::cout << duration_cast<microseconds>(end4 - start4).count() << ": microsec std queue on int" << std::endl;
#pragma endregion

		//T1.Print();
		//std::cout << T1.Peek() << "\n";
		//T1.Pop();
		//T1.Print();
		//std::cout << T1.Peek();

	}MemoryLeakChecker::DumpInformation();
	getchar();
	return 0;
}