#include <iostream>
#include <thread>
#include "ThreadPool.hpp"
#include <atomic>


int main(int argc, char* argv[])
{
	std::atomic<int> counter(0);

	auto task_1 = Threading::DefaultThreadPool::submitJob([&counter]()
	{
		for (int i = 0; i < 10; i++)
		{
			counter++;
		}
	
	});


	auto task_2 = Threading::DefaultThreadPool::submitJob([&counter]()
	{
		for (int i = 0; i < 10; i++)
		{
			counter++;
		}

	});

	task_1.get();
	task_2.get();

	std::cout << "Counter = " << counter << std::endl;
	getchar();


	return 0;
}