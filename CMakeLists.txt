cmake_minimum_required(VERSION 3.23)

project(mindfudge)

find_package(fmt CONFIG REQUIRED)

add_subdirectory(Lexer)
add_subdirectory(Interpreter)

add_executable(mindfudge)
target_sources(mindfudge
  PRIVATE
    mindfudge.cpp
)

target_link_libraries(mindfudge PRIVATE fmt::fmt)
target_link_libraries(mindfudge PRIVATE Lexer)
target_link_libraries(mindfudge PRIVATE Interpreter)
