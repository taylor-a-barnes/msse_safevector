cmake_minimum_required(VERSION 3.14)

# Project name and version
project(SaveVector VERSION 1.0
	          DESCRIPTION "Memory-safe vector implementation"
		      LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRTRUE)

# Add the executable
add_executable(safevector src/main.cpp)
