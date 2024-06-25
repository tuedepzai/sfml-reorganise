// sfml.cpp : Defines the entry point for the application.
//

#include "sfml.h"
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "vector"
#include <chrono>
#include <ctime>
#include <thread>
#include <random>
#include <mutex>
#include <string>

#include "Engine.h"

using namespace std;

const int WIDTH = 800, HEIGHT = 600, OFFSET = 50;

const std::string name = "untield window";

int main() {
	Engine engine(WIDTH, HEIGHT, name);

	engine.CreateWindow();
	//engine.MainLoop();
}
