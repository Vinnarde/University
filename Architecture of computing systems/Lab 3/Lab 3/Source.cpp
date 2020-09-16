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

	int sum = 0;

	//#pragma omp parallel for shared(A, B) num_threads(4) reduction(+:sum)
	//	for (int i = 0; i < 100; ++i)
	//	{
	//		//sum = A[i] * B[i];
	//		sum = i * i;
	//	}

	sum = 0;
	int i;
#pragma omp parallel for num_threads(4), reduction(+:sum) 
	for (i = 1; i <= 100; i += 1)
	{
		int temp = i * i;
		sum += temp;
	}

	std::cout << "Result: " << sum << '\n';

	sum = 0;

	for (int i = 1; i <= 100; ++i)
	{
		sum += i * i;
	}

	std::cout << "Result: " << sum << '\n';

}

int main()
{
#ifdef _OPENMP
	std::cout << "OpenMP is supported\n";
#endif // _OPENMP



	srand(std::time(nullptr));
	//task_1();

	task_2();
}