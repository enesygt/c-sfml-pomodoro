#pragma once
#include "SFML\Graphics.hpp"
#include <Windows.h>
#include <sstream>
#include <iostream>
 
class kronometre
{
private:
	sf::RenderWindow *window;
	sf::RenderWindow window1;
	std::string seconds;
	std::string minutes;
	sf::Clock clock;
	sf::Clock deltaClock;
	sf::Font font;
	sf::Time time;
	sf::Time time_2;

	sf::Event event;
	 int minute;
	int second;
	int kron_minute;
	int kron_second;
	sf::Text t_kronometre;
	sf::Texture tex;
	sf::Texture tex_2;
	bool clock_work_flag;
	bool time_finish_flag;

	sf::Sprite spr;



public:
	int minute_limit;

	kronometre();
	virtual ~kronometre();
	
	void clock_work();
	void init();
	void update();
	void run();
 	void display();

};

