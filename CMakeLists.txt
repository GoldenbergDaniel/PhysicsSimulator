cmake_minimum_required(VERSION 3.11)
project(PhysicsSimulator)

find_package(raylib 3.5 QUIET)

add_executable(${PROJECT_NAME} Engine/main.c Engine/game.c)
target_link_libraries(${PROJECT_NAME} raylib)
