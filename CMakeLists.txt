cmake_minimum_required(VERSION 3.19)
project(PhysicsSimulator)

set(CMAKE_C_STANDARD 11)

add_executable(${PROJECT_NAME}
        src/main.c
        src/utility/collision.c
        src/object/object.c)

find_package(raylib 3.0 QUIET)

target_link_libraries(${PROJECT_NAME} "-framework IOKit")
target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
target_link_libraries(${PROJECT_NAME} "-framework OpenGL")

target_link_libraries(${PROJECT_NAME} raylib)
