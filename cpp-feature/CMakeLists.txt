cmake_minimum_required(VERSION 3.10)

project(Tutorial VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(Tutorial Tutorial.cpp)

configure_file(TutorialConfig.h.in TutorialConfig.h)


target_include_directories(Tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
