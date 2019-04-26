#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <chrono>
#include <exception>
#include <vector>
#include <queue>
#include <stack>
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
		const int CAP = 10000;
		std::vector<int> rngInt;
		for (size_t i = 0; i < CAP; i++)
		{
			rngInt.push_back(rand() % 100 + 1);
		}

		std::vector<SteadyClockTimePoint> startClock;
		std::vector<SteadyClockTimePoint> stopClock;

		std::vector<SteadyClockTimePoint> startClockTot;
		std::vector<SteadyClockTimePoint> stopClockTot;

		std::vector<long long> time;
		std::vector<long long> timeTotal;

		Queue<int> Queue_int;
		std::queue<int> std_Queue_int;

		Stack<int> Stack_int;
		std::stack<int> std_Stack_int;

		Queue<std::string> Queue_string;
		std::queue<std::string> std_Queue_string;

		Stack<std::string> Stack_string;
		std::stack<std::string> std_Stack_string;

		int mySum;
		int stdSum;
		std::string myStrSum;
		std::string stdStrSum;

		std::ifstream in;
		in.open("Resources/Lab4_TestFile", std::ifstream::in);

		std::string str;
		std::string temp;
		std::getline(in, str, '\0');
		std::stringstream str_s1(str);
		std::stringstream str_s2(str);
		std::stringstream str_s3(str);
		std::stringstream str_s4(str);
#pragma endregion

#pragma region try1
		try
		{
			Queue_int.Pop();
		}
		catch (const std::exception &e)
		{
			std::cerr << "exeption: " << e.what() << "\n";
		}
		try
		{
			Queue_int.Peek();
		}
		catch (const std::exception &e)
		{
			std::cerr << "exeption: " << e.what() << "\n";
		}

		try
		{
			Stack_int.Pop();
		}
		catch (const std::exception &e)
		{
			std::cerr << "exeption: " << e.what() << "\n";
		}
		try
		{
			Stack_int.Peek();
		}
		catch (const std::exception &e)
		{
			std::cerr << "exeption: " << e.what() << "\n";
		}
#pragma endregion

#pragma region queue_int
		startClockTot.push_back(steady_clock::now());//0t

		//load my queue with int
		startClock.push_back(steady_clock::now());//1
		for (int i = 0; i < CAP; i++)
		{
			Queue_int.Push(rngInt[i]);
		}
		stopClock.push_back(steady_clock::now());//1

		//sum my queue
		startClock.push_back(steady_clock::now());//2
		mySum = 0;
		for (int i = 0; i < CAP; i++)
		{
			try
			{
				mySum += Queue_int.Peek();
			}
			catch (const std::exception &e)
			{
				std::cerr << "exeption: " << e.what() << "\n";
				i = CAP;
			}
			try
			{
				Queue_int.Pop();
			}
			catch (const std::exception &e)
			{
				std::cerr << "exeption: " << e.what() << "\n";
			}
		}
		stopClock.push_back(steady_clock::now());//2

		stopClockTot.push_back(steady_clock::now());//0t



		startClockTot.push_back(steady_clock::now());//1t

		//load std queue with int
		startClock.push_back(steady_clock::now());//3
		for (int i = 0; i < CAP; i++)
		{
			std_Queue_int.push(rngInt[i]);
		}
		stopClock.push_back(steady_clock::now());//3

		//sum std queue
		startClock.push_back(steady_clock::now());//4
		stdSum = 0;
		for (int i = 0; i < CAP; i++)
		{
			stdSum += std_Queue_int.front();
			std_Queue_int.pop();
		}
		stopClock.push_back(steady_clock::now());//4

		stopClockTot.push_back(steady_clock::now());//1t
#pragma endregion

#pragma region stack_int
		startClockTot.push_back(steady_clock::now());//2t;

		//load my stack with int
		startClock.push_back(steady_clock::now());//5
		for (int i = 0; i < CAP; i++)
		{
			Stack_int.Push(rngInt[i]);
		}
		stopClock.push_back(steady_clock::now());//5

		//sum my stack
		startClock.push_back(steady_clock::now());//6
		mySum = 0;
		for (int i = 0; i < CAP; i++)
		{
			mySum += Stack_int.Peek();
			Stack_int.Pop();
		}
		stopClock.push_back(steady_clock::now());//6

		stopClockTot.push_back(steady_clock::now());//2t



		startClockTot.push_back(steady_clock::now());//3t

		//load std stack with int
		startClock.push_back(steady_clock::now());//7
		for (int i = 0; i < CAP; i++)
		{
			std_Stack_int.push(rngInt[i]);
		}
		stopClock.push_back(steady_clock::now());//7

		//sum std stack
		startClock.push_back(steady_clock::now());//8
		stdSum = 0;
		for (int i = 0; i < CAP; i++)
		{
			stdSum += std_Stack_int.top();
			std_Stack_int.pop();
		}
		stopClock.push_back(steady_clock::now());//8

		stopClockTot.push_back(steady_clock::now());//3t

#pragma endregion

