#include <chrono>
#include <iostream>
#include <omp.h>
#include <cmath>
#include <iomanip>

inline double f(double x)
{
	return std::sin(1.0 / 3.0) * std::log(0.1 + x * x);
}

class Timer
{
private:
	// Псевдонимы типов используются для удобного доступа к вложенным типам
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

		const double step = (b - a) / num_of_steps;


		for (int64_t i = 0; i < num_of_steps; i++)
		{
			double x = a + step * (i);
			result += f(x);
		}
		result *= step;
		num_of_steps *= 2;

	}
	std::cout << "Time elapsed: " << t.elapsed() << '\n';
	std::cout.precision(10);
	std::cout << "Number of iterations: " << num_of_iterations << '\n';
	std::cout << "Left rectangles: " << result << "\n\n";

}

void left_rectangles_omp(const double a = 1.0, const double b = 3.0, const double eps = 1e-7)
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

		const double step = (b - a) / num_of_steps;
		double x;

#pragma omp parallel for private(x) reduction(+:result)
		for (int64_t i = 0; i < num_of_steps; i++)
		{
			x = a + step * (i);
			result += f(x);
		}
		result *= step;
		num_of_steps *= 2;
	}
	std::cout << "Time elapsed omp: " << t.elapsed() << '\n';
	std::cout.precision(10);
	std::cout << "Number of iterations: " << num_of_iterations << '\n';
	std::cout << "Left rectangles: " << result << "\n\n";;
}

void right_rectangles(const double a = 1.0, const double b = 3.0, const double eps = 1e-7)
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

		const double step = (b - a) / num_of_steps;
		double x;
#pragma omp parallel for private(x) reduction(+:result)
		for (int64_t i = 1; i <= num_of_steps; i++)
		{
			x = a + step * (i);
			result += f(x);
		}
		result *= step;
		num_of_steps *= 2;
	}
	std::cout << "Time elapsed omp: " << t.elapsed() << '\n';
	std::cout.precision(10);
	std::cout << "Number of iterations: " << num_of_iterations << '\n';
	std::cout << "Right rectangles: " << result << "\n\n";
}

void middle_rectangles(const double a = 1.0, const double b = 3.0, const double eps = 1e-7)
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

		const double step = (b - a) / num_of_steps;
		double x;
		double x_prev;
#pragma omp parallel for private(x, x_prev) reduction(+:result)
		for (int64_t i = 1; i <= num_of_steps; i++)
		{
			x = a + step * (i);
			x_prev = a + step * (i - 1);
			result += f((x + x_prev) / 2.0);
		}
		result *= step;
		num_of_steps *= 2;
	}
	std::cout << "Time elapsed omp: " << t.elapsed() << '\n';
	std::cout.precision(10);
	std::cout << "Number of iterations: " << num_of_iterations << '\n';
	std::cout << "Middle rectangles: " << result << "\n\n";
}

void trapezoidal_rule(const double a = 1.0, const double b = 3.0, const double eps = 1e-7)
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

		const double step = (b - a) / num_of_steps;

		double x;
		double x_prev;
#pragma omp parallel for private(x, x_prev) reduction(+:result)
		for (int64_t i = 1; i <= num_of_steps; i++)
		{
			x = a + step * (i);
			x_prev = a + step * (i - 1);
			result += f(x) + f(x_prev);
		}
		result *= step / 2.0;
		num_of_steps *= 2;
	}
	std::cout << "Time elapsed omp: " << t.elapsed() << '\n';
	std::cout.precision(10);
	std::cout << "Number of iterations: " << num_of_iterations << '\n';
	std::cout << "Trapezoidal rule: " << result << "\n\n";
}

void simpsons_rule(const double a = 1.0, const double b = 3.0, const double eps = 1e-7)
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

		const double step = (b - a) / num_of_steps;

		/*
		 *	f(x)dx = h/6 sum( f(x_i-1) + 4f(x_i-0.5) + f(x_i)) from 1 to n
		 *	x_i-0.5 = (x_i-1 + x_i)/2
		 */
		double x;
		double x_prev;
#pragma omp parallel for private(x, x_prev) reduction(+:result)
		for (int64_t i = 1; i <= num_of_steps; i++)
		{
			x = a + step * (i);
			x_prev = a + step * (i - 1);
			result += f(x) + f(x_prev) + 4 * f((x + x_prev) / 2);
		}
		result *= step / 6;
		num_of_steps *= 2;
	}
	std::cout << "Time elapsed omp: " << t.elapsed() << '\n';
	std::cout.precision(10);
	std::cout << "Number of iterations: " << num_of_iterations << '\n';
	std::cout << "Simpson's rule rule: " << result << "\n\n";
}

int main(int argc, char* argv[])
{
	omp_set_num_threads(12);

	double arr[3] = { 1e-5,1e-6,1e-7 };

	for (auto x : arr)
	{
		std::cout << "Epsilon: " << x << "\n\n";
		left_rectangles(1.0, 3.0, x);
		left_rectangles_omp(1.0, 3.0, x);
		right_rectangles(1.0, 3.0, x);
		middle_rectangles(1.0, 3.0, x);
		trapezoidal_rule(1.0, 3.0, x);
		simpsons_rule(1.0, 3.0, x);
	}

	return 0;
}

