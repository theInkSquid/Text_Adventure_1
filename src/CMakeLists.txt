cmake_minimum_required (VERSION 3.5)
project (textgame C CXX)

set(CMAKE_INCLUDE_CURRENT_DIR true)

file( GLOB SRCS *.cpp )

add_executable(text_adventure_1 ${SRCS})


