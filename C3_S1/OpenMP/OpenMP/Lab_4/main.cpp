#include <iostream>
#include <omp.h>
#include <chrono>
#include <cmath>
#include <iomanip>

constexpr double leftBoundary{ 1.0 };
constexpr double rightBoundary{ 3.0 };

inline double f(const double x)
{
	return std::sin(1.0 / 3.0) * std::log(0.1 + x * x);
}

inline void printLine(const char* methodName, const double result,
	const double timeElapsed, const uint_fast64_t numOfIterations
)
{
	std::cout << std::left << std::setw(25) << std::setfill(' ') << methodName;
	std::cout << std::left << std::setprecision(12) << std::setw(20) << std::setfill(' ') << result;
	std::cout << std::left << std::setw(20) << std::setfill(' ') << timeElapsed;
	std::cout << std::left << std::setw(20) << std::setfill(' ') << numOfIterations;
	std::cout << '\n';
}

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

void left_rectangles(const double a = 1.0, const double b = 3.0, const double eps = 1e-7)
{
	int64_t num_of_steps = 1;
	double result = 0.0;
	double result_prev = result + 1.0;
	Timer t;
	uint64_t num_of_iterations = 0;

	while (std::abs(result - result_prev) > eps)
	{
		num_of_iterations += num_of_steps;
		result_prev = result;
		result = 0;

		const double intervalSize = (b - a) / num_of_steps;


		for (int64_t i = 0; i < num_of_steps; i++)
		{
			double x = a + intervalSize * (i);
			result += f(x);
		}
		result *= intervalSize;
		num_of_steps *= 2;

	}
	std::cout << "Time elapsed: " << t.elapsed() << '\n';
	std::cout.precision(10);
	std::cout << "Number of iterations: " << num_of_iterations << '\n';
	std::cout << "Left rectangles: " << result << "\n\n";

}

void leftRectangles(const double epsilon = 1e-7)
{
	int_fast64_t numOfSteps{ 2 };
	double result{ 0.0 };
	double previousResult{ 1.0 };
	uint_fast64_t numOfIterations{ 0 };

	Timer t;

	while (std::abs(result - previousResult) > epsilon)
	{
		numOfIterations += numOfSteps;
		previousResult = result;
		result = 0;

		const double intervalSize = (rightBoundary - leftBoundary) / numOfSteps;
		double x{};
		omp_set_dynamic(true);
#pragma omp parallel for private(x) reduction(+:result) 
		for (int_fast64_t i = 0; i < numOfSteps; ++i)
		{
			x = leftBoundary + intervalSize * i;
			result += f(x);
		}
		result *= intervalSize;
		numOfSteps *= 2;
	}
	printLine("Left rectangles", result, t.elapsed(), numOfIterations);
}

void rightRectangles(const double epsilon = 1e-7)
{
	int_fast64_t numOfSteps{ 2 };
	double result{ 0.0 };
	double previousResult{ 1.0 };
	uint_fast64_t numOfIterations{ 0 };

	Timer t;

	while (std::abs(result - previousResult) > epsilon)
	{
		numOfIterations += numOfSteps;
		previousResult = result;
		result = 0;

		const double intervalSize = (rightBoundary - leftBoundary) / numOfSteps;
		double x{};
		omp_set_dynamic(true);

#pragma omp parallel for private(x) reduction(+:result) 
		for (int_fast64_t i = 1; i <= numOfSteps; ++i)
		{
			x = leftBoundary + intervalSize * i;
			result += f(x);
		}
		result *= intervalSize;
		numOfSteps *= 2;
	}
	printLine("Right rectangles", result, t.elapsed(), numOfIterations);
}

void middleRectangles(const double epsilon = 1e-7)
{
	int_fast64_t numOfSteps{ 2 };
	double result{ 0.0 };
	double previousResult{ 1.0 };
	uint_fast64_t numOfIterations{ 0 };

	Timer t;

	while (std::abs(result - previousResult) > epsilon)
	{
		numOfIterations += numOfSteps;
		previousResult = result;
		result = 0;

		const double intervalSize = (rightBoundary - leftBoundary) / numOfSteps;
		double x{};
		omp_set_dynamic(true);
#pragma omp parallel for private(x) reduction(+:result) 
		for (int_fast64_t i = 0; i < numOfSteps; ++i)
		{
			x = leftBoundary + intervalSize * (i + 0.5);
			result += f(x);
		}
		result *= intervalSize;
		numOfSteps *= 2;
	}
	printLine("Middle rectangles", result, t.elapsed(), numOfIterations);
}

