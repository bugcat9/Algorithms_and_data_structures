cmake_minimum_required(VERSION 3.10) 

# set the project name 
project(Algorithms_and_data_structures)

find_library(BOOSTTEST_LIBRARY NAMES boost_unit_test_framework)
add_subdirectory(test)

# add the executable 
add_executable(main main.cpp) 