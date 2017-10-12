cmake_minimum_required(VERSION 3.8)
project(Module7)

set(CMAKE_CXX_STANDARD 11)

#set(SOURCE_FILES unary.cpp)
#set(SOURCE_FILES assignment.cpp)
#set(SOURCE_FILES binaryOperator.cpp)
#set(SOURCE_FILES casting.cpp)
set(SOURCE_FILES mytime.cpp)
add_executable(Module7 ${SOURCE_FILES})