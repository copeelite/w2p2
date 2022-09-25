cmake_minimum_required(VERSION 3.23)
project(w2p2)

set(CMAKE_CXX_STANDARD 17)

add_executable(w2p2 main.cpp File.cpp File.h Population.cpp Population.h cmake-build-debug/PCpopulations.csv cmake-build-debug/PCpopulationsComplete.csv)
