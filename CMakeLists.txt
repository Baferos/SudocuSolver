cmake_minimum_required(VERSION 3.23)
project(suducuSolver)

set(CMAKE_CXX_STANDARD 14)

add_executable(suducuSolver src/main.cpp src/SudocuSolver.cpp src/SudocuSolver.hpp)
