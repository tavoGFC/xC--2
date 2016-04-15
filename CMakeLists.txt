cmake_minimum_required(VERSION 3.5)
project(Kevin_C__2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp xPointer.h xPointer.cpp xPointer.h xObject.cpp xObject.h xMemoryManager.cpp xMemoryManager.h  xList.cpp xList.h)
add_executable(Kevin_C__2 ${SOURCE_FILES})