#pragma once

#include <iostream>

#define INTERSECT 0
#define PARALLEL 1
#define SAME 2

#define INPUT_MIN (-1e15)
#define INPUT_MAX (+1e15)


struct linear_t
{
	double k;
	double b;
	bool is_vertical;
};

struct point_t
{
	double x;
	double y;
};
