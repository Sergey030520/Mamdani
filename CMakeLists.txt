cmake_minimum_required(VERSION 3.17)
project(Mamdani)

set(CMAKE_CXX_STANDARD 14)

add_executable(Mamdani main.cpp Mamdani.cpp Mamdani.h Rule.cpp Rule.h Term.cpp Term.h StringOperation.cpp StringOperation.h Variable.h UniverseFuzzyVariables.h Statement.cpp Statement.h FuzzySet.h Conclusion.h)