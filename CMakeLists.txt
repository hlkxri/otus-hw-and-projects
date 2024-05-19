cmake_minimum_required(VERSION 3.25)
project(guess_the_number)

set(CMAKE_CXX_STANDARD 17)

add_executable(guess_the_number
        header.h
        main.cpp
        high_scores.txt)
