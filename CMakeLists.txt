cmake_minimum_required(VERSION 3.21)
project(5b C)

set(CMAKE_C_STANDARD 99)

add_executable(5b main.c data_structures/vector/vector.h data_structures/vector/vector.c data_structures/vector/testVector.h data_structures/vector/testVector.c data_structures/vector/vectorVoid.h data_structures/vector/vectorVoid.c)
