cmake_minimum_required(VERSION 3.0)
project(ShootEmUpGame)

find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

add_executable(main main.cpp)

target_link_libraries(main sfml-graphics sfml-window sfml-system)
