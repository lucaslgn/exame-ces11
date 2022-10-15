cmake_minimum_required(VERSION 3.14)
project(Exam)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML COMPONENTS window system REQUIRED)

set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Wextra -pedantic")

file(GLOB_RECURSE SRC_HPP src/*.hpp)
file(GLOB_RECURSE SRC_CPP src/*.cpp)

include_directories(src)

add_executable(Exam ${SRC_CPP} ${SRC_HPP})

target_link_libraries(Exam sfml-window sfml-system sfml-graphics)