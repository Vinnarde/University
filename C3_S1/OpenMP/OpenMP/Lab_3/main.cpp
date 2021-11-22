#include <chrono>
#include <functional>
#include <omp.h>
#include <iostream>
#include <random>

auto seed = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine generator(seed);
std::uniform_int_distribution<int_fast32_t> distribution(0, 10);
auto generateRandomNumber = std::bind(distribution, std::ref(generator));

#pragma optimize ("", off)
void task_1()
{
	printf_s("\nThis is the output of program #1!\n\n");

	constexpr size_t size{ 16 };

	std::vector<int> A(size);
	std::vector<int> B(size);
	std::vector<int> C(size);

	std::for_each(A.begin(), A.end(), [](auto& x) { x = generateRandomNumber(); });
	std::for_each(B.begin(), B.end(), [](auto& x) { x = generateRandomNumber(); });

	double startPoint{ omp_get_wtime() };

	omp_set_dynamic(true);
#pragma omp parallel shared(A, B, C), num_threads(4)
	{
#pragma omp for
		for (int_fast32_t i = 0; i < size; ++i)
		{
			C[i] = A[i] + B[i];
			printf_s("\tThreadId: %d, Element id: %d\n", omp_get_thread_num(), i);
			printf_s("\tA[%d] + B[%d] = %d + %d = %d\n", i, i, A[i], B[i], C[i]);
		}
	}

	double endPoint{ omp_get_wtime() };

	std::cout << "Time taken: " << endPoint - startPoint << " seconds.\n";
}

void task_2()
{
	printf_s("\nThis is the output of program #2!\n\n");

	constexpr size_t size{ 8 };
	std::vector<int> A(size);
	std::vector<int> B(size);

	std::for_each(A.begin(), A.end(),
		[](auto& x) { x = generateRandomNumber(); });
	std::for_each(B.begin(), B.end(),
		[](auto& x) { x = generateRandomNumber(); });

	uint_fast64_t sum{ 0 };
	omp_set_dynamic(true);
#pragma omp parallel shared(A, B) reduction(+:sum), num_threads(4)
	{
#pragma omp for
		for (int_fast32_t i = 0; i < size; ++i)
		{
			sum += static_cast<uint_fast64_t>(A[i]) * B[i];
			printf_s("\tThreadId: %d, Element id: %d\n", omp_get_thread_num(), i);
			printf_s("\tA[%d] * B[%d] = %d * %d = %d\n", i, i, A[i], B[i], A[i] * B[i]);
		}
	}

	std::cout << "\tReduction in parallel area result: " << sum << '\n';

	sum = 0;

	for (int_fast32_t i = 0; i < size; ++i)
	{
		sum += static_cast<int_fast64_t>(A[i]) * B[i];
	}

	std::cout << "\tSequential area result: " << sum << '\n';
}

void task_3()
{
	printf_s("\nThis is the output of program #3!\n\n");

	constexpr size_t size = 3;

	std::vector<std::vector<int>> matrix(size, std::vector<int>(size));

	std::cout << "\tMatrix:\n\t";
	for (auto& row : matrix)
	{
		for (auto& elem : row)
		{
			elem = generateRandomNumber();
			std::cout << elem << ' ';
		}
		std::cout << "\n\t";
	}
	std::cout << '\n';

	std::cout << "\tVector:\n\t";
	std::vector<int> vector(size);
	std::for_each(vector.begin(), vector.end(),
		[](auto& x)
		{
			x = generateRandomNumber(); std::cout << x << ' ';
		});
	std::cout << '\n';
	std::vector<int_fast64_t> new_vector(size);

	omp_set_dynamic(true);
#pragma omp parallel shared(matrix, vector)
	{
#pragma omp for
		for (int_fast32_t i = 0; i < size; ++i)
		{
			int_fast64_t temp = 0;

			for (size_t j = 0; j < size; ++j)
			{
				temp += matrix[i][j] * vector[j];
			}
			printf_s("\tThreadId: %d, ElementId: %d, ElementValue: %llu\n",
				omp_get_thread_num(), i, temp);

			new_vector[i] = temp;
		}
	}
	std::cout << "\nResult vector: \n";
	for (auto x : new_vector)
	{
		std::cout << '\t' << x << '\n';
	}
}

void task_4()
{
	printf_s("\nThis is the output of program #4!\n\n");

	omp_set_dynamic(true);
#pragma omp parallel 
	{
#pragma omp for ordered
		for (int i = 1; i <= 10; i++)
		{
#pragma omp ordered
			for (int j = 1; j <= 10; j++)
			{
				printf_s("%dx%d=%d\t", j, i, i * j);
			}
			printf_s("\n");
		}
	}
}

int main(int argc, char* argv[])
{
#ifdef _OPENMP
	printf_s("OpenMP is supported!\n");
#endif


	//task_1();
	//task_2();
	//task_3();
	task_4();
}
