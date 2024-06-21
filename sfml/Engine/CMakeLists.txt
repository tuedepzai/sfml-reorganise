cmake_minimum_required (VERSION 3.8)
project(Engine)
find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
find_package(ImGui-SFML CONFIG REQUIRED)

add_library(Engine Engine.cpp Engine.h)




