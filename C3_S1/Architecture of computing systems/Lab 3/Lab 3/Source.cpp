#include <iostream>
#include <omp.h>
#include <array>
#include <ctime>

void task_1()
{
	const size_t size = 10;

	std::array<int, size> A;
	std::array<int, size> B;
	std::array<int, size> C;

	for (int& x : A)
	{
		x = rand();
	}

	for (int& x : B)
	{
		x = rand();
	}

#pragma omp parallel for shared(A, B, C), num_threads(2)
	for (int i = 0; i < A.size(); i++)
	{
		C[i] = A[i] + B[i];
		printf("ThreadId: %d, Element id: %d\n", omp_get_thread_num(), i);
		printf("A[%d] + B[%d] = %d + %d = %d\n", i, i, A[i], B[i], C[i]);
	}
}

void task_2()
{
	const int size = 100;
	std::array<int, size> A;
	std::array<int, size> B;

	for (int& x : A)
	{
		x = rand();
	}

	for (int& x : B)
	{
		x = rand();
	}

	uint64_t sum = 0;

#pragma omp parallel for shared(A, B) num_threads(4) reduction(+:sum)
	for (int i = 0; i < 100; ++i)
	{
		sum += A[i] * B[i];
	}

	std::cout << "Result: " << sum << '\n';

	sum = 0;

	for (int i = 0; i < 100; ++i)
	{
		sum += A[i] * B[i];
	}

	std::cout << "Result: " << sum << '\n';

}

void task_3()
{
	const size_t size = 8;

	int arr[size][size];

	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			arr[i][j] = rand() % 10;
		}
	}

	int vector[size];

	for (size_t i = 0; i < size; ++i)
	{
		vector[i] = rand() % 10;
	}

	int new_vector[size];

	omp_set_num_threads(2);

#pragma omp parallel for
	for (int i = 0; i < size; ++i)
	{
		int temp = 0;
		for (int j = 0; j < size; ++j)
		{
			temp += arr[i][j] * vector[j];
		}
		printf("ThreadId: %d\tElementId: %d\tElementVal: %d\n", omp_get_thread_num(), i, temp);
		new_vector[i] = temp;
	}

	std::cout << "Result vector: [";


	for (size_t i = 0; i < size; ++i)
	{
		std::cout << new_vector[i] << " ";
	}

	std::cout << "]^T\n\n";

	for (size_t i = 0; i < size; ++i)
	{
		int temp = 0;
		for (size_t j = 0; j < size; ++j)
		{
			temp += arr[i][j] * vector[j];
		}
		new_vector[i] = temp;
	}

	std::cout << "Result vector: [";


	for (size_t i = 0; i < size; ++i)
	{
		std::cout << new_vector[i] << " ";
	}

	std::cout << "]^T\n\n";
}

void task_4()
{
#pragma omp parallel for ordered
		for (int i = 1; i <= 10; i++)
		{
#pragma omp ordered
			for (int j = 1; j <= 10; j++)
			{
				printf("%d * %d = %d\t", j, i, i * j);
			}
			printf("\n");
		}
}

void test()
{
	int sum = 0;
	int threads = 1606;
#pragma omp parallel for num_threads(threads) reduction(+:sum)
	for (int i = 0; i < threads; ++i)
		sum = 1;

	std::cout << sum;
}

int main()
{
#ifdef _OPENMP
	std::cout << "OpenMP is supported\n";
#endif // _OPENMP



	srand(std::time(nullptr));
	//task_1();
	//task_2();
	//task_3();
	//task_4();

	test();
}