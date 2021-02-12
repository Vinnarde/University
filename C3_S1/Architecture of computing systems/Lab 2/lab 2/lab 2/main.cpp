#include <iostream>
#include <omp.h>

#include <array>

void task_1()
{
	double a, b;
	double result = 1;

	std::cout << "Enter a: ";
	std::cin >> a;
	std::cout << "Enter b: ";
	std::cin >> b;

	double t_0 = omp_get_wtime();
	for (int64_t i = 0; i < UINT32_MAX; ++i)
	{
		result += a;
	}
	printf("Time elapsed: %lf\n", omp_get_wtime() - t_0);
	printf("Result: %lf\n\n", result);

	omp_set_num_threads(8);
	result = 1;
	t_0 = omp_get_wtime();
	
#pragma omp parallel for

	for (int64_t i = 0; i < UINT32_MAX; ++i)
	{
		result += a;
	}

	printf("Time elapsed: %lf\n", omp_get_wtime() - t_0);
	printf("Result: %lf\n\n", result);
	printf("UINT32_MAX/8 %d\n\n", UINT32_MAX / 8);
}


void task_2()
{
	const double t_0 = omp_get_wtime();

#pragma omp parallel num_threads(8)
	{
	}

	const double t_1 = omp_get_wtime();

	std::cout << "Time of creating parallel region is " << t_1 - t_0 << std::endl;
}

void task_3()
{
#pragma omp parallel num_threads(3)
	{
		printf("Thread number %d. Begin\n", omp_get_thread_num());

#pragma omp barrier
		{}

#pragma omp single 
		{
			printf("Thread number %d. Single thread\n", omp_get_thread_num());
		}

		printf("Thread number %d. End\n", omp_get_thread_num());
	}
	printf("\n\n\n");

}

void task_3_nowait()
{
#pragma omp parallel num_threads(4)
	{
		printf("Thread number %d. Begin\n", omp_get_thread_num());

#pragma omp single nowait
		{
			printf("Thread number %d. Single thread\n", omp_get_thread_num());
		}

		printf("Thread number %d. End\n", omp_get_thread_num());
	}

}

void task_4()
{
#pragma omp parallel num_threads(3)
	{
		printf("Thread number %d. Begin\n", omp_get_thread_num());

#pragma omp barrier
		{}

#pragma omp master
		printf("Master thread. %d. \n", omp_get_thread_num());

#pragma omp barrier
		{}

		printf("Thread number %d. Middle\n", omp_get_thread_num());

#pragma omp barrier 
		{}
#pragma omp master
		printf("Master thread. %d. \n", omp_get_thread_num());

#pragma omp barrier
		{}
		
		printf("Thread number %d. End\n", omp_get_thread_num());
	}
}

void task_5()
{
	int n = 10;

	printf("Serial region. n = %d\n\n", n);

#pragma omp parallel num_threads(2), firstprivate(n)
	{
		printf("Parallel region. ThreadId: %d. n = %d\n\n", omp_get_thread_num(), n);

		n = omp_get_thread_num();

		printf("Parallel region. ThreadId: %d. n = %d\n\n", omp_get_thread_num(), n);
	}

	printf("Serial region. n = %d\n\n", n);
}

void task_6()
{
	std::array<int, 5> arr{};

	for (size_t i = 0; i < arr.size(); ++i)
	{
		std::cout << "arr[" << i << "] = " << arr[i] << '\n';
	}

#pragma omp parallel shared(arr), num_threads(2)
	{
		arr.at(omp_get_thread_num()) = 1;
	}

	for (size_t i = 0; i < arr.size(); ++i)
	{
		std::cout << "arr[" << i << "] = " << arr[i] << '\n';
	}
}

void task_7()
{
	auto reduction = 0;

	omp_set_dynamic(1);

#pragma omp parallel reduction(+:reduction)
	{
		reduction = 1;
		printf("ThreadId: %d, var = %d\n", omp_get_thread_num(), reduction);
	}
	printf("\nvar = %d\n", reduction);
}

void task_8()
{
	auto sum = 0;

#pragma omp parallel reduction(+:sum) num_threads(4)
	{
		sum = omp_get_thread_num();
		printf("ThreadId: %d, var = %d\n", omp_get_thread_num(), sum);
	}
	printf("\nvar = %d\n", sum);
}

int main()
{

#ifdef _OPENMP
	printf("OpenMP is supported!\n\n");
#endif // 

	//task_3();
	//task_3_nowait();

	//task_4();

	task_5();

	//task_6();
}