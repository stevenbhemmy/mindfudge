cmake_minimum_required(VERSION 3.23)

project(mindfudge)

add_executable(mindfudge)
target_sources(mindfudge
  PRIVATE
    mindfudge.cpp
)
