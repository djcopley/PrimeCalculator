cmake_minimum_required(VERSION 3.0)

set(CMAKE_C_STANDARD 11)
project(PrimeCounter C)
link_libraries(pthread m)
add_executable(PrimeCounter count_primes.c)
