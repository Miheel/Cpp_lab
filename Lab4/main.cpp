#include <iostream>
#include <string>
#include <sstream>
#include <chrono>
#include <queue>
#include <stack>
#include <fstream>
#include <exception>
#include "DataContainer.hpp"
#include "Queue.hpp"
#include "Stack.hpp"

#undef new

#include "MemoryLeakChecker.hpp"

using namespace std;
using namespace chrono;
typedef duration<unsigned int, nano> DurationNano;
typedef time_point<steady_clock, DurationNano> SteadyClockTimePoint;

int main()
{
	{

#pragma region init
		srand((unsigned)time(0));
		const int CAP = 1000;
		int a = rand() % 100 + 1;

		Queue<int> Q1;
		std::queue<int> Q2;

		Stack<int> S1;
		std::stack<int> S2;

		Queue<std::string> Q3;
		std::queue<std::string> Q4;

		std::ifstream in;
		in.open("Lab4_TestFile", std::ifstream::in);
		std::string str;
		std::string temp;
		std::getline(in, str, '\0');
		std::stringstream str_s1(str);
		std::stringstream str_s2(str);
#pragma endregion

#pragma region try1
		try
		{
			Q1.Pop();
		}
		catch (const std::exception &e)
		{
			std::cerr << "exeption: " << e.what() << "\n";
		}
		try
		{
			Q1.Peek();
		}
		catch (const std::exception &e)
		{
			std::cerr << "exeption: " << e.what() << "\n";
		}

		try
		{
			S1.Pop();
		}
		catch (const std::exception &e)
		{
			std::cerr << "exeption: " << e.what() << "\n";
		}
		try
		{
			S1.Peek();
		}
		catch (const std::exception &e)
		{
			std::cerr << "exeption: " << e.what() << "\n";
		}
#pragma endregion

#pragma region queue_int
		SteadyClockTimePoint starttot1 = steady_clock::now();

		SteadyClockTimePoint start1 = steady_clock::now();
		for (int i = 0; i < CAP; i++)
		{
			Q1.Push(a);
		}
		SteadyClockTimePoint end1 = steady_clock::now();

		SteadyClockTimePoint start3 = steady_clock::now();
		int mySum = 0;
		for (int i = 0; i < CAP; i++)
		{
			try
			{
				mySum += Q1.Peek();
			}
			catch (const std::exception &e)
			{
				std::cerr << "exeption: " << e.what() << "\n";
			}
			try
			{
				Q1.Pop();
			}
			catch (const std::exception &e)
			{
				std::cerr << "exeption: " << e.what() << "\n";
			}
		}
		SteadyClockTimePoint end3 = steady_clock::now();

		SteadyClockTimePoint endtot1 = steady_clock::now();

		SteadyClockTimePoint starttot2 = steady_clock::now();

		SteadyClockTimePoint start2 = steady_clock::now();
		for (int i = 0; i < CAP; i++)
		{
			Q2.push(a);
		}
		SteadyClockTimePoint end2 = steady_clock::now();

		SteadyClockTimePoint start4 = steady_clock::now();
		int stdSum = 0;
		for (int i = 0; i < CAP; i++)
		{
			stdSum += Q2.front();
			Q2.pop();
		}
		SteadyClockTimePoint end4 = steady_clock::now();

		SteadyClockTimePoint endtot2 = steady_clock::now();

		std::cout << "\nsum of my Queue" << mySum << "\n";
		std::cout << "sum of std Queue" << stdSum << "\n\n";

		std::cout << duration_cast<microseconds>(end1 - start1).count() << ": microsec my queue on int" << std::endl;
		std::cout << duration_cast<microseconds>(end2 - start2).count() << ": microsec std queue on int" << std::endl;
		std::cout << duration_cast<microseconds>(end3 - start3).count() << ": microsec my queue to sum" << std::endl;
		std::cout << duration_cast<microseconds>(end4 - start4).count() << ": microsec std queue to sum" << std::endl;
		std::cout << duration_cast<microseconds>(endtot1 - starttot1).count() << ": microsec total time my" << std::endl;
		std::cout << duration_cast<microseconds>(endtot2 - starttot2).count() << ": microsec total time std" << std::endl
				  << std::endl;
#pragma endregion

#pragma region stack_int
		SteadyClockTimePoint starttot3 = steady_clock::now();
		SteadyClockTimePoint start5 = steady_clock::now();
		for (int i = 0; i < CAP; i++)
		{
			S1.Push(a);
		}
		SteadyClockTimePoint end5 = steady_clock::now();

		SteadyClockTimePoint start7 = steady_clock::now();
		mySum = 0;
		for (int i = 0; i < CAP; i++)
		{
			mySum += S1.Peek();
			S1.Pop();
		}
		SteadyClockTimePoint end7 = steady_clock::now();
		SteadyClockTimePoint endtot3 = steady_clock::now();

		SteadyClockTimePoint starttot4 = steady_clock::now();
		SteadyClockTimePoint start6 = steady_clock::now();
		for (int i = 0; i < CAP; i++)
		{
			S2.push(a);
		}
		SteadyClockTimePoint end6 = steady_clock::now();

		SteadyClockTimePoint start8 = steady_clock::now();
		stdSum = 0;
		for (int i = 0; i < CAP; i++)
		{
			stdSum += S2.top();
			S2.pop();
		}
		SteadyClockTimePoint end8 = steady_clock::now();

		SteadyClockTimePoint endtot4 = steady_clock::now();

		std::cout << "\nsum of my stack" << mySum << "\n";
		std::cout << "sum of std stack" << stdSum << "\n\n";

		std::cout << duration_cast<microseconds>(end5 - start5).count() << ": microsec my stack on int" << std::endl;
		std::cout << duration_cast<microseconds>(end6 - start6).count() << ": microsec std stack on int" << std::endl;
		std::cout << duration_cast<microseconds>(end7 - start7).count() << ": microsec my stack to sum" << std::endl;
		std::cout << duration_cast<microseconds>(end8 - start8).count() << ": microsec std stack to sum" << std::endl;
		std::cout << duration_cast<microseconds>(endtot3 - starttot3).count() << ": microsec total time my" << std::endl;
		std::cout << duration_cast<microseconds>(endtot4 - starttot4).count() << ": microsec total time std" << std::endl
				  << std::endl;
#pragma endregion

#pragma region queue string
		SteadyClockTimePoint start9 = steady_clock::now();
		while (str_s1 >> temp)
		{
			Q3.Push(temp);
		}

		SteadyClockTimePoint end9 = steady_clock::now();

		SteadyClockTimePoint start10 = steady_clock::now();
		while (str_s2 >> temp)
		{
			Q4.push(temp);
		}

		SteadyClockTimePoint end10 = steady_clock::now();
		std::cout << duration_cast<microseconds>(end9 - start9).count() << ": microsec my queue on string" << std::endl;
		std::cout << duration_cast<microseconds>(end10 - start10).count() << ": microsec std queue on string" << std::endl;
#pragma endregion

#pragma region try2
		try
		{
			Q1.Pop();
		}
		catch (const std::exception &e)
		{
			std::cerr << "exeption: " << e.what() << "\n";
		}
		try
		{
			Q1.Peek();
		}
		catch (const std::exception &e)
		{
			std::cerr << "exeption: " << e.what() << "\n";
		}

		try
		{
			S1.Pop();
		}
		catch (const std::exception &e)
		{
			std::cerr << "exeption: " << e.what() << "\n";
		}
		try
		{
			S1.Peek();
		}
		catch (const std::exception &e)
		{
			std::cerr << "exeption: " << e.what() << "\n";
		}
#pragma endregion
	
	}
	MemoryLeakChecker::DumpInformation();
	getchar();
	return 0;
}