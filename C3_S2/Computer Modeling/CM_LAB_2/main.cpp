#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Color.hpp"
#include <iostream>
#include <sstream>
#include <cmath>
#include <chrono>
#include <iomanip>


uint16_t constexpr winWidth = 1600u;
uint16_t constexpr winHeight = 900u;

uint16_t constexpr iter = 1000;
double tick = 1.0 / iter;
double constexpr g = 9.81;
const auto pi = std::acos(-1);
double tickCounter = 0.0;
double distance = 0.0;
const float bottom_padding = 40.0f;

struct Var
{
	uint16_t l, b, r, h, h2;
	float m, alpha, beta, mu;
	double speed;
};

struct Point
{
	double x, y;
};

struct Line
{
	double a, b, c;

	Line(Point p1, Point p2)
	{
		a = p2.y - p1.y;
		b = p1.x - p2.x;
		c = a * p1.x + b * p1.y;
	}
};

bool intersect(Line& l, sf::CircleShape& puck)
{
	const double radius = puck.getRadius();
	const auto x = puck.getPosition().x + radius;
	const auto y = puck.getPosition().y + radius;

	const auto dist = (std::abs(l.a * x + l.b * y - l.c) / sqrt(l.a * l.a + l.b * l.b));

	return radius >= dist;
}

static auto switchX(1.0);
static auto switchY(1.0);

void updatePuckCoord(sf::CircleShape& puck, Var& var)
{
	sf::Vector2f pos = puck.getPosition();

	
	auto radiansBeta = var.beta / 180.0 * pi;
	const auto radiansAlpha = var.alpha / 180.0 * pi;

	const auto at = var.mu * g * tick * tick / 2;

	Line left_inclined_line
	(
		{ winWidth / 2.0 - var.l, winHeight - bottom_padding - var.h },
		{
			winWidth / 2.0 - var.l + var.h2 * std::cos(radiansAlpha),
			winHeight - bottom_padding - var.h - var.h2 * std::sin(radiansAlpha)
		}
		);

	Line right_inclined_line
	(
		{ winWidth / 2.0 + var.l, winHeight - bottom_padding - var.h },
		{
			winWidth / 2.0 + var.l + var.h2 * std::cos(radiansAlpha),
			winHeight - bottom_padding - var.h - var.h2 * std::sin(radiansAlpha)
		}
		);

	if (pos.y > winHeight - bottom_padding - var.h &&
		(
			pos.x + 100.0 * var.speed * std::sin(radiansBeta) * tick - at < winWidth / 2.0f - var.l ||
			pos.x + 100.0 * var.speed * std::sin(radiansBeta) * tick - at + 2.0f * var.r > winWidth / 2.0f + var.l))
	{
		var.beta = std::fmod(var.beta + 90.0f, 180.0f);
		//switchX *= -1.0;
	}
	else if (pos.y > winHeight - bottom_padding - var.h - var.h2 * std::sin(radiansAlpha) && pos.y < winHeight -
		bottom_padding - var.h)
	{
		if (intersect(left_inclined_line, puck) || intersect(right_inclined_line, puck))
		{
			var.beta = std::fmod(var.beta + 90.0f + var.alpha, 180.0f);
			//switchX *= -1.0;
		}
	}
	else if (pos.y <= winHeight - bottom_padding - var.h - var.h2 * std::sin(radiansAlpha) || pos.y + 0.9 * var.r >
		winHeight - bottom_padding)
	{
		var.beta = std::fmod(var.beta + 90.0f, 180.0f);
		switchY *= -1.0;
	}


	if (var.speed > 0)
	{
		// a = mu * g;
		// V = v_0 + a * t = v_0 + mu * g * t
		// speed = speed_0 + mu * g * tick
		// distance = distance_0 + speed_0 * t + a * t^2 / 2;
		radiansBeta = var.beta / 180.0 * pi;

		pos.x = pos.x + 100.0 * var.speed * std::cos(radiansBeta) * tick * switchX - at * switchX;
		pos.y = pos.y - 100.0 * var.speed * std::abs(std::sin(radiansBeta)) * tick * switchY - at * switchY;

		distance += var.speed * tick - var.mu * g * tick * tick / 2.0;
		var.speed -= var.mu * g * tick;
		tickCounter += tick;
		puck.setPosition(pos);
	}

	// 2. Check collisions
	//	2.1 left line:
	//if ((pos.x < winWidth / 2.0f - var.l) || (pos.x + 2.0f * var.r > winWidth / 2.0f + var.l))
	//{
	//	switch_x *= -1.0f;
	//}
	/*else if (pos.x + 2.0f * var.r > winWidth / 2.0f + var.l)
	{
		switch_x *= -1.0f;
	}*/
}