#pragma region queue string
		startClockTot.push_back(steady_clock::now());//4t;

		//load my queue with str
		startClock.push_back(steady_clock::now());//9
		while (str_s1 >> temp)
		{
			Queue_string.Push(temp);
		}
		stopClock.push_back(steady_clock::now());//9

		//sum my queue
		startClock.push_back(steady_clock::now());//10
		myStrSum = "";
		for (int i = 0; i < CAP && Queue_string.Size() > 0; i++)
		{
				myStrSum += Queue_string.Peek();
				Queue_string.Pop();

		}
		stopClock.push_back(steady_clock::now());//10

		stopClockTot.push_back(steady_clock::now());//4t



		startClockTot.push_back(steady_clock::now());//5t;

		//load std queue with str
		startClock.push_back(steady_clock::now());//11
		while (str_s2 >> temp)
		{
			std_Queue_string.push(temp);
		}
		stopClock.push_back(steady_clock::now());//11

		//sum std queue
		startClock.push_back(steady_clock::now());//12
		stdStrSum = "";
		for (int i = 0; i < CAP && std_Queue_string.size() > 0; i++)
		{
				stdStrSum += std_Queue_string.front();
				std_Queue_string.pop();
		}
		stopClock.push_back(steady_clock::now());//12

		stopClockTot.push_back(steady_clock::now());//5t

#pragma endregion

#pragma region stack_string
		startClockTot.push_back(steady_clock::now());//5t;

		startClock.push_back(steady_clock::now());//13
		while (str_s3 >> temp)
		{
			Stack_string.Push(temp);
		}
		stopClock.push_back(steady_clock::now());//13

		//sum my stack
		startClock.push_back(steady_clock::now());//14
		myStrSum = "";
		for (int i = 0; i < CAP && Stack_string.Size() > 0; i++)
		{
			myStrSum += Stack_string.Peek();
			Stack_string.Pop();

		}
		stopClock.push_back(steady_clock::now());//14

		stopClockTot.push_back(steady_clock::now());//6t



		startClockTot.push_back(steady_clock::now());//7t;

		startClock.push_back(steady_clock::now());//15
		while (str_s4 >> temp)
		{
			std_Stack_string.push(temp);
		}
		stopClock.push_back(steady_clock::now());//15

		//sum std stack
		startClock.push_back(steady_clock::now());//16
		stdStrSum = "";
		for (int i = 0; i < CAP && std_Stack_string.size() > 0; i++)
		{
			stdStrSum += std_Stack_string.top();
			std_Stack_string.pop();
		}
		stopClock.push_back(steady_clock::now());//16

		stopClockTot.push_back(steady_clock::now());//7t
#pragma endregion

#pragma region utskrift
		for (size_t i = 0; i < startClock.size(); i++)
		{
			time.push_back(duration_cast<microseconds>(stopClock[i] - startClock[i]).count());
		}
		for (size_t i = 0; i < startClockTot.size(); i++)
		{
			timeTotal.push_back(duration_cast<microseconds>(stopClockTot[i] - startClockTot[i]).count());
		}
		//---------------Queue int---------------
		std::cout << "\nsum of my Queue: " << mySum << "\n";
		std::cout << time[0] << ": microsec my queue on int" << std::endl;
		std::cout << time[1] << ": microsec my queue to sum" << std::endl;
		std::cout << timeTotal[0] << ": microsec total time my queue" << std::endl << std::endl;

		std::cout << "sum of std Queue: " << stdSum << "\n";
		std::cout << time[2] << ": microsec std queue on int" << std::endl;
		std::cout << time[3] << ": microsec std queue to sum" << std::endl;
		std::cout << timeTotal[1] << ": microsec total time std queue" << std::endl << std::endl;

		//---------------Stack int---------------
		std::cout << "\nsum of my stack: " << mySum << "\n";
		std::cout << time[4] << ": microsec my stack on int" << std::endl;
		std::cout << time[5] << ": microsec my stack to sum" << std::endl;
		std::cout << timeTotal[2] << ": microsec total time my stack" << std::endl << std::endl;

		std::cout << "sum of std stack: " << stdSum << "\n";
		std::cout << time[6] << ": microsec std stack on int" << std::endl;
		std::cout << time[7] << ": microsec std stack to sum" << std::endl;
		std::cout << timeTotal[3] << ": microsec total time std stack" << std::endl << std::endl;

		//---------------Queue string---------------
		std::cout << "\nsum of my queue: " << "\n";
		std::cout << time[8] << ": microsec my queue on str" << std::endl;
		std::cout << time[9] << ": microsec my queue to sum" << std::endl;
		std::cout << timeTotal[4] << ": microsec total time my queue" << std::endl << std::endl;

		std::cout << "sum of std queue: " << "\n";
		std::cout << time[10] << ": microsec std queue on str" << std::endl;
		std::cout << time[11] << ": microsec std queue to sum" << std::endl;
		std::cout << timeTotal[5] << ": microsec total time std queue" << std::endl << std::endl;

		//---------------Stack string---------------
		std::cout << "\nsum of my stack: " << "\n";
		std::cout << time[12] << ": microsec my stack on str" << std::endl;
		std::cout << time[13] << ": microsec my stack to sum" << std::endl;
		std::cout << timeTotal[6] << ": microsec total time my stack" << std::endl << std::endl;

		std::cout << "sum of std stack: " <<"\n";
		std::cout << time[14] << ": microsec std stack on str" << std::endl;
		std::cout << time[15] << ": microsec std stack to sum" << std::endl;
		std::cout << timeTotal[7] << ": microsec total time std stack" << std::endl << std::endl;

#pragma endregion

#pragma region try2
		try
		{
			Queue_int.Pop();
		}
		catch (const std::exception &e)
		{
			std::cerr << "exeption: " << e.what() << "\n";
		}
		try
		{
			Queue_int.Peek();
		}
		catch (const std::exception &e)
		{
			std::cerr << "exeption: " << e.what() << "\n";
		}

		try
		{
			Stack_int.Pop();
		}
		catch (const std::exception &e)
		{
			std::cerr << "exeption: " << e.what() << "\n";
		}
		try
		{
			Stack_int.Peek();
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