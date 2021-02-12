#include <chrono>
#include <iostream>
#include <cmath>
#include <functional>
#include <random>
#include <array>

struct Point
{
	double x;
	double y;
};

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

constexpr double pi = 3.141592;
constexpr double g = 9.80665;

void task_1_analytics(double speed, double angle)
{
	std::cout << "L = " << std::abs(speed * speed * sin(2 * angle * pi / 180) / g) << "\n\n";
}

void task_1_imitation(double speed, double angle, double delta = 0.001)
{
	double x_0, y_0, v_x, v_y_0;

	x_0 = y_0 = 0.0;
	v_x = speed * std::cos(angle * pi / 180);
	v_y_0 = speed * std::sin(angle * pi / 180);

	double x_1, y_1, v_y_1;
	x_1 = y_1 = x_0;
	v_y_1 = v_y_0;

	while (y_0 + v_y_0 * delta > 0)
	{
		x_0 = x_1;
		y_0 = y_1;
		v_y_0 = v_y_1;

		x_1 = x_0 + v_x * delta;
		y_1 = y_0 + v_y_0 * delta;
		v_y_1 = v_y_0 - g * delta;
	}

	double L = std::abs(x_0 + v_x * y_0 / v_y_0);

	std::cout << "L = " << L << "\n";
}

void task_2_analytics()
{

}

void task_2_imitation()
{

	double radius;
	Point top_left;
	Point bottom_right;

	std::cout << "Enter left top coords (x;y) via space(e.g. -2 5): ";
	std::cin >> top_left.x >> top_left.y;

	std::cout << "Enter bottom right coords (x;y) via space(e.g. -2 5): ";
	std::cin >> bottom_right.x >> bottom_right.y;

	std::cout << "Enter circle radius: ";
	std::cin >> radius;

	//top_left.x = bottom_right.y = -1;
	//top_left.y = bottom_right.x = 1;
	//radius = 1;

	//int max_side = std::max(width, height);
	//int half_diagonal = std::sqrt(width * width + height * height);

	double min_x = std::min(top_left.x, -radius);
	double max_x = std::max(bottom_right.x, radius);

	double min_y = std::min(bottom_right.y, -radius);
	double max_y = std::max(top_left.y, radius);

	double width = std::abs(min_x - max_x);
	double height = std::abs(min_y - max_y);

	const size_t size = 1e7;

	double x_eps = 1.0 / size;
	double y_eps = 1.0 / size;

	double avg_x = 0.0;
	double avg_y = 0.0;
	avg_x = avg_y = 0.0;


	unsigned temp_seed_1;
	unsigned temp_seed_2;

	size_t counter = 0;
	double result = 0;


	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	//unsigned seed = 305893695;
	std::default_random_engine generator_x(seed);
	std::uniform_real_distribution<double> distribution_x(min_x, max_x);
	auto rand_x = std::bind(distribution_x, generator_x);
	temp_seed_1 = seed;

	seed = std::chrono::system_clock::now().time_since_epoch().count();
	//seed = 3058936968;
	std::default_random_engine generator_y(seed);
	std::uniform_real_distribution<double> distribution_y(min_y, max_y);
	auto rand_y = std::bind(distribution_y, generator_y);
	temp_seed_2 = seed;



	size_t counter_2 = 0;
	size_t counter_3 = 0;


	for (size_t i = 0; i < size; ++i)
	{
		double x = rand_x();
		double y = rand_y();

		//avg_x += x;
		//avg_y += y;

		if (x >= top_left.x && x <= bottom_right.x && y <= top_left.y && y >= bottom_right.y &&
			x * x + y * y <= radius * radius)
			counter++;

	}
	result = static_cast<double>(counter) / (double)size * (double)(width * height);

	std::cout << "N = " << size << "\t area: " << result;
}

//Seed #1: 3058936951
//Seed #2: 3058936968

void task_1_scenario()
{
	//std::cout << std::sin(30 * pi / 180);

	std::array<double, 7> arr = { { 1e-1,1e-2,1e-3,1e-4,1e-5,1e-6,1e-7} };

	double angle = 30;
	double speed = 10;

	task_1_analytics(speed, angle);
	for (auto x : arr)
	{

		std::cout << "delta = " << x << ":\n";
		Timer t;
		task_1_imitation(speed, angle, x);
		std::cout << "Time elapsed: " << t.elapsed() << "\n\n";
	}

	std::array<double, 12> angle_arr = { {0.0, 15.0, 30.0, 45.0, 60.0, 75.0, 90.0, 105.0, 120.0, 135.0, 150.0, 165.0} };
	//task_1_imitation(10, 30, 0.00000001);

	for (auto x : angle_arr)
	{

		std::cout << "angle = " << x << ":\n";
		Timer t;
		task_1_imitation(speed, x, 1e-6);
		std::cout << "Time elapsed: " << t.elapsed() << "\n\n";
	}
}

int main()
{

	//task_1_scenario();
		
	task_2_imitation();
}