void trapezoidalRule(const double epsilon = 1e-7)
{
	int_fast64_t numOfSteps{ 2 };
	double result{ 0.0 };
	double previousResult{ 1.0 };
	uint_fast64_t numOfIterations{ 0 };

	Timer t;

	while (std::abs(result - previousResult) > epsilon)
	{
		numOfIterations += numOfSteps;
		previousResult = result;
		result = 0;

		const double intervalSize = (rightBoundary - leftBoundary) / numOfSteps;
		double x{}, xPrevious{};
		omp_set_dynamic(true);
#pragma omp parallel for private(x, xPrevious) reduction(+:result) 
		for (int_fast64_t i = 1; i <= numOfSteps; ++i)
		{
			x = leftBoundary + intervalSize * i;
			xPrevious = leftBoundary + intervalSize * (i - 1);
			result += f(x) + f(xPrevious);
		}
		result *= intervalSize / 2.0;
		numOfSteps *= 2;
	}
	printLine("Trapezoidal rule", result, t.elapsed(), numOfIterations);
}

void simpsonsRule8(const double epsilon = 1e-7)
{
	int_fast64_t numOfSteps{ 3 };
	double result{ 0.0 };
	double previousResult{ 1.0 };
	uint_fast64_t numOfIterations{ 0 };

	Timer t;

	while (std::abs(result - previousResult) > epsilon)
	{
		numOfIterations += numOfSteps;
		previousResult = result;
		result = f(leftBoundary) + f(rightBoundary);

		const double intervalSize = (rightBoundary - leftBoundary) / numOfSteps;
		double x{};
		omp_set_dynamic(true);
#pragma omp parallel for private(x) reduction(+:result) 
		for (int_fast64_t i = 1; i < numOfSteps; ++i)
		{
			x = leftBoundary + i * intervalSize;
			if (i % 3 == 0)
			{
				result += 2 * f(x);
			}
			else
			{
				result += 3 * f(x);
			}
		}
		result *= intervalSize * 3.0 / 8.0;
		numOfSteps *= 2;
	}
	printLine("Simpson's 3/8 rule", result, t.elapsed(), numOfIterations);
}

void simpsonsRule3(const double epsilon = 1e-7)
{
	int_fast64_t numOfSteps{ 2 };
	double result{ 0.0 };
	double previousResult{ 1.0 };
	uint_fast64_t numOfIterations{ 0 };

	Timer t;

	while (std::abs(result - previousResult) > epsilon)
	{
		numOfIterations += numOfSteps;
		previousResult = result;
		result = f(leftBoundary) + f(rightBoundary);

		const double intervalSize = (rightBoundary - leftBoundary) / numOfSteps;
		double x{};
		omp_set_dynamic(true);
#pragma omp parallel for private(x) reduction(+:result) 
		for (int_fast64_t i = 1; i < numOfSteps; ++i)
		{
			x = leftBoundary + i * intervalSize;
			if (i % 2 == 0)
			{
				result += 2 * f(x);
			}
			else
			{
				result += 4 * f(x);
			}
		}
		result *= intervalSize / 3.0;
		numOfSteps *= 2;
	}
	printLine("Simpson's 1/3 rule", result, t.elapsed(), numOfIterations);
}

int main(int argc, char* argv[])
{
#ifdef _OPENMP
	printf_s("OpenMP is supported!\n\n");
#endif

	double arr[]{ 1e-5,1e-6,1e-7 };
	//double arr[]{ 1e-5,1e-6,1e-7,1e-8,1e-9,1e-10,1e-11,1e-12, 1e-13,1e-14,1e-15 };

	std::cout << std::left << std::setw(25) << std::setfill(' ') << "Method's name";
	std::cout << std::left << std::setw(20) << std::setfill(' ') << "Result";
	std::cout << std::left << std::setw(20) << std::setfill(' ') << "Time elapsed(s)";
	std::cout << std::left << std::setw(20) << std::setfill(' ') << "Iterations";
	std::cout << '\n';

	for (auto eps : arr)
	{
		std::cout << "\nEpsilon: " << eps << '\n';
		//left_rectangles(1.0, 3.0, eps);
		leftRectangles(eps);
		rightRectangles(eps);
		middleRectangles(eps);
		trapezoidalRule(eps);
		simpsonsRule8(eps);
		simpsonsRule3(eps);
	}

	return 0;
}
