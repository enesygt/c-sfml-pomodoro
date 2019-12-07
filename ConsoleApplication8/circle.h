#pragma once
#include <SFML\Graphics.hpp>

class circle
{
private:
	float circle_radius=100.0;
	float pos_x = 50.0;
	float pos_y=50.0;
	float thickness=12.0;

public:
	sf::CircleShape my_circle;
	sf::CircleShape centerCircle;
	circle();
	//Circle initialize
	void circle_initialize();
	void circle_grow_up();
	void take_pos();
	~circle();
};

