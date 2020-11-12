# cmake_minimum_required(VERSION <specify CMake version here>)
project(TP1)

set(CMAKE_CXX_STANDARD 17)

add_executable(TP1 main.cpp main.hpp Automaton.cpp Automaton.hpp State.cpp State.hpp Occurrence.cpp Occurrence.hpp Link.cpp Link.hpp)