int main(int argc, char** argv)
{
	// VARIABLES

	Var var{};

	var.l = 100;
	var.b = 15;
	var.r = 25;
	var.m = 0.100f;
	var.h = 350;
	var.h2 = 800 - var.h;
	var.alpha = 60.0f;
	var.beta = 60.0f;
	var.speed = 15.0;
	var.mu = 0.15f;

	auto radians = var.alpha / 180.0 * pi;

	// SFML VARIABLES

	sf::RenderWindow renderWindow(sf::VideoMode(winWidth, winHeight), "Lab 2");
	sf::Event event{};
	// A Clock starts counting as soon as it's created
	sf::Clock clock;
	sf::Font font;

	font.loadFromFile("Consolas.ttf");

	sf::Text text;
	text.setCharacterSize(24);
	text.setFont(font);
	text.setFillColor(sf::Color::Green);
	text.setStyle(sf::Text::Bold);
	text.setString("Test String!");

	sf::CircleShape puck;
	puck.setRadius(var.r);
	puck.setFillColor(sf::Color::Green);
	puck.setPosition(winWidth / 2.0f - var.r - var.b, winHeight - bottom_padding - var.r);

	sf::VertexArray left_line(sf::Lines, 2);
	left_line[0].position = sf::Vector2f(winWidth / 2.0f - var.l, winHeight - bottom_padding);
	left_line[1].position = sf::Vector2f(winWidth / 2.0f - var.l, winHeight - bottom_padding - var.h);
	left_line[0].color = left_line[1].color = sf::Color::Green;


	sf::VertexArray right_line(sf::Lines, 2);
	right_line[0].position = sf::Vector2f(winWidth / 2.0f + var.l, winHeight - bottom_padding);
	right_line[1].position = sf::Vector2f(winWidth / 2.0f + var.l, winHeight - bottom_padding - var.h);
	right_line[0].color = right_line[1].color = sf::Color::Green;


	sf::VertexArray left_inclined_line(sf::Lines, 2);
	left_inclined_line[0].position = sf::Vector2f(winWidth / 2.0f - var.l, winHeight - bottom_padding - var.h);
	left_inclined_line[1].position = sf::Vector2f(winWidth / 2.0f - var.l + var.h2 * std::cos(radians),
		winHeight - bottom_padding - var.h - var.h2 * std::sin(radians));
	left_inclined_line[0].color = left_inclined_line[1].color = sf::Color::Red;


	sf::VertexArray right_inclined_line(sf::Lines, 2);
	right_inclined_line[0].position = sf::Vector2f(winWidth / 2.0f + var.l, winHeight - bottom_padding - var.h);
	right_inclined_line[1].position = sf::Vector2f(winWidth / 2.0f + var.l + var.h2 * std::cos(radians),
		winHeight - bottom_padding - var.h - var.h2 * std::sin(radians));
	right_inclined_line[0].color = right_inclined_line[1].color = sf::Color::Red;


	renderWindow.setFramerateLimit(100);

	std::chrono::high_resolution_clock::time_point start;
	std::chrono::high_resolution_clock::time_point end;
	float fps = 0.0f;

	while (renderWindow.isOpen())
	{
		// Check for all the events that occurred since the last frame.
		while (renderWindow.pollEvent(event))
		{
			//Handle events here
			if (event.type == sf::Event::EventType::Closed)
				renderWindow.close();
		}

		// A microsecond is 1/1,000,000th of a second, 1000 microseconds == 1 millisecond
		std::cout << "Elapsed time since previous frame(microseconds): "
			<< clock.getElapsedTime().asMicroseconds() << std::endl;
		// Start the countdown over.  Think of laps on a stop watch.
		clock.restart();

		std::stringstream ss;
		ss << "Fps: " << std::fixed << std::setprecision(3) << fps << "\n\nSpeed: " << std::max(0.0, var.speed)
			<< "m/s\n" << "Distance: " << distance << "m\n"
			<< "Puck angle: " << var.beta << "\nTime passed: " << tickCounter << "s\n";


		text.setString(ss.str());
		updatePuckCoord(puck, var);

		start = std::chrono::high_resolution_clock::now();

		renderWindow.clear(sf::Color::Black);
		renderWindow.draw(left_line);
		renderWindow.draw(right_line);
		renderWindow.draw(left_inclined_line);
		renderWindow.draw(right_inclined_line);
		renderWindow.draw(puck);
		renderWindow.draw(text);

		renderWindow.display();

		end = std::chrono::high_resolution_clock::now();

		fps = static_cast<float>(1e9) / static_cast<float>(std::chrono::duration_cast<std::chrono::nanoseconds
		>(end - start).count());
	}
}