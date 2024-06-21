#include <iostream>
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "Engine.h"
#include <string>
#include <mutex>


Engine::Engine(const int WIDTH, const int HEIGHT, std::string name) {
	this->WIDTH = WIDTH;
	this->HEIGHT = HEIGHT;
	this->NAME = name;

	std::cout << "Window init successfully!" << '\n';
}
void Engine::CreateWindow(){	
	sf::RenderWindow window(sf::VideoMode(this->WIDTH, this->HEIGHT), this->NAME);
	this->GameWindow = &window;
}


void Engine::MainLoop() {
	while (this->GameWindow->isOpen()) {

	}
}

Engine::~Engine() {

}

