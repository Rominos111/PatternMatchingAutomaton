# cmake_minimum_required(VERSION <specify CMake version here>)
project(TP1)

set(CMAKE_CXX_STANDARD 17)

add_executable(TP1 main.cpp main.hpp Automate.cpp Automate.hpp Etat.cpp Etat.hpp Occurrence.cpp Occurrence.hpp Lien.cpp Lien.hpp)
