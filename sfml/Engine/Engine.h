#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <mutex>
#pragma once

class Engine {
public:
	sf::RenderWindow* GameWindow;
	int WIDTH;
	int HEIGHT;
	std::string NAME;
	sf::Event event;


	Engine(const int WIDTH, const int HEIGHT, std::string name);

	void CreateWindow();

	void MainLoop();

	~Engine();


	void say_hi();
};
