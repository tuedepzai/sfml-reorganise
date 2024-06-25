#include <iostream>
#include "SFML/Window.hpp"
#include "mutex"
#include "SFML/Graphics.hpp"
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include "Engine.h"

#include "imgui.h"
#include "imgui-SFML.h"

#include <string>
#include <mutex>


Engine::Engine(const int WIDTH, const int HEIGHT, std::string name) {
	this->WIDTH = WIDTH;
	this->HEIGHT = HEIGHT;
	this->NAME = name;

	

	std::cout << "Window & ImGUI init successfully!" << std::endl;
}


void Engine::CreateWindow(){	
	sf::RenderWindow window(sf::VideoMode(this->WIDTH, this->HEIGHT), this->NAME);
	this->GameWindow = &window;


	ImGui::SFML::Init(*this->GameWindow);
	sf::Clock deltaClock;
	while (this->GameWindow->isOpen()) {
		sf::Event event;
		while (this->GameWindow->pollEvent(event)) {
			ImGui::SFML::ProcessEvent(*this->GameWindow, event);
			if (event.type == sf::Event::Closed) {
				this->GameWindow->close();
			}
		}
		this->MainLoopFunction();
		ImGui::SFML::Update(window, deltaClock.restart());

		ImGui::ShowDemoWindow();

		ImGui::Begin("Hello, world!");
		ImGui::Button("Look at this pretty button");
		ImGui::End();

		window.clear();
		ImGui::SFML::Render(*this->GameWindow);

		window.display();

		this->GameWindow->display();
	}
	ImGui::SFML::Shutdown();
}

void Engine::MainLoopFunction() {

}

void Engine::DrawGrid(int OFFSET) {
	if (this->WindowMutex.try_lock()) {
		std::cout << "[DrawGrid] : Variable control granted" << '\n';
		int x_start = 0, y_start = 0, x_end = WIDTH, y_end = 0;

		//int horizontal_lines = WIDTH / OFFSET, vertical_lines = HEIGHT / OFFSET;
		int horizontal_lines = 100, vertical_lines = 100;

		while (horizontal_lines-- > 0) {

			sf::Vertex vertices[] = {
				sf::Vertex(sf::Vector2f(x_start, y_start), sf::Color::White),
				sf::Vertex(sf::Vector2f(x_end, y_end), sf::Color::White)
			};
			y_start += OFFSET;
			y_end += OFFSET;

			this->GameWindow->draw(vertices, 2, sf::Lines);

		}
		x_start = 0, y_start = 0, x_end = 0, y_end = HEIGHT;

		while (vertical_lines-- > 0) {
			sf::Vertex vertices[] = {
				sf::Vertex(sf::Vector2f(x_start, y_start), sf::Color::White),
				sf::Vertex(sf::Vector2f(x_end, y_end), sf::Color::White)
			};
			x_start += OFFSET;
			x_end += OFFSET;

			this->GameWindow->draw(vertices, 2, sf::Lines);
		}
		this->WindowMutex.unlock();
	}
}

Engine::~Engine() {

}

