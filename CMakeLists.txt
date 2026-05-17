cmake_minimum_required(VERSION 3.23)

project(mindfudge)

# set(CMAKE_CXX_CLANG_TIDY 
# 	clang-tidy;
# 		-checks=*,-llvmlibc-restrict-system-libc-headers)

# DEPENDENCIES
find_package(fmt CONFIG REQUIRED)
find_package(Catch2 CONFIG REQUIRED)

# SOURCE
add_subdirectory(src)

# TESTS
add_subdirectory(tests)
