cmake_minimum_required(VERSION 3.15)

project(EngineSimulator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing(TRUE)

add_subdirectory(app)
add_subdirectory(lib)
add_subdirectory(tests)
