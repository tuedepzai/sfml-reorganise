#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <mutex>
#pragma once

class Engine {
public:
	sf::RenderWindow* GameWindow;
	std::mutex WindowMutex;
	int WIDTH;
	int HEIGHT;
	std::string NAME;



	Engine(const int WIDTH, const int HEIGHT, std::string name);

	void CreateWindow();

	void DrawGrid(int OFFSET);

	void MainLoopFunction();

	~Engine();


	void say_hi();
};
