cmake_minimum_required(VERSION 3.19)
project(PhysicsSimulator)

set(CMAKE_C_STANDARD 11)

find_package(raylib 3.0 QUIET)

add_executable(${PROJECT_NAME}
        src/main.c
        src/simulation.c
        src/object/object.c)

if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()

target_link_libraries(${PROJECT_NAME} raylib)
