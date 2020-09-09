#include <iostream>
#include <omp.h>
#include <chrono>

class Timer
{
private:
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<clock_t> m_beg;

public:
	Timer() : m_beg(clock_t::now())
	{
	}

	void reset()
	{
		m_beg = clock_t::now();
	}

	double elapsed() const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};

void task_1()
{
	printf("Sequantial region 1\n");

#pragma omp parallel
	{
		printf("Parallel region\n");
	}

	printf("Sequantial region 2\n");

}

void task_2()
{
	omp_set_num_threads(8);

#pragma omp parallel
	{
		int ThreadId = omp_get_thread_num();
			
		if (ThreadId == 0)
			printf("I'm master!!! Number of my slaves: %d\n", omp_get_num_threads());
		else
			printf("I'm thread #%d\n", ThreadId);
	}
}

void task_3()
{
#pragma omp parallel 
	{
		printf("[First region]\n");
	}

#pragma omp parallel num_threads(3)
	{
		printf("[Second region]\n");
	}

	omp_set_num_threads(4);
#pragma omp parallel 
	{
		printf("[Third region]\n");
	}
}

void task_4()
{
	omp_set_num_threads(128);
	omp_set_dynamic(0);

	printf("\nomp_set_dynamic(0);\n\n");

#pragma omp parallel
	{
		int ThreadId = omp_get_thread_num();

		if (ThreadId == 0)
			printf("I'm master!!! Number of my slaves: %d\n", omp_get_num_threads());
		else
			printf("I'm thread #%d\n", ThreadId);
	}

	printf("\nomp_set_dynamic(1);\n\n");
	omp_set_dynamic(1);

#pragma omp parallel
	{
		int ThreadId = omp_get_thread_num();

		if (ThreadId == 0)
			printf("I'm master!!! Number of my slaves: %d\n", omp_get_num_threads());
		else
			printf("I'm thread #%d\n", ThreadId);
	}
}

int main(int argc, char** argv)
{
#ifdef _OPENMP
	printf("OPENMP is supported!\n");
#endif // _OPENMP

	//task_1();
	task_4();

}