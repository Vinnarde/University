#include <array>
#include <omp.h>
#include <iostream>
#include <cstdint>
#include <thread>
#include <random>

void task_1()
{
	printf_s("\nThis is the output of program #1!\n\n");
	constexpr int_fast32_t numOfIterations{ INT32_MAX };

	double firstNum{};
	double secondNum{};
	std::cout << "Type first floating-point number: ";
	std::cin >> firstNum;
	std::cout << "Type second floating-point number: ";
	std::cin >> secondNum;

	volatile double a{ firstNum };
	volatile double b{ secondNum };


	double startPoint{ omp_get_wtime() };

	for (int_fast32_t i = 0; i < numOfIterations; ++i)
	{
		a* b;
	}

	double endPoint{ omp_get_wtime() };

	std::cout << "\nSequential method.\n";
	std::cout << "\tTime taken: " << endPoint - startPoint << " seconds.\n";

	std::cout << "Parallel method.\n";
	startPoint = omp_get_wtime();
#pragma omp parallel
	{

#pragma omp for
		for (int_fast32_t i = 0; i < numOfIterations; ++i)
		{
			a* b;
		}
	}
	endPoint = omp_get_wtime();
	std::cout << "\tTime taken: " << endPoint - startPoint << " seconds.\n";

}

void task_2()
{
	printf_s("\nThis is the output of program #2!\n\n");
	const auto processorCount = std::thread::hardware_concurrency();


	double startPoint{ omp_get_wtime() };

#pragma omp parallel num_threads(processorCount)
	{

	}
	double endPoint{ omp_get_wtime() };

	std::cout << "\tTime taken: " << endPoint - startPoint << " seconds.\n";
}

void task_3()
{
	printf_s("\nThis is the output of program #3!\n\n");
#pragma omp parallel num_threads(3)
	{
		printf_s("\tThreadId: %d. Beginning.\n",
			omp_get_thread_num());

		//#pragma omp barrier
		//		{}

#pragma omp single	
		{
			printf_s("\tThreadId: %d. Single thread.\n",
				omp_get_thread_num());
		}
		// implicit barrier

		printf_s("\tThreadId: %d. End.\n",
			omp_get_thread_num());
	}
}
void task_3_nowait()
{
	printf_s("\nThis is the output of program #3 nowait version!\n\n");
#pragma omp parallel num_threads(3)
	{
		printf_s("\tThreadId: %d. Beginning.\n",
			omp_get_thread_num());

		//#pragma omp barrier
		//		{}

#pragma omp single nowait
		{
			printf_s("\tThreadId: %d. Single thread.\n",
				omp_get_thread_num());
		}
		// no barrier

		printf_s("\tThreadId: %d. End.\n",
			omp_get_thread_num());
	}
}

void task_4()
{
	printf_s("\nThis is the output of program #4!\n\n");
#pragma omp parallel num_threads(3)
	{
		printf_s("\tThreadId: %d. Begin\n", omp_get_thread_num());

#pragma omp barrier
		{}

#pragma omp master
		{
			printf_s("\t\tMaster thread. %d. \n", omp_get_thread_num());
		}

#pragma omp barrier 
		{}

		printf_s("\tThreadId: %d. Middle\n", omp_get_thread_num());

#pragma omp barrier 
		{}

#pragma omp master
		{
			printf_s("\t\tMaster thread. %d. \n", omp_get_thread_num());
		}

#pragma omp barrier 
		{}

		printf_s("\tThreadId: %d. End\n", omp_get_thread_num());
	}
}

void task_5()
{
	printf_s("\nThis is the output of program #5!\n\n");

	int n{ 10 };

	printf_s("Sequential area. n = %d\n", n);
	
#pragma  omp parallel num_threads(2), firstprivate(n)
	{
		printf_s("\tParallel area. ThreadId: %d. n = %d\n",
			omp_get_thread_num(), n);

		n = omp_get_thread_num();

		printf_s("\tParallel area. ThreadId: %d. n = %d\n",
			omp_get_thread_num(), n);
	}
	
	printf_s("Sequential area. n = %d\n", n);

}

void task_6()
{
	printf_s("\nThis is the output of program #6!\n\n");
	std::array<int, 5> arr{};

	std::cout << "Array before parallel area: \n";
	for (size_t i = 0; i < arr.size(); ++i)
	{
		std::cout << "\tarr[" << i << "] = " << arr[i] << '\n';
	}

#pragma omp parallel shared(arr), num_threads(2)
	{
		arr.at(omp_get_thread_num()) = 1;
	}
	
	std::cout << "\nArray after parallel area: \n";
	for (size_t i = 0; i < arr.size(); ++i)
	{
		std::cout << "\tarr[" << i << "] = " << arr[i] << '\n';
	}
}

void task_7()
{
	printf_s("\nThis is the output of program #7!\n\n");
	auto reduction{ 0 };

	omp_set_dynamic(true);
#pragma omp parallel reduction(+:reduction)
	{
		reduction = 1;
		printf_s("\tThreadId: %d, var = %d\n",
			omp_get_thread_num(), reduction);
	}
	printf_s("\nvar = %d\n", reduction);
}

void task_8()
{
	printf_s("\nThis is the output of program #8!\n\n");

	auto sum{ 0 };

#pragma omp parallel reduction(+:sum) num_threads(4)
	{
		sum = omp_get_thread_num();
		printf_s("\tThreadId: %d, var = %d\n", omp_get_thread_num(), sum);
	}
	printf_s("\nvar = %d\n", sum);
}

int main(int argc, char* argv[])
{
#ifdef _OPENMP
	printf_s("OpenMP is supported!\n");
#endif
	//task_1();
	//task_2();
	//task_3();
	//task_3_nowait();
	//task_4();
	//task_5();
	//task_6();
	task_7();
	task_8();
	
	return 0;
}
