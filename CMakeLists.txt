cmake_minimum_required(VERSION 3.23)

project(mindfudge)

# set(CMAKE_CXX_CLANG_TIDY 
# 	clang-tidy;
# 		-checks=*,-llvmlibc-restrict-system-libc-headers)

find_package(fmt CONFIG REQUIRED)
find_package(Catch2 CONFIG REQUIRED)

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

# TESTS
add_executable(mindfudge_tests)
target_sources(mindfudge_tests
  PRIVATE
    mindfudge_tests.cpp
)
target_link_libraries(mindfudge_tests PRIVATE Catch2::Catch2WithMain)
target_link_libraries(mindfudge_tests PRIVATE Lexer)
