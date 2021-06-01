#include "header.h"

bool is_in_range(double x) 
{
	return (x <= INPUT_MAX && x >= INPUT_MIN);
}

linear_t get_equation(point_t p1, point_t p2, bool &error) 
{
	linear_t lin = { 0 };

	if (!is_in_range(p1.x) || 
		!is_in_range(p1.y) || 
		!is_in_range(p2.x) || 
		!is_in_range(p2.y)) {
		error = true;
		return lin;
	}

	if (p1.x == p2.x) {
		if (p1.y == p2.y) {
			error = true;
			return lin;
		}
		lin.is_vertical = true;
		lin.k = p1.x;
		lin.b = 0;
	}
	else {
		lin.is_vertical = false;
		lin.k = (p1.y - p2.y) / (p1.x - p2.x);
		lin.b = p1.y - lin.k * p1.x;
	}

	error = false;
	return lin;
}

point_t solve(linear_t f, linear_t g, int &type)
{
	point_t p = {0};

	if (f.is_vertical && g.is_vertical) {
		if (f.k == g.k) {
			type = SAME;
			return p;
		}
		else {
			type = PARALLEL;
			return p;
		}
	}
	
	if (g.is_vertical) std::swap(f, g);

	if (f.is_vertical) {
		p.x = f.k;
		p.y = g.k * p.x + g.b;
		type = INTERSECT;
		return p;
	}
		
	if (f.k == g.k) {
		type = (f.b == g.b) ? SAME : PARALLEL;
		return p;
	}
	p.x = (g.b - f.b) / (f.k - g.k);
	p.y = f.k * p.x + f.b;
	type = INTERSECT;
	return p;
}

/**
*	Функциональные требования:
*	Входные данные: (x1, y1), (x2, y2), (x3, y3), (x4, y4): (-inf; +inf)
*	Выходные данные: (x; y) или "Прямые параллельны" или "Прямые совпадают"
*/

int main () 
{
	point_t p1 = {}, p2 = {}, p3 = {}, p4 = {};
	std::cout << "Enter first line points (space-delimited): x1 y1 x2 y2\n";
	std::cin >> p1.x >> p1.y >> p2.x >> p2.y;
	std::cout << "Enter second line points (space-delimited): x1 y1 x2 y2\n";
	std::cin >> p3.x >> p3.y >> p4.x >> p4.y;
	
	if (std::cin.fail()) 
	{
		std::cout << "Invalid data\n";
	}

	bool error1 = false, error2 = false;
	linear_t f = get_equation(p1, p2, error1),
			 g = get_equation(p3, p4, error2);

	if (error1 || error2) {
		std::cout << "Invalid data\n";
		return 1;
	}

	int type;
	point_t solution = solve(f, g, type);

	if (type == INTERSECT) {
		std::cout << "Solution: " << solution.x << " " << solution.y << std::endl;
	}
	else if (type == PARALLEL) {
		std::cout << "Parallel\n";
	}
	else if (type == SAME) {
		std::cout << "Coincide\n";
	}
	else {
		std::cout << "Error\n";
	}

}
