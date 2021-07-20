#include <omp.h>
#include <iostream>
#include <thread>

void task_1()
{
	printf_s("\nThis is the output of program #1!\n\n");

	printf_s("\tThis is sequential area #1\n");

	const auto processor_count = std::thread::hardware_concurrency();

#pragma omp parallel num_threads(processor_count)
	{
		printf_s("\t\tParallel area. ThreadId: %d\n",
			omp_get_thread_num());
	}

	printf_s("\tThis is sequential area #2\n");
}

void task_2()
{
	printf_s("\nThis is the output of program #2!\n\n");

	const auto processor_count = std::thread::hardware_concurrency();

#pragma omp parallel num_threads(processor_count)
	{
		if (omp_get_thread_num() == 0)
		{
			printf_s("\tMaster thread. Total number of threads: %d\n",
				omp_get_num_threads());
		}
		else
		{
			printf_s("\t\tParallel area. ThreadId: %d\n",
				omp_get_thread_num());
		}
	}
}

void task_3()
{
	printf_s("\nThis is the output of program #3!\n\n");

#pragma omp parallel
	{
		printf_s("\tParallel area 1. ThreadId: %d\n",
			omp_get_thread_num());
	}

#pragma omp parallel num_threads(3)
	{
		printf_s("\t\tParallel area 2. ThreadId: %d\n",
			omp_get_thread_num());
	}

	omp_set_num_threads(4);
#pragma omp parallel
	{
		printf_s("\tParallel area 3. ThreadId: %d\n",
			omp_get_thread_num());
	}
}

void task_4_non_dynamic()
{
	printf_s("\nThis is the output of program #4 non-dynamic version!\n\n");

	omp_set_dynamic(false);
#pragma omp parallel num_threads(128)
	{
#pragma omp master
		printf_s("\tThis is master thread. Total number of threads: %d\n",
			omp_get_num_threads());
	}
}

void task_4_dynamic()
{
	printf_s("\nThis is the output of program #4 dynamic version!\n\n");
	omp_set_dynamic(true);
#pragma omp parallel num_threads(128)
	{
#pragma omp master
		printf_s("\tThis is master thread. Total number of threads: %d\n",
			omp_get_num_threads());
	}
}

void task_5(int argc, char* argv[])
{
	printf_s("\nThis is the output of program #5!\n\n");
	if (argc <= 1)
		printf_s("\tNo arguments were provided!\n");
	else if (strcmp("serial", argv[1]) == 0)
	{
		printf_s("\tThis is sequential area!\n");
	}
	else
	{
		bool condition = strcmp("parallel", argv[1]) == 0;
		const auto processor_count = std::thread::hardware_concurrency();
#pragma omp parallel num_threads(processor_count) if(condition)
		{
			printf_s("\tThis is parallel area! ThreadId: %d\n",
				omp_get_thread_num());
		}
	}
}

int main(int argc, char* argv[])
{
#ifdef _OPENMP
	printf_s("OpenMP is supported!\n");
#endif

	char ch{};

	while (ch < '1' || ch > '5')
	{
		printf_s("Type program number(1 - 5): ");
		ch = getchar();

		while (std::isspace(ch))
			ch = getchar();
	}

	switch (ch)
	{
	case '1':
		task_1();
		break;
	case '2':
		task_2();
		break;
	case '3':
		task_3();
		break;
	case '4':
		task_4_non_dynamic();
		task_4_dynamic();
		break;
	case '5':
		task_5(argc, argv);
		break;
	default:
		printf_s("Something went wrong! Terminating process.\n");
		exit(EXIT_FAILURE);
	}

}